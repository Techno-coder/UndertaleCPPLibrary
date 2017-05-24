#pragma once

#include <memory>
#include <string>
#include "ResourceResolver.h"

namespace ug {
	class BasicResourceResolver : public ResourceResolver {
		struct Impl;
		std::unique_ptr<Impl> impl;
	public:
		BasicResourceResolver();
		virtual ~BasicResourceResolver();

		static const std::string getResourcesRootPath();
		static std::unique_ptr<sf::Texture> loadTexture(const std::string& internalPath);
		static std::unique_ptr<sf::Font> loadFont(const std::string& internalPath);
		static std::unique_ptr<sf::SoundBuffer> loadSound(const std::string& internalPath);

		void registerTexture(std::unique_ptr<sf::Texture> texture, const std::string& ID);
		const sf::Texture& getTexture(const std::string& ID) const override;

		void registerFont(std::unique_ptr<sf::Font> font, const std::string& ID);
		const sf::Font& getFont(const std::string& ID) const override;

		void registerSound(std::unique_ptr<sf::SoundBuffer> sound, const std::string& ID);
		const sf::SoundBuffer& getSound(const std::string& ID) const override;
	};
}

