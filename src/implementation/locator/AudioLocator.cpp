#include <locator/AudioLocator.h>
#include <audio/SimpleAudio.h>

template <>
std::unique_ptr<ucl::Audio> ucl::AudioLocator::object{new SimpleAudio()};

template <>
ucl::Audio& ucl::AudioLocator::get() {
	if (!object) throw NoServiceProvidedException("AUDIO");
	return *object;
}
