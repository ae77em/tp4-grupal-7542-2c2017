#include <iostream>
#include "MessageFactory.h"
#include "Message.h"
#include "Protocol.h"
#include "../common/Point.h"

int MessageFactory::getOperation(Message& request){
    Json::Value &root = request.getData();
    return root[OPERATION_KEY].asInt();
}

std::vector<std::string> MessageFactory::getMaps(Message& message){
    std::vector<std::string> response;
    Json::Value &root = message.getData();
    for (Json::Value &map : root["maps"]){
        response.push_back(map.asString());
    }
    return response;
}

std::string MessageFactory::getMapName(Message& message){
    std::string response;
    Json::Value &root = message.getData();

    response = root.get("mapName", "").asString();

    return response;
}

std::string MessageFactory::getMatchName(Message& message){
    std::string response;
    Json::Value &root = message.getData();

    response = root.get("matchName", "").asString();

    return response;
}

std::string MessageFactory::getClientIdNotification(int clientId){
    std::string toReturn;
    Json::Value root(Json::objectValue);
    Message message;

    root[OPERATION_KEY] = SERVER_NOTIFICATION_CLIENT_ID;
    root[CLIENT_ID_KEY] = clientId;

    message.setData(root);

    toReturn = message.serialize();

    return toReturn;
}

std::string MessageFactory::getCreateMatchNotification(int gameId,int clientIdWhoCreatedGame){
    std::string toReturn;
    Json::Value root(Json::objectValue);
    Message message;

    root[OPERATION_KEY] = SERVER_NOTIFICATION_NEW_MATCH;
    //por el momento id el cliente con su ID, deberia de tener un nombre
    //sino que se  va a mostar en los combos
    root["clientIdWhoCreatedGame"] = clientIdWhoCreatedGame;
    root["mgameIdapId"] = gameId;

    message.setData(root);

    toReturn = message.serialize();

    return toReturn;
}


std::string MessageFactory::getGamesNotification(int clientId,std::string games){
    std::string toReturn;
    Json::Value root(Json::objectValue);
    Message message;

    root[OPERATION_KEY] = CLIENT_REQUEST_GET_MATCHES;
    root["games"] = games;
    root[CLIENT_ID_KEY] = clientId;

    message.setData(root);

    toReturn = message.serialize();

    return toReturn;
}



/* ****************************************************************************
 * NON-GAMING REQUESTS
 * ****************************************************************************
 * */
std::string MessageFactory::getGamesRequest(int clientId){
    std::string toReturn;
    Json::Value root(Json::objectValue);
    Message message;

    root[OPERATION_KEY] = CLIENT_REQUEST_GET_MATCHES;
    root[CLIENT_ID_KEY] = clientId;

    message.setData(root);

    toReturn = message.serialize();

    return toReturn;
}

std::string MessageFactory::getExistingMapsRequest(int clientId){
    std::string toReturn;
    Json::Value root(Json::objectValue);
    Message message;

    root[OPERATION_KEY] = CLIENT_REQUEST_GET_MAPS;
    root[CLIENT_ID_KEY] = clientId;

    message.setData(root);

    toReturn = message.serialize();

    return toReturn;
}

std::string MessageFactory::getExistingMapsNotification() {
    std::string toReturn;
    Message message;

    Json::Value responseRoot(Json::objectValue);

    responseRoot[OPERATION_KEY] = SERVER_NOTIFICATION_GET_MAPS;
    responseRoot["maps"] = Json::arrayValue;
    /* TODO: obtener la data posta... */
    responseRoot["maps"].append("mapa1");
    responseRoot["maps"].append("mapa2");

    message.setData(responseRoot);
    toReturn = message.serialize();

    return toReturn;
}

std::string MessageFactory::getExistingMatchesRequest(int clientId) {
    std::string toReturn;
    Json::Value root(Json::objectValue);
    Message message;

    root[OPERATION_KEY] = CLIENT_REQUEST_GET_MATCHES;
    root[CLIENT_ID_KEY] = clientId;

    message.setData(root);

    toReturn = message.serialize();

    return toReturn;
}

std::string MessageFactory::getExistingMatchesNotification(std::set<std::string> &matches) {
    std::string toReturn;
    Message message;

    Json::Value responseRoot(Json::objectValue);

    responseRoot[OPERATION_KEY] = SERVER_NOTIFICATION_GET_MATCHES;
    responseRoot["matches"] = Json::arrayValue;

    for (const std::string &match : matches) {
        responseRoot["matches"].append(match);
    }

    message.setData(responseRoot);
    toReturn = message.serialize();

    return toReturn;
}

std::string MessageFactory::getCreateMatchRequest(int clientId, std::string mapName){
    std::string toReturn;
    Json::Value root(Json::objectValue);
    Message message;

    root[OPERATION_KEY] = CLIENT_REQUEST_NEW_MATCH;
    root[CLIENT_ID_KEY] = clientId;
    root["mapName"] = mapName;

    message.setData(root);

    toReturn = message.serialize();

    return toReturn;
}

/* ****************************************************************************
 * GAMING REQUESTS
 * ****************************************************************************
 * */
std::string MessageFactory::getPutTowerRequest(int clientId, int x, int y, bool isPut) {
    std::string toReturn;
    Json::Value root(Json::objectValue);
    Message message;

    root[OPERATION_KEY] = CLIENT_REQUEST_PUT_TOWER;
    root[CLIENT_ID_KEY] = clientId;
    root["xCoord"] = x;
    root["yCoord"] = y;
    root["isPut"] = isPut;

    message.setData(root);

    toReturn = message.serialize();

    return toReturn;
}

std::string MessageFactory::getPutTowerNotification(Message &request) {
    Json::Value &root = request.getData();
    std::string toReturn;
    Message message;

    Json::Value responseRoot(root);

    responseRoot[OPERATION_KEY] = SERVER_NOTIFICATION_PUT_TOWER;

    message.setData(responseRoot);
    toReturn = message.serialize();

    return toReturn;
}

std::string MessageFactory::getMarkTileRequest(int clientId, int x, int y, bool isPut) {
    std::string toReturn;
    Json::Value root(Json::objectValue);
    Message message;

    root[OPERATION_KEY] = CLIENT_REQUEST_MARK_TILE;
    root[CLIENT_ID_KEY] = clientId;
    root["xCoord"] = x;
    root["yCoord"] = y;
    root["isMark"] = isPut;

    message.setData(root);

    toReturn = message.serialize();

    return toReturn;
}

std::string MessageFactory::getMarkTileNotification(Message &request) {
    Json::Value &root = request.getData();
    std::string toReturn;
    Message message;

    Json::Value responseRoot(root);

    responseRoot[OPERATION_KEY] = SERVER_NOTIFICATION_MARK_TILE;

    message.setData(responseRoot);
    toReturn = message.serialize();

    return toReturn;
}

std::string MessageFactory::getNewMatchRequest(int clientId, std::string &mapName, std::string &matchName) {
    std::string toReturn;
    Json::Value root(Json::objectValue);
    Message message;

    root[OPERATION_KEY] = CLIENT_REQUEST_NEW_MATCH;
    root[CLIENT_ID_KEY] = clientId;
    root["mapName"] = mapName;
    root["matchName"] = matchName;

    message.setData(root);

    toReturn = message.serialize();

    return toReturn;
}

std::string MessageFactory::getNewMatchNotification(Message &request, std::set<std::string> &matches) {
    Json::Value &root = request.getData();
    std::string toReturn;
    Message message;

    Json::Value responseRoot(root);

    std::string mapName = root["mapName"].asString();
    std::string matchName = root["matchName"].asString();

    std::string composedMatchName;
    composedMatchName.assign(mapName);
    composedMatchName.append(" ");
    composedMatchName.append(matchName);

    if (matches.find(matchName) == matches.end()) {
        matches.insert(matchName);
        responseRoot[OPERATION_KEY] = SERVER_NOTIFICATION_NEW_MATCH;
        responseRoot["mapName"] = mapName;
        responseRoot["matchName"] = matchName;
    } else {
        responseRoot[OPERATION_KEY] = SERVER_NOTIFICATION_NEW_MATCH_ERROR;
        responseRoot["mapName"] = mapName;
        responseRoot["matchName"] = matchName;
        responseRoot["errorDesc"] = "La partida no se puede crear ya que existe otra con ese nombre.";
    }

    message.setData(responseRoot);
    toReturn = message.serialize();

    return toReturn;
}

std::string MessageFactory::getCreateFullMatchNotification(int gameId, int clientId) {
    std::string toReturn;
    Json::Value root(Json::objectValue);
    Message message;

    root[OPERATION_KEY] = SERVER_NOTIFICATION_MATCH_FULL;

    root[CLIENT_ID_KEY] = clientId;
    root["gameId"] = gameId;

    message.setData(root);

    toReturn = message.serialize();

    return toReturn;
}

std::string MessageFactory::getAddPlayerToMatchNotification(int gameId, int clientIdWasAdded) {
    std::string toReturn;
    Json::Value root(Json::objectValue);
    Message message;

    root[OPERATION_KEY] = SERVER_NOTIFICATION_ENTER_EXISTING_GAME;

    root[CLIENT_ID_KEY] = clientIdWasAdded;
    root["gameId"] = gameId;

    message.setData(root);

    toReturn = message.serialize();

    return toReturn;
}

//VER COMO MANEJAR ESTO, SI SE HACE EN DOS PASOS O EN UNO
std::string MessageFactory::getAddPlayerAndRunMatchNotification(int gameID, int clientId) {
    return std::__cxx11::string();
}

int MessageFactory::getClientId(Message &request) {
    Json::Value &root = request.getData();
    int clientId = root[CLIENT_ID_KEY].asInt();
    return clientId;
}

int MessageFactory::getMatchId(Message &request) {
    Json::Value &root = request.getData();
    int matchId = root["matchId"].asInt();
    return matchId;
}

std::string MessageFactory::getClientEndConectionNotification(int clientId) {
    std::string toReturn;
    Json::Value root(Json::objectValue);
    Message message;

    root[OPERATION_KEY] = SERVER_NOTIFICATION_END_CLIENT_CONNECTION;
    root[CLIENT_ID_KEY] = clientId;

    message.setData(root);

    toReturn = message.serialize();

    return toReturn;
}

std::string MessageFactory::getMovementNotification(int moveable, int x, int y, int direction) {
    std::string toReturn;
    Json::Value root(Json::objectValue);
    Message message;

    root[OPERATION_KEY] = SERVER_NOTIFICATION_MOVE_ENEMY;
    root["xCoord"] = x;
    root["yCoord"] = y;
    root["typeOfMoveable"] = moveable;
    root["direction"] = direction;

    message.setData(root);

    toReturn = message.serialize();

    return toReturn;
}

Point MessageFactory::getPoint(Message message) {
    Json::Value &root = message.getData();
    int x = root.get("xCoord","-1").asInt();
    int y = root.get("yCoord","-1").asInt();
    return Point(x,y);
}

int MessageFactory::getDirection(Message message) {
    Json::Value &root = message.getData();
    int direction = root.get("direction","1").asInt();
    return direction;
}
