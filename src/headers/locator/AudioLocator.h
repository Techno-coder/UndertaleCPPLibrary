#pragma once

#include "Locator.h"

namespace ug {
	class Audio;

	typedef ug::Locator<ug::Audio> AudioLocator;

	template <>
	ug::Audio& ug::AudioLocator::get();

}
