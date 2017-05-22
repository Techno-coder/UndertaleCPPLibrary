#include <encounter/components/PlayerInfoInterface.h>

#include <player/PlayerStatistics.h>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <resource/Resources.h>

struct ug::PlayerInfoInterface::Impl {
	static std::unique_ptr<sf::Font> crypt;
	static std::unique_ptr<sf::Font> mars;

	sf::Text playerName;
	sf::Text playerLevel;
	sf::Text playerHealthLabel;
	sf::Text playerHealthFraction;
	sf::RectangleShape currentHealthBar;
	sf::RectangleShape maxHealthBar;

	Impl() {
		if (!crypt) {
			crypt.reset(new sf::Font);
			crypt->loadFromFile(Resources::createResourcesPath("default/statistics/fontCrypt.ttf"));
		}
		if (!mars) {
			mars.reset(new sf::Font);
			mars->loadFromFile(Resources::createResourcesPath("default/encounter/fontMars.ttf"));
		}

		playerName.setFont(*mars);
		playerName.setCharacterSize(25);
		playerName.setFillColor(sf::Color::White);

		playerLevel.setFont(*mars);
		playerLevel.setCharacterSize(25);
		playerLevel.setFillColor(sf::Color::White);

		playerHealthLabel.setFont(*crypt);
		playerHealthLabel.setCharacterSize(15);
		playerHealthLabel.setFillColor(sf::Color::White);
		playerHealthLabel.setString("HP");

		playerHealthFraction.setFont(*mars);
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

std::unique_ptr<sf::Font> ug::PlayerInfoInterface::Impl::crypt;
std::unique_ptr<sf::Font> ug::PlayerInfoInterface::Impl::mars;

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

ug::PlayerInfoInterface::PlayerInfoInterface(const ug::PlayerStatistics& initialStatistics) : impl(
		std::make_unique<Impl>()) {
	updateInterface(initialStatistics);
	setTopLeftPosition(30, 393);
}
