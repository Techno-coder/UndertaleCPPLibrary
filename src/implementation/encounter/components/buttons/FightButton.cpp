#include <encounter/components/buttons/FightButton.h>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <resource/Resources.h>

struct StaticTextures {
	sf::Texture highlighted;
	sf::Texture normal;

	StaticTextures() {
		highlighted.loadFromFile(ucl::Resources::createResourcesPath("default/encounter/buttonFightHighlight.png"));
		normal.loadFromFile(ucl::Resources::createResourcesPath("default/encounter/buttonFight.png"));
	}
};

struct ucl::FightButton::Impl {
	sf::Sprite sprite;
	static std::unique_ptr<StaticTextures> staticTextures;

	Impl() {
		if (!staticTextures) staticTextures.reset(new StaticTextures());
		sprite.setTexture(staticTextures->normal);
	}
};

std::unique_ptr<StaticTextures> ucl::FightButton::Impl::staticTextures;

ucl::FightButton::FightButton() {}

void ucl::FightButton::draw(sf::RenderTarget& target) {
	target.draw(impl->sprite);
}

void ucl::FightButton::setHighlighted(bool isHighlighted) {
	impl->sprite.setTexture(isHighlighted ? impl->staticTextures->highlighted : impl->staticTextures->normal);
}

void ucl::FightButton::setPosition(float x, float y) {
	impl->sprite.setPosition(x, y);
}
