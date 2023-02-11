#include "Server.h"
#include "WebSocketRoute.h"
#include <microhttpd.h>
#include <cstring>
#include <iostream>

struct MHD_Daemon *Server::start(int port, WebSocketRoute *route)
{
    auto *daemon = MHD_start_daemon(
        MHD_USE_THREAD_PER_CONNECTION | MHD_USE_DEBUG,
        port,
        nullptr,
        nullptr,
        &Server::handleRequest,
        route,
        MHD_OPTION_END);
    if (daemon == nullptr)
    {
        std::cerr << "Failed to start daemon" << std::endl;
    }
    return daemon;
}

int Server::handleRequest(
    void *cls, MHD_Connection *connection, const char *url, const char *method, const char *version,
    const char *upload_data, size_t *upload_data_size, void **con_cls)
{
    auto *route = static_cast<WebSocketRoute *>(cls);

    if (strcmp(method, MHD_HTTP_METHOD_GET) == 0)
    {
        return route->handleGetRequest(connection, url);
    }
    else if (strcmp(method, MHD_HTTP_METHOD_POST) == 0)
    {
        return route->handlePostRequest(connection, url, upload_data, upload_data_size);
    }
    else if (strcmp(method, MHD_HTTP_METHOD_WEBSOCKET) == 0)
    {
        return route->handleWebSocketRequest(connection);
    }
    return MHD_NO;
}
