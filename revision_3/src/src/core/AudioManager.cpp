#include "AudioManager.h"

void ug::AudioManager::playSound(const sf::SoundBuffer &soundBuffer) {
    std::unique_ptr<sf::Sound> sound(new sf::Sound);
    sound->setBuffer(soundBuffer);
    sound->play();
    playingSounds.push_back(std::move(sound));
    cleanSounds();
}

void ug::AudioManager::cleanSounds() {
    auto it = playingSounds.begin();
    while (it != playingSounds.end()) {
        if((*it)->getStatus() == sf::SoundSource::Stopped) it = playingSounds.erase(it);
        else ++it;
    }
}
