// HttpRequest.cpp
#include "http_request.h"

HttpRequest::HttpRequest(const std::string& url, const std::string& method)
    : url_(url), method_(method) {}

void HttpRequest::addHeader(const std::string& key, const std::string& value) {
    headers_[key] = value;
}

void HttpRequest::setBody(const std::string& body) {
    body_ = body;
}

const std::string& HttpRequest::getUrl() const {
    return url_;
}

const std::string& HttpRequest::getMethod() const {
    return method_;
}

const std::map<std::string, std::string>& HttpRequest::getHeaders() const {
    return headers_;
}

const std::string& HttpRequest::getBody() const {
    return body_;
}
