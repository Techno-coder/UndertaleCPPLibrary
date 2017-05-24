#pragma once

#include <memory>
#include "Logger.h"

namespace ug {
	class ConsoleLogger : public Logger {
		struct Impl;
		std::unique_ptr<Impl> impl;
	public:
		ConsoleLogger();
		~ConsoleLogger();
		void log(const LogSeverity& severity, const std::string& message) override;
	};
}
