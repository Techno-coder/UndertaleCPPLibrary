#include "locator/StatesLocator.h"

template <>
ucl::StateManager& ucl::StatesLocator::get() {
	if (!object) throw NoServiceProvidedException("STATE_MANAGER");
	return *object;
}
