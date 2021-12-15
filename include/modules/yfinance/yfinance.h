#pragma once

#include <yaml-cpp/yaml.h>
#include <Downloader.h>
#include <iostream>
#include <sstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

/*
 * @about YahooFinanceApiHelper
 * This class provides the supports functions for YahooFinanceApi class
 */
class YahooFinanceApiHelper
{
public:
    enum DataType
    {
        price,
        fundamentals
    };

    std::string getFundamentalDataUrl(std::string ticker);
    void parseConfigFile(std::string yFinanceConfigFilePath);

protected:

    void showConfigs();
    std::string generateFundamentalDataUrl(std::string ticker);
    std::string generateHistoricalPriceDataUrl(std::string ticker);

    YAML::Node configs;
};

class YahooFinanceApi: public YahooFinanceApiHelper
{
public:
    YahooFinanceApi();
    ~YahooFinanceApi() = default;

    void getFundamentalData(std::string ticker);
    void getPriceHistory(std::string ticker);
    
private:
    std::unique_ptr<Downloader> downloader;
};

