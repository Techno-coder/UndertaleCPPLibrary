#ifndef PROJECT_RESOURCE_H
#define PROJECT_RESOURCE_H

#include <string>
#include <vector>
#include "UndertaleGame.h"

namespace ug {
    enum ResourceType {
        TEXTURE,
        FONT,
        SOUND,
        MUSIC
    };

    struct ResourceItem {
        std::string name;
        std::string filepath;
        ResourceType type;
    };

    class ResourceList {
        std::vector<ResourceItem> resources;
    public:
        void addResource(std::string name, std::string filepath, ResourceType type);

        friend void initializeResources(ResourceList resources);
    };
}

#endif //PROJECT_RESOURCE_H
