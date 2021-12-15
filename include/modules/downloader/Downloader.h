//
// Created by rangw on 3/12/2021.
//

#pragma once

#include <string>
#include <memory>
#include <functional>
#include <curl/curl.h>

using std::string;

std::size_t dataHandler(const char *buffer, std::size_t size, std::size_t nmemb, std::string *data);

class Downloader {

private:

    constexpr static auto deleter = [](CURL* c)
    {
        curl_easy_cleanup(c);
        curl_global_cleanup();
    };

    std::unique_ptr<CURL, std::function<void(CURL*)>> curlptr;
    std::string m_data;

public:

    Downloader();
    ~Downloader();
    void setUrl(string url);
    void registerWriteDataCallback(void* functor);
    CURLcode fetch();
    std::string getFetchedData();
};