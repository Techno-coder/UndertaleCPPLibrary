#include <locator/AudioLocator.h>
#include <audio/SimpleAudio.h>

template <>
std::shared_ptr<ug::Audio> ug::AudioLocator::object{new SimpleAudio()};

template <>
std::shared_ptr<ug::Audio> ug::AudioLocator::get() {
	if (!object) throw NoServiceProvidedException("AUDIO");
	return object;
}
