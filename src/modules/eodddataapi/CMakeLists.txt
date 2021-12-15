add_library(EodDataApi EODDataAPI.cpp)
target_include_directories(EodDataApi PUBLIC
                                    ${PROJECT_SOURCE_DIR}/include/modules/downloader
                                    ${PROJECT_SOURCE_DIR}/include/modules/eoddataapi)
target_link_libraries(EodDataApi PUBLIC libcurl Downloader)
target_link_libraries(EodDataApi PRIVATE nlohmann_json::nlohmann_json)

