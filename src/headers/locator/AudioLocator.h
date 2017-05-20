#pragma once

#include <audio/Audio.h>
#include "Locator.h"

namespace ucl {
	typedef ucl::Locator<ucl::Audio> AudioLocator;

	template <>
	ucl::Audio& ucl::AudioLocator::get();
}
