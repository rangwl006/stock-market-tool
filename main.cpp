#include <iostream>
#include <memory>
#include <string>
#include <curl/curl.h>
#include "EODDataAPI.h"
#include <nlohmann/json.hpp>
#include "yfinance.h"
#include <yaml-cpp/yaml.h>

int main()
{
    /*
     * e.setUrl("https://query2.finance.yahoo.com/v10/finance/quoteSummary/AAPL?modules=assetProfile%2CsummaryProfile"
              "%2CsummaryDetail%2CesgScores%2Cprice%2CincomeStatementHistory%2CincomeStatementHistoryQuarterly%2CbalanceSheetHistory%2CbalanceSheetHistoryQuarterly%2CcashflowStatementHistory%2CcashflowStatementHistoryQuarterly%2CdefaultKeyStatistics%2CfinancialData%2CcalendarEvents%2CsecFilings%2CrecommendationTrend%2CupgradeDowngradeHistory%2CinstitutionOwnership%2CfundOwnership%2CmajorDirectHolders%2CmajorHoldersBreakdown%2CinsiderTransactions%2CinsiderHolders%2CnetSharePurchaseActivity%2Cearnings%2CearningsHistory%2CearningsTrend%2CindustryTrend%2CindexTrend%2CsectorTrend");
    */
//    EODDataAPI eod;
//    auto x = eod.getFetchedData().dump(eod.format.indent);
//    std::cout << x;

//    YahooFinanceApiHelper y;
//    auto config = y.readConfig("C:\\Users\\rangw\\Documents\\stock-market-analyzer\\resource\\yfinance\\cfg.yaml");
//
//    for(auto field : config["fields"])
//    {
//        std::cout << field.first << std::endl;
//    }

//    YahooFinanceApiHelper y;
//    y.parseConfigFile("/home/russell/Documents/stock-market-tool/resource/yfinance/cfg.yaml");
//    std::cout << y.generateFundamentalDataUrl("AAPL");

    YahooFinanceApi y2;
    y2.parseConfigFile("/home/russell/Documents/stock-market-tool/resource/yfinance/cfg.yaml");
    y2.getFundamentalData("TSLA");
    return 0;
}
