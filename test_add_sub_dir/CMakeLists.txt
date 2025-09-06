cmake_minimum_required(VERSION 3.18)

project(TestInclude)

add_executable(test test.cpp)

include(GNUInstallDirs)
install(TARGETS test)

message(STATUS "from top-level CMakeLists.txt")

# 打印源代码目录
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

# 生成构建目录
message(STATUS "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")

# 打印当前执行cmake脚本的完整名称
message(STATUS "CMAKE_CURRENT_LIST_FILE: ${CMAKE_CURRENT_LIST_FILE}")

# 打印当前执行cmake脚本的完整目录
message(STATUS "CMAKE_CURRENT_LIST_DIR: ${CMAKE_CURRENT_LIST_DIR}")

# 添加子目录
add_subdirectory(sub)
