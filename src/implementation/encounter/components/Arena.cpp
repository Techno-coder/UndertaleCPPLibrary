#include <encounter/components/Arena.h>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

struct ug::Arena::Impl {
	sf::RectangleShape rectangle;
};

void ug::Arena::draw(sf::RenderTarget& target) {
	target.draw(impl->rectangle);
}

ug::Arena::Arena() : impl(std::make_unique<Impl>()) {
	impl->rectangle.setFillColor(sf::Color::Black);
	impl->rectangle.setOutlineColor(sf::Color::White);
	impl->rectangle.setOutlineThickness(5);
	resize(570, 130);
	setPosition(320, 320);
}

void ug::Arena::resize(float width, float height) {
	float widthDiff = impl->rectangle.getSize().x - width;
	float heightDiff = impl->rectangle.getSize().y - height;
	impl->rectangle.setSize(sf::Vector2f(width, height));
	impl->rectangle.setOrigin(width / 2, height / 2);
	impl->rectangle.move(widthDiff / 2, heightDiff / 2);
}

void ug::Arena::setPosition(float x, float y) {
	impl->rectangle.setPosition(x, y);
}

ug::Arena::~Arena() {}

