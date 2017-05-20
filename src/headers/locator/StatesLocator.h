#pragma once

#include "Locator.h"

namespace ucl {
	class StateManager;

	typedef ucl::Locator<ucl::StateManager> StatesLocator;

	template <>
	ucl::StateManager& ucl::StatesLocator::get();

}
