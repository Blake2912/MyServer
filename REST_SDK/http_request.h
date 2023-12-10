#pragma once
#include <string>
#include <map>

using namespace std;

class HttpRequest {
    public:
        HttpRequest(const std::string& url, const std::string& method);
        void addHeader(const std::string& key, const std::string& value);
        void setBody(const std::string& body);

        const std::string& getUrl() const;
        const std::string& getMethod() const;
        const std::map<std::string, std::string>& getHeaders() const;
        const std::string& getBody() const;
    
    private:
        string url_;
        string method_;
        map<std::string, std::string> headers_;
        string body_;

};