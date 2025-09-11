file(GLOB SRC_LISTS "src/*.cpp")

# 使用源文件生成静态库MyMath
add_library(MyMath SHARED ${SRC_LISTS})

# 告诉cmake对于目标MyMath, 从哪里找到头文件
target_include_directories(MyMath PUBLIC
    # 构建阶段, 就以源代码上的头文件做包含路径
    "$<BUILD_INTERFACE:>${CMAKE_CURRENT_SOURCE_DIR}/include"
    # 安装阶段, 就以本地安装目录为准, 可以直接简写为include
    "#<INSTALL_INTERFACE:include>"
)

# 修改默认输出路径
set_target_properties(MyMath PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    OUTPUT_NAME MyMath
    VERSION 1.2.3
    SOVERSION 20
)

# 安装库文件
install(TARGETS MyMath)

# 安装头文件
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)
