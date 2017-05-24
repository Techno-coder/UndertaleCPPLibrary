#include <encounter/components/buttons/DefaultButtons.h>

#include <encounter/components/buttons/TexturedEncounterButton.h>
#include <locator/ResourceLocator.h>
#include <resource/ResourceResolver.h>

std::unique_ptr<ug::EncounterButton> ug::DefaultButtons::createFightButton() {
	return std::make_unique<TexturedEncounterButton>(
			ResourceLocator::get()->getTexture("ENCOUNTER_BUTTON_FIGHT_HIGHLIGHT"),
			ResourceLocator::get()->getTexture("ENCOUNTER_BUTTON_FIGHT"));
}

std::unique_ptr<ug::EncounterButton> ug::DefaultButtons::createActButton() {
	return std::make_unique<TexturedEncounterButton>(
			ResourceLocator::get()->getTexture("ENCOUNTER_BUTTON_ACT_HIGHLIGHT"),
			ResourceLocator::get()->getTexture("ENCOUNTER_BUTTON_ACT"));
}

std::unique_ptr<ug::EncounterButton> ug::DefaultButtons::createItemButton() {
	return std::make_unique<TexturedEncounterButton>(
			ResourceLocator::get()->getTexture("ENCOUNTER_BUTTON_ITEM_HIGHLIGHT"),
			ResourceLocator::get()->getTexture("ENCOUNTER_BUTTON_ITEM"));
}

std::unique_ptr<ug::EncounterButton> ug::DefaultButtons::createMercyButton() {
	return std::make_unique<TexturedEncounterButton>(
			ResourceLocator::get()->getTexture("ENCOUNTER_BUTTON_MERCY_HIGHLIGHT"),
			ResourceLocator::get()->getTexture("ENCOUNTER_BUTTON_MERCY"));
}
