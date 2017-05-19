#ifndef PROJECT_RESOURCEITEM_H
#define PROJECT_RESOURCEITEM_H

#include <string>

namespace ug {
    enum ResourceType {
        TEXTURE,
        FONT,
        SOUND,
        MUSIC
    };

    class ResourceItem {
        const std::string id;
        const std::string filepath;
        const ResourceType type;
    public:

        /**
         * Constructor
         * @param id The string that will be used for identifying this resource
         * @param filepath The location of the resource relative to this game executable
         * @param type The type of resource
         */
        ResourceItem(const std::string &id, const std::string &filepath, ResourceType type);

        /**
         * Get the ID used for identifying this resource
         * @return A string ID
         */
        const std::string &getID() const;

        /**
         * Get the file path that this resource is located in
         * @return A string file path relative to the location of the game executable
         */
        const std::string &getFilepath() const;

        /**
         * Get the type of this resource
         * @return The resource type
         */
        ResourceType getType() const;
    };
}

#endif //PROJECT_RESOURCEITEM_H
