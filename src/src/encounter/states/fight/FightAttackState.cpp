#include <cmath>
#include "FightAttackState.h"

ug::FightAttackState::FightTextures ug::FightAttackState::textures;
ug::FightAttackState::FightSounds ug::FightAttackState::sounds;

ug::FightAttackState::FightAttackState(const std::shared_ptr<ug::Encounter> &encounter,
                                       std::vector<Enemy>::iterator enemy) :
        EncounterState(encounter), enemy(enemy) {
    EncounterState::setActiveButton(ActiveButton::FIGHT);
    fightBar.setPosition(47, 263);
    fightBar.setTexture(textures.FIGHT_BAR);
    positioner.setPosition(47, 259);
    positioner.setFillColor(sf::Color::Black);
    positioner.setOutlineThickness(3);
    positioner.setOutlineColor(sf::Color::White);
    soul.setPosition(-100, -100);
    slice.setOrigin(slice.getGlobalBounds().width / 2, slice.getGlobalBounds().height / 2);
    slice.setPosition(enemy->getSprite().getPosition().x + (enemy->getSprite().getGlobalBounds().width / 2),
                      enemy->getSprite().getPosition().y + (enemy->getSprite().getGlobalBounds().height / 2)); //TODO FIX Up
}

void ug::FightAttackState::onDraw(sf::RenderWindow &window) {
    EncounterState::onDraw(window);
    window.draw(fightBar);
    window.draw(positioner);
    if(hit) {
        if(sliceCounter <= 5) window.draw(slice);
    }
}

void ug::FightAttackState::onKeyPress(ug::Controls::Keys key) {
    switch (key) {
        case Controls::Keys::CONFIRM:
            //TODO
            hit = true;
            audio.playSound(sounds.SLICE);
            calculateDamageDealt();
            enemy->getAttributes().health.setValue(enemy->getAttributes().health.getValue() - damageDealt);
            break;

        default:
            break;
    }
}

void ug::FightAttackState::onEnter() {
    State::controls.setOnKeyPressedListener(std::bind(&FightAttackState::onKeyPress, this, std::placeholders::_1));
}

void ug::FightAttackState::onUpdate() {
    if(!hit) positioner.move(5 * player.getStatistics().weaponAttackSpeed, 0);
    else if(hit){
        if(timerCounter % 8 == 0) {
            if(positioner.getFillColor() == sf::Color::White) {
                positioner.setFillColor(sf::Color::Black);
                positioner.setOutlineColor(sf::Color::White);
            } else {
                positioner.setFillColor(sf::Color::White);
                positioner.setOutlineColor(sf::Color::Black);
            }
        }
        if(timerCounter % 6 == 0) {
            switch (sliceCounter++) {
                case 0: slice.setTexture(textures.SLICE_0); break;
                case 1: slice.setTexture(textures.SLICE_1); break;
                case 2: slice.setTexture(textures.SLICE_2); break;
                case 3: slice.setTexture(textures.SLICE_3); break;
                case 4: slice.setTexture(textures.SLICE_4); break;
                case 5: slice.setTexture(textures.SLICE_5); break;
                case 6: slice.setPosition(-100, -100); break;
                default: break;
            }
        }
    }
    ++timerCounter;
}

ug::FightAttackState::~FightAttackState() {}

void ug::FightAttackState::calculateDamageDealt() {
    int distBetweenLineAndCenter = abs((int) fightBar.getPosition().x - (int) positioner.getPosition().x);
    float b =  distBetweenLineAndCenter <= 12 ? 2.2f :
               (1 - (distBetweenLineAndCenter / (fightBar.getGlobalBounds().width / 2))) * 2;
    damageDealt = (int)((player.getStatistics().attackModifier + 10 - enemy->getAttributes().defense
                         + getRandomFloat(0.0f, 2.0f)) * b);
}

float ug::FightAttackState::getRandomFloat(float min, float max) {
    srand((unsigned int) time(nullptr));
    return min + static_cast <float> (rand()) / (RAND_MAX / (max - min));
}
