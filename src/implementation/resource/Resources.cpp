#include <resource/Resources.h>

std::string ug::Resources::getResourcesRoot() {
	return "resources/";
}

std::string ug::Resources::createResourcesPath(const std::string& internalPath) {
	return getResourcesRoot() + internalPath;
}
