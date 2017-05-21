#pragma once

#include <memory>

namespace sf {
	class RenderTarget;
}

namespace ug {
	class FightBar {
		struct Impl;
		std::unique_ptr<Impl> impl;
	public:
		/**
		 * @param numTargetLines
		 * @param distBetweenLines
		 * @param linesStartOnLeft
		 */
		FightBar(unsigned int numTargetLines, bool linesStartOnLeft);
		virtual ~FightBar();

		void draw(sf::RenderTarget& target);
		/**
		 * Updates the fight bar
		 * @param attackSpeed Affects speed of target lines, negative values causes lines to move backwards
		 */
		void update(float attackSpeed);
		/**
		 * Hits the fight bar
		 * @param removeLastTargetLine Removes the rightmost target line if true
		 * @return The distance from the center of the bar or NaN if there are no more target lines
		 */
		float hit(bool removeLastTargetLine);
		/**
		 * Make the next target line start moving
		 */
		void startNextTargetLine();
		void setTopLeftPosition(float x, float y);
	};
}


