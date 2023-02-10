#ifndef RESPONSE_H
#define RESPONSE_H

#include <string>
#include <unordered_map>

struct MHD_Connection;

class Response
{
public:
    Response(MHD_Connection *connection) : connection_(connection), status_(0) {}

    MHD_Connection *connection() const { return connection_; }
    int status() const { return status_; }
    const std::unordered_map<std::string, std::string> &headers() const { return headers_; }
    const std::string &body() const { return body_; }

    void setStatus(int status) { status_ = status; }
    void addHeader(const std::string &name, const std::string &value) { headers_[name] = value; }
    void setBody(const std::string &body) { body_ = body; }

private:
    MHD_Connection *connection_;
    int status_;
    std::unordered_map<std::string, std::string> headers_;
    std::string body_;
};

#endif
