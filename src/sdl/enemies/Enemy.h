#ifndef TP4_TOWERDEFENSE_ENEMY_H
#define TP4_TOWERDEFENSE_ENEMY_H


#include <vector>
#include "../LTexture.h"
#include "../../common/Point.h"
#include "../Constants.h"

const int NUMBER_OF_ABOMINABLE_SPRITES = 12;

class Enemy {
protected:
    // abominable como monstruo default...porque sí (?)
    const std::string TEXTURE_FILE_PATH = "images/sprites/enemy-abominable-walk.png";

    const int ENEMY_WIDTH = 105;
    const int ENEMY_HEIGHT = 119;

    const int MAX_VELOCITY = 10;

private:
    //Collision box of the enemy
    SDL_Rect drawBox;

    //The velocity of the enemy
    int velocityX, velocityY;

    std::vector<Point> path;

    LTexture &texture;
    SDL_Renderer *renderer;
    SDL_Rect walkingSprites[NUMBER_OF_ABOMINABLE_SPRITES];
    SDL_Rect deathSprites[NUMBER_OF_ABOMINABLE_SPRITES];

public:
    Enemy(int x, int y, SDL_Renderer *renderer, LTexture &t);

    ~Enemy();

    /*
     * Carga la imagen que contiene los sprites del monstruo.
     */
    bool loadMedia();

    /*
     * Setea la posición del monstruo en la pantalla.
     */
    void setPosition(int x, int y);

    /*
     * Carga los sprites del monstruo en un array.
     */
    void setSprites();

    /*
     * Toma los datos de configuración del enemigo de un archivo y lo nutre
     * con eso.
     */
    void deserialize(std::string data);

    /*
     * Mueve el enemigo, siguiendo el camino indicado, y chequea colisiones.
     * */
    void move();

    /*
     * Renderea el enemigo en la pantalla.
     * camera: cuadrado que representa el lugar visible del mapa.
     * clip: el número de clip en el sprite a dibujar.
     * */
    void render(SDL_Rect &camera);

    /*
     * Modifica la textura que se utilizará para mostrar el enemigo.
     * texture: referencia a la textura a utilizar.
     * */
    void setTexture(LTexture &texture);

    /*
     * Modifica la cámara del juego donde está metido el enemigo, es decir,
     * el cuadro que se encarga de mostrar la parte visible del juego.
     * camera: referencia a la cámara a utilizar.
     * */
    void setCamera(SDL_Rect &camera);

    /*
     * Setea el renderer, encargad de dibujar la textura del enemigo en el juego.
     * camera: puntero al renderer utilizado.
     * */
    void setRenderer(SDL_Renderer *renderer);

    /*
     * Setea la velocidad
     * camera: puntero al renderer utilizado.
     * */
    void setVelocity(int velocityX, int velocityY);

};


#endif //TP4_TOWERDEFENSE_ENEMY_H