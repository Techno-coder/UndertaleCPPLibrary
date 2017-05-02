#ifndef PROJECT_STATEMANAGER_H
#define PROJECT_STATEMANAGER_H

#include <stack>
#include "fights/Fight.h"
#include "states/State.h"
#include "Resource.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class ResourceList;

namespace ug {
    class StateManager {
        sf::RenderWindow window;
        std::stack<ug::State*> states;

        void startGame();
    public:
        void beginFight(Fight fight);

        friend void initialize(ResourceList resources);
    };
}

#endif //PROJECT_STATEMANAGER_H
