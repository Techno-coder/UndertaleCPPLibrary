#pragma once

namespace sf {
	class Event;

	class RenderTarget;
}

namespace ucl {
	class State {
	public:
		virtual void handleEvent(sf::Event& event) {};

		virtual void update() {};

		virtual void draw(sf::RenderTarget& target) {};
	};
}

