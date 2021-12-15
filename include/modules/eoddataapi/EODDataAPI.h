//
// Created by rangw on 7/12/2021.
//

#pragma once

#include <string>
#include <memory>

#include <nlohmann/json.hpp>
#include <curl/curl.h>

#include "Downloader.h"

using json = nlohmann::json;

struct JsonFormat
{
    int indent = 4;
};

class EODDataAPI
{

private:
    Downloader dataDownloader;
    const std::string m_testUrl = "https://eodhistoricaldata.com/api/fundamentals/AAPL"
                                  ".US?api_token=OeAFFmMliFG5orCUuwAKQ8l4WWFQ67YX";
public:
    EODDataAPI();
    ~EODDataAPI() = default;
    json getFetchedData(std::string ticker);
    json getFetchedData();
    JsonFormat format;

};

