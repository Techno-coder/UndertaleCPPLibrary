#include <algorithm>
#include "../../src/src/state/StateManager.h"
#include "../../src/src/encounter/states/ActionSelectState.h"

class TestEnemyProjectileSpawner : public ug::ProjectileSpawner {
public:
};

int main() {
    ug::Encounter encounter;
    ug::Enemy temp((TestEnemyProjectileSpawner()));
    temp.getAttributes().name = "Succ";
    ug::Act poo([](ug::Enemy &enemy){});
    poo.setName("GAH BLABH");
    temp.getActs().push_back(poo);
    auto otherTemp = temp.clone();
    otherTemp.getAttributes().spareable = true;
    encounter.addEnemy(temp.clone());
    encounter.addEnemy(otherTemp);
    encounter.addEnemy(temp.clone());

    std::unique_ptr<ug::State> stuff(new ug::ActionSelectState(std::shared_ptr<ug::Encounter>(&encounter)));
    ug::StateManager stateManager(std::move(stuff));
}