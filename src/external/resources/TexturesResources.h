#ifndef TECHNOCODER_TEXTURESRESOURCES_H
#define TECHNOCODER_TEXTURESRESOURCES_H

#include <SFML/Graphics/Texture.hpp>
#include "Resources.h"

class TexturesResources : public Resources<sf::Texture> {
protected:
    class TexturesResourceItem : public ResourceItem {
    public:
        virtual ~TexturesResourceItem() {}
        TexturesResourceItem(const std::string &filepath, TexturesResources* resources) : ResourceItem(resources) {
            sf::Texture texture;
            texture.loadFromFile(filepath);
            resources->resourceHolder[getID()] = texture;
        }
    };
public:
    virtual ~TexturesResources() {}
};

#endif