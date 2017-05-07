#ifndef PROJECT_IENCOUNTER_H
#define PROJECT_IENCOUNTER_H

#include <vector>
#include "Enemy.h"
#include "EncounterEventHandler.h"

namespace ug {
    class Enemy;
    class EncounterEventHandler;

    struct EncounterTemporaryState {
        int lastEnemySelected = 0;
        int lastActSelected = 0;
        int lastMercySelected = 0;
        sf::Vector2f desiredDefendArenaSize{150, 150};
        sf::Vector2f endTransitionArenaPosition{320, 320};
        bool customArenaSize = false;
    };

    class Encounter {
        std::vector<Enemy> enemies;

        //TODO consider having variables here which determine the fight states; easy modifying of functionality
    public:
        Encounter();

        void addEnemy(Enemy enemy);
        std::vector<Enemy>& getAllEnemies();

        EncounterTemporaryState temporaryState;
        std::unique_ptr<EncounterEventHandler> eventHandler;
    };
}

#endif //PROJECT_IENCOUNTER_H
