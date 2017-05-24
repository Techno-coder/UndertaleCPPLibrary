#include <encounter/states/ActionSelectState.h>

#include <encounter/components/Controls.h>
#include <encounter/components/soul/Soul.h>
#include <encounter/components/EncounterInterface.h>
#include <locator/PlayerLocator.h>
#include <player/Player.h>
#include <player/PlayerStatistics.h>
#include <locator/AudioLocator.h>
#include <audio/Audio.h>

struct ug::ActionSelectState::Impl {
	std::shared_ptr<ResourceResolver> resources;

	EncounterInterface encounterInterface;
	Controls controls;
	std::unique_ptr<Soul> soul;

	std::function<void(ButtonInterface::Button)> callbackOnSelect;
	int currentlySelected = 0;

	ButtonInterface::Button buttonResolver() {
		switch (currentlySelected) {
			case 0:
				return ButtonInterface::FIGHT;
			case 1:
				return ButtonInterface::ACT;
			case 2:
				return ButtonInterface::ITEM;
			case 3:
				return ButtonInterface::MERCY;
			default:
				break;
		}
		return ButtonInterface::Button::NONE;
	}

	void updateSoul() {
		switch (buttonResolver()) {
			case ButtonInterface::FIGHT:
				soul->setPosition(47, 452);
				break;
			case ButtonInterface::ACT:
				soul->setPosition(204, 452);
				break;
			case ButtonInterface::ITEM:
				soul->setPosition(359, 452);
				break;
			case ButtonInterface::MERCY:
				soul->setPosition(516, 452);
				break;
			case ButtonInterface::Button::NONE:
				break;
		}
	}

	void updateButtonsInterface() {
		AudioLocator::get()->playSound(resources->getSound("OPTION_MOVE"));
		encounterInterface.setHighlightedButton(buttonResolver());
		updateSoul();
	}

	Impl(std::shared_ptr<ResourceResolver> resourceResolver) : encounterInterface(
			ug::PlayerLocator::get()->statistics(),
			resourceResolver),
	                                                           resources(resourceResolver) {
		controls.setOnPressedListener(Controls::KeyType::LEFT, [this]() {
			if (--currentlySelected < 0) currentlySelected = 3;
			updateButtonsInterface();
		});
		controls.setOnPressedListener(Controls::KeyType::RIGHT, [this]() {
			++currentlySelected %= 4;
			updateButtonsInterface();
		});
		controls.setOnPressedListener(Controls::KeyType::CONFIRM, [this]() {
			AudioLocator::get()->playSound(resources->getSound("OPTION_CONFIRM"));
			callbackOnSelect(buttonResolver());
		});
		encounterInterface.setHighlightedButton(ButtonInterface::FIGHT);
	}
};

void ug::ActionSelectState::handleEvent(sf::Event& event) {
	impl->controls.handleEvent(event);
}

void ug::ActionSelectState::update() {
}

void ug::ActionSelectState::draw(sf::RenderTarget& target) {
	impl->encounterInterface.draw(target);
	impl->soul->draw(target);
}

ug::ActionSelectState::ActionSelectState(std::function<void(ButtonInterface::Button)> callbackOnSelect,
                                         std::unique_ptr<Soul> soul, std::shared_ptr<ResourceResolver> resources)
		: impl(std::make_unique<Impl>(resources)) {
	impl->callbackOnSelect = callbackOnSelect;
	impl->soul = std::move(soul);
	impl->updateSoul();
}

ug::ActionSelectState::~ActionSelectState() {}

void ug::ActionSelectState::enter() {
	impl->encounterInterface.updateStatistics(ug::PlayerLocator::get()->statistics());
}
