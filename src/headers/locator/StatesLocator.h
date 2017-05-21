#pragma once

#include "Locator.h"

namespace ug {
	class StateManager;

	typedef ug::Locator<ug::StateManager> StatesLocator;

	template <>
	ug::StateManager& ug::StatesLocator::get();

}
