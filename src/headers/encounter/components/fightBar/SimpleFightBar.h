#pragma once

#include <memory>
#include "FightBar.h"

namespace ug {
	/**
	 * Fight bar which has one target line which moves from the left
	 * When confirm key is pressed target line switches colours indefinitely
	 */
	class SimpleFightBar : public FightBar {
		struct Impl;
		std::unique_ptr<Impl> impl;
	public:
		SimpleFightBar();

		void update(float attackSpeed) override;
		void draw(sf::RenderTarget& target) override;
		void setTopLeftPosition(float x, float y) override;
		float onConfirmKeyPress() override;
	};
}

