#pragma once

namespace sf {
	class RenderTarget;
}

namespace ug {
	class EncounterButton {
	public:
		virtual void draw(sf::RenderTarget& target) = 0;
		virtual void setTopLeftPosition(float x, float y) = 0;
		virtual void setHighlighted(bool isHighlighted) = 0;

		virtual ~EncounterButton() {}
	};
}