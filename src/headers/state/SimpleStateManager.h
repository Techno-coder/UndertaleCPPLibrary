#pragma once

#include "StateManager.h"

namespace ug {
	class SimpleStateManager : public StateManager {
		struct Impl;
		std::unique_ptr<Impl> impl;
	public:
		SimpleStateManager();

		void pushState(std::unique_ptr<State> state);
		void changeState(std::unique_ptr<State> state);
		void popState();

		void handleEvent(sf::Event& event);
		void update();
		void draw(sf::RenderTarget& target);
	};
}

