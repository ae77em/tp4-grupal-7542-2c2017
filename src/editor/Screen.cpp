#include "Screen.h"
#include <stdexcept>
#include "../sdl/Constants.h"
#include "../sdl/Utils.h"

Screen::Screen() {
    window = SDL_CreateWindow("Tower4Defense", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (!window) throw std::runtime_error("Could not create window"
            + std::string(SDL_GetError()));

    renderer = SDL_CreateRenderer(window, -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) throw std::runtime_error("Could not create renderer"
            + std::string(SDL_GetError()));

    //Initialize renderer color
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if (! IMG_Init(imgFlags) || ! imgFlags )
        throw std::runtime_error("Could not initialize SDL_image. Error: "
                + std::string(IMG_GetError()));

    tile.loadFromFile("images/sprites/tile-grass.png", renderer);
    tower.loadFromFile("images/sprites/tower-earth-alone.png", renderer);
}

Screen::~Screen() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

void Screen::draw() {
    dot.move();
    dot.setCamera(camera);
    SDL_RenderPresent(renderer);
}

void Screen::putTower(unsigned x, unsigned y) {
    Point pos = Utils::mapToScreen(x, y); 
    pos.x -= camera.x;
    pos.y -= camera.y;
    tower.render(renderer, pos.x, pos.y); 
}

void Screen::putTile(unsigned x, unsigned y) {
    Point pos = Utils::mapToScreen(x, y); 
    pos.x -= camera.x;
    pos.y -= camera.y;
    tile.render(renderer, pos.x, pos.y); 
}

void Screen::handleEvent(SDL_Event &e) {
    std::string s;
    dot.handleEvent(e, s);
}

void Screen::clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
    SDL_RenderClear(renderer);
}
