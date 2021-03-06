#ifndef TP4_TOWERDEFENSE_SERVER_H
#define TP4_TOWERDEFENSE_SERVER_H

#include <mutex>
#include <vector>
#include <jsoncpp/json/json.h>
#include <unordered_map>
#include <set>
#include "Socket.h"
#include "ThreadedQueue.h"
#include "Thread.h"
#include "TextMessage.h"
#include "Message.h"

#include "ServerPlayer.h"
#include "ServerMatch.h"
#include "Map.h"
#include <map>
#include <string>
#include <list>

class Server : public Thread {
private:
    std::set<std::string> matchesNames;
    std::mutex m;

    std::mutex& mutexPlayers;

    ThreadedQueue<Message>& queueMessagesClient;
    std::map<unsigned int,ServerPlayer*> players;
    std::map<std::string, ServerMatch*> matches;
    std::map<std::string, model::Map> maps;

public:
    Server(std::mutex& m,ThreadedQueue<Message>& tq);

    void run();

    void createGame(int clientId, std::string matchName, std::string string);
    bool createMatch(std::string basicString, std::string string);

    void addPlayerToMatch(std::string nameMatch, ServerPlayer *sp);

    void createAndRunPlayer(Socket* s);

    unsigned int getAmountGames();

    /*
     * Notifica a todos los clientes el mensaje pasado por parámetro.
     * Este método activa el mutexPlayers, y lo libera al terminar.
     * messsage: mensaje que se debe enviar a los clientes.
     * */
    void notifyAll(std::string message);

    /*
     * Agrega un cliente asociado al server.
     * queue: cola encargada de manejar el envío y recepción de datos.
     * */
    void addClient(ThreadedQueue<TextMessage> &queue);

    void loadMaps();

    std::string splitFilename(std::string filename);

private:
    void addPlayerToGame(int clientId,
                         std::string mName,
                         std::list<std::string> elementName);

    void notifyTo(int clientId, std::string &message);

    void removeClient(int id);

    void startMatch(int id, std::string basic_string);

    void sendUnavailableElementsToClient(int clientId, std::string matchName);

    std::vector<std::string> getMatchesNames();

    void notifyPlayerAdded(std::string matchName);

    void markTile(std::string matchName, int x, int y);

    void putTower(std::string matchName, int typeOfTower, int x, int y);

    void castSpell(std::string matchName, int x, int y);

    void upgradeTower(std::string matchName, int clientId, int towerId,
                          int upgradeType);

    void towerInfo(int clientId, std::string matchName, int towerId);

    std::vector<std::string> getAllMapsNames();

    void removePlayerFromMatch(int id);
};

#endif //TP4_TOWERDEFENSE_SERVER_H
