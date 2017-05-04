#include "../../src/external/ObservableField.h"

ObservableField<short> poo;

void test() {
    FieldObserver<short> blah([=](short oldValue, short newValue){});
    poo.registerObserver(blah);
}

int main() {
//    std::unique_ptr<ug::State> stuff(new ug::ActionSelectState);
//    ug::StateManager stateManager(std::move(stuff));
    test();
}