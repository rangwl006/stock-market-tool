//
// Created by rangw on 10/12/2021.
//

#include "yfinance.h"

void YahooFinanceApiHelper::parseConfigFile(std::string yFinanceConfigFilePath, YAML::Node &configs)
{
    configs = YAML::LoadFile(yFinanceConfigFilePath);
}

void YahooFinanceApiHelper::showConfigs()
{
    std::cout << "###### Configuration ######" << std::endl;
    std::cout << configs;
}

std::string YahooFinanceApiHelper::generateFundementalDataUrl(std::string ticker)
{
    std::ostream urlSstream;
    for(auto&& param : configs)
    {
        if(param.second == true)

    }
}

std::string YahooFinanceApiHelper::generateHistoricalPriceDataUrl(std::string ticker)
{
}

std::string YahooFinanceApiHelper::generateUrl()
{
    std::string output;

    return output;
}

YahooFinanceApi::YahooFinanceApi():
    downloader(std::make_unique<Downloader>())
{
}

void YahooFinanceApi::getTickerInfo(std::string ticker)
{

}
