#pragma once

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace ucl {
	class State {
	public:
		virtual void handleEvent(sf::Event& event) {};
		virtual void update() {};
		virtual void draw(sf::RenderWindow& window) {};
	};
}

