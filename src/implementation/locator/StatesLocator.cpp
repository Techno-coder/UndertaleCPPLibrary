#include <locator/StatesLocator.h>
#include <state/StateManager.h>

template <>
std::unique_ptr<ug::StateManager> ug::StatesLocator::object{new StateManager()};

template <>
ug::StateManager& ug::StatesLocator::get() {
	if (!object) throw NoServiceProvidedException("STATE_MANAGER");
	return *object;
}
