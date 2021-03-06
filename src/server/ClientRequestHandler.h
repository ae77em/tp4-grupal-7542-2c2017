#ifndef SERVER_CLIENT_REQUEST_HANDLER_H
#define SERVER_CLIENT_REQUEST_HANDLER_H

#include "Thread.h"
#include "Socket.h"
#include "Message.h"
#include "ThreadedQueue.h"
#include <string>

class ClientRequestHandler : public Thread {
private:
    char op;
    Socket* client;
    ThreadedQueue<Message>& queueSharedMessage;

public:
    explicit ClientRequestHandler(Socket* client, ThreadedQueue<Message> &th);

    void run();
    void sendData(std::string data);

private:
    ClientRequestHandler() = delete;
    ClientRequestHandler(const ClientRequestHandler& orig) = delete;

    void sendClientId();
};

#endif /* SERVER_CLIENT_REQUEST_HANDLER_H */

