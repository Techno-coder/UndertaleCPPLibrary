#include <logging/ConsoleLogger.h>

#include <sstream>
#include <iostream>
#include <SFML/System/Clock.hpp>

struct ug::ConsoleLogger::Impl {
	sf::Clock clock;

	Impl() {
		clock.restart();
	}
};

void ug::ConsoleLogger::log(const ug::LogSeverity& severity, const std::string& message) {
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

ug::ConsoleLogger::ConsoleLogger() : impl{std::make_unique<Impl>()} {}

ug::ConsoleLogger::~ConsoleLogger() {}
