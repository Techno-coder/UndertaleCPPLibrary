#pragma once

#include <memory>
#include "EncounterButton.h"

namespace ucl {
	class FightButton : public EncounterButton {
		struct Impl;
		std::unique_ptr<Impl> impl;
	public:
		FightButton();
		void draw(sf::RenderTarget& target) override;
		void setPosition(float x, float y) override;
		void setHighlighted(bool isHighlighted) override;
	};
}

