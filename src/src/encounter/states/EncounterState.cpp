#include "EncounterState.h"

ug::EncounterState::Textures ug::EncounterState::textures;
ug::EncounterState::Sounds ug::EncounterState::sounds;
ug::EncounterState::Fonts ug::EncounterState::fonts;

void ug::EncounterState::setActiveButton(ug::EncounterState::ActiveButton button) {
    activeButton = button;
    privateSprites.fightButton.setTexture(textures.FIGHT);
    privateSprites.actButton.setTexture(textures.ACT);
    privateSprites.itemButton.setTexture(textures.ITEM);
    privateSprites.mercyButton.setTexture(textures.MERCY);
    switch (activeButton) {
        case ActiveButton::FIGHT:
            privateSprites.fightButton.setTexture(textures.FIGHT_HIGHLIGHT); break;
        case ActiveButton::ACT:
            privateSprites.actButton.setTexture(textures.ACT_HIGHLIGHT); break;
        case ActiveButton::ITEM:
            privateSprites.itemButton.setTexture(textures.ITEM_HIGHLIGHT); break;
        case ActiveButton::MERCY:
            privateSprites.mercyButton.setTexture(textures.MERCY_HIGHLIGHT); break;
        case ActiveButton::NONE:
            break;
    }
}

void ug::EncounterState::onDraw(sf::RenderWindow &window) {
    window.draw(privateSprites.fightButton);
    window.draw(privateSprites.actButton);
    window.draw(privateSprites.itemButton);
    window.draw(privateSprites.mercyButton);
    window.draw(privateSprites.playerName);
    window.draw(privateSprites.playerLevel);
    window.draw(privateSprites.playerHealthLabel);
    window.draw(privateSprites.playerHealthFraction);
    window.draw(privateSprites.maxHealthBar);
    window.draw(privateSprites.currentHealthBar);
    for (auto &enemy : enemyCache) { //TODO potentially cache enemies; remember draw before dialogue box
        window.draw(enemy.getSprite());
    }
    window.draw(dialogueBox);
    window.draw(soul);
}

ug::EncounterState::EncounterState(const std::shared_ptr<Encounter> &encounter) :
        encounter(encounter), enemyCache(encounter->getAllEnemies()) {
    initializePrivateSprites();
    initializeObservers();

    soul.setTexture(textures.SOUL);
    soul.setOrigin(soul.getGlobalBounds().width / 2, soul.getGlobalBounds().height / 2);

    dialogueBox.setFillColor(sf::Color::Black);
    dialogueBox.setOutlineColor(sf::Color::White);
    dialogueBox.setOutlineThickness(5);
    dialogueBox.setSize(sf::Vector2f(570, 130));
    dialogueBox.setOrigin(dialogueBox.getSize().x / 2, dialogueBox.getSize().y);
    dialogueBox.setPosition(320, 385);
}

void ug::EncounterState::initializePrivateSprites() {
    privateSprites.fightButton.setPosition(30, 430);
    privateSprites.actButton.setPosition(185, 430);
    privateSprites.itemButton.setPosition(345, 430);
    privateSprites.mercyButton.setPosition(500, 430);

    privateSprites.playerName.setFont(fonts.MARS);
    privateSprites.playerName.setCharacterSize(25);
    privateSprites.playerName.setPosition(30, 393);
    privateSprites.playerName.setFillColor(sf::Color::White);

    privateSprites.playerLevel.setFont(fonts.MARS);
    privateSprites.playerLevel.setCharacterSize(25);
    privateSprites.playerLevel.setFillColor(sf::Color::White);

    privateSprites.playerHealthLabel.setFont(fonts.CRYPT);
    privateSprites.playerHealthLabel.setCharacterSize(15);
    privateSprites.playerHealthLabel.setPosition(245, 400);
    privateSprites.playerHealthLabel.setFillColor(sf::Color::White);
    privateSprites.playerHealthLabel.setString("HP");

    privateSprites.playerHealthFraction.setFont(fonts.MARS);
    privateSprites.playerHealthFraction.setCharacterSize(25);
    privateSprites.playerHealthFraction.setFillColor(sf::Color::White);

    privateSprites.currentHealthBar.setFillColor(sf::Color::Yellow);
    privateSprites.currentHealthBar.setPosition(270, 400);

    privateSprites.maxHealthBar.setFillColor(sf::Color::Red);
    privateSprites.maxHealthBar.setPosition(270, 400);
}

void ug::EncounterState::initializeObservers() {
    player.getStatistics().health.registerObserver(&playerStatisticsObservers.health(player.getStatistics().health));
    player.getStatistics().maxHealth.registerObserver(&playerStatisticsObservers.maxHealth(player.getStatistics().maxHealth));
    player.getStatistics().playerName.registerObserver(&playerStatisticsObservers.playerName(player.getStatistics().playerName));
    player.getStatistics().level.registerObserver(&playerStatisticsObservers.level(player.getStatistics().level));
}

ug::EncounterState::~EncounterState() {
    player.getStatistics().health.unregisterObserver(&playerStatisticsObservers.health(player.getStatistics().health));
    player.getStatistics().maxHealth.unregisterObserver(&playerStatisticsObservers.maxHealth(player.getStatistics().maxHealth));
    player.getStatistics().playerName.unregisterObserver(&playerStatisticsObservers.playerName(player.getStatistics().playerName));
    player.getStatistics().level.unregisterObserver(&playerStatisticsObservers.level(player.getStatistics().level));
}
