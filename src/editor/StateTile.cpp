#include "Editor.h"

void Editor::StateTile::handle(const SDL_Event &e, Editor &context) {
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        Point p = context.getScreen().mouseCurrentTile();
        Point d = context.getMap().dimensions();
        if ((p.isPositive()) && (p.x < d.x) && (p.y < d.y))
            context.getMap().setTile(tile, p.x, p.y);
    }

    const Keybinding& keys = context.getKeys();

    // Change tool type
    if (e.type == SDL_KEYDOWN) {
        if (e.key.keysym.sym == keys.portal_entry) tile = 'E';
        else if (e.key.keysym.sym == keys.portal_exit) tile = 'S';
        else if (e.key.keysym.sym == keys.firm_ground) tile = 'x';

        // On keys.cancel, alternate between '.' and '#'
        else if (e.key.keysym.sym == keys.cancel)
            tile = (tile == '.') ? '#' : '.';
    }

    // Change mode
    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == keys.road) {
        context.transition(new StatePath());
    } else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_COMMA) {
        context.transition(new StateCommand());
    } else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == keys.horde) {
        context.transition(new StateHordeManagement());
    }
}
