#ifndef PROJECT_AUDIOMANAGER_H
#define PROJECT_AUDIOMANAGER_H

#include <string>
#include <SFML/Audio.hpp>
#include <map>
#include "Resource.h"

class ResourceList;

namespace ug {
    class AudioManager {
        std::map<std::string, std::unique_ptr<sf::SoundBuffer>> soundHolder;
        std::map<std::string, std::string> musicHolder;

        sf::Music* currentMusic = new sf::Music();
    public:
        void playMusic(std::string name);
        void playSound(std::string name);

        void stopMusic();

        friend void initializeResources(ResourceList resources);
    };
}


#endif //PROJECT_AUDIOMANAGER_H
