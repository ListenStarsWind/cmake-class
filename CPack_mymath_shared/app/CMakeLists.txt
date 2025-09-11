# 搜集文件列表
file(GLOB SRC_LISTS "*.cpp")

# 构建目标
add_executable(main ${SRC_LISTS})

# 添加链接库列表
target_link_libraries(main PRIVATE MyMath)

set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    # 添加构件时rpath
    BUILD_RPATH ${CMAKE_BINARY_DIR}/lib
    # 添加运行时rpath
    INSTALL_RPATH "\$ORIGIN/../lib" # ORIGIN是程序所在目录, 再向上以及就可以找到库目录, 这在构建和安装期都是成立的
)

install(TARGETS main)
