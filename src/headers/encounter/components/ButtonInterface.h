#pragma once

#include <memory>

namespace sf {
	class RenderTarget;
}

namespace ug {
	class EncounterButton;

	class ButtonInterface {
		struct Impl;
		std::unique_ptr<Impl> impl;
	public:
		ButtonInterface(std::unique_ptr<EncounterButton> buttonOne,
		                std::unique_ptr<EncounterButton> buttonTwo,
		                std::unique_ptr<EncounterButton> buttonThree,
		                std::unique_ptr<EncounterButton> buttonFour
		);
		void draw(sf::RenderTarget& target);

		enum class Button {
			ONE, TWO, THREE, FOUR, NONE
		};
		void setHighlighted(Button button);
		void setTopLeftPosition(float x, float y);
	};
}

