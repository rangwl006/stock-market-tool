add_library(Downloader Downloader.cpp)
target_include_directories(Downloader PUBLIC ${PROJECT_SOURCE_DIR}/include/modules/downloader)
target_link_libraries(Downloader PUBLIC libcurl)
