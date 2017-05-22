#pragma once

#include <memory>
#include <functional>

namespace sf {
	class Event;
}

namespace ug {
	class Controls {
		struct Impl;
		std::unique_ptr<Impl> impl;
	public:
		Controls();
		virtual ~Controls();
		void handleEvent(sf::Event& event);

		enum class KeyType {
			CONFIRM, CANCEL, UP, DOWN, LEFT, RIGHT
		};
		void setOnPressedListener(KeyType type, std::function<void()> callback);
	};
}

