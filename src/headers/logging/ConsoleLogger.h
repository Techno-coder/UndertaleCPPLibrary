#pragma once

#include <memory>
#include "Logger.h"

namespace ucl {
	class ConsoleLogger : public Logger {
		struct Impl;
		std::unique_ptr<Impl> impl;
	public:
		ConsoleLogger();
		void log(const LogSeverity& severity, const std::string& message) override;
	};
}
