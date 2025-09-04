cmake_minimum_required(VERSION 3.15)
project(ProjectB LANGUAGES CXX)

# 假设 ProjectA 已安装到系统路径中
find_package(ProjectA REQUIRED PATHS "/usr/local/lib/cmake/ProjectA" NO_DEFAULT_PATH)

add_executable(B main.cpp)

# 链接 ProjectA
target_link_libraries(B PRIVATE A)
