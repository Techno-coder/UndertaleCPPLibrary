#include "headers/AudioManager.h"

void ug::AudioManager::playMusic(std::string name) {
    currentMusic->stop();
    if(!currentMusic->openFromFile(musicHolder[name])) {
        std::runtime_error("Failed to load music " + musicHolder[name]);
    }
    currentMusic->play();
}

void ug::AudioManager::stopMusic() {
    currentMusic->stop();
}

void ug::AudioManager::playSound(std::string name) {
    sf::Sound sound;
    sound.setBuffer(*soundHolder[name]);
    sound.play();
}
