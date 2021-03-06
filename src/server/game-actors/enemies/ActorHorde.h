#ifndef TP4_TOWERDEFENSE_SERVER_HORDE_H
#define TP4_TOWERDEFENSE_SERVER_HORDE_H

#include "ActorEnemy.h"
#include <vector>

class ActorHorde {
public:
    ActorHorde();

    explicit ActorHorde(int t);

    virtual ~ActorHorde();

    void setEnemies(std::vector<ActorEnemy *> enemies);

    std::vector<ActorEnemy *> getEnemies();

    void addEnemy(ActorEnemy *enemy);

    static ActorHorde *createHorde(int enemyType, int amount, std::vector<Point> path);

    bool itIsAlive();

    void setIsAlive(bool isAlive);

    bool itIsAir();

    bool shouldSendMoreData();

private:
    std::vector<ActorEnemy*> enemies;

    int type = 0;

    bool isAlive;

    int timeOfDeath;

    bool mustSendData;

    static ActorEnemy *getEnemyByType(int type);

    void setTimeOfDeath();

    void initialize();
};


#endif //TP4_TOWERDEFENSE_SERVER_HORDE_H
