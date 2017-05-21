#include <iostream>
#include <SFML/Audio/SoundBuffer.hpp>
#include <audio/Audio.h>
#include <locator/AudioLocator.h>

int main() {
	sf::SoundBuffer buffer;
	buffer.loadFromFile("resources/default/encounter/fight/soundSlice.wav");

	auto& existingAudio = ug::AudioLocator::get();
	ug::AudioLocator::get().playSound(buffer);
}
