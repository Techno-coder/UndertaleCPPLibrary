#pragma once

#include "Locator.h"

namespace ug {
	class Audio;

	typedef ug::Locator<ug::Audio> AudioLocator;

	template <>
	std::shared_ptr<ug::Audio> ug::AudioLocator::get();

}
