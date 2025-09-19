cmake_minimum_required(VERSION 3.18)

project(pkg_confif_json LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. 引入 cmake 中的PkgConfig模块
find_package(PkgConfig REQUIRED)

# 2. 让 pkg-config 搜索 jsoncpp.pc，并⽣成 IMPORTED 目标
#    - JSONCPP     : 这是前缀，用来生成一系列变量 (JSONCPP_INCLUDE_DIRS、…)
#    - REQUIRED    : 找不到就报错并停止配置
#    - IMPORTED_TARGET : 额外创建 PkgConfig::JSONCPP 目标（推荐用法）
pkg_check_modules(JSONCPP REQUIRED IMPORTED_TARGET jsoncpp)

# 3. 添加你的可执行文件 / 库
add_executable(main main.cpp)

# 4. 通过导入目标 PkgConfig::JSONCPP，把所有使用需求一次性传播进来
target_link_libraries(main PRIVATE PkgConfig::JSONCPP)

# 可选：查看自动填充的属性（调试用）
# 读取 PkgConfig::JSONCPP 头文件路径 INTERFACE_INCLUDE_DIRECTORIES
get_target_property(_incs PkgConfig::JSONCPP INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "jsoncpp include dirs = ${_incs}")