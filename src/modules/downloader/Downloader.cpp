//
// Created by rangw on 3/12/2021.
//

#include "Downloader.h"

std::size_t dataHandler(const char *buffer, std::size_t size, std::size_t nmemb, std::string *data) {
    if (data == nullptr) {
        return 0;
    }
    data->append(buffer, (size * nmemb));
    return size * nmemb;
};

Downloader::Downloader(): curlptr(curl_easy_init(), deleter)
{
    curl_global_init(CURL_GLOBAL_ALL);
    curl_easy_setopt(curlptr.get(), CURLOPT_WRITEFUNCTION, dataHandler);
    curl_easy_setopt(curlptr.get(), CURLOPT_WRITEDATA, &m_data);

}

Downloader::~Downloader() {

}

void Downloader::setUrl(string url) {
    curl_easy_setopt(curlptr.get(), CURLOPT_URL, url.c_str());
}

CURLcode Downloader::fetch() {
    return curl_easy_perform(curlptr.get());
}

std::string Downloader::getFetchedData() {
    return m_data;
}
