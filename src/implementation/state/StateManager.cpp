#include <state/State.h>
#include <stack>
#include "state/StateManager.h"

struct ucl::StateManager::Impl {
	std::stack<std::unique_ptr<State>> states;
};

ucl::StateManager::StateManager() : impl(std::make_unique<Impl>()) {}

void ucl::StateManager::pushState(std::unique_ptr<ucl::State> state) {
	impl->states.push(std::move(state));
}

void ucl::StateManager::changeState(std::unique_ptr<ucl::State> state) {
	impl->states.push(std::move(state));
}

void ucl::StateManager::popState() {
	impl->states.pop();
}

void ucl::StateManager::handleEvent(sf::Event& event) {
	impl->states.top()->handleEvent(event);
}

void ucl::StateManager::update() {
	impl->states.top()->update();
}

void ucl::StateManager::draw(sf::RenderWindow& window) {
	impl->states.top()->draw(window);
}
