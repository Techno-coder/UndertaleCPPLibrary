#include "../../src/src/state/StateManager.h"
#include "../../src/src/encounter/states/ActionSelectState.h"
#include "../../src/src/encounter/states/defend/DefendArenaSizeTransitionState.h"

class EventHandlerThing : public ug::EncounterEventHandler {
    int internalCounter = 0;
public:
    void onDefendBegin(ug::EncounterState &encounterState) override {
        internalCounter = 0;
    }

    void onDefendUpdate(ug::EncounterState &encounterState) override {
        internalCounter++;
        if(internalCounter > 300) {
            exitDefendState(encounterState);
        }
    }
};

int main() {
    sf::Texture tempFroggit;
    tempFroggit.loadFromFile("resources/froggit_test.png");
    sf::Sprite test(tempFroggit);

    ug::Encounter encounter;
    encounter.eventHandler.reset(new EventHandlerThing);

    sf::Texture bullet;
    bullet.loadFromFile("resources/bullet.png");

    ug::Projectile gasdbahbhug;
    gasdbahbhug.getSprite().setTexture(bullet);
    gasdbahbhug.setOnUpdate([](ug::EncounterState& a, ug::Projectile& b) {
        b.getSprite().move(1, 0);
    });
    std::vector<ug::Projectile> initialProjectiles;
    initialProjectiles.push_back(gasdbahbhug);

    ug::ProjectileSpawner bahhumgug;
    bahhumgug.getInitialProjectiles = [&]() -> std::vector<ug::Projectile> {
        return initialProjectiles;
    };
    ug::Enemy temp(bahhumgug, test);

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
//    encounter.addEnemy(temp.clone(sf::Vector2f(250, 150)));
//    encounter.addEnemy(temp.clone(sf::Vector2f(400, 150)));
    auto asdasd = std::shared_ptr<ug::Encounter>(&encounter);
    ug::StateManager stateManager(std::unique_ptr<ug::State>(new ug::ActionSelectState(asdasd)));
}