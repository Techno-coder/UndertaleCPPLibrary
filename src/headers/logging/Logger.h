#pragma once

#include <string>

namespace ucl {
	enum class LogSeverity {
		/**
		 * Used to provide more information about the running of the program
		 */
				DEBUG,

		/**
		 * General information about the running of the program
		 */
				INFO,

		/**
		 * A problem that indicates a potential mistake in the code
		 */
				WARNING,

		/**
		 * A problem that is likely to cause the program to crash
		 */
				FATAL
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

