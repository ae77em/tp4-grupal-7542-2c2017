#ifndef TP4_TOWERDEFENSE_ISOMETRICTILE_H
#define TP4_TOWERDEFENSE_ISOMETRICTILE_H

#include <string>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_system.h>
#include <SDL2/SDL_events.h>
#include "../sdl/LTexture.h"

class Tile {
public:
    Tile(int x, int y, int type);

    void render(SDL_Rect &camera,
                SDL_Rect *gTileClips,
                SDL_Renderer *gRenderer,
                LTexture *gTileTextures);

    void renderSprite(SDL_Rect &camera,
                      SDL_Rect *gTileClips,
                      SDL_Renderer *gRenderer,
                      LTexture *gTileTextures);

    /* Maneja los eventos sobre los tiles.
     * */
    void handleEvent(SDL_Event &e, std::string &desc);

    /* Maneja las notificaciones del server.
     * */
    void handleServerNotification(int opCode);

    //Get the tile type
    int getType();

    //Set the tile type
    void setType(int tileType);

    //Get the collision box
    SDL_Rect getBox();


    void verifyIfMustContinueMarked();

private:
    //The attributes of the tile
    SDL_Rect containerBoxAttributes;

    //The tile type
    int type;

    //GamePlayWindow-event dispatched from the tile
    int gameEvent;

    int tileMarkedTime;
public:
    int getTileMarkedTime() const;

    void setMarkedTime(int tileMarkedTime);

    bool itIsMarked() const;

    void setIsMarked(bool isMarked);

private:

    bool isMarked;

};



#endif //TP4_TOWERDEFENSE_ISOMETRICTILE_H
