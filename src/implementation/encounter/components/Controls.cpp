#include <encounter/components/Controls.h>

#include <array>
#include <SFML/Window/Event.hpp>

struct ug::Controls::Impl {
	std::array<std::function<void()>, 6> callbacks;
	std::array<bool, 6> isPressed;

	int KeyTypeResolver(ug::Controls::KeyType type) {
		switch (type) {
			case KeyType::CONFIRM:
				return 0;
			case KeyType::CANCEL:
				return 1;
			case KeyType::UP:
				return 2;
			case KeyType::DOWN:
				return 3;
			case KeyType::LEFT:
				return 4;
			case KeyType::RIGHT:
				return 5;
		}
	}

	void setKeyStatus(ug::Controls::KeyType type, bool pressed) {
		int keyNumber = KeyTypeResolver(type);
		if (pressed) {
			if (!isPressed[keyNumber]) {
				isPressed[keyNumber] = true;
				callbacks[keyNumber]();
			}
			return;
		}
		isPressed[keyNumber] = false;
	}
};

ug::Controls::~Controls() {}

void ug::Controls::handleEvent(sf::Event& event) {
	using sf::Keyboard;
	switch (event.type) {
		case sf::Event::KeyPressed: {
			int keyCode = event.key.code;
			if (keyCode == Keyboard::Z || keyCode == event.key.shift)
				impl->setKeyStatus(KeyType::CONFIRM, true);
			if (keyCode == Keyboard::X || keyCode == Keyboard::Return)
				impl->setKeyStatus(KeyType::CANCEL, true);
			if (keyCode == Keyboard::Up) impl->setKeyStatus(KeyType::UP, true);
			if (keyCode == Keyboard::Down) impl->setKeyStatus(KeyType::DOWN, true);
			if (keyCode == Keyboard::Left) impl->setKeyStatus(KeyType::LEFT, true);
			if (keyCode == Keyboard::Right) impl->setKeyStatus(KeyType::RIGHT, true);
			break;
		}
		case sf::Event::KeyReleased: {
			int keyCode = event.key.code;
			if (keyCode == Keyboard::Z || keyCode == event.key.shift)
				impl->setKeyStatus(KeyType::CONFIRM, false);
			if (keyCode == Keyboard::X || keyCode == Keyboard::Return)
				impl->setKeyStatus(KeyType::CANCEL, false);
			if (keyCode == Keyboard::Up) impl->setKeyStatus(KeyType::UP, false);
			if (keyCode == Keyboard::Down) impl->setKeyStatus(KeyType::DOWN, false);
			if (keyCode == Keyboard::Left) impl->setKeyStatus(KeyType::LEFT, false);
			if (keyCode == Keyboard::Right) impl->setKeyStatus(KeyType::RIGHT, false);
			break;
		}
		default:
			break;
	}
}

void ug::Controls::setOnPressedListener(ug::Controls::KeyType type, std::function<void()> callback) {
	impl->callbacks[impl->KeyTypeResolver(type)].operator=(callback);
}

ug::Controls::Controls() : impl(std::make_unique<Impl>()) {
	impl->callbacks.fill([]() {});
	impl->isPressed.fill(false);
}
