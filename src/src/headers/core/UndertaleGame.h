#ifndef PROJECT_UNDERTALEGAME_H
#define PROJECT_UNDERTALEGAME_H


#include "../resource/ResourceManager.h"
#include "../audio/AudioManager.h"
#include "StateManager.h"
#include "../player/Player.h"
#include "LaunchParameters.h"
#include "../render/Renderer.h"

namespace ug {
    class UndertaleGame {
        static UndertaleGame* instance;
        sf::RenderWindow* window;

        Renderer* renderer;
        StateManager* stateManager;
        Player* player;
        ResourceManager* resourceManager;
        AudioManager* audioManager;

        /**
         * Initialize classes that this class uses
         * @param parameters Variables that classes may use to initialize
         */
        void initializeModules(const LaunchParameters& parameters);

        /**
         * Start the game loop (updating every 1/60th of a second)
         * @todo Consider variable update speed
         */
        void startGameLoop();

        /**
         * Private destructor for singleton forcing
         */
        UndertaleGame();
    public:
        static UndertaleGame* const getInstance();

        /**
         * Destructor
         */
        ~UndertaleGame();

        /**
         * Get the StateManager
         * @return The state manager associated with this game
         */
        StateManager* const getStateManager();

        /**
         * Get the player
         * @return The player associated with this game
         */
        Player* const getPlayer();

        /**
         * Get the renderer
         * @return The renderer associated with this game
         */
        Renderer* const getRenderer();

        /**
         * Get the resource manager
         * @return The resource manager associated with this game
         */
        ResourceManager* const getResourceManager();

        /**
         * Get the audio manager
         * @return The audio manager associated with this game
         */
        AudioManager* const getAudioManager();

        /**
         * @todo finish
         */
        void startGame(const LaunchParameters& parameters);

        /**
         * Call this function after the game has ended
         * @warning Accessing the game instance after calling this is not possible
         */
        static void cleanupGame();
    };
}

#endif //PROJECT_UNDERTALEGAME_H
