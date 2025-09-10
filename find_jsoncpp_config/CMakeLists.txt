cmake_minimum_required(VERSION 3.18)

project(JsoncppDemo LANGUAGES CXX)

# 使用C++11标准
set(CMAKE_CXX_STANDARD 11)

# REQUIRED找不到直接退出
find_package(jsoncpp CONFIG REQUIRED)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE jsoncpp_lib)
