#ifndef TP4_TOWERDEFENSE_GREENDAEMON_H
#define TP4_TOWERDEFENSE_GREENDAEMON_H


#include "Enemy.h"

class GreenDaemon : public Enemy{
public:
    GreenDaemon(int x, int y, SDL_Renderer *renderer, LTexture &t);

};


#endif //TP4_TOWERDEFENSE_GREENDAEMON_H