cmake_minimum_required(VERSION 3.15)
project(ProjectA LANGUAGES CXX)

# 1. 创建一个静态库 A
add_library(A STATIC libA.cpp)

# 2. 模拟一些依赖库
# 这里使用系统库作为例子，或者你可以用其他空库
target_link_libraries(A
    INTERFACE
        m           # 数学库
        pthread     # pthread库
)

# 3. 安装库
install(TARGETS A
        EXPORT ProjectAConfig
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include)

# 4. 安装导出文件，供find_package使用
install(EXPORT ProjectAConfig
        DESTINATION lib/cmake/ProjectA)
