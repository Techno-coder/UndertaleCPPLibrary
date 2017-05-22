#include <locator/PlayerLocator.h>
#include <player/Player.h>

template <>
std::unique_ptr<ug::Player> ug::PlayerLocator::object{new Player()};

template <>
ug::Player& ug::PlayerLocator::get() {
	if (!object) throw NoServiceProvidedException("PLAYER");
	return *object;
}
