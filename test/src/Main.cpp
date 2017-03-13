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

int main() {
    ug::LaunchParameters parameters;
    ug::Fight fight;
    ug::Enemy enemy1("EnemyOne");
//    ug::Enemy enemy2("EnemyTwo");
//    ug::Enemy enemy3("EnemyThree");
    ug::ActCommand actCommand("Print");
    ug::ActCommand actCommand1("Print1");
    ug::ActCommand actCommand2("Print2");
    PrintActHandler actHandler;
    actCommand.setHandler(&actHandler);
    actCommand1.setHandler(&actHandler);
    actCommand2.setHandler(&actHandler);
    enemy1.addActCommand(&actCommand);
    enemy1.addActCommand(&actCommand1);
    enemy1.addActCommand(&actCommand2);
    fight.addEnemy(enemy1);
//    fight.addEnemy(enemy2);
//    fight.addEnemy(enemy3);
    ug::FightActionSelectState::getInstance().loadFight(&fight);
    parameters.setStartingState(&ug::FightActionSelectState::getInstance());
    parameters.setStartWindowTitle("Undertale Test Game");
    parameters.setStartWindowWidth(1024);
    parameters.setStartWindowHeight(768);
    ug::UndertaleGame::getInstance()->startGame(parameters);
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

