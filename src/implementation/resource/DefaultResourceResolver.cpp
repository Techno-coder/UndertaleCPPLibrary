#include <resource/DefaultResourceResolver.h>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <fstream>
#include <locator/LoggerLocator.h>
#include <logging/Logger.h>
#include <sstream>
#include <resource/BasicResourceResolver.h>

struct ug::DefaultResourceResolver::Impl {
	std::unique_ptr<BasicResourceResolver> internalResolver{new BasicResourceResolver()};
};

std::unique_ptr<ug::ResourceResolver> ug::DefaultResourceResolver::createNew() {
	return std::make_unique<ug::DefaultResourceResolver>();
}

ug::DefaultResourceResolver::~DefaultResourceResolver() {}

template <typename Out>
void split(const std::string& s, char delimiter, Out result) {
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delimiter)) {
		*(result++) = item;
	}
}

std::vector<std::string> split(const std::string& s, char delimiter) {
	std::vector<std::string> elements;
	split(s, delimiter, std::back_inserter(elements));
	return elements;
}

ug::DefaultResourceResolver::DefaultResourceResolver() : impl(std::make_unique<Impl>()) {
	std::ifstream input(BasicResourceResolver::getResourcesRootPath() + "default/resource_map");
	if (!input.is_open()) {
		LoggerLocator::get()->log(LogSeverity::WARNING,
		                          "Default resource_map file failed to open. No resources were registered");
		return;
	}

	std::string currentLine;
	while (!std::getline(input, currentLine).eof()) {
		auto tokens = split(currentLine, ' ');
		if (tokens.size() == 0) continue;
		else if (tokens.size() != 3) {
			LoggerLocator::get()->log(LogSeverity::WARNING, "Invalid listing in default resource_map");
			continue;
		}

		if (tokens[0] == "FONT") {
			impl->internalResolver->registerFont(BasicResourceResolver::loadFont("default/" + tokens[2]), tokens[1]);
		} else if (tokens[0] == "TEXTURE") {
			impl->internalResolver->registerTexture(BasicResourceResolver::loadTexture("default/" + tokens[2]),
			                                        tokens[1]);
		} else if (tokens[0] == "SOUND") {
			impl->internalResolver->registerSound(BasicResourceResolver::loadSound("default/" + tokens[2]), tokens[1]);
		} else {
			LoggerLocator::get()->log(LogSeverity::WARNING, "Unknown type " + tokens[0] + " in default resource_map");
		}
	}
}

const sf::Texture& ug::DefaultResourceResolver::getTexture(const std::string& ID) const {
	return impl->internalResolver->getTexture(ID);
}

const sf::Font& ug::DefaultResourceResolver::getFont(const std::string& ID) const {
	return impl->internalResolver->getFont(ID);
}

const sf::SoundBuffer& ug::DefaultResourceResolver::getSound(const std::string& ID) const {
	return impl->internalResolver->getSound(ID);
}
