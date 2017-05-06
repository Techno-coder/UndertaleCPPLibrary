#include "FightAttackState.h"

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
    slice.setPosition(enemy->getSprite().getPosition()); //TODO FIX Up
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
            break;

        default:
            break;
    }
}

void ug::FightAttackState::onEnter() {
    State::controls.setOnKeyPressedListener(std::bind(&FightAttackState::onKeyPress, this, std::placeholders::_1));
}

void ug::FightAttackState::onUpdate() {
    if(!hit) positioner.move(5 * player.getStatistics().attackSpeed, 0);
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
