
#include <SFML/Audio/Music.hpp>
#include "../../headers/audio/AudioManager.h"
#include "../../headers/core/Logger.h"

void ug::AudioManager::playMusic(const std::string& id) {
    currentMusic->stop();
    if(!currentMusic->openFromFile(resourceManager->getMusicFilepath(id))) {
        ug::Logger::instance().warning("AUDIO", "Failed to load music file " + resourceManager->getMusicFilepath(id));
    }
    currentMusic->play();
}

ug::AudioManager::AudioManager(ug::ResourceManager* const resourceManager) : resourceManager(resourceManager){
    currentMusic = new sf::Music;
}

void ug::AudioManager::playSound(const std::string& id) {
    sf::Sound *sound = new sf::Sound;
    sound->setBuffer(resourceManager->getSound(id));
    sound->play();
    currentSounds.push_back(sound);
    cleanSounds();
}

ug::AudioManager::~AudioManager() {
    currentMusic->stop();
    delete currentMusic;
}

void ug::AudioManager::cleanSounds() {
    std::vector<sf::Sound*>::iterator it = currentSounds.begin();
    while (it != currentSounds.end()) {
        if((*it)->getStatus() == sf::SoundSource::Stopped) {
            delete (*it);
            it = currentSounds.erase(it);
        } else {
            ++it;
        }
    }
}

