#pragma once

#include <state/StateManager.h>
#include "Locator.h"

namespace ucl {
	typedef ucl::Locator<ucl::StateManager> StatesLocator;

	template <>
	ucl::StateManager& ucl::StatesLocator::get();

	template <>
	std::unique_ptr<ucl::StateManager> StatesLocator::object{new StateManager()};
}
