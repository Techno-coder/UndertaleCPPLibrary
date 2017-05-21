#include <encounter/components/FightBar.h>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <resource/Resources.h>
#include <cmath>
#include <locator/LoggerLocator.h>
#include <logging/Logger.h>

struct ug::FightBar::Impl {
	static std::unique_ptr<sf::Texture> texture;
	sf::Sprite barSprite;

	typedef bool isMoving;
	std::vector<std::pair<sf::RectangleShape, isMoving>> targetLines;
	int nextNotMovingLine;

	Impl(unsigned int numTargetLines) {
		if (!texture) {
			texture.reset(new sf::Texture());
			texture->loadFromFile(Resources::createResourcesPath("default/encounter/fight/fightBar.png"));
		}
		barSprite.setTexture(*texture);
		barSprite.setPosition(0, 4);

		targetLines.resize(numTargetLines, {sf::RectangleShape(sf::Vector2f(7, 122)), false});
		for (int i = 0; i < numTargetLines; ++i) {
			targetLines[i].first.setFillColor(sf::Color::Black);
			targetLines[i].first.setOutlineThickness(3);
			targetLines[i].first.setOutlineColor(sf::Color::White);
		}

		nextNotMovingLine = numTargetLines - 1;
	}
};

std::unique_ptr<sf::Texture> ug::FightBar::Impl::texture;

void ug::FightBar::draw(sf::RenderTarget& target) {
	target.draw(impl->barSprite);
	for (auto& pair : impl->targetLines) {
		target.draw(pair.first);
	}
}

void ug::FightBar::setTopLeftPosition(float x, float y) {
	const sf::Vector2f& currentPosition = impl->barSprite.getPosition();
	for (auto& pair : impl->targetLines) {
		pair.first.move(sf::Vector2f(currentPosition.x - x, currentPosition.y - y));
	}
	impl->barSprite.setPosition(x, y);
}

ug::FightBar::FightBar(unsigned int numTargetLines, bool linesStartOnLeft) : impl(
		std::make_unique<Impl>(numTargetLines)) {
	for (auto& pair : impl->targetLines) {
		pair.first.setPosition(
				linesStartOnLeft ? 0 : impl->barSprite.getPosition().x + impl->barSprite.getGlobalBounds().width, 0);
	}
}

float ug::FightBar::hit(bool removeLastTargetLine) {
	if (!impl->targetLines.empty()) {
		const auto& targetLine = impl->targetLines.back().first;
		const auto& barSprite = impl->barSprite;
		float returnValue = std::abs(((barSprite.getPosition().x + (barSprite.getGlobalBounds().width / 2))
		                              - (targetLine.getPosition().x + (targetLine.getSize().x / 2))));
		if (removeLastTargetLine) {
			impl->targetLines.pop_back();
			if (impl->targetLines.size() <= impl->nextNotMovingLine) {
				impl->nextNotMovingLine = (int) (impl->targetLines.size() - 1);
			}
		}
		return returnValue;
	}
	return std::numeric_limits<float>::quiet_NaN();
}

void ug::FightBar::update(float attackSpeed) {
	for (auto& pair : impl->targetLines) {
		if (pair.second) {
			pair.first.move(5 * attackSpeed, 0);
			if (pair.first.getPosition().x >
			    impl->barSprite.getPosition().x + impl->barSprite.getGlobalBounds().width) {
				impl->targetLines.pop_back();
			}
		}
	}
}

void ug::FightBar::startNextTargetLine() {
	if (impl->nextNotMovingLine >= 0) {
		impl->targetLines[impl->nextNotMovingLine--].second = true;
		return;
	}
	LoggerLocator::get().log(LogSeverity::WARNING,
	                         "FightBar startNextTargetLine called but no more non moving target lines left");
}

ug::FightBar::~FightBar() {}
