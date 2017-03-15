#include <core/UndertaleGame.h>
#include <fights/states/FightActionSelectState.h>
#include <iostream>

using namespace std;

class PrintActHandler : public ug::ActCommandHandler {
public:
    void handle(ug::Enemy &enemy) override {
        std::cout << "Act used on " << enemy.getEnemyName() << std::endl;
    }
};

class PrintItemHandler : public ug::ItemHandler {
public:
    void handle(ug::Item& item) override {
        std::cout << "Item used" << std::endl;
    }
};

int main() {
    ug::LaunchParameters parameters;
    parameters.setStartingState(&ug::FightActionSelectState::getInstance());
    parameters.setStartWindowTitle("Undertale Test Game");
    parameters.setStartWindowWidth(1024);
    parameters.setStartWindowHeight(768);
    ug::UndertaleGame::getInstance()->initializeGame(parameters);

    ug::Fight fight;
    ug::Enemy enemy1("EnemyOne");
//    ug::Enemy enemy2("EnemyTwo");
//    ug::Enemy enemy3("EnemyThree");
    ug::ActCommand actCommand("Check");
    ug::ActCommand actCommand1("Taunt");
    ug::ActCommand actCommand2("Eat");
    PrintItemHandler itemHandler;
    ug::Item cookieTurd("CookieTurd");
    cookieTurd.setHandler(&itemHandler);
    ug::UndertaleGame::getInstance()->getPlayer()->addItem(cookieTurd);
    PrintActHandler actHandler;
    actCommand.setHandler(&actHandler);
    actCommand1.setHandler(&actHandler);
    actCommand2.setHandler(&actHandler);
    enemy1.addActCommand(&actCommand);
    enemy1.addActCommand(&actCommand1);
    enemy1.addActCommand(&actCommand2);
    enemy1.setMaxHealth(200);
    enemy1.setHealth(180);
    fight.addEnemy(enemy1);
//    fight.addEnemy(enemy2);
//    fight.addEnemy(enemy3);
    ug::FightActionSelectState::getInstance().loadFight(&fight);

    ug::UndertaleGame::getInstance()->startGame();
    ug::UndertaleGame::cleanupGame();
    return 0;
}

//class AttackSequence {
//
//};
//
//class TorielFight : public Fight {
//    vector<AttackSequence> sequences;
//public:
//    TorielFight() {
//    }
//
//    void initFight() {
//        game->audioManager.playMusic("AsgoreDeterminationPoo");
//    }
//
//    AttackSequence getAttackSequence() {
//        return sequences[rand() % sequences.size()];
//    }
//
//    void onHit(FighterEntity attacker) {
//        game->audioManager.playSound("FireballHit");
//        game->thePlayer.lowerHealth(5);
//    }
//
//    void endFight() {
//        game->audioManager.stopMusic();
//    }
//};

