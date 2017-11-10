#include "Editor.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


Editor::Editor::Editor(State *state) : state(state), screen(),
        map(10, 10), keys(default_keybinding) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw std::runtime_error("SDL init failed");

    if (TTF_Init() == -1)
        throw std::runtime_error("TTF init failed");

    map.setCasilla('~', 1, 1);
    map.setCasilla('*', 1, 8);
    map.setCasilla('!', 8, 1);
    map.setCasilla('@', 8, 8);
    map.setCasilla('E', 4, 4);
}

Editor::Editor::~Editor() {
    TTF_Quit();
    SDL_Quit();
}

void Editor::Editor::transition(State *newstate) {
    state.reset(newstate);
}

void Editor::Editor::run() {
    bool quit = false;
    while (!quit) {
        screen.clear();

        SDL_Event e;
        while(SDL_PollEvent( &e ) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else {
                state->handle(e, *this);
                screen.handleEvent(e);
            }
        }

        screen.put(map);
        //TODO move path tracing to screen::put(map)
        for (const auto& camino : map.getCaminos())
            screen.trace(camino);
        screen.draw();
    }
}

Screen& Editor::Editor::getScreen() {
    return screen;
}

Mapa& Editor::Editor::getMap() {
    return map;
}

const Keybinding& Editor::Editor::getKeys() {
    return keys;
}
