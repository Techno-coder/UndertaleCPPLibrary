#pragma once

#include "Audio.h"

namespace ucl {
	class LoggedAudio : public Audio {
		struct Impl;
		std::unique_ptr<Impl> impl;
	public:
		LoggedAudio(std::unique_ptr<Audio> audio);
		void playSound(const sf::SoundBuffer& buffer) override;
	};
}

