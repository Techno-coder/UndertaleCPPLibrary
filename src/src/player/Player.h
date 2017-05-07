#ifndef PROJECT_PLAYER_H
#define PROJECT_PLAYER_H

#include <string>
#include "../../external/ObservableField.h"
#include "Inventory.h"

namespace ug {
    class Player {
        struct PlayerStatistics { //TODO load from somewhere later
            ObservableField<int> health{10};
            ObservableField<int> maxHealth{20};
            ObservableField<int> level{3};
            ObservableField<std::string> playerName{"CHARA"};
            ObservableField<float> weaponAttackSpeed{1.5};
            ObservableField<int> attackModifier{10};
            ObservableField<float> soulMoveSpeed{1.0};
        } playerStatistics;
        Inventory playerInventory;
    public:
        Player(); //TODO REMOVE LATER

        PlayerStatistics& getStatistics();
        Inventory& getInventory();
    };
}

#endif //PROJECT_PLAYER_H
