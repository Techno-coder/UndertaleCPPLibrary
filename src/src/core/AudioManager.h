#ifndef PROJECT_AUDIOMANAGER_H
#define PROJECT_AUDIOMANAGER_H

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

namespace ug {
    class AudioManager {
        std::vector<std::unique_ptr<sf::Sound>> playingSounds;

        void cleanSounds();
    public:
        void playSound(const sf::SoundBuffer& soundBuffer);
    };
}

#endif //PROJECT_AUDIOMANAGER_H
