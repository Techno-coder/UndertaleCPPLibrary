#include <locator/LoggerLocator.h>
#include <logging/ConsoleLogger.h>

template <>
std::unique_ptr<ucl::Logger> ucl::LoggerLocator::object{new ucl::ConsoleLogger()};

template <>
ucl::Logger& ucl::LoggerLocator::get() {
	if (!object) throw NoServiceProvidedException("LOGGER");
	return *object;
}
