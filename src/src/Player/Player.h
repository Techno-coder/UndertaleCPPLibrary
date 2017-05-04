#ifndef PROJECT_PLAYER_H
#define PROJECT_PLAYER_H

#include "../../external/ObservableField.h"

namespace ug {
    class Player {
        struct PlayerStatistics {
            ObservableField<short> health;
            ObservableField<short> maxHealth;
            ObservableField<short> level;
        } statistics;
    public:
        PlayerStatistics& getStatistics();
    };
}

#endif //PROJECT_PLAYER_H
