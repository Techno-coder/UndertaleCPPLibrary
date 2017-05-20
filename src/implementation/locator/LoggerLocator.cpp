#include <locator/LoggerLocator.h>

template <>
ucl::Logger& ucl::LoggerLocator::get() {
	if (!object) throw NoServiceProvidedException("LOGGER");
	return *object;
}
