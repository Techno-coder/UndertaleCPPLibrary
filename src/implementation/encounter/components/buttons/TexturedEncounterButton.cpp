#include <encounter/components/buttons/TexturedEncounterButton.h>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

struct ug::TexturedEncounterButton::Impl {
	const sf::Texture& highlighted;
	const sf::Texture& normal;
	sf::Sprite button;

	Impl(const sf::Texture& highlighted, const sf::Texture& normal) : highlighted(highlighted), normal(normal) {}
};

void ug::TexturedEncounterButton::draw(sf::RenderTarget& target) {
	target.draw(impl->button);
}

void ug::TexturedEncounterButton::setTopLeftPosition(float x, float y) {
	impl->button.setPosition(x, y);
}

void ug::TexturedEncounterButton::setHighlighted(bool isHighlighted) {
	impl->button.setTexture(isHighlighted ? impl->highlighted : impl->normal);
}

ug::TexturedEncounterButton::~TexturedEncounterButton() {}

ug::TexturedEncounterButton::TexturedEncounterButton(const sf::Texture& highlighted, const sf::Texture& normal) : impl(
		std::make_unique<Impl>(highlighted, normal)) {}
