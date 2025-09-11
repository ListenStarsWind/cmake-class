cmake_minimum_required(VERSION 3.18)

project(TestMyMath LANGUAGES CXX)

# 开启测试功能
include(CTest)

# 添加可执行测试文件
add_executable(main main.cpp)

# 查找MaMath库
find_package(MyMath CONFIG REQUIRED)

# 链接MyMath库
target_link_libraries(main PRIVATE MyMath::MyMath)

# 添加测试 到CTest
add_test(NAME TestMyMath COMMAND main)