// HttpResponse.h
#pragma once

#include <string>
#include <map>

class HttpResponse {
public:
    HttpResponse(int statusCode, const std::map<std::string, std::string>& headers, const std::string& body);

    int getStatusCode() const;
    const std::map<std::string, std::string>& getHeaders() const;
    const std::string& getBody() const;

private:
    int statusCode_;
    std::map<std::string, std::string> headers_;
    std::string body_;
};
