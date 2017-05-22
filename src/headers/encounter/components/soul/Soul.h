#pragma once

namespace sf {
	class RenderTarget;
}

namespace ug {
	class Soul {
	public:
		/**
		 * Draw the soul
		 * @param target The target to draw on
		 */
		virtual void draw(sf::RenderTarget& target) = 0;
		/**
		 * Sets the position of the center of the soul
		 * @param x Distance from left
		 * @param y Distance from right
		 */
		virtual void setPosition(float x, float y) = 0;

		virtual ~Soul() {}
	};
}