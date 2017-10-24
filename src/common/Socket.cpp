#include "Socket.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <memory.h>
#include <iostream>
#include <string>
#include <stdexcept>

#define TRON
#include "tron.h"

Socket::Socket() {
    this->socket = ::socket(AF_INET, SOCK_STREAM, 0);
    const int en = errno;

    // TODO: este error seria mas util con el output de strerror en lugar del
    // codigo de error. strerror no es thread safe y strerror_r viene en dos
    // versiones, la disponibilidad de las mismas variando con el sistema
    // operativo y el compilador usado.
    if (this->socket == -1) throw std::runtime_error("No se pudo crear"
            " el socket. errno: " + std::to_string(en));
}

Socket::Socket(int socket) {
    this->socket = socket;
}

Socket::Socket(Socket &&other) {
    this->socket = other.socket;
    other.socket = -1;
}

Socket::~Socket() {
    TRACE("cerrando socket fd: " + std::to_string(socket) + "\n");
    close();
}

void Socket::bind(unsigned short port) {
    int bind_result = 0;
    struct sockaddr_in addr;

    memset((char *) &addr, 0, sizeof (addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind_result = ::bind(this->socket,
            (struct sockaddr *) &addr,
            (socklen_t)sizeof (struct sockaddr));
    const int en = errno;

    if (bind_result < 0) throw std::runtime_error("No se pudo bindear"
            " el socket en el puerto " + std::to_string(port) + ". errno: "
            + std::to_string(en));
}

void Socket::listen(unsigned short n) {
    int listen_status = ::listen(this->socket, n);
    const int en = errno;

    if (listen_status < 0) throw std::runtime_error("No se pudo escuchar"
            " del socket. errno: " + std::to_string(en));
}

void Socket::listen() {
    listen(1);
}

void Socket::connect(const char* host_name, unsigned short port) {
    struct hostent *he;

    if ((he = ::gethostbyname(host_name)) == NULL) {
        extern h_errno;
        const int en = h_errno;
        throw std::runtime_error("No se pudo obtener la direccion del host "
                + std::string(host_name) + ", errno: " + std::to_string(en));
    } else {
        struct sockaddr_in their_addr;
        int conn_status;

        their_addr.sin_family = AF_INET; // orden de bytes de la máquina
        their_addr.sin_port = htons(port); // short, orden de bytes de la red
        their_addr.sin_addr = *((struct in_addr *) he->h_addr_list[0]);
        memset(&(their_addr.sin_zero), 8, sizeof (int)); // poner a 0 el resto

        conn_status = ::connect(
                this->socket,
                (struct sockaddr *) &their_addr,
                sizeof (struct sockaddr));
        const int en = errno;

        if (conn_status == -1) throw std::runtime_error("No se pudo conectar"
                " el socket. errno: " + std::to_string(en) + " host: "
                + std::string(host_name) + " port: " + std::to_string(port));
    }
}

int Socket::accept() {
    int newsockfd;

    newsockfd = ::accept(this->socket, NULL, NULL);
    const int en = errno;

    if (newsockfd < 0) throw std::runtime_error("No se pudo aceptar del socket."
            " errno: " + std::to_string(en));

    return newsockfd;
}

void Socket::send(const char* buffer, size_t length) {
    int sent = 0;
    int s = 0;
    bool is_open_socket = true;

    while (sent < (int) length && is_open_socket) {
        s = ::send(this->socket,
                &buffer[sent],
                length - sent,
                MSG_NOSIGNAL);
        const int en = errno;

        if (s == 0) {
            is_open_socket = false;
        } else if (s < 0) {
            throw std::runtime_error("Fallo la escritura al socket."
                   " fd: " + std::to_string(get_socket()) + " errno: "
                    + std::to_string(en) + " se intentaron enviar "
                    + std::to_string(length) + " bytes, se enviaron "
                    + std::to_string(sent) + " bytes exitosamente");
        } else {
            sent += s;
        }
    }
}

int Socket::receive(char* buffer, size_t length) {
    int received = 0;
    int r = 0;
    bool is_open_socket = true;

    while (received < (int) length && is_open_socket) {
        r = ::recv(this->socket,
                &buffer[received],
                length - received,
                MSG_NOSIGNAL);
        const int en = errno;

        if (r == 0) {
            is_open_socket = false;
        } else if (r < 0) {
            throw std::runtime_error("Fallo la lectura del socket. errno: "
                    + std::to_string(en) + " se intentaron leer "
                    + std::to_string(length) + " bytes, se leyeron "
                    + std::to_string(received) + " bytes exitosamente");
        } else {
            received += r;
        }
    }

    return received;
}

void Socket::shutdown() {
    if (this->socket >= 0) {
        ::shutdown(this->socket, SHUT_RDWR);
    }
}

void Socket::close() {
    if (this->socket >= 0) {
        ::close(this->socket);
    }
}

void Socket::shutdown_send() {
    ::shutdown(this->socket, SHUT_WR);
}

int Socket::get_socket() {
    return this->socket;
}

int Socket::set_socket(int s) {
    this->socket = s;
    return this->socket;
}
