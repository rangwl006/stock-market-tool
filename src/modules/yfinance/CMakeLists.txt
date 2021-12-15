add_library(YFinanceApi yfinance.cpp)
target_include_directories(YFinanceApi PUBLIC
                                    ${PROJECT_SOURCE_DIR}/include/modules/downloader
                                    ${PROJECT_SOURCE_DIR}/include/modules/yfinance)
target_link_libraries(YFinanceApi PUBLIC libcurl yaml-cpp Downloader)
target_link_libraries(YFinanceApi PRIVATE nlohmann_json::nlohmann_json spdlog::spdlog_header_only)

