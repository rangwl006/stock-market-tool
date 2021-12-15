#pragma once

#include <yaml-cpp/yaml.h>
#include <Downloader.h>
#include <iostream>
#include <sstream>

/*
 * @about YahooFinanceApiHelper
 * This class provides the supports functions for YahooFinanceApi class
 */
class YahooFinanceApiHelper
{
public:
    YahooFinanceApiHelper() = default;
    ~YahooFinanceApiHelper() = default;

    enum DataType
    {
        price,
        fundementals
    };

protected:
    void parseConfigFile(std::string yFinanceConfigFilePath, YAML::Node& configs);
    void showConfigs();
    std::string generateFundementalDataUrl(std::string ticker);
    std::string generateHistoricalPriceDataUrl(std::string ticker);
    YAML::Node configs;
};

class YahooFinanceApi: protected YahooFinanceApiHelper
{
public:
    YahooFinanceApi();
    ~YahooFinanceApi() = default;

    void getFundementalData(std::string ticker);
    void getPriceHistory(std::string ticker);
private:
    std::unique_ptr<Downloader> downloader;
};


#endif //STOCK_MARKET_ANALYZER_YFINANCE_H
