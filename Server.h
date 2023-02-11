#ifndef SERVER_H
#define SERVER_H

#include <unordered_map>
#include <string>

class Request;
class Route;
class WebSocketRoute;

class Server
{
public:
    Server();
    ~Server();

    void addRoute(const std::string &path, Route *route);
    void addWebSocketRoute(const std::string &path, WebSocketRoute *route);
    int start();

private:
    struct Impl;
    Impl *impl_;
};

#endif
