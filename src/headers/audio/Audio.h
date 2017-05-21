#pragma once

namespace sf {
	class SoundBuffer;
}

namespace ug {
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