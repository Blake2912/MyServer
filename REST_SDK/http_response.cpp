// HttpResponse.cpp
#include "http_response.h"

HttpResponse::HttpResponse(int statusCode, const std::map<std::string, std::string>& headers, const std::string& body)
    : statusCode_(statusCode), headers_(headers), body_(body) {}

int HttpResponse::getStatusCode() const {
    return statusCode_;
}

const std::map<std::string, std::string>& HttpResponse::getHeaders() const {
    return headers_;
}

const std::string& HttpResponse::getBody() const {
    return body_;
}
