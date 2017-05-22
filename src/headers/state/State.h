#pragma once

namespace sf {
	class Event;

	class RenderTarget;
}

namespace ug {
	class State {
	public:
		virtual void enter() {};

		virtual void handleEvent(sf::Event& event) {};

		virtual void update() {};

		virtual void draw(sf::RenderTarget& target) {};
	};
}

