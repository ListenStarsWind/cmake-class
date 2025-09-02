# 搜集文件列表
file(GLOB SRC_LISTS "*.cpp")

# 构建目标
add_executable(main ${SRC_LISTS})

# 添加链接库列表
target_link_libraries(main PRIVATE MyMath)

set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
