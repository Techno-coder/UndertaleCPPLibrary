#include <cmath>
#include "FightAttackState.h"

ug::FightAttackState::FightTextures ug::FightAttackState::textures;
ug::FightAttackState::FightSounds ug::FightAttackState::sounds;
ug::FightAttackState::FightFonts ug::FightAttackState::fonts;

ug::FightAttackState::FightAttackState(const std::shared_ptr<ug::Encounter> &encounter,
                                       std::vector<Enemy>::iterator enemy) :
        EncounterState(encounter), enemy(enemy) {
    EncounterState::setActiveButton(ActiveButton::NONE);
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

    maxHealthRect.setPosition(enemy->getSprite().getPosition().x, enemy->getSprite().getPosition().y - 20);
    maxHealthRect.setSize(sf::Vector2f(enemy->getSprite().getGlobalBounds().width, 16));
    maxHealthRect.setFillColor(sf::Color::Red);
    healthRect.setPosition(enemy->getSprite().getPosition().x, enemy->getSprite().getPosition().y - 20);
    healthRect.setSize(sf::Vector2f((enemy->getAttributes().health / (float) enemy->getAttributes().maxHealth) * maxHealthRect.getSize().x, 16));
    healthRect.setFillColor(sf::Color::Green);
    damageText.setFillColor(sf::Color::Red);
}

void ug::FightAttackState::onDraw(sf::RenderWindow &window) {
    EncounterState::onDraw(window);
    window.draw(fightBar);
    window.draw(positioner);
    if(hit) {
        if(sliceCounter <= 5) window.draw(slice);
        if(sliceCounter > 7) {
            window.draw(maxHealthRect);
            window.draw(healthRect);
            window.draw(damageText);
        }
    }
}

void ug::FightAttackState::onKeyPress(ug::Controls::Keys key) {
    switch (key) {
        case Controls::Keys::CONFIRM:
            //TODO SWITCH TO DIFFERENT STATE
            if(!hit) {
                hit = true;
                audio.playSound(sounds.SLICE);
                calculateDamageDealt();
                int enemyHealth = enemy->getAttributes().health.getValue();
                if(enemyHealth - damageDealt < 0) damageDealt = enemyHealth;
                damageText.setString(std::to_string(damageDealt));
                damageText.setOrigin(damageText.getGlobalBounds().width / 2, damageText.getGlobalBounds().height);
                damageText.setPosition(maxHealthRect.getPosition().x + (maxHealthRect.getSize().x / 2), maxHealthRect.getPosition().y - 6);
                enemy->getAttributes().health.setValue(enemyHealth - damageDealt);
                break;
            }
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
                case 6:
                    slice.setPosition(-100, -100);
                    audio.playSound(sounds.HIT);
                    break;
                default: break;
            }
        }
    }
    ++timerCounter;

    if(sliceCounter > 5 && enemy->getAttributes().maxHealth > 0) {
        int enemyHealth = enemy->getAttributes().health.getValue();
        int maxEnemyHealth = enemy->getAttributes().maxHealth.getValue();
        int desiredHealthBarWidth = (int) ((enemyHealth / (float) maxEnemyHealth) * maxHealthRect.getSize().x);
        if(healthRect.getSize().x > desiredHealthBarWidth) {
            healthRect.setSize(sf::Vector2f(healthRect.getSize().x - ((maxHealthRect.getSize().x - desiredHealthBarWidth) / 45.0f), 16));
        }
    }

    if (sliceCounter >= 6 && sliceCounter <= 9) {
        damageText.move(0, -1.25f);
    } else if (sliceCounter >= 10 && sliceCounter <= 11) {
        damageText.move(0, 2.5f);
    } else if (sliceCounter >= 12 && sliceCounter <= 13) {
        damageText.move(0, -0.5f);
    } else if (sliceCounter >= 14 && sliceCounter <= 15) {
        damageText.move(0, 0.5f);
    }
}

ug::FightAttackState::~FightAttackState() {}

void ug::FightAttackState::calculateDamageDealt() {
    int distFromCenter = abs((int) ((fightBar.getPosition().x + (fightBar.getGlobalBounds().width / 2))
                                    - (positioner.getPosition().x + (positioner.getSize().x / 2))));
    float b = distFromCenter <= 12 ? 2.2f : (1.0f - (distFromCenter / fightBar.getGlobalBounds().width)) * 2.0f;
    damageDealt = (int) (((float) player.getStatistics().attackModifier.getValue()
                          - (float) enemy->getAttributes().defense
                          + getRandomFloat(2.0f))
                         * b);
}

float ug::FightAttackState::getRandomFloat(float max) {
    return static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / max));
}
