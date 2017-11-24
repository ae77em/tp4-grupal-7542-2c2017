#ifndef TP4_TOWERDEFENSE_ACTORTOWER_H
#define TP4_TOWERDEFENSE_ACTORTOWER_H

#include "../../../common/Circle.h"
#include "../../../common/Point.h"
#include "../../GameActor.h"
#include "../enemies/Horde.h"
#include "../enemies/ActorEnemy.h"

#include <string>

class ActorTower  {
public:
    ActorTower();

    explicit ActorTower(int id);

    virtual ~ActorTower();

    std::string getClass();

    void live();

    void attack(Horde *horde);

    int getXPosition();

    int getYPosition();

    int getEnergy();

    int getId();

    ActorRectT getRect();

    void shiftColliders();

    Circle &getCollisionCircle();

    virtual int getShotDamage(ActorEnemy enemy);

    void setIsShooting(bool isShooting);

    void sumExperiencePoints(int points);

    int getExperiencePoints();

    int getSlowDownPercentaje();

    void setSlowDownPercentaje(double perc);

    bool itIsShooting();

    void setPosition(int x, int y);

    void shootTo(ActorEnemy *pEnemy);

    void doShootTo(ActorEnemy *pEnemy);

    int getRange();

    int getReach();

    /* Para retornar info al juego de la torre */
    std::string getRangeInfo();

    std::string getReachInfo();

    std::string getSlowDownPercentajeInfo();

    std::string getShotDamageInfo();

    bool isReadyToShoot() const;

    virtual bool upgradeDamage();

    std::string getExperiencePointsInfo();

protected:
    int range;
    int reach;
    int shotSecondsGap;
    bool isShooting;
    int lastShotTime;
    int shotDamage;
    int reachDamage;
    double slowDownPercentaje;
    int experiencePoints;

    int rangeLevel;
    int shotDamageLevel;
    int reachLevel;
    int slowdownLevel;

    Circle collisionCircle;
    Point currentPoint = Point(0, 0);
    //ActorRectT rect;

    int id;

    void updateLastShotTime();

    int getCollisionCircleRadio();

    void initialize();

};


#endif //TP4_TOWERDEFENSE_ACTORTOWER_H
