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

		virtual ~Soul() {}
	};
}