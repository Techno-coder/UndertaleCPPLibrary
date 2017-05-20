#include <resource/Resources.h>

std::string ucl::Resources::getResourcesRoot() {
	return "resources/";
}

std::string ucl::Resources::createResourcesPath(const std::string& internalPath) {
	return getResourcesRoot() + internalPath;
}
