#pragma once

#include <memory>

namespace sf {
	class RenderTarget;
}

namespace ug {
	class Arena {
		struct Impl;
		std::unique_ptr<Impl> impl;
	public:
		Arena();
		~Arena();
		void draw(sf::RenderTarget& target);
		/**
		 * Changes the size of the rectangle relative from the center
		 * @param width The width
		 * @param height The height
		 */
		void resize(float width, float height);
		/**
		 * Sets the position of the center of the arena
		 * @param x Distance from left
		 * @param y Distance from top
		 */
		void setPosition(float x, float y);
	};
}

