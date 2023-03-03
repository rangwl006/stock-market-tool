cmake_minimum_required(VERSION 3.14)

project(TestApplication)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# create folder based on system processor
message("System processor: ${CMAKE_SYSTEM_PROCESSOR}")
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install/${CMAKE_SYSTEM_PROCESSOR})

# add cpm for dependency libraries
set(CPM_DOWNLOAD_VERSION 0.34.0)

if(CPM_SOURCE_CACHE)
  set(CPM_DOWNLOAD_LOCATION "${CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
elseif(DEFINED ENV{CPM_SOURCE_CACHE})
  set(CPM_DOWNLOAD_LOCATION "$ENV{CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
else()
  set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
endif()

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
  message(STATUS "Downloading CPM.cmake to ${CPM_DOWNLOAD_LOCATION}")
  file(DOWNLOAD
       https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake
       ${CPM_DOWNLOAD_LOCATION}
  )
endif()

include(${CPM_DOWNLOAD_LOCATION})

# download dependencies
CPMAddPackage("gh:catchorg/Catch2@3.3.1")

# add subdirectories
add_subdirectory(src)
add_subdirectory(test)
