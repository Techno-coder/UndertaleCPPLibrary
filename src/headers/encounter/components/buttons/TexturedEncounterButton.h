#pragma once

#include <memory>
#include "EncounterButton.h"

namespace sf {
	class Texture;
}

namespace ug {
	class TexturedEncounterButton : public EncounterButton {
		struct Impl;
		std::unique_ptr<Impl> impl;
	public:
		/**
		 * Create an encounter button based on two textures
		 * @warning The textures provided must exist for the lifetime of this button
		 * @param highlighted The texture for when the button is highlighted
		 * @param normal The texture for when the button is not highlighted
		 */
		TexturedEncounterButton(const sf::Texture& highlighted, const sf::Texture& normal);
		~TexturedEncounterButton();

		void draw(sf::RenderTarget& target) override;
		void setTopLeftPosition(float x, float y) override;
		void setHighlighted(bool isHighlighted) override;
	};
}

