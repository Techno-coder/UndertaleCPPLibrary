#pragma once

#include <string>

namespace ucl {
	enum class LogSeverity {
		DEBUG, /**< Used to provide more information about the running of the program */
		INFO, /**< General information about the running of the program */
		WARNING, /**< A problem that indicates a potential mistake in the code */
		FATAL /**< A problem that is likely to cause the program to crash */
	};

	class Logger {
	public:
		/**
		 * Logs a message
		 * @param severity The severity of the message
		 * @param message The message to be logged
		 */
		virtual void log(const LogSeverity& severity, const std::string& message) = 0;

		virtual ~Logger() {}
	};
}

