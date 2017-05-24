#include <resource/BasicResourceResolver.h>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <unordered_map>
#include <locator/LoggerLocator.h>
#include <logging/Logger.h>

struct ug::BasicResourceResolver::Impl {
	std::unordered_map<std::string, std::unique_ptr<sf::Texture>> textures;
	std::unordered_map<std::string, std::unique_ptr<sf::Font>> fonts;
	std::unordered_map<std::string, std::unique_ptr<sf::SoundBuffer>> sounds;

	const sf::Texture nullTexture;
	const sf::Font nullFont;
	const sf::SoundBuffer nullSound;
};

ug::BasicResourceResolver::~BasicResourceResolver() {}

void ug::BasicResourceResolver::registerTexture(std::unique_ptr<sf::Texture> texture, const std::string& ID) {
	impl->textures.emplace(ID, std::move(texture));
}

const sf::Texture& ug::BasicResourceResolver::getTexture(const std::string& ID) const {
	if (impl->textures.count(ID) <= 0) {
		LoggerLocator::get()->log(LogSeverity::WARNING, "Texture " + ID + " was not registered");
		return impl->nullTexture;
	}
	return *impl->textures[ID];
}

void ug::BasicResourceResolver::registerFont(std::unique_ptr<sf::Font> font, const std::string& ID) {
	impl->fonts.emplace(ID, std::move(font));
}

const sf::Font& ug::BasicResourceResolver::getFont(const std::string& ID) const {
	if (impl->fonts.count(ID) <= 0) {
		LoggerLocator::get()->log(LogSeverity::WARNING, "Font " + ID + " was not registered");
		return impl->nullFont;
	}
	return *impl->fonts[ID];
}

void ug::BasicResourceResolver::registerSound(std::unique_ptr<sf::SoundBuffer> sound, const std::string& ID) {
	impl->sounds.emplace(ID, std::move(sound));
}

const sf::SoundBuffer& ug::BasicResourceResolver::getSound(const std::string& ID) const {
	if (impl->sounds.count(ID) <= 0) {
		LoggerLocator::get()->log(LogSeverity::WARNING, "Sound " + ID + " was not registered");
		return impl->nullSound;
	}
	return *impl->sounds[ID];
}

ug::BasicResourceResolver::BasicResourceResolver() : impl(std::make_unique<Impl>()) {}

const std::string ug::BasicResourceResolver::getResourcesRootPath() {
	return "resources/";
}

std::unique_ptr<sf::Texture> ug::BasicResourceResolver::loadTexture(const std::string& internalPath) {
	std::unique_ptr<sf::Texture> temp(std::make_unique<sf::Texture>());
	temp->loadFromFile(getResourcesRootPath() + internalPath);
	return temp;
}

std::unique_ptr<sf::Font> ug::BasicResourceResolver::loadFont(const std::string& internalPath) {
	std::unique_ptr<sf::Font> temp(std::make_unique<sf::Font>());
	temp->loadFromFile(getResourcesRootPath() + internalPath);
	return temp;
}

std::unique_ptr<sf::SoundBuffer> ug::BasicResourceResolver::loadSound(const std::string& internalPath) {
	std::unique_ptr<sf::SoundBuffer> temp(std::make_unique<sf::SoundBuffer>());
	temp->loadFromFile(getResourcesRootPath() + internalPath);
	return temp;
}

