#include <iostream>
#include <audio/Audio.h>
#include <locator/AudioLocator.h>
#include <logging/Logger.h>
#include <logging/ConsoleLogger.h>
#include <audio/SimpleAudio.h>

int main() {
	sf::SoundBuffer buffer;
	buffer.loadFromFile("resources/default/encounter/fight/soundSlice.wav");

	ucl::Locator<ucl::Logger>::provide(std::unique_ptr<ucl::Logger>(new ucl::ConsoleLogger()));
	ucl::AudioLocator::provide(std::unique_ptr<ucl::Audio>(new ucl::SimpleAudio()));
	ucl::AudioLocator::get().playSound(buffer);
}
