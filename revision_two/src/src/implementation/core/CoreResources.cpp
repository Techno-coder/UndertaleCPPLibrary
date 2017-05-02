
#include "../../headers/core/UndertaleGame.h"
#include "../../headers/core/CoreResources.h"

bool ug::CoreResources::loaded = false;

void ug::CoreResources::load() {
    if (loaded) {
        return;
    }

    ug::ResourceManager* resourceManager = ug::UndertaleGame::getInstance()->getResourceManager();

    ug::ResourceItem monoFont("DETERMINATION_MONO_FONT", "resources/default/DTM-Mono.otf", ug::ResourceType::FONT);
    ug::ResourceItem sansFont("DETERMINATION_SANS_FONT", "resources/default/DTM-Sans.otf", ug::ResourceType::FONT);
    ug::ResourceItem cryptFont("CRYPT_TOMORROW_FONT", "resources/default/CryptOfTomorrow.ttf", ug::ResourceType::FONT);

    resourceManager->loadResource(monoFont);
    resourceManager->loadResource(sansFont);
    resourceManager->loadResource(cryptFont);

    loaded = true;
}
