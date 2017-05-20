#pragma once

#include <audio/Audio.h>
#include <audio/SimpleAudio.h>
#include "Locator.h"

namespace ucl {
	typedef ucl::Locator<ucl::Audio> AudioLocator;

	template <>
	ucl::Audio& ucl::AudioLocator::get();

	template <>
	std::unique_ptr<ucl::Audio> AudioLocator::object{new SimpleAudio()};
}
