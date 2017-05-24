#include <audio/LoggedAudio.h>
#include <locator/Locator.h>
#include <logging/Logger.h>

struct ug::LoggedAudio::Impl {
	std::unique_ptr<ug::Audio> audio;
};

void ug::LoggedAudio::playSound(const sf::SoundBuffer& buffer) {
	Locator<Logger>::get()->log(LogSeverity::DEBUG, "Sound was played");
	impl->audio->playSound(buffer);
}

ug::LoggedAudio::LoggedAudio(std::unique_ptr<ug::Audio> audio) : impl{std::make_unique<Impl>()} {
	impl->audio = std::move(audio);
}
