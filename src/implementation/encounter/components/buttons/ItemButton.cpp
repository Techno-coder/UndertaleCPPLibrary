#include <encounter/components/buttons/ItemButton.h>

struct ug::ItemButton::Impl {
	EncounterButtonStaticTextures <ItemButton> textures{
			"default/encounter/buttonItemHighlight.png", "default/encounter/buttonItem.png"};
};

ug::ItemButton::ItemButton() : impl(std::make_unique<Impl>()) {}

sf::Texture& ug::ItemButton::getTexture(bool isHighlighted) {
	return *(isHighlighted ? impl->textures.highlight : impl->textures.normal);
}

ug::ItemButton::~ItemButton() {}
