#ifndef PROJECT_RENDERER_H
#define PROJECT_RENDERER_H

#include <SFML/Graphics.hpp>
#include "Resource.h"

class ResourceList;

namespace ug {
    class Renderer {
        std::map<std::string, std::unique_ptr<sf::Texture>> textures;
        std::map<std::string, std::unique_ptr<sf::Font>> fonts;
    public:

        friend void initializeResources(ResourceList resources);
    };
}


#endif //PROJECT_RENDERER_H
