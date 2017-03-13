#ifndef PROJECT_ITEM_H
#define PROJECT_ITEM_H

#include <string>

namespace ug {
    class Item {

        /**
         * @todo Consider allowing itemID to change
         */
        const std::string itemID;

        /**
         * @todo Consider allowing itemName to change
         */
        const std::string itemName;
    public:
        /**
         * Non overrideable constructor
         * If no itemID is provided the itemName is used
         * @param itemID The id of this item (useful if there are multiple items with the same name)
         * @param itemName The name of the item shown on the item selection menu
         */
        Item(const std::string& itemID, const std::string& itemName);
        Item(const std::string& itemName);

        /**
         * Getter for ItemID
         * @return The ItemName for this item
         */
        const std::string& getItemID();

        /**
         * Getter for ItemID
         * @return The ItemName for this item
         */
        const std::string& getItemName();

        /**
         * Called when this item is selected
         */
        virtual void handle() = 0;
    };
}

#endif //PROJECT_ITEM_H
