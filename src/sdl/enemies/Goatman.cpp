#include "Goatman.h"

Goatman::Goatman(int x, int y, SDL_Renderer *renderer, LTexture &t) : Enemy(x, y, renderer) {
    initialLifePoints = 100;
    isAir = false;
    velocity = 2;
}