cmake_minimum_required(VERSION 3.20)
project(stock_market_analyzer)
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

### include curl package ###
FetchContent_Declare(
        embedded_curl
        GIT_REPOSITORY https://github.com/curl/curl
        GIT_TAG curl-7_78_0)

FetchContent_GetProperties(embedded_curl)
if(NOT embedded_curl_POPULATED)
    FetchContent_Populate(embedded_curl)
endif()

set(HTTP_ONLY ON CACHE BOOL "" FORCE)
set(ENABLE_MANUAL OFF CACHE BOOL "" FORCE)
set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
set(BUILD_CURL_EXE OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

if(MSVC AND USE_STATIC_CRT)
    set(CURL_STATIC_CRT ON CACHE BOOL "" FORCE)
endif()

if(WIN32)
    set(CMAKE_USE_SCHANNEL ON CACHE BOOL "" FORCE)
    set(CURL_CA_PATH "none" CACHE STRING "" FORCE)
    set(CURL_CA_BUNDLE "none" CACHE STRING "" FORCE)
endif()

if(UNIX AND NOT APPLE)
    set(CMAKE_USE_OPENSSL ON CACHE BOOL "" FORCE)
    set(CURL_CA_PATH "auto" CACHE STRING "" FORCE)
    set(CURL_CA_BUNDLE "auto" CACHE STRING "" FORCE)
endif()

### include json package
FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.10.3
)

FetchContent_GetProperties(nlohmann_json)
if(NOT json_POPULATED)
    FetchContent_Populate(nlohmann_json)
    add_subdirectory(${nlohmann_json_SOURCE_DIR} ${nlohmann_json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

### include spdlog
FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.9.2
)

### include yaml-cpp
FetchContent_Declare(
        yaml-cpp
        GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
        GIT_TAG yaml-cpp-0.7.0
)

FetchContent_MakeAvailable(nlohmann_json spdlog yaml-cpp)

add_subdirectory(${embedded_curl_SOURCE_DIR} ${embedded_curl_BINARY_DIR})
add_subdirectory(src)

add_executable(${PROJECT_NAME} main.cpp src/modules/yfinance/yfinance.cpp include/modules/yfinance/yfinance.h)
target_link_libraries(${PROJECT_NAME} PUBLIC libcurl Downloader EodDataApi YFinanceApi)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
target_include_directories(${PROJECT_NAME} PRIVATE ${CURL_SOURCE_DIR}/include)


