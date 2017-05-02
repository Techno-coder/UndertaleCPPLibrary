
#include "../../headers/resource/ResourceManager.h"
#include "../../headers/core/Logger.h"

void ug::ResourceManager::loadResource(const ug::ResourceItem& item) {
    switch (item.getType()) {
        case TEXTURE:
        {
            std::unique_ptr<sf::Texture> texture(new sf::Texture());
            if(!texture->loadFromFile(item.getFilepath())) {
                ug::Logger::instance().warning("RESOURCES", "The texture file was not found " + item.getFilepath());
            }
            texturesHolder[item.getID()] = std::move(texture);
            break;
        }
        case FONT:
        {
            std::unique_ptr<sf::Font> font(new sf::Font);
            if(!font->loadFromFile(item.getFilepath())) {
                ug::Logger::instance().warning("RESOURCES", "The font file was not found " + item.getFilepath());
            }
            fontsHolder[item.getID()] = std::move(font);
            break;
        }
        case SOUND:
        {
            std::unique_ptr<sf::SoundBuffer> sound(new sf::SoundBuffer);
            if(!sound->loadFromFile(item.getFilepath())) {
                ug::Logger::instance().warning("RESOURCES", "The sound file was not found " + item.getFilepath());
            }
            soundBuffersHolder[item.getID()] = std::move(sound);
            break;
        }
        case MUSIC:
            musicFilePathsHolder[item.getID()] = item.getFilepath();
            break;
    }
}

const std::string &ug::ResourceManager::getMusicFilepath(std::string id) {
    return musicFilePathsHolder[id];
}

const sf::Texture &ug::ResourceManager::getTexture(std::string id) {
    return *texturesHolder[id];
}

const sf::SoundBuffer &ug::ResourceManager::getSound(std::string id) {
    return *soundBuffersHolder[id];
}

const sf::Font &ug::ResourceManager::getFont(std::string id) {
    return *fontsHolder[id];
}
