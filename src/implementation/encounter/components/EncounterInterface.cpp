#include <encounter/components/EncounterInterface.h>

#include <encounter/components/Controls.h>
#include <encounter/components/Arena.h>
#include <encounter/components/PlayerInfoInterface.h>
#include <SFML/Graphics/RenderTarget.hpp>

struct ug::EncounterInterface::Impl {
	std::unique_ptr<ButtonInterface> buttons{getNewDefaultButtonInterface()};
	Arena arena;
	PlayerInfoInterface infoInterface;

	Impl(const ug::PlayerStatistics& newStatistics) : infoInterface(newStatistics) {}
};

void ug::EncounterInterface::draw(sf::RenderTarget& target) {
	impl->buttons->draw(target);
	impl->arena.draw(target);
	impl->infoInterface.draw(target);
}

ug::EncounterInterface::EncounterInterface(const ug::PlayerStatistics& newStatistics) : impl(
		std::make_unique<Impl>(newStatistics)) {}

ug::EncounterInterface::~EncounterInterface() {}

void ug::EncounterInterface::updateStatistics(const ug::PlayerStatistics& newStatistics) {
	impl->infoInterface.updateInterface(newStatistics);
}

void ug::EncounterInterface::setHighlightedButton(const ug::ButtonInterface::Button& button) {
	impl->buttons->setHighlighted(button);
}
