#include <microhttpd.h>
#include <cstring>
#include <iostream>

#include "WebSocketRoute.h"
#include "Server.h"

class WebSocketContext
{
public:
    WebSocketContext(WebSocketRoute &route, int socket) : route(route), socket(socket) {}

    WebSocketRoute &route;
    int socket;
};

int WebSocketHandler(void *cls, struct MHD_Connection *connection, void **socket_context,
                     enum MHD_WebSocketEvent event, const char *data, size_t size)
{
    WebSocketContext *context = reinterpret_cast<WebSocketContext *>(*socket_context);
    switch (event)
    {
    case MHD_WEBSOCKET_EVENT_ESTABLISHED:
        context = new WebSocketContext(*reinterpret_cast<WebSocketRoute *>(cls), *reinterpret_cast<int *>(socket_context));
        *socket_context = context;
        break;
    case MHD_WEBSOCKET_EVENT_DATA:
        context->route.handleWebSocketRequest(context->socket, data, size);
        break;
    case MHD_WEBSOCKET_EVENT_CLOSED:
        delete context;
        *socket_context = nullptr;
        break;
    default:
        break;
    }

    return MHD_YES;
}
