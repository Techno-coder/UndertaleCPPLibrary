#include <algorithm>
#include "../../src/src/state/StateManager.h"
#include "../../src/src/encounter/states/ActionSelectState.h"

class TestEnemyProjectileSpawner : public ug::ProjectileSpawner {
public:
};

int main() {
    sf::Texture tempFroggit;
    tempFroggit.loadFromFile("resources/froggit_test.png");
    sf::Sprite test(tempFroggit);

    ug::Encounter encounter;
    ug::Enemy temp((TestEnemyProjectileSpawner()), test);
    temp.getAttributes().name = "Succ";
    ug::Act poo([](ug::State &state){});
    poo.setName("GAH BLABH");
    temp.getActs().push_back(poo);
    temp.getActs().push_back(poo);
    temp.getActs().push_back(poo);
    temp.getAttributes().health = 80;
    temp.getAttributes().maxHealth = 100;
    auto ASDUIUHSADH = temp.clone(sf::Vector2f(123, 123));
    encounter.addEnemy(temp.clone(sf::Vector2f(100, 150)));
    encounter.addEnemy(temp.clone(sf::Vector2f(250, 150)));
    encounter.addEnemy(temp.clone(sf::Vector2f(400, 150)));
    auto asdasd = std::shared_ptr<ug::Encounter>(&encounter);
    ug::StateManager stateManager(std::unique_ptr<ug::State>(new ug::ActionSelectState(asdasd)));
}