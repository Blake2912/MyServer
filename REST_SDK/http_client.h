// RestClient.h
#pragma once

#include "http_request.h"
#include "http_response.h"

class RestClient {
public:
    RestClient();

    HttpResponse get(const HttpRequest& request);
    HttpResponse post(const HttpRequest& request);
    HttpResponse put(const HttpRequest& request);
    HttpResponse del(const HttpRequest& request);

private:
    // Add any necessary private methods or members
};
