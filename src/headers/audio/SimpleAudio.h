#pragma once

#include <memory>
#include "Audio.h"

namespace ug {
	class SimpleAudio : public Audio {
		struct Impl;
		std::unique_ptr<Impl> impl;
	public:
		SimpleAudio();
		void playSound(const sf::SoundBuffer& buffer) override;
	};
}

