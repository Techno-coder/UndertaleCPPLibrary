#ifndef PROJECT_UNDERTALEGAME_H
#define PROJECT_UNDERTALEGAME_H

#include "AudioManager.h"
#include "StateManager.h"
#include "Player.h"
#include "Resource.h"
#include "Renderer.h"

class ResourceList;
class AudioManager;
class Renderer;
class StateManager;

namespace ug {

    void initialize(ResourceList resources);

    class UndertaleGame {
        static UndertaleGame* instance;

        AudioManager* audioManager = nullptr;
        StateManager* stateManager = nullptr;
        Renderer* renderer = nullptr;
        Player* player = nullptr;
    public:
        static UndertaleGame* getInstance();

        AudioManager* getAudioManager();
        StateManager* getStateManager();
        Renderer* getRenderer();
        Player* getPlayer();

        friend void initialize(ResourceList resources);
        friend void initializeResources(ResourceList resources);
    };
}

#endif //PROJECT_UNDERTALEGAME_H
