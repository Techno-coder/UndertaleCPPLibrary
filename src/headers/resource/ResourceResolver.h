#pragma once

#include <string>

namespace sf {
	class Texture;

	class Font;

	class SoundBuffer;
}

namespace ug {
	class ResourceResolver {
	public:
		virtual const sf::Texture& getTexture(const std::string& ID) const = 0;
		virtual const sf::Font& getFont(const std::string& ID) const = 0;
		virtual const sf::SoundBuffer& getSound(const std::string& ID) const = 0;
	};
}

