#pragma once

#include <memory>

namespace ug {
	class EncounterButton;

	class DefaultButtons {
	public:
		static std::unique_ptr<EncounterButton> createFightButton();
		static std::unique_ptr<EncounterButton> createActButton();
		static std::unique_ptr<EncounterButton> createItemButton();
		static std::unique_ptr<EncounterButton> createMercyButton();
	};
}

