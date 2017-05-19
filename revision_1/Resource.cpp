#include "headers/Resource.h"

void ug::ResourceList::addResource(std::string name, std::string filepath, ResourceType type) {
    resources.push_back({name, filepath, type});
}
