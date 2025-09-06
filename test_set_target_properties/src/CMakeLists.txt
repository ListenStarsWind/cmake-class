# 这次我们使用动态库
add_library(add SHARED add.cpp)

# 添加编译选项
target_compile_options(add PRIVATE -g -O3 -fPIC)

set_target_properties(add PROPERTIES

        ## 目标属性

            # 编译属性
                INCLUDE_DIRECTORIES "/public"
                INTERFACE_INCLUDE_DIRECTORIES "/interface"

            # 链接属性
                LINK_DIRECTORIES "/public"
                INTERFACE_LINK_DIRECTORIES "/interface"
                LINK_LIBRARIES "curl"
                INTERFACE_LINK_LIBRARIES "jsoncpp"             # sudo apt install libjsoncpp-dev

            # 输出属性
                RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
                ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"

            BUILD_RPATH "${CMAKE_BINARY_DIR}/lib"  # 为项目中的动态库文件临时链接提供方案, 这样就不需要将其安装到系统中

        ## 安装属性
            # 库在安装到系统后, BUILD_RPATH就会失效, 转而使用系统的安装路径
            INSTALL_RPATH "lib" #  实际上就是/usr/local/lib
            OUTPUT_NAME "add"
            VERSION "1.2.3"
            SOVERSION "20"      #  动态库的兼容版本, 描述库中所提供接口执行的标准, 为用户提供一种简便的验证接口是否还可用的方式
)

