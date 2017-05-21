#include <locator/AudioLocator.h>
#include <audio/SimpleAudio.h>

template <>
std::unique_ptr<ug::Audio> ug::AudioLocator::object{new SimpleAudio()};

template <>
ug::Audio& ug::AudioLocator::get() {
	if (!object) throw NoServiceProvidedException("AUDIO");
	return *object;
}
