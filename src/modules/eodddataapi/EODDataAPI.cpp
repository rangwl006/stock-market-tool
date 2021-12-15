//
// Created by rangw on 7/12/2021.
//

#include "EODDataAPI.h"

EODDataAPI::EODDataAPI()
{
    dataDownloader.setUrl(m_testUrl);
}

json EODDataAPI::getFetchedData(std::string ticker)
{
    dataDownloader.setUrl(ticker);
    return json();
}

json EODDataAPI::getFetchedData()
{
    dataDownloader.fetch();

    return json::parse(dataDownloader.getFetchedData());
}
