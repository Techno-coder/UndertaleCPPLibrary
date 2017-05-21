#include <locator/LoggerLocator.h>
#include <logging/ConsoleLogger.h>

template <>
std::unique_ptr<ug::Logger> ug::LoggerLocator::object{new ug::ConsoleLogger()};

template <>
ug::Logger& ug::LoggerLocator::get() {
	if (!object) throw NoServiceProvidedException("LOGGER");
	return *object;
}
