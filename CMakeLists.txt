cmake_minimum_required(VERSION 3.2)

project(cmake-project-template)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -ggdb -g3 -fno-omit-frame-pointer -std=c++17 -Wall")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(DIVISIBLE_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(DIVISIBLE_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(DIVISIBLE_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)
set(RAPIDJSON_INCLUDES ${PROJECT_SOURCE_DIR}/module/rapidjson/include/)
set(DIVISION_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/division)

include_directories(${DIVISIBLE_INSTALL_INCLUDE_DIR})
include_directories(${DIVISION_HEADERS_DIR})
include_directories(${RAPIDJSON_INCLUDES})

add_subdirectory(src)
add_subdirectory(test)


