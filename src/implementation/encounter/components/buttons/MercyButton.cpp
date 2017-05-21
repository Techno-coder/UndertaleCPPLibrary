#include <encounter/components/buttons/MercyButton.h>

struct ug::MercyButton::Impl {
	EncounterButtonStaticTextures <MercyButton> textures{
			"default/encounter/buttonMercyHighlight.png", "default/encounter/buttonMercy.png"};
};

ug::MercyButton::MercyButton() : impl(std::make_unique<Impl>()) {}

sf::Texture& ug::MercyButton::getTexture(bool isHighlighted) {
	return *(isHighlighted ? impl->textures.highlight : impl->textures.normal);
}
