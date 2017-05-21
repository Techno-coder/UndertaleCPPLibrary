#pragma once

namespace sf {
	class RenderTarget;
}

namespace ug {
	class EncounterButton {
	public:
		/**
		 * Draw this button
		 * @param target The target to draw onto
		 */
		virtual void draw(sf::RenderTarget& target) = 0;
		/**
		 * Set the top left position of this button
		 * @param x Distance from left
		 * @param y Distance from top
		 */
		virtual void setTopLeftPosition(float x, float y) = 0;
		/**
		 * Set the texture of this button
		 * @param isHighlighted Use the highlighted texture if true
		 */
		virtual void setHighlighted(bool isHighlighted) = 0;

		virtual ~EncounterButton() {}
	};
}