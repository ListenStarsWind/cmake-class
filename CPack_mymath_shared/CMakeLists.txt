cmake_minimum_required(VERSION 3.18)

project(TestMyMath)

add_subdirectory(my_lib)

add_subdirectory(app)

# 要放在顶层最后一行, 否则收集文件可能不全
include(CPack)