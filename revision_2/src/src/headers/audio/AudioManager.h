#ifndef PROJECT_AUDIOMANAGER_H
#define PROJECT_AUDIOMANAGER_H

#include <string>
#include "../resource/ResourceManager.h"

namespace ug {
    class AudioManager {
        ResourceManager* const resourceManager;

        /**
         * @todo Consider having a vector of music to allow multiple music playing
         * @todo destruct the music to avoid crashed message?
         * @note Pointer used to forcible destruct
         */
        sf::Music* currentMusic;

        std::vector<sf::Sound*> currentSounds;
    public:

        /**
         * Destructor
         */
        ~AudioManager();

        /**
         * Constructor
         * @param resourceManager The resource manager containing ids for the sound files
         */
        AudioManager(ResourceManager* const resourceManager);

        /**
         * Play a music file
         * @param id The id of the music file
         */
        void playMusic(const std::string& id);

        /**
         * Play a sound
         * @param id The id of the sound
         */
        void playSound(const std::string& id);

        /**
         * Remove sounds that have finish playing
         */
        void cleanSounds();
    };
}

#endif //PROJECT_AUDIOMANAGER_H
