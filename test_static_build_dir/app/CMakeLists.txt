# 搜集文件列表
file(GLOB SRC_LISTS "*.cpp")

# 构建目标
add_executable(main ${SRC_LISTS})

# 添加链接库列表
target_link_libraries(main PRIVATE MyMath)

set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# 输出静态库路径
add_custom_command(                                             # 添加自定义命令
    TARGET main POST_BUILD                                      # 在目标main生成后执行
    COMMAND echo "输出静态库的全路径"                               
    COMMAND ${CMAKE_COMMAND} -E echo "$<TARGET_FILE:MyMath>"    # CMAKE_COMMAND是cmake指令的安装路径, 打印目标MyMath的生成路径
)