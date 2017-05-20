#pragma once

#include "Locator.h"

namespace ucl {
	class Logger;

	typedef ucl::Locator<ucl::Logger> LoggerLocator;

	template <>
	ucl::Logger& ucl::LoggerLocator::get();
}
