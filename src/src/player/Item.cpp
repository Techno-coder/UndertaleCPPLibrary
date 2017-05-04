#include "Item.h"
#include "Player.h"

unsigned long ug::Item::nextID = 0;

ug::Item::Item(const ug::ItemAction &action, const unsigned long &ID) : action(action), ID(ID) {}
ug::Item::Item(const ug::ItemAction &action) : Item(action, nextID++) {}

ug::Item ug::Item::clone() const {
    Item t = Item(action, ID);
    t.setName(name);
    return t;
}

const std::string &ug::Item::getName() const {
    return name;
}
void ug::Item::setName(const std::string &name) {
    Item::name = name;
}

void ug::Item::execute(ug::Player &player) const {
    action(player);
}

const unsigned long ug::Item::getID() const {
    return ID;
}

ug::Item::operator unsigned long() const {
    return getID();
}
