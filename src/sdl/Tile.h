#ifndef TP4_TOWERDEFENSE_ISOMETRICTILE_H
#define TP4_TOWERDEFENSE_ISOMETRICTILE_H

#include <string>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_system.h>
#include <SDL2/SDL_events.h>
#include "towers/Tower.h"
#include "Texture.h"

class Tile {
public:
    Tile(int x, int y, int type);

    void render(SDL_Rect &camera,
                SDL_Rect *gTileClips,
                SDL_Renderer *renderer,
                Texture *gTileTextures);

    void renderSprite(SDL_Rect &camera,
                      SDL_Rect *tileClips,
                      SDL_Renderer *renderer,
                      Texture *tileTextures);

    /* Maneja los eventos sobre los tiles.
     * */
    void handleEvent(SDL_Event &e, std::string &desc);

    /* Maneja las notificaciones del server.
     * */
    void handleServerNotification(int opCode);

    int getType();
    void setType(int tileType);

    //Get the collision box
    SDL_Rect getBox();


    // Methods controlling marked (highlighted) status
    void verifyIfMustContinueMarked();
    int getTileMarkedTime() const;
    void setMarkedTime(int tileMarkedTime);
    bool itIsMarked() const;
    void setIsMarked(bool isMarked);

    void setTower(Tower *tower);
    Tower *getTower();

    bool isDrawable();

private:
    //The attributes of the tile
    SDL_Rect containerBoxAttributes;

    int type;

    //GamePlayWindow-event dispatched from the tile
    int gameEvent;

    int tileMarkedTime;
    bool isMarked;

    Tower *tower = nullptr;
};



#endif //TP4_TOWERDEFENSE_ISOMETRICTILE_H
