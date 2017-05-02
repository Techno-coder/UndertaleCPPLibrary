#include "headers/UndertaleGame.h"

ug::UndertaleGame* ug::UndertaleGame::instance = nullptr;

ug::UndertaleGame* ug::UndertaleGame::getInstance() {
    if (instance == nullptr) {
        std::runtime_error("Game was not initialized; use ug::initialize();");
    }
    return instance;
}

void ug::initializeResources(ug::ResourceList resources) {
    for(ResourceItem item : resources.resources) {
        switch (item.type) {
            case TEXTURE:
            {
                std::unique_ptr<sf::Texture> texture(new sf::Texture());
                if(!texture->loadFromFile(item.filepath)) {
                    std::runtime_error("Failed to load texture " + item.filepath);
                }
                UndertaleGame::getInstance()->getRenderer()->textures[item.name] = std::move(texture);
                break;
            }
            case FONT:
            {
                std::unique_ptr<sf::Font> font(new sf::Font());
                if(!font->loadFromFile(item.filepath)) {
                    std::runtime_error("Failed to load font " + item.filepath);
                }
                UndertaleGame::getInstance()->getRenderer()->fonts[item.name] = std::move(font);
                break;
            }
            case SOUND:
            {
                std::unique_ptr<sf::SoundBuffer> buffer(new sf::SoundBuffer());
                if(!buffer->loadFromFile(item.filepath)) {
                    std::runtime_error("Failed to load sound " + item.filepath);
                }
                UndertaleGame::getInstance()->getAudioManager()->soundHolder[item.name] = std::move(buffer);
                break;
            }
            case MUSIC:
                UndertaleGame::getInstance()->getAudioManager()->musicHolder[item.name] = item.filepath;
                break;
        }
    }
}

void ug::initialize(ResourceList resources) {
    UndertaleGame::instance = new UndertaleGame();
    UndertaleGame::getInstance()->audioManager = new AudioManager();
    UndertaleGame::getInstance()->stateManager = new StateManager();
    UndertaleGame::getInstance()->renderer = new Renderer();
    UndertaleGame::getInstance()->player = new Player();
    initializeResources(resources);
    UndertaleGame::getInstance()->stateManager->startGame();
}

ug::AudioManager *ug::UndertaleGame::getAudioManager() {
    return audioManager;
}

ug::StateManager *ug::UndertaleGame::getStateManager() {
    return stateManager;
}

ug::Player *ug::UndertaleGame::getPlayer() {
    return player;
}

ug::Renderer *ug::UndertaleGame::getRenderer() {
    return renderer;
}
