#pragma once

#include "Locator.h"

namespace ug {
	class Player;

	typedef ug::Locator<ug::Player> PlayerLocator;

	template <>
	std::shared_ptr<ug::Player> ug::PlayerLocator::get();
}
