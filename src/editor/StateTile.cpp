#include "Editor.h"

void Editor::StateTile::handle(const SDL_Event &e, Editor &context) {
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        Point p = context.getScreen().mouseCurrentTile();
        Point d = context.getMap().dimensiones();
        if ((p.isPositive()) && (p.x < d.x) && (p.y < d.y))
            context.getMap().setCasilla(tile, p.x, p.y);
    }

    const Keybinding& keys = context.getKeys();

    // Change tool type
    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == keys.water)
        tile = '~';
    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == keys.earth)
        tile = '*';
    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == keys.fire)
        tile = '!';
    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == keys.air)
        tile = '@';

    // Change mode
    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == keys.road) {
        context.transition(new StatePath());
    }
}
