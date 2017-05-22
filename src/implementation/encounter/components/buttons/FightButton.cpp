#include <encounter/components/buttons/FightButton.h>

struct ug::FightButton::Impl {
	EncounterButtonStaticTextures <FightButton> textures{
			"default/encounter/buttonFightHighlight.png", "default/encounter/buttonFight.png"};
};

ug::FightButton::FightButton() : impl(std::make_unique<Impl>()) {}

sf::Texture& ug::FightButton::getTexture(bool isHighlighted) {
	return *(isHighlighted ? impl->textures.highlight : impl->textures.normal);
}

ug::FightButton::~FightButton() {}
