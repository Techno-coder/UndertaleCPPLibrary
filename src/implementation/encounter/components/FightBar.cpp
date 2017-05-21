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
	unsigned long nextNotMovingLine;

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
			targetLines[i].first.setPosition(0, 0);
		}

		nextNotMovingLine = numTargetLines - 1;
	}
};

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

ug::FightBar::FightBar(unsigned int numTargetLines, float distBetweenLines) : impl(
		std::make_unique<Impl>(numTargetLines)) {}

float ug::FightBar::hit(bool removeLastTargetLine) {
	if (!impl->targetLines.empty()) {
		const auto& targetLine = impl->targetLines.back().first;
		const auto& barSprite = impl->barSprite;
		float returnValue = std::abs(((barSprite.getPosition().x + (barSprite.getGlobalBounds().width / 2))
		                              - (targetLine.getPosition().x + (targetLine.getSize().x / 2))));
		if (removeLastTargetLine) {
			impl->targetLines.pop_back();
			if (impl->targetLines.size() <= impl->nextNotMovingLine) {
				impl->nextNotMovingLine = impl->targetLines.size() - 1;
			}
		}
		return returnValue;
	}
	LoggerLocator::get().log(LogSeverity::WARNING, "FightBar hit function called but no more target lines left");
	return 0.0f;
}

void ug::FightBar::update(float attackSpeed) {
	for (auto& pair : impl->targetLines) {
		if (pair.second) {
			pair.first.move(5 * attackSpeed, 0);
		}
	}
}

void ug::FightBar::startNextTargetLine() {
	if (startNextTargetLine && impl->nextNotMovingLine >= 0) {
		impl->targetLines[impl->nextNotMovingLine--].second = true;
		return;
	}
	LoggerLocator::get().log(LogSeverity::WARNING,
	                         "FightBar startNextTargetLine called but no more non moving target lines left");
}
