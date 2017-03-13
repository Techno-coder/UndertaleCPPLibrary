#ifndef PROJECT_RESOURCEMANAGER_H
#define PROJECT_RESOURCEMANAGER_H

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ResourceItem.h"

namespace ug {
    class ResourceManager {
        std::map<std::string, std::unique_ptr<sf::Texture>> texturesHolder;
        std::map<std::string, std::unique_ptr<sf::Font>> fontsHolder;
        std::map<std::string, std::unique_ptr<sf::SoundBuffer>> soundBuffersHolder;
        std::map<std::string, std::string> musicFilePathsHolder;
    public:

        /**
         * Load a resource from the ResourceItem
         * @param item The resource information
         */
        void loadResource(const ResourceItem& item);

        /**
         * Get the file path of a music file
         * @param id The id of the music file
         * @return A string containing the file path
         */
        const std::string& getMusicFilepath(std::string id);

        /**
         * Get a SFML texture
         * @param id The id of the texture
         * @return A SFML texture
         */
        const sf::Texture& getTexture(std::string id);

        /**
         * Get a SFML sound buffer
         * @param id The id of the sound buffer
         * @return A SFML sound buffer
         */
        const sf::SoundBuffer& getSound(std::string id);

        /**
         * Get a SFML font
         * @param id The id of the font
         * @return A SFML font
         */
        const sf::Font& getFont(std::string id);
    };
}

#endif //PROJECT_RESOURCEMANAGER_H
