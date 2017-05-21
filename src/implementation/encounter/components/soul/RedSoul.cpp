#include <encounter/components/soul/RedSoul.h>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <resource/Resources.h>

struct ug::RedSoul::Impl {
	static std::unique_ptr<sf::Texture> texture;
	sf::Sprite sprite;

	Impl() {
		if (!texture) {
			texture.reset(new sf::Texture);
			texture->loadFromFile(Resources::createResourcesPath("default/encounter/heartDefend.png"));
		}
		sprite.setTexture(*texture);
	}
};

std::unique_ptr<sf::Texture> ug::RedSoul::Impl::texture;

void ug::RedSoul::draw(sf::RenderTarget& target) {
	target.draw(impl->sprite);
}

ug::RedSoul::RedSoul() : impl(std::make_unique<Impl>()) {}