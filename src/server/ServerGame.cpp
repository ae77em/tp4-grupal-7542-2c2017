#include "ServerGame.h"
#include "../sdl/Constants.h"
#include "../common/Protocol.h"
#include "../common/MessageFactory.h"

#include <algorithm>

ServerGame::ServerGame(std::mutex& m):mutexPlayers(m),
                                      endSignal(false),
                                      workerLoopGame(players,actions,mutexActionsGame,endSignal),
                                      listenerLoopGame(actions,mutexActionsGame,queueMessagesGame,endSignal) {
    elements.push_back(STR_WATER);
    elements.push_back(STR_AIR);
    elements.push_back(STR_FIRE);
    elements.push_back(STR_EARTH);
}

void ServerGame::addPlayer(ServerPlayer* sp){
    players.insert(
            std::pair<int, ServerPlayer *>(sp->getId(),sp)
    );
}

bool ServerGame::elementsAreAvailables(list<string> elements) {
    std::list<std::string> othersElements;
    for (auto it=players.begin(); it!=players.end(); ++it){
        othersElements = it->second->getElements();

        for (std::string oe : othersElements) {
            if(std::find(elements.begin(), elements.end(), oe) != elements.end()) {
                return false;
            }
        }
    }
    return true;
}

bool ServerGame::isFull(){
    return players.size() == MAX_PLAYERS;
}

void ServerGame::startGame() {
    changeStatusPlayesOnGame(PLAYING);

    workerLoopGame.buildGameContext();

    listenerLoopGame.start();
    workerLoopGame.start();
}

void ServerGame::changeStatusPlayesOnGame(int status) {
    for (auto it=players.begin(); it!=players.end(); ++it){
        it->second->setStatus(status);
    }
}

void ServerGame::addEventMessage(Message m){
    queueMessagesGame.push(m);
}

void ServerGame::notifyAll(string message) {
    for (auto it=players.begin(); it!=players.end(); ++it){
        it->second->sendData(message);
    }
}

bool ServerGame::isPlaying() const {
    return playing;
}

void ServerGame::setPlaying(bool playing) {
    ServerGame::playing = playing;
}

void ServerGame::removeElement(std::string elementName) {
    elements.remove(elementName);
}

std::list<std::string> ServerGame::getElements() {
    return elements;
}

std::list<std::string> ServerGame::getUnavailableElements() {
    std::list<std::string> toReturn;
    std::list<std::string> playerElements;

    for (auto it=players.begin(); it!=players.end(); ++it){
        playerElements = it->second->getElements();
        for (std::string el : playerElements){
            toReturn.push_back(el);
        }
    }
    return toReturn;
}

void ServerGame::enableElements(int idPlayer) {
    ServerPlayer* sp = players.at(idPlayer);

    std::list<std::string>& elementsRecovered = sp->getElements();

    this->elements.merge(elementsRecovered);
}

void ServerGame::removePlayer(int i) {
    players.erase(i);
}


int ServerGame::getAmountPlayers() {
    return players.size();
}

void ServerGame::kill() {

    queueMessagesGame.close();

    listenerLoopGame.join();
    workerLoopGame.join();
}

void ServerGame::markTile(int x, int y){
    std::string markTileStr = MessageFactory::getMarkTileNotification(x, y);
    Message message;

    message.deserialize(markTileStr);

    mutexPlayers.lock();
    notifyAll(message.serialize());
    mutexPlayers.unlock();
}

void ServerGame::putTower(int typeOfTower, int x, int y) {
    std::string req = MessageFactory::getPutTowerGameRequest(typeOfTower, x, y);
    Message message;
    message.deserialize(req);
    queueMessagesGame.push(message);

    /** HASTA TENER DEFINIDO EL ACCESO A EL LOOP DE JUEGO CON LA INFO ***/
    req = MessageFactory::getCastSpellNotification(x, y);
    mutexPlayers.lock();
    notifyAll(message.serialize());
    mutexPlayers.unlock();
    /*****/
}

void ServerGame::castSpell(int x, int y) {
    std::string req = MessageFactory::getCastSpellGameRequest(x, y);
    Message message;
    message.deserialize(req);
    queueMessagesGame.push(message);

    /** HASTA TENER DEFINIDO EL ACCESO A EL LOOP DE JUEGO CON LA INFO ***/
    req = MessageFactory::getCastSpellNotification(x, y);
    mutexPlayers.lock();
    notifyAll(req);
    mutexPlayers.unlock();
    /*****/
}

void ServerGame::upgradeTower(int towerId, int upgradeType) {
    std::string req = MessageFactory::getUpgradeTowerGameRequest(towerId, upgradeType);
    Message message;
    message.deserialize(req);
    queueMessagesGame.push(message);

    /** HASTA TENER DEFINIDO EL ACCESO A EL LOOP DE JUEGO CON LA INFO ***/
    mutexPlayers.lock();
    notifyAll(message.serialize());
    mutexPlayers.unlock();
    /*****/
}

void ServerGame::towerInfo(int towerId) {
    std::string req = MessageFactory::getTowerInfoGameRequest(towerId);
    Message message;
    message.deserialize(req);
    queueMessagesGame.push(message);


    /** HASTA TENER DEFINIDO EL ACCESO A EL LOOP DE JUEGO CON LA INFO ***/
    req = MessageFactory::getTowerInfoNotification(towerId, 999, 999, 999);
    mutexPlayers.lock();
    notifyAll(req);
    mutexPlayers.unlock();
    /*****/
}

