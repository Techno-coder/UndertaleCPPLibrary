#pragma once

#include <memory>
#include "EncounterBaseButton.h"

namespace ug {
	class ItemButton : public EncounterBaseButton {
		struct Impl;
		std::unique_ptr<Impl> impl;
		sf::Texture& getTexture(bool isHighlighted) override;
	public:
		ItemButton();
	};
}

