#pragma once

namespace sf {
	class SoundBuffer;
}

namespace ucl {
	class Audio {
	public:
		/**
		 * Play a sound
		 * @param buffer The sound buffer to play
		 */
		virtual void playSound(const sf::SoundBuffer& buffer) = 0;

		virtual ~Audio() {}
	};
}