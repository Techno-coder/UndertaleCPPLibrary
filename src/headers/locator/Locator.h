#pragma once

#include <memory>
#include <string>

namespace ucl {
	class NoServiceProvidedException : public std::exception {
		const std::string serviceName;
	public:
		NoServiceProvidedException(const std::string& serviceName);
		const char* what() const throw();
	};

	template <typename T>
	class Locator {
		static std::unique_ptr<T> object;
	public:
		/**
		 * Gets a previously provided object
		 * @return The current stored object for this template type
		 * @throws ucl::NoServiceProvidedException Thrown if no object was provided
		 */
		static T& get() {
			if (!object) throw NoServiceProvidedException("UNKNOWN");
			return *object;
		}

		/**
		 * Provides an object for this template type
		 * @param newObject The object to be stored
		 */
		static void provide(std::unique_ptr<T> newObject) {
			object = std::move(newObject);
		}
	};

	template <typename T>
	std::unique_ptr<T> ucl::Locator<T>::object;
}
