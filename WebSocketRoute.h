#ifndef WEBSOCKETROUTE_H
#define WEBSOCKETROUTE_H

#include "Route.h"

#include <unordered_map>
#include <string>

struct MHD_Connection;

class WebSocketRoute : public Route
{
public:
    virtual ~WebSocketRoute() {}

    virtual void handleWebSocketRequest(int socket) = 0;
    virtual void onConnect(MHD_Connection *connection) = 0;
    virtual void onMessage(MHD_Connection *connection, const std::string &message) = 0;
    virtual void onClose(MHD_Connection *connection, enum MHD_RequestTerminationCode toe) = 0;
};

#endif
