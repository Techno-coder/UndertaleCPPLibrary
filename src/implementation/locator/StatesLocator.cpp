#include <locator/StatesLocator.h>
#include <state/StateManager.h>

template <>
std::shared_ptr<ug::StateManager> ug::StatesLocator::object{new StateManager()};

template <>
std::shared_ptr<ug::StateManager> ug::StatesLocator::get() {
	if (!object) throw NoServiceProvidedException("STATE_MANAGER");
	return object;
}
