// RestClient.cpp
#include "http_client.h"
#include <curl/curl.h>
#include <string>
#include <iostream>
#include "Constants/status_codes.h"

/*
Things TODO:: Check on how to handle Headers on curl and send back
*/

using namespace std;

CURL *curl;

RestClient::RestClient() {
    // Initialize any necessary settings
    curl = curl_easy_init();
}

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

HttpResponse RestClient::get(const HttpRequest& request) {
    // Implement GET request logic
    if (curl){
        curl_easy_setopt(curl, CURLOPT_URL, request.getUrl());
        string responseData;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseData);

        CURLcode response = curl_easy_perform(curl);

        if (response != CURLE_OK){
            return HttpResponse(StatusCodes::STATUS_CODE_500_ERR, request.getHeaders(), "REST API Error");
        }
        else{
            return HttpResponse(StatusCodes::STATUS_CODE_200_OK, request.getHeaders(), responseData);
        }
        curl_easy_cleanup(curl);
    }
    else {
        cerr<<"Curl was not initalized properly"<<endl;
        return HttpResponse(StatusCodes::STATUS_CODE_500_ERR, request.getHeaders(), "REST API Error");
    }
}

HttpResponse RestClient::post(const HttpRequest& request) {
    // Implement POST request logic
    if (curl){
        curl_easy_setopt(curl, CURLOPT_URL, request.getUrl());

        // SET the POST data
        const string postData = request.getBody();
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData);


        string responseData;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseData);

        CURLcode response = curl_easy_perform(curl);

        if (response != CURLE_OK){
            return HttpResponse(StatusCodes::STATUS_CODE_500_ERR, request.getHeaders(), "REST API Error");
        }
        else{
            return HttpResponse(StatusCodes::STATUS_CODE_201_CREATED, request.getHeaders(), responseData);
        }
        curl_easy_cleanup(curl);

    }
    else {
        cerr<<"Curl was not initalized properly"<<endl;
        return HttpResponse(StatusCodes::STATUS_CODE_500_ERR, request.getHeaders(), "REST API Error");
    }

}

HttpResponse RestClient::put(const HttpRequest& request) {
    // Implement PUT request logic
}

HttpResponse RestClient::del(const HttpRequest& request) {
    // Implement DELETE request logic
}
