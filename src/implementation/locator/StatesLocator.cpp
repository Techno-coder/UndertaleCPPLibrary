#include <locator/StatesLocator.h>
#include <state/SimpleStateManager.h>

template <>
std::unique_ptr<ucl::StateManager> ucl::StatesLocator::object{new SimpleStateManager()};

template <>
ucl::StateManager& ucl::StatesLocator::get() {
	if (!object) throw NoServiceProvidedException("STATE_MANAGER");
	return *object;
}
