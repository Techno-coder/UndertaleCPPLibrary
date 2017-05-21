#include <encounter/components/fightBar/SimpleFightBar.h>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <resource/Resources.h>
#include <cmath>

struct ug::SimpleFightBar::Impl {
	static std::unique_ptr<sf::Texture> fightBarTexture;
	sf::Sprite fightBar;
	sf::RectangleShape targetLine;
	int updateCounter = -1;

	Impl() {
		if (!fightBarTexture) {
			fightBarTexture.reset(new sf::Texture());
			fightBarTexture->loadFromFile(Resources::createResourcesPath("default/encounter/fight/fightBar.png"));
		}

		fightBar.setPosition(0, 4);
		fightBar.setTexture(*fightBarTexture);
		targetLine.setPosition(0, 0);
		targetLine.setFillColor(sf::Color::Black);
		targetLine.setOutlineThickness(3);
		targetLine.setOutlineColor(sf::Color::White);
	}
};

std::unique_ptr<sf::Texture> ug::SimpleFightBar::Impl::fightBarTexture;

void ug::SimpleFightBar::update(float attackSpeed) {
	if (impl->updateCounter >= 0) {
		impl->updateCounter = ++impl->updateCounter % 8;
		if (impl->updateCounter == 0) {
			if (impl->targetLine.getFillColor() == sf::Color::White) {
				impl->targetLine.setFillColor(sf::Color::Black);
				impl->targetLine.setOutlineColor(sf::Color::White);
			} else {
				impl->targetLine.setFillColor(sf::Color::White);
				impl->targetLine.setOutlineColor(sf::Color::Black);
			}
		}
	} else impl->targetLine.move(attackSpeed * 5, 0);
}

void ug::SimpleFightBar::draw(sf::RenderTarget& target) {
	target.draw(impl->fightBar);
	target.draw(impl->targetLine);
}

void ug::SimpleFightBar::setTopLeftPosition(float x, float y) {
	const sf::Vector2f& currentPosition = impl->fightBar.getPosition();
	impl->targetLine.move(currentPosition.x - x, currentPosition.y - y);
	impl->fightBar.setPosition(x, y);
}

float ug::SimpleFightBar::onConfirmKeyPress() {
	impl->updateCounter = 0;
	float distFromCenter = std::abs(((impl->fightBar.getPosition().x + (impl->fightBar.getGlobalBounds().width / 2))
	                                 - (impl->targetLine.getPosition().x + impl->targetLine.getSize().x / 2)));
	return distFromCenter;
}

ug::SimpleFightBar::SimpleFightBar() : impl(std::make_unique<Impl>()) {
	setTopLeftPosition(47, 263);
}
