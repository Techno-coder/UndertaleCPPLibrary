#pragma once

namespace sf {
	class RenderTarget;
}

namespace ug {
	class FightBar { //TODO redo the api because it succs
	public:
		virtual void update(float attackSpeed) = 0;
		virtual void draw(sf::RenderTarget& target) = 0;
		virtual void setTopLeftPosition(float x, float y) = 0;
		/**
		 * Should be called when the confirm key is pressed
		 * @return The distance in pixels of how far away a target line is from the center of the bar or NaN if finished
		 */
		virtual float onConfirmKeyPress() = 0;
		/**
		 * Returns true if all target lines are expired
		 * @return A boolean
		 */
		virtual bool isFinished() = 0;
	};
}