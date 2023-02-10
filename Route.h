#ifndef ROUTE_H
#define ROUTE_

#include <string>
#include <unordered_map>

class Request;
class Response;

class Route
{
public:
    virtual ~Route() {}

    virtual void handleRequest(const Request &request, Response &response) = 0;
};

#endif
