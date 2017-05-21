#pragma once

#include <memory>

namespace sf {
	class Event;

	class RenderTarget;
}

namespace ug {
	class State;

	class StateManager {
		struct Impl;
		std::unique_ptr<Impl> impl;
	public:
		StateManager();
		~StateManager();

		void pushState(std::unique_ptr<State> state);
		void changeState(std::unique_ptr<State> state);
		void popState();

		void handleEvent(sf::Event& event);
		void update();
		void draw(sf::RenderTarget& target);
	};
}

