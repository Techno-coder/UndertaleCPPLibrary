#include <audio/SimpleAudio.h>

#include <SFML/Audio/Sound.hpp>
#include <vector>

struct ug::SimpleAudio::Impl {
	std::vector<std::unique_ptr<sf::Sound>> currentSounds;

	void cleanExpiredSounds() {
		auto it = currentSounds.begin();
		while (it != currentSounds.end()) {
			if ((*it)->getStatus() == sf::SoundSource::Stopped) {
				std::swap(*it, currentSounds.back());
				currentSounds.pop_back();
			} else ++it;
		}
	}
};

void ug::SimpleAudio::playSound(const sf::SoundBuffer& buffer) {
	std::unique_ptr<sf::Sound> sound(new sf::Sound());
	sound->setBuffer(buffer);
	sound->play();
	impl->currentSounds.push_back(std::move(sound));
	impl->cleanExpiredSounds();
}

ug::SimpleAudio::SimpleAudio() : impl{std::make_unique<Impl>()} {}

ug::SimpleAudio::~SimpleAudio() {}
