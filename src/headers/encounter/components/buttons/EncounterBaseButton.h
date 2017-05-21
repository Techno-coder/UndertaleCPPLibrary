#pragma once

#include <memory>
#include "EncounterButton.h"

#include <SFML/Graphics/Texture.hpp>

namespace ug {
	template <typename T>
	struct EncounterButtonStaticTextures {
		static std::unique_ptr<sf::Texture> highlight;
		static std::unique_ptr<sf::Texture> normal;

		EncounterButtonStaticTextures(const std::string& internalHighlightPath, const std::string& internalNormalPath) {
			if (!highlight) highlight->loadFromFile(internalHighlightPath);
			if (!normal) normal->loadFromFile(internalNormalPath);
		}
	};

	template <typename T>
	std::unique_ptr<sf::Texture> EncounterButtonStaticTextures<T>::highlight;

	template <typename T>
	std::unique_ptr<sf::Texture> EncounterButtonStaticTextures<T>::normal;

	class EncounterBaseButton : public EncounterButton {
		struct Impl;
		std::unique_ptr<Impl> impl;
		virtual sf::Texture& getTexture(bool isHighlighted) = 0;
	public:
		EncounterBaseButton();
		virtual ~EncounterBaseButton();

		void draw(sf::RenderTarget& target) override;
		void setTopLeftPosition(float x, float y) override;
		void setHighlighted(bool isHighlighted) override;
	};
}

