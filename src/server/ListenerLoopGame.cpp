#include <iostream>
#include "ListenerLoopGame.h"
#include "Request.h"
#include "../common/MessageFactory.h"
#include "../common/Protocol.h"

ListenerLoopGame::ListenerLoopGame(std::list<GameAction *> &a,
                                   std::mutex &m,
                                   ThreadedQueue<Message> &q,
                                    bool& end) :
        actions(a),
        mutexActions(m),
        queueMessagesGame(q),
        endSignal(end){

}

void ListenerLoopGame::run() {
    std::cout << "ListenerLoopGame: "
            "Hilo de sincronizacion de partida arrancando" << std::endl;

    try {
        while (!queueMessagesGame.isAtEnd()) {
            std::cout << "ListenerLoopGame: "
                    "Llego un request de partida" << std::endl;

            Message messageRequest = queueMessagesGame.pop();
            std::string response;

            Request request(messageRequest);
            //hago switch para identificar el tipo de action a aplicar
            // sobre el game loop
            switch (request.getAsInt(OPERATION_KEY)) {
                case GAME_REQUEST_PUT_TOWER: {
                    std::string x = request.getAsString(XCOORD_KEY);
                    std::string y = request.getAsString(YCOORD_KEY);

                    std::cout << "me llego request para poner torre en ("
                            << x << ", " << y << ")..." << std::endl;

                    break;
                }
                case GAME_REQUEST_CAST_SPELL: {
                    std::string x = request.getAsString(XCOORD_KEY);
                    std::string y = request.getAsString(YCOORD_KEY);

                    std::cout << "me llego request para lanzar hechizo torre en ("
                              << x << ", " << y << ")..." << std::endl;

                    break;
                }
                case GAME_REQUEST_TOWER_INFO: {
                    std::string towerId = request.getAsString("towerId");

                    std::cout << "me llego request de info de torre "
                              << towerId << std::endl;

                    break;
                }
                case GAME_REQUEST_UPGRADE_TOWER: {
                    std::string towerId = request.getAsString("towerId");
                    std::string upgradeId = request.getAsString("upgradeId");

                    std::cout << "me llego request de upgrade de torre "
                              << towerId << std::endl;

                    break;
                }
            }

            mutexActions.lock();
            //actions.push_back(new SpecificAction);
            mutexActions.unlock();
        }
    } catch (std::exception) {
        std::cout << "ListenerLoopGame: se rompio cola compartida de acitons"
                  << std::endl;
    }

    //nose si esta parte sirve,
    mutexActions.lock();
    endSignal = true;
    mutexActions.unlock();
    std::cout << "ListenerLoopGame: Se murio" << std::endl;
}