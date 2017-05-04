#ifndef PROJECT_PLAYER_H
#define PROJECT_PLAYER_H

#include <string>
#include "../../external/ObservableField.h"

namespace ug {
    class Player {
        struct PlayerStatistics {
            ObservableField<short> health{10};
            ObservableField<short> maxHealth{20};
            ObservableField<short> level{3};
            ObservableField<std::string> playerName{"CHARA"};
        } playerStatistics;
    public:
        PlayerStatistics& getStatistics();
    };
}

#endif //PROJECT_PLAYER_H
