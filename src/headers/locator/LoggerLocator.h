#pragma once

#include <logging/Logger.h>
#include <logging/ConsoleLogger.h>
#include "Locator.h"

namespace ucl {
	typedef ucl::Locator<ucl::Logger> LoggerLocator;

	template <>
	ucl::Logger& ucl::LoggerLocator::get();

	template <>
	std::unique_ptr<ucl::Logger> LoggerLocator::object{new ConsoleLogger()};
}
