#pragma once

#include <memory>
#include "EncounterBaseButton.h"

namespace ug {
	class MercyButton : public EncounterBaseButton {
		struct Impl;
		std::unique_ptr<Impl> impl;
		sf::Texture& getTexture(bool isHighlighted) override;
	public:
		MercyButton();
	};
}

