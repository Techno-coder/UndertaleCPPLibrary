#include <logging/ConsoleLogger.h>

#include <sstream>
#include <iostream>
#include <SFML/System/Clock.hpp>

struct ucl::ConsoleLogger::Impl {
	sf::Clock clock;

	Impl() {
		clock.restart();
	}
};

void ucl::ConsoleLogger::log(const ucl::LogSeverity& severity, const std::string& message) {
	std::stringstream output;
	output << "[" << std::to_string((int) impl->clock.getElapsedTime().asSeconds() / 60) << "m:"
	       << std::to_string((int) impl->clock.getElapsedTime().asSeconds() % 60) << "s]";
	switch (severity) {
		case LogSeverity::DEBUG:
			output << "[DEBUG]";
			break;
		case LogSeverity::INFO:
			output << "[INFO]";
			break;
		case LogSeverity::WARNING:
			output << "[WARN]";
			break;
		case LogSeverity::FATAL:
			output << "[FATAL]";
			break;
	}
	output << " " << message;
	std::cout << output.str() << std::endl;
}

ucl::ConsoleLogger::ConsoleLogger() : impl{std::make_unique<Impl>()} {}
