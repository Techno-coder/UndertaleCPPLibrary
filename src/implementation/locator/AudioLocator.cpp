#include <locator/AudioLocator.h>

template <>
ucl::Audio& ucl::AudioLocator::get() {
	if (!object) throw NoServiceProvidedException("AUDIO");
	return *object;
}
