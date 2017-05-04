#ifndef PROJECT_INVENTORY_H
#define PROJECT_INVENTORY_H

#include <map>
#include "Item.h"

namespace ug {
    class Inventory {
        std::multimap<unsigned long, Item> items;
    public:
        void addItem(const Item &item);
        void removeItem(const unsigned long &itemID);

        /**
         * Gets an item by the specified ID
         * @param itemID The item ID
         * @return An item with the same ID or an empty item if one was not found
         */
        Item& getItem(const unsigned long &itemID);
        std::vector<Item> getAllItems();
    };
}

#endif //PROJECT_INVENTORY_H
