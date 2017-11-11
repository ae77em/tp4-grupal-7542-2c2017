#include "Horde.h"
#include "Abmonible.h"

Horde::Horde() {}

Horde::Horde(int enemyType, size_t size, int x, int y, SDL_Renderer *r, LTexture &t) {
    switch (enemyType){
        case ABMONIBLE:{
            loadAbmonibles(size, x, y, r);
            break;
        }
        default:{
            //do nothing;
        }
    }
}

Horde::~Horde() {}

void Horde::loadAbmonibles(size_t size, int x, int y, SDL_Renderer *r) {
    enemySeparation = Abmonible::getCollisionCircleRadio();
    for (unsigned i = 0; i < size; ++i){
        enemies.push_back(new Abmonible(x, y, r, nullptr));
    }
}

void Horde::loadBloodHawks(size_t size) {

}

void Horde::loadGoatmans(size_t size) {

}

void Horde::loadGreenDaemons(size_t size) {

}

void Horde::loadSpectres(size_t size) {

}

void Horde::loadZombies(size_t size) {

}

void Horde::addEnemy(Enemy *e){
    enemies.push_back(e);
}

std::vector<Enemy *> &Horde::getEnemies() {
    return enemies;
}

Enemy* &Horde::getEnemieAt(unsigned i) {
    return enemies.at(i);
}
