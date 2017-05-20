#include <state/SimpleStateManager.h>

#include <state/State.h>
#include <stack>

struct ucl::SimpleStateManager::Impl {
	std::stack<std::unique_ptr<State>> states;
};

ucl::SimpleStateManager::SimpleStateManager() : impl(std::make_unique<Impl>()) {}

void ucl::SimpleStateManager::pushState(std::unique_ptr<ucl::State> state) {
	impl->states.push(std::move(state));
}

void ucl::SimpleStateManager::changeState(std::unique_ptr<ucl::State> state) {
	impl->states.push(std::move(state));
}

void ucl::SimpleStateManager::popState() {
	impl->states.pop();
}

void ucl::SimpleStateManager::handleEvent(sf::Event& event) {
	impl->states.top()->handleEvent(event);
}

void ucl::SimpleStateManager::update() {
	impl->states.top()->update();
}

void ucl::SimpleStateManager::draw(sf::RenderTarget& target) {
	impl->states.top()->draw(target);
}
