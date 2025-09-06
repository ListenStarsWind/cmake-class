# 新建一个变量, 用于指代源文件, 作用范围只在本文件中
file(GLOB SRC_LISTS "src/*.cpp")

# 使用源文件生成静态库MyMath
add_library(MyMath STATIC ${SRC_LISTS})

# 告诉cmake对于目标MyMath, 从哪里找到头文件
target_include_directories(MyMath
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include
)

# 修改默认输出路径
set_target_properties(MyMath PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)
