#ifndef PROJECT_ACTCOMMANDHANDLER_H
#define PROJECT_ACTCOMMANDHANDLER_H

#include "enemies/Enemy.h"

namespace ug {
    class Enemy;

    class ActCommandHandler {
    public:
        virtual void handle(Enemy& enemy) = 0;
    };
}

#endif //PROJECT_ACTCOMMANDHANDLER_H
