#ifndef TP4_TOWERDEFENSE_SERVERGAME_H
#define TP4_TOWERDEFENSE_SERVERGAME_H

#define MAX_PLAYERS 4

#include <iostream>
#include "ServerPlayer.h"
#include "WorkerLoopGame.h"
#include "GameAction.h"
#include <map>
#include <string>
#include <list>

class ServerGame {
private:
    std::map<int,ServerPlayer*> players;
    //lo usaria para bloquear un jugador
    std::mutex& mutexPlayers;
    bool endSignal;

    //lo uso para bloquear la lista de acciones a aplicar sobre el juego
    std::mutex mutexActionsGame;
    WorkerLoopGame workerLoopGame;

    std::list<GameAction*> actions;

    bool playing = false;

    std::list<std::string> elements;

public:
    explicit ServerGame(std::mutex& mutex);

    bool elementsAreAvailables(std::list<std::string> elements);

    void addPlayer(ServerPlayer* sp);

    bool isPlaying() const;

    void setPlaying(bool playing);

    bool isFull();

    void startGame();

    void changeStatusPlayesOnGame(int i);

    void addEventMessage(Message m);

    void notifyAll(std::string basic_string);

    std::list<std::string> getElements();

    void removeElement(std::string elementName);

    std::list<std::string> getUnavailableElements();

    void enableElements(int idPlayer);

    void removePlayer(int i);

    void markTile(int x, int y);

    int getAmountPlayers();

    std::string getName();

    void kill();

    void putTower(int typeOfTower, int x, int y);

    void upgradeTower(int x, int y);

    void castSpell(int x, int y);

    void towerInfo(int clientId, int towerId);

    void notifyTo(int clientId, std::string message);
};


#endif //TP4_TOWERDEFENSE_SERVERGAME_H
