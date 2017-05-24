#pragma once

#include "Locator.h"

namespace ug {
	class StateManager;

	typedef ug::Locator<ug::StateManager> StatesLocator;

	template <>
	std::shared_ptr<ug::StateManager> ug::StatesLocator::get();

}
