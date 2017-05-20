#include <audio/LoggedAudio.h>
#include <locator/Locator.h>
#include <logging/Logger.h>

struct ucl::LoggedAudio::Impl {
	std::unique_ptr<ucl::Audio> audio;
};

void ucl::LoggedAudio::playSound(const sf::SoundBuffer& buffer) {
	Locator<Logger>::get().log(LogSeverity::DEBUG, "Sound was played");
	impl->audio->playSound(buffer);
}

ucl::LoggedAudio::LoggedAudio(std::unique_ptr<ucl::Audio> audio) : impl{std::make_unique<Impl>()} {
	impl->audio = std::move(audio);
}
