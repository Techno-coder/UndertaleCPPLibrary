#include <state/SimpleStateManager.h>

#include <state/State.h>
#include <stack>

struct ug::SimpleStateManager::Impl {
	std::stack<std::unique_ptr<State>> states;
};

ug::SimpleStateManager::SimpleStateManager() : impl(std::make_unique<Impl>()) {}

void ug::SimpleStateManager::pushState(std::unique_ptr<ug::State> state) {
	impl->states.push(std::move(state));
}

void ug::SimpleStateManager::changeState(std::unique_ptr<ug::State> state) {
	impl->states.push(std::move(state));
}

void ug::SimpleStateManager::popState() {
	impl->states.pop();
}

void ug::SimpleStateManager::handleEvent(sf::Event& event) {
	impl->states.top()->handleEvent(event);
}

void ug::SimpleStateManager::update() {
	impl->states.top()->update();
}

void ug::SimpleStateManager::draw(sf::RenderTarget& target) {
	impl->states.top()->draw(target);
}
