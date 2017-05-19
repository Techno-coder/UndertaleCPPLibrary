#ifndef TECHNOCODER_FONTSRESOURCES_H
#define TECHNOCODER_FONTSRESOURCES_H

#include <SFML/Graphics/Font.hpp>
#include "Resources.h"

class FontsResources : public Resources<sf::Font> {
protected:
    class FontsResourceItem : public ResourceItem {
    public:
        virtual ~FontsResourceItem() {}
        FontsResourceItem(const std::string& filepath, Resources<sf::Font> *const resources) : ResourceItem(resources) {
            sf::Font font;
            font.loadFromFile(filepath);
            resources->resourceHolder[getID()] = font;
        }
    };
public:
    virtual ~FontsResources() {}
};

#endif
