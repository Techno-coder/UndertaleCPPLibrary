#include <state/StateManager.h>

#include <state/State.h>
#include <stack>

struct ug::StateManager::Impl {
	std::stack<std::unique_ptr<State>> states;
};

ug::StateManager::StateManager() : impl(std::make_unique<Impl>()) {}

void ug::StateManager::pushState(std::unique_ptr<ug::State> state) {
	impl->states.push(std::move(state));
}

void ug::StateManager::changeState(std::unique_ptr<ug::State> state) {
	impl->states.push(std::move(state));
}

void ug::StateManager::popState() {
	impl->states.pop();
}

void ug::StateManager::handleEvent(sf::Event& event) {
	impl->states.top()->handleEvent(event);
}

void ug::StateManager::update() {
	impl->states.top()->update();
}

void ug::StateManager::draw(sf::RenderTarget& target) {
	impl->states.top()->draw(target);
}

ug::StateManager::~StateManager() {}
