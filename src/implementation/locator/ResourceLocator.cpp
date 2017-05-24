#include <locator/ResourceLocator.h>
#include <resource/BasicResourceResolver.h>
#include <resource/DefaultResourceResolver.h>

template <>
std::shared_ptr<ug::ResourceResolver> ug::ResourceLocator::object{new ug::DefaultResourceResolver()};

template <>
std::shared_ptr<ug::ResourceResolver> ug::ResourceLocator::get() {
	if (!object) throw NoServiceProvidedException("RESOURCE");
	return object;
}
