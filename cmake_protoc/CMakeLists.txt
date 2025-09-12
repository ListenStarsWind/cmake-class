cmake_minimum_required(VERSION 3.18)

project(ProtocExample LANGUAGES CXX)

# 规定C++标准
set(CMAKE_CXX_STANDARD 11)

# 查找Protobuf库, 为proto的使用奠定基础: 包含需要用到的库文件/头文件
# 最低版本3.0
find_package(Protobuf 3.0 REQUIRED)

# 收集proto元消息文件
file(GLOB PROTO_FILES ${CMAKE_CURRENT_SOURCE_DIR}/proto/*.proto)

# 将来存放所有头文件 源文件全名称的集合
set(GEN_SRCS "") # *.pb.cc
set(GEN_HEADS "") # *.pb.h

# 创建proto的C++代码生成目录
set(PB_CPP_OUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/gen/cpp)
file(MAKE_DIRECTORY ${PB_CPP_OUT_DIR})

# 对PROTO_FILES下的所有文件进行循环操作
foreach(FILE ${PROTO_FILES})  # 将其中的每个文件取出, 用FILE指代
    # 获取原始文件中不带扩展名的基础名, 为将来生成的C++代码文件提供命名依据
    get_filename_component(BASE_NAME ${FILE} NAME_WE) # 如果原始文件是person.proto, 将把person取出放到BASE_NAME中

    # 将单个头文件源文件全名称追加到文件集合中
    list(APPEND GEN_SRCS "${PB_CPP_OUT_DIR}/${BASE_NAME}.pb.cc")
    list(APPEND GEN_HEADS "${PB_CPP_OUT_DIR}/${BASE_NAME}.pb.h")

    # 生成C++代码文件

    # 添加自定义指令
    add_custom_command(
        OUTPUT "${PB_CPP_OUT_DIR}/${BASE_NAME}.pb.cc" "${PB_CPP_OUT_DIR}/${BASE_NAME}.pb.h" # 指令输出文件, 将这些文件注册金cmake文件管理器
        COMMAND protoc # 使用外部命令行工具protoc
        ARGS --cpp_out=${PB_CPP_OUT_DIR} # 调用外部工具时的参数 输出cpp文件到指定目录下
            -I ${CMAKE_CURRENT_SOURCE_DIR}/proto # 告知protoc原始文件的搜索路径
            ${FILE} # protoc的操作文件
        DEPENDS ${FILE} # 自定义指令仅依赖于原始文件FILE
        COMMENT echo "从proto生成对应的C++代码"
        VERBATIM # 该指令不需要进行拆分优化, 保证搜索路径可以被正常传递
    )
    
endforeach()

# 添加自定义目标, 依赖于GEN_SRCS和GEN_HEADS两个文件集合
add_custom_target(generate_protobuf DEPENDS ${GEN_SRCS} ${GEN_HEADS})

# 配置阶段, 也就是cmake.. 阶段, cmake会执行foreach这个循环体, 它会把理应存在的文件全名称写入到GEN_SRCS和GEN_HEADS这两个文件集合中
# 并且, 由于cmake在自定义指令中发现将会生成某些文件, 于是也会将这些文件注册到自己的文件管理系统中, 并依据自定义指令, 为这些文件生成
# 对应的构建命令

# 而在构建阶段, 当试图构建自定义目标generate_protobuf时, cmake会读取两个文件集合中的文件信息, 并借助于自己的文件管理系统去寻找文件
# 文件管理器会发现文件是不存在的, 但在之前的注册信息中发现;了对应的生成方式, 于是文件管理器将这些文件构建指令交给cmake的其它相关组件
# 进行指令执行, 从而生成所需文件, 满足自定义目标的构建要求


# 将proto 生成的C++文件编译为静态库, 以方便它们作为一个整体供下游使用管理
add_library(MyPrto STATIC ${GEN_SRCS})
# cmake的普通目标不会通过文件管理器找文件, 也就是不能触发自动构建, 因此需要显示写明, 依赖于特定目标进行间接触发
add_dependencies(MyPrto generate_protobuf)
# 要求下游包含对应头文件
target_include_directories(MyPrto INTERFACE ${PB_CPP_OUT_DIR})
# 生成的C++源文件和头文件并不是完全自实现的, 它们还依赖于官方protobuf的相应文件
target_link_libraries(MyPrto PUBLIC protobuf::libprotobuf)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE MyPrto)