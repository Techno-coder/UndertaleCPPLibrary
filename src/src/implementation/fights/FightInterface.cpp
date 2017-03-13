
#include "../../headers/fights/FightInterface.h"

ug::FightInterface ug::FightInterface::instance;

void ug::FightInterface::setCurrentlySelectedButton(ug::FightInterface::CurrentSelectedButton newCurrent) {
    currentSelectedButton = newCurrent;
}

const ug::FightInterface::CurrentSelectedButton &ug::FightInterface::getCurrentlySelectedButton() {
    return currentSelectedButton;
}

void ug::FightInterface::draw() {
    fightButton.setTextureID("FIGHT_BUTTON");
    actButton.setTextureID("ACT_BUTTON");
    itemButton.setTextureID("ITEM_BUTTON");
    mercyButton.setTextureID("MERCY_BUTTON");
    switch (currentSelectedButton) {
        case FIGHT:
            fightButton.setTextureID("FIGHT_BUTTON_HIGHLIGHT");
            break;
        case ACT:
            actButton.setTextureID("ACT_BUTTON_HIGHLIGHT");
            break;
        case ITEM:
            itemButton.setTextureID("ITEM_BUTTON_HIGHLIGHT");
            break;
        case MERCY:
            mercyButton.setTextureID("MERCY_BUTTON_HIGHLIGHT");
            break;
        case NONE:
            break;
    }

    gameInstance->getRenderer()->drawRawSprite(dialogueBox);
    gameInstance->getRenderer()->drawSprite(fightButton);
    gameInstance->getRenderer()->drawSprite(actButton);
    gameInstance->getRenderer()->drawSprite(itemButton);
    gameInstance->getRenderer()->drawSprite(mercyButton);
    gameInstance->getRenderer()->drawRawSprite(playerName);
    gameInstance->getRenderer()->drawRawSprite(playerLevel);
    gameInstance->getRenderer()->drawRawSprite(playerHealthLabel);
    gameInstance->getRenderer()->drawRawSprite(playerHealthFraction);
    gameInstance->getRenderer()->drawRawSprite(maxHealthBar);
    gameInstance->getRenderer()->drawRawSprite(currentHealthBar);
}

void ug::FightInterface::load() {
    if(!loaded) {
        gameInstance = ug::UndertaleGame::getInstance();
        ug::ResourceManager* resourceManager = gameInstance->getResourceManager();

        ug::ResourceItem fightButtonSprite("FIGHT_BUTTON", "resources/default/FightButton.png", ug::ResourceType::TEXTURE);
        ug::ResourceItem actButtonSprite("ACT_BUTTON", "resources/default/ActButton.png", ug::ResourceType::TEXTURE);
        ug::ResourceItem itemButtonSprite("ITEM_BUTTON", "resources/default/ItemButton.png", ug::ResourceType::TEXTURE);
        ug::ResourceItem mercyButtonSprite("MERCY_BUTTON", "resources/default/MercyButton.png", ug::ResourceType::TEXTURE);

        ug::ResourceItem actButtonHighlightSprite("ACT_BUTTON_HIGHLIGHT", "resources/default/ActHighlightButton.png", ug::ResourceType::TEXTURE);
        ug::ResourceItem itemButtonHighlightSprite("ITEM_BUTTON_HIGHLIGHT", "resources/default/ItemHighlightButton.png", ug::ResourceType::TEXTURE);
        ug::ResourceItem fightButtonHighlightSprite("FIGHT_BUTTON_HIGHLIGHT", "resources/default/FightHighlightButton.png", ug::ResourceType::TEXTURE);
        ug::ResourceItem mercyButtonHighlightSprite("MERCY_BUTTON_HIGHLIGHT", "resources/default/MercyHighlightButton.png", ug::ResourceType::TEXTURE);

        ug::ResourceItem marsFont("MARS_FONT", "resources/default/MarsFont.ttf", ug::ResourceType::FONT);
        ug::ResourceItem hachicroFont("HACHICRO_FONT", "resources/default/hachicro.ttf", ug::ResourceType::FONT);

        resourceManager->loadResource(fightButtonSprite);
        resourceManager->loadResource(actButtonSprite);
        resourceManager->loadResource(itemButtonSprite);
        resourceManager->loadResource(mercyButtonSprite);
        resourceManager->loadResource(fightButtonHighlightSprite);
        resourceManager->loadResource(actButtonHighlightSprite);
        resourceManager->loadResource(itemButtonHighlightSprite);
        resourceManager->loadResource(mercyButtonHighlightSprite);
        resourceManager->loadResource(marsFont);
        resourceManager->loadResource(hachicroFont); // TODO only used for enemy damage in fight state move to that state later

        ug::ResourceItem heartSprite("SOUL_SPRITE", "resources/default/Soul.png", ug::ResourceType::TEXTURE);
        ug::ResourceItem selectSound("SELECT_SOUND", "resources/default/menuconfirm.wav", ug::ResourceType::SOUND);
        ug::ResourceItem moveSound("MENU_MOVE_SOUND", "resources/default/menumove.wav", ug::ResourceType::SOUND);

        ug::UndertaleGame::getInstance()->getResourceManager()->loadResource(heartSprite);
        ug::UndertaleGame::getInstance()->getResourceManager()->loadResource(selectSound);
        ug::UndertaleGame::getInstance()->getResourceManager()->loadResource(moveSound);

        initializeSprites();
    }
}

ug::FightInterface &ug::FightInterface::getInstance() {
    return instance;
}

void ug::FightInterface::initializeSprites() {
    fightButton.setTextureID("FIGHT_BUTTON");
    fightButton.setXPosition(30);
    fightButton.setYPosition(430);
    actButton.setTextureID("ACT_BUTTON");
    actButton.setXPosition(185);
    actButton.setYPosition(430);
    itemButton.setTextureID("ITEM_BUTTON");
    itemButton.setXPosition(345);
    itemButton.setYPosition(430);
    mercyButton.setTextureID("MERCY_BUTTON");
    mercyButton.setXPosition(500);
    mercyButton.setYPosition(430);

    dialogueBox.setFillColor(sf::Color::Black);
    dialogueBox.setOutlineColor(sf::Color::White);
    dialogueBox.setOutlineThickness(5);
    dialogueBox.setSize(sf::Vector2f(570, 130));
    dialogueBox.setPosition(35, 255);

    playerName.setFont(gameInstance->getResourceManager()->getFont("MARS_FONT"));
    playerName.setCharacterSize(25);
    playerName.setPosition(30, 393);
    playerName.setFillColor(sf::Color::White);

    playerLevel.setFont(gameInstance->getResourceManager()->getFont("MARS_FONT"));
    playerLevel.setCharacterSize(25);
    playerLevel.setFillColor(sf::Color::White);

    playerHealthLabel.setFont(gameInstance->getResourceManager()->getFont("CRYPT_TOMORROW_FONT"));
    playerHealthLabel.setCharacterSize(15);
    playerHealthLabel.setPosition(245, 400);
    playerHealthLabel.setFillColor(sf::Color::White);
    playerHealthLabel.setString("HP");

    playerHealthFraction.setFont(gameInstance->getResourceManager()->getFont("MARS_FONT"));
    playerHealthFraction.setCharacterSize(25);
    playerHealthFraction.setFillColor(sf::Color::White);

    currentHealthBar.setFillColor(sf::Color::Yellow);
    currentHealthBar.setPosition(270, 400);

    maxHealthBar.setFillColor(sf::Color::Red);
    maxHealthBar.setPosition(270, 400);

    updatePlayerVariables();
}

void ug::FightInterface::updatePlayerVariables() {
    ug::PlayerStats& playerStats = gameInstance->getPlayer()->getPlayerStats();
    playerName.setString(playerStats.getName());
    playerLevel.setString("LV " + std::to_string(playerStats.getLevel()));
    playerLevel.setPosition(playerName.getPosition().x + playerName.getGlobalBounds().width + 25, 393);
    currentHealthBar.setSize(sf::Vector2f(playerStats.getHealth() * 1.5f, 20));
    maxHealthBar.setSize(sf::Vector2f(playerStats.getMaxHealth() * 1.5f, 20));
    playerHealthFraction.setString((playerStats.getHealth() < 10 ? "0" + std::to_string(playerStats.getHealth()) :
                       std::to_string(playerStats.getHealth())) + " / " + (playerStats.getMaxHealth() < 10 ? "0" +
                       std::to_string(playerStats.getMaxHealth()) : std::to_string(playerStats.getMaxHealth())));
    playerHealthFraction.setPosition(maxHealthBar.getPosition().x + maxHealthBar.getSize().x + 10, 393);
}
