//
// Created by rangw on 10/12/2021.
//

#include "yfinance.h"

void YahooFinanceApiHelper::parseConfigFile(std::string yFinanceConfigFilePath)
{
    configs = YAML::LoadFile(yFinanceConfigFilePath);
}

void YahooFinanceApiHelper::showConfigs()
{
    std::cout << "###### Configuration ######" << std::endl;
    std::cout << configs;
}

std::string YahooFinanceApiHelper::getFundamentalDataUrl(std::string ticker)
{
    return generateFundamentalDataUrl(ticker);
}

std::string YahooFinanceApiHelper::generateFundamentalDataUrl(std::string ticker)
{
    std::stringstream urlStream;

    urlStream << configs["data_type"]["fundamental"][0].as<std::string>()
              << ticker
              << configs["data_type"]["fundamental"][1].as<std::string>();


    for(auto&& field : configs["fundamental_data_field"])
    {
        if(field.second.as<bool>() == true)
        {
            urlStream << field.first.as<std::string>()
                      << "%2c";
        }
    }
    return urlStream.str();

}

std::string YahooFinanceApiHelper::generateHistoricalPriceDataUrl(std::string ticker)
{
    return ticker;
}

YahooFinanceApi::YahooFinanceApi():
    downloader(std::make_unique<Downloader>())
{
}

void YahooFinanceApi::getFundamentalData(std::string ticker)
{
    std::string url = getFundamentalDataUrl(ticker);
    std::cout << url << std::endl;
    downloader->setUrl(url);
    downloader->fetch();
    auto data = json::parse(downloader->getFetchedData()).dump(4);
    std::cout << data;

}


