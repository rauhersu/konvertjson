cmake_minimum_required(VERSION 3.2)
project(konvertjson_tests)

add_subdirectory(lib/googletest)

include_directories(${KONVERTJSON_HEADERS_DIR})
include_directories(lib/googletest/googletest/include)

set(SOURCE_FILES main.cpp src/divider_tests.cpp)

add_executable(divider_tests ${SOURCE_FILES})
target_link_libraries(divider_tests division gtest)
install(TARGETS divider_tests DESTINATION bin)

