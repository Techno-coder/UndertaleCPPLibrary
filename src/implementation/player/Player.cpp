#include <player/Player.h>
#include <player/PlayerStatistics.h>

struct ug::Player::Impl {
	PlayerStatistics statistics;
};

ug::PlayerStatistics& ug::Player::statistics() {
	return impl->statistics;
}

ug::Player::~Player() {}

ug::Player::Player() : impl(std::make_unique<Impl>()) {}
