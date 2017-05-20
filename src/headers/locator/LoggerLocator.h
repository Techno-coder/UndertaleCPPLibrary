#pragma once

#include <logging/Logger.h>
#include "Locator.h"

namespace ucl {
	typedef ucl::Locator<ucl::Logger> LoggerLocator;

	template <>
	ucl::Logger& ucl::LoggerLocator::get();
}
