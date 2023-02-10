#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <unordered_map>

class Request
{
public:
    Request() {}
    Request(const std::unordered_map<std::string, std::string> &headers, const std::string &body)
        : headers_(headers), body_(body) {}

    const std::unordered_map<std::string, std::string> &headers() const { return headers_; }
    const std::string &body() const { return body_; }

private:
    std::unordered_map<std::string, std::string> headers_;
    std::string body_;
};

#endif
