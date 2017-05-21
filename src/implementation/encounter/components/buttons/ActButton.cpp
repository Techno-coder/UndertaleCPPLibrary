#include <encounter/components/buttons/ActButton.h>

struct ug::ActButton::Impl {
	EncounterButtonStaticTextures <ActButton> textures{
			"default/encounter/buttonActHighlight.png", "default/encounter/buttonAct.png"};
};

ug::ActButton::ActButton() : impl(std::make_unique<Impl>()) {}

sf::Texture& ug::ActButton::getTexture(bool isHighlighted) {
	return *(isHighlighted ? impl->textures.highlight : impl->textures.normal);
}
