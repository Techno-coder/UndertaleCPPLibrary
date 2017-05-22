#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <locator/StatesLocator.h>
#include <state/StateManager.h>

#include <SFML/Window/Event.hpp>
#include <encounter/states/ActionSelectState.h>
#include <locator/LoggerLocator.h>
#include <logging/Logger.h>
#include <encounter/components/soul/RedSoul.h>
#include <locator/PlayerLocator.h>
#include <player/Player.h>
#include <player/PlayerStatistics.h>

int main() {
	ug::PlayerLocator::get().statistics().setName("Chara");
	ug::PlayerLocator::get().statistics().setLevel(20);
	ug::PlayerLocator::get().statistics().setCurrentHealth(10);
	ug::PlayerLocator::get().statistics().setMaxHealth(50);

	ug::StatesLocator::get().pushState(std::make_unique<ug::ActionSelectState>([](ug::ButtonInterface::Button button) {
		ug::LoggerLocator::get().log(ug::LogSeverity::DEBUG, "Yo this was called from a callback!");
	}, std::make_unique<ug::RedSoul>()));

	sf::RenderWindow window;
	window.create(sf::VideoMode(640, 480), "Undertale Game");
	window.setVerticalSyncEnabled(true);

	sf::Clock clock;
	sf::Time accumulator = sf::Time::Zero;
	sf::Time ups = sf::seconds(1.f / 60.f);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				return 0;
			}
			ug::StatesLocator::get().handleEvent(event);
		}
		while (accumulator > ups) {
			accumulator -= ups;
			ug::StatesLocator::get().update();
		}

		window.clear(sf::Color::Black);
		ug::StatesLocator::get().draw(window);
		window.display();

		accumulator += clock.restart();
	}
}
