/* A TextMessage flows through the network as a fixed-length prefix,
 * and a variable-length tail.
 *
 * The prefix is a ten-character, fixed-width, zero padded decimal
 * representation of the length of the tail.
 */

#include "Socket.h"
#include <string>

#ifndef TEXTMESSAGE_H
#define TEXTMESSAGE_H

static const int MESSAGE_PREFIX_LENGTH = 11;

class TextMessage {
    std::string message;

public:
    TextMessage(std::string message);
    void sendTo(Socket &sock);
    TextMessage receiveFrom(Socket &sock);

    const std::string& getMessage();
};


#endif
