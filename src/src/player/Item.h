#ifndef PROJECT_ITEM_H
#define PROJECT_ITEM_H

#include <functional>
#include <string>

namespace ug {
    class Player;
    class Inventory;

    typedef std::function<void(Player &player)> ItemAction;

    class Item {
        const ItemAction action;

        static unsigned long nextID;
        const unsigned long ID;

        std::string name = "Default Item";
    public:
        Item(const ItemAction &action, const unsigned long& ID);
        Item(const ItemAction &action);

        Item clone() const;
        operator unsigned long() const;
        const unsigned long getID() const;

        void execute(Player &player) const;

        const std::string &getName() const;
        void setName(const std::string &name);
    };
}

#endif //PROJECT_ITEM_H
