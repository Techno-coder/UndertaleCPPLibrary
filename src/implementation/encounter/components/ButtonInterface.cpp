#include <encounter/components/ButtonInterface.h>

#include <array>
#include <SFML/Graphics/RenderTarget.hpp>
#include <encounter/components/buttons/EncounterButton.h>
#include <encounter/components/buttons/DefaultButtons.h>

struct ug::ButtonInterface::Impl {
	std::array<std::unique_ptr<EncounterButton>, 4> buttons;
};

constexpr ug::ButtonInterface::Button ug::ButtonInterface::FIGHT;
constexpr ug::ButtonInterface::Button ug::ButtonInterface::ACT;
constexpr ug::ButtonInterface::Button ug::ButtonInterface::ITEM;
constexpr ug::ButtonInterface::Button ug::ButtonInterface::MERCY;

ug::ButtonInterface::ButtonInterface(std::unique_ptr<ug::EncounterButton> buttonOne,
                                     std::unique_ptr<ug::EncounterButton> buttonTwo,
                                     std::unique_ptr<ug::EncounterButton> buttonThree,
                                     std::unique_ptr<ug::EncounterButton> buttonFour) : impl(std::make_unique<Impl>()) {
	impl->buttons[0] = std::move(buttonOne);
	impl->buttons[1] = std::move(buttonTwo);
	impl->buttons[2] = std::move(buttonThree);
	impl->buttons[3] = std::move(buttonFour);
	setTopLeftPosition(30, 430);
	setHighlighted(Button::NONE);
}

void ug::ButtonInterface::draw(sf::RenderTarget& target) {
	for (auto& ptr : impl->buttons) {
		ptr->draw(target);
	}
}

void ug::ButtonInterface::setHighlighted(const Button& button) {
	for (auto& ptr : impl->buttons) {
		ptr->setHighlighted(false);
	}
	switch (button) {
		case Button::ONE:
			impl->buttons[0]->setHighlighted(true);
			break;
		case Button::TWO:
			impl->buttons[1]->setHighlighted(true);
			break;
		case Button::THREE:
			impl->buttons[2]->setHighlighted(true);
			break;
		case Button::FOUR:
			impl->buttons[3]->setHighlighted(true);
			break;
		case Button::NONE:
			break;
	}
}

void ug::ButtonInterface::setTopLeftPosition(float x, float y) {
	for (int i = 0; i < impl->buttons.size(); ++i) {
		impl->buttons[i]->setTopLeftPosition((157 * i) + x, y);
	}
}

ug::ButtonInterface::~ButtonInterface() {}

std::unique_ptr<ug::ButtonInterface> ug::getNewDefaultButtonInterface() {
	return std::make_unique<ug::ButtonInterface>(
			DefaultButtons::createFightButton(),
			DefaultButtons::createActButton(),
			DefaultButtons::createItemButton(),
			DefaultButtons::createMercyButton()
	);
};

