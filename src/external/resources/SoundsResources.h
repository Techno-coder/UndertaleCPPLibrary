#ifndef TECHNOCODER_SOUNDSRESOURCES_H
#define TECHNOCODER_SOUNDSRESOURCES_H

#include <SFML/Audio/SoundBuffer.hpp>
#include "Resources.h"

class SoundsResources : public Resources<sf::SoundBuffer> {
protected:
    class SoundsResourceItem : public ResourceItem {
    public:
        virtual ~SoundsResourceItem() {}
        SoundsResourceItem(const std::string &filepath, Resources<sf::SoundBuffer> *const resources) : ResourceItem(resources) {
            sf::SoundBuffer soundBuffer;
            soundBuffer.loadFromFile(filepath);
            resources->resourceHolder[getID()] = soundBuffer;
        }
    };
public:
    virtual ~SoundsResources() {}
};

#endif
