
#include <string>
#include "../../headers/resource/ResourceItem.h"

ug::ResourceItem::ResourceItem(const std::string &id, const std::string &filepath, ug::ResourceType type) :
        id(id), filepath(filepath), type(type) {

}

const std::string &ug::ResourceItem::getID() const {
    return id;
}

const std::string &ug::ResourceItem::getFilepath() const {
    return filepath;
}

ug::ResourceType ug::ResourceItem::getType() const {
    return type;
}
