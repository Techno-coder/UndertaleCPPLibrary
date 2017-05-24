#pragma once

#include "Locator.h"

namespace ug {
	class Logger;

	typedef ug::Locator<ug::Logger> LoggerLocator;

	template <>
	std::shared_ptr<ug::Logger> ug::LoggerLocator::get();
}
