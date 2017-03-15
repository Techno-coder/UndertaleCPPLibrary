#ifndef PROJECT_ITEMHANDLER_H
#define PROJECT_ITEMHANDLER_H

#include "Item.h"

namespace ug {
    class Item;

    class ItemHandler {
    public:
        virtual void handle(Item& item) = 0;
    };
}

#endif //PROJECT_ITEMHANDLER_H
