#include "EnemySelectState.h"

ug::EnemySelectState::EnemySelectState(const std::shared_ptr<ug::Encounter> &encounter) : EncounterState(encounter) {}

void ug::EnemySelectState::onDraw(sf::RenderWindow &window) {
    EncounterState::onDraw(window);
    for(auto text : generatedSprites) {
        window.draw(text);
    }
}

void ug::EnemySelectState::generateSprites() {
    generatedSprites.clear();
    int currentIndex = 0;
    for(auto &enemy : enemyCache) {
        sf::Text asterix("*", State::fonts.MONO, 25);
        sf::Text option(enemy.getAttributes().name, State::fonts.MONO, 25);
        asterix.setPosition(100, 270 + (currentIndex * 32));
        option.setPosition(130, 270 + (currentIndex * 32));

        if(enemy.getAttributes().spareable) {
            asterix.setFillColor(sf::Color::Yellow);
            option.setFillColor(sf::Color::Yellow);
        }

        generatedSprites.push_back(asterix);
        generatedSprites.push_back(option);

        ++currentIndex;
    }
}

void ug::EnemySelectState::onKeyPressed(ug::Controls::Keys key) {
    switch (key) {
        case Controls::Keys::UP:
            if(selectedOption > 0) {
                --selectedOption;
                audio.playSound(sounds.MENU_MOVE);
            }
            break;
        case Controls::Keys::DOWN:
            if(selectedOption < enemyCache.size() - 1) {
                ++selectedOption;
                audio.playSound(sounds.MENU_MOVE);
            }
            break;
        case Controls::Keys::CONFIRM:
            audio.playSound(sounds.MENU_CONFIRM);
            goToNextState(encounter->getAllEnemies().begin() + selectedOption);
            break;
        case Controls::Keys::CANCEL:
            states->popState();
            break;
        default:
            break;
    }
    soul.setPosition(73, (286 + (selectedOption * 32)));
    encounter->temporaryState.lastEnemySelected = selectedOption;
}

void ug::EnemySelectState::onEnter() {
    if(enemyCache.empty()) {
        states->popState();
        return;
    }

    selectedOption = encounter->temporaryState.lastEnemySelected;
    controls.setOnKeyPressedListener(std::bind(&EnemySelectState::onKeyPressed, this, std::placeholders::_1));
    generateSprites();
    onKeyPressed(Controls::Keys::INVALID);
}

ug::EnemySelectState::~EnemySelectState() {}
