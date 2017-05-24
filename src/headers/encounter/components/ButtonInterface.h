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
		virtual ~ButtonInterface();

		void draw(sf::RenderTarget& target);

		enum class Button {
			ONE, TWO, THREE, FOUR, NONE
		};

		static constexpr Button FIGHT = Button::ONE;
		static constexpr Button ACT = Button::TWO;
		static constexpr Button ITEM = Button::THREE;
		static constexpr Button MERCY = Button::FOUR;

		/**
		 * Set the button that should be highlighted
		 * @param button The button
		 */
		void setHighlighted(const Button& button);
		/**
		 * Set the top left position of all the buttons
		 * @param x Distance from left
		 * @param y Distance from top
		 */
		void setTopLeftPosition(float x, float y);
	};

	std::unique_ptr<ButtonInterface> getNewDefaultButtonInterface();
}

