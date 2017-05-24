#include <encounter/components/soul/RedSoul.h>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <locator/ResourceLocator.h>
#include <resource/ResourceResolver.h>

struct ug::RedSoul::Impl {
	sf::Sprite sprite;

	Impl() {
		sprite.setTexture(ResourceLocator::get()->getTexture("ENCOUNTER_HEART_RED"));
		sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	}
};

void ug::RedSoul::draw(sf::RenderTarget& target) {
	target.draw(impl->sprite);
}

ug::RedSoul::RedSoul() : impl(std::make_unique<Impl>()) {}

ug::RedSoul::~RedSoul() {}

void ug::RedSoul::setPosition(float x, float y) {
	impl->sprite.setPosition(x, y);
}
