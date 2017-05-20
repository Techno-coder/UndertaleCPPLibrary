#pragma once

#include <memory>

namespace ucl {
	class StateManager {
		struct Impl;
		std::unique_ptr<Impl> impl;
	public:
		StateManager();

		void pushState(std::unique_ptr<State> state);
		void changeState(std::unique_ptr<State> state);
		void popState();

		void handleEvent(sf::Event& event);
		void update();
		void draw(sf::RenderWindow& window);
	};
}

