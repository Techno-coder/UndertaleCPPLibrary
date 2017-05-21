#include <encounter/components/buttons/EncounterBaseButton.h>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>

struct ug::EncounterBaseButton::Impl {
	sf::Sprite sprite;
};

void ug::EncounterBaseButton::draw(sf::RenderTarget& target) {
	target.draw(impl->sprite);
}

void ug::EncounterBaseButton::setTopLeftPosition(float x, float y) {
	impl->sprite.setPosition(x, y);
}

ug::EncounterBaseButton::~EncounterBaseButton() {}

ug::EncounterBaseButton::EncounterBaseButton() : impl(std::make_unique<Impl>()) {}

void ug::EncounterBaseButton::setHighlighted(bool isHighlighted) {
	impl->sprite.setTexture(getTexture(isHighlighted));
}
