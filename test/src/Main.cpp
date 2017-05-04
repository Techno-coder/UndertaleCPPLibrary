#include <algorithm>
#include "../../src/src/state/StateManager.h"
#include "../../src/src/encounter/states/ActionSelectState.h"

int main() {
    std::unique_ptr<ug::State> stuff(new ug::ActionSelectState);
    ug::StateManager stateManager(std::move(stuff));
}