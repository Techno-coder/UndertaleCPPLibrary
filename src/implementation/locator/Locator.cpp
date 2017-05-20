#include <locator/Locator.h>


const char* ucl::NoServiceProvidedException::what() const throw() {
	std::string message = "Service: " + serviceName + " was used before it was provided";
	return message.c_str();
}

ucl::NoServiceProvidedException::NoServiceProvidedException(const std::string& serviceName) : serviceName(
		serviceName) {}
