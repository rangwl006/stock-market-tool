add_library(statistics MovingAverage.cpp)
message("CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
target_include_directories(statistics PUBLIC ${CMAKE_SOURCE_DIR}/inc/modules/utils/statistics)