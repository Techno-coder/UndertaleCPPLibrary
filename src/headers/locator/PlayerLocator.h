#pragma once

#include "Locator.h"

namespace ug {
	class Player;

	typedef ug::Locator<ug::Player> PlayerLocator;

	template <>
	ug::Player& ug::PlayerLocator::get();
}
