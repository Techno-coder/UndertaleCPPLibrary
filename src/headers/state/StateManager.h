#pragma once

#include <memory>

namespace sf {
	class Event;

	class RenderTarget;
}

namespace ug {
	class State;

	class StateManager {
	public:
		virtual void pushState(std::unique_ptr<State> state) = 0;
		virtual void changeState(std::unique_ptr<State> state) = 0;
		virtual void popState() = 0;

		virtual void handleEvent(sf::Event& event) = 0;
		virtual void update() = 0;
		virtual void draw(sf::RenderTarget& target) = 0;
	};
}