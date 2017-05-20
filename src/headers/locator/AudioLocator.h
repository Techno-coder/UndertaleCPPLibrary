#pragma once

#include "Locator.h"

namespace ucl {
	class Audio;

	typedef ucl::Locator<ucl::Audio> AudioLocator;

	template <>
	ucl::Audio& ucl::AudioLocator::get();

}
