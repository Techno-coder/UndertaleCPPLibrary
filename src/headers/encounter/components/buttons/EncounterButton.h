#pragma once

namespace sf {
	class RenderTarget;
}

namespace ucl {
	class EncounterButton {
	public:
		virtual void draw(sf::RenderTarget& target) = 0;
		virtual void setPosition(float x, float y) = 0;
		virtual void setHighlighted(bool isHighlighted) = 0;
	};
}