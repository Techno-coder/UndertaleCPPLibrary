#include <encounter/components/PlayerInfoInterface.h>

#include <player/PlayerStatistics.h>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <resource/ResourceResolver.h>

struct ug::PlayerInfoInterface::Impl {
	sf::Text playerName;
	sf::Text playerLevel;
	sf::Text playerHealthLabel;
	sf::Text playerHealthFraction;
	sf::RectangleShape currentHealthBar;
	sf::RectangleShape maxHealthBar;

	Impl() {
		playerName.setCharacterSize(25);
		playerName.setFillColor(sf::Color::White);

		playerLevel.setCharacterSize(25);
		playerLevel.setFillColor(sf::Color::White);

		playerHealthLabel.setCharacterSize(15);
		playerHealthLabel.setFillColor(sf::Color::White);
		playerHealthLabel.setString("HP");

		playerHealthFraction.setCharacterSize(25);
		playerHealthFraction.setFillColor(sf::Color::White);

		currentHealthBar.setFillColor(sf::Color::Yellow);
		maxHealthBar.setFillColor(sf::Color::Red);

		constexpr float UNKNOWN = 0;
		playerName.setPosition(UNKNOWN, 0);
		playerLevel.setPosition(UNKNOWN, 0);
		playerHealthLabel.setPosition(215, 7);
		playerHealthFraction.setPosition(UNKNOWN, 0);
		currentHealthBar.setPosition(240, 7);
		maxHealthBar.setPosition(240, 7);
	}
};

ug::PlayerInfoInterface::~PlayerInfoInterface() {}

void ug::PlayerInfoInterface::draw(sf::RenderTarget& target) {
	target.draw(impl->playerName);
	target.draw(impl->playerLevel);
	target.draw(impl->playerHealthLabel);
	target.draw(impl->playerHealthFraction);
	target.draw(impl->maxHealthBar);
	target.draw(impl->currentHealthBar);
}

void ug::PlayerInfoInterface::setTopLeftPosition(float x, float y) {
	sf::Vector2f diff{x - impl->playerName.getPosition().x, y - impl->playerName.getPosition().y};
	impl->playerName.move(diff);
	impl->playerLevel.move(diff);
	impl->playerHealthLabel.move(diff);
	impl->playerHealthFraction.move(diff);
	impl->currentHealthBar.move(diff);
	impl->maxHealthBar.move(diff);
}

void ug::PlayerInfoInterface::updateInterface(const ug::PlayerStatistics& newStatistics) {
	impl->currentHealthBar.setSize({newStatistics.getCurrentHealth() * 1.5f, 20});
	impl->maxHealthBar.setSize({newStatistics.getMaxHealth() * 1.5f, 20});

	impl->playerName.setString(newStatistics.getName());

	impl->playerLevel.setString("LV " + std::to_string(newStatistics.getLevel()));
	impl->playerLevel.setPosition(impl->playerName.getPosition().x + impl->playerName.getGlobalBounds().width + 25,
	                              impl->playerLevel.getPosition().y);

	const auto& health = newStatistics.getCurrentHealth();
	const auto& maxHealth = newStatistics.getMaxHealth();
	impl->playerHealthFraction.setString(
			(health < 10 ? "0" + std::to_string(health) : std::to_string(health)) + " / " +
			(maxHealth < 10 ? "0" + std::to_string(maxHealth) : std::to_string(maxHealth)));
	impl->playerHealthFraction.setPosition(impl->maxHealthBar.getPosition().x + impl->maxHealthBar.getSize().x + 10,
	                                       impl->playerHealthFraction.getPosition().y);
}

ug::PlayerInfoInterface::PlayerInfoInterface(const PlayerStatistics& initialStatistics,
                                             std::shared_ptr<ResourceResolver> resources)
		: impl(
		std::make_unique<Impl>()) {
	impl->playerName.setFont(resources->getFont("ENCOUNTER_FONT_MARS"));
	impl->playerLevel.setFont(resources->getFont("ENCOUNTER_FONT_MARS"));
	impl->playerHealthLabel.setFont(resources->getFont("FONT_CRYPT"));
	impl->playerHealthFraction.setFont(resources->getFont("ENCOUNTER_FONT_MARS"));
	updateInterface(initialStatistics);
	setTopLeftPosition(30, 393);
}
