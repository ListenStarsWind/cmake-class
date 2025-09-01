# 本项目所需的最低cmake版本
cmake_minimum_required(VERSION 3.18)

# 设置项目名称
project(helloWorld)

# 描述依赖关系及目标文件
add_executable(hello main.cpp)

# 生成测试文件
add_executable(testAdd test.cpp)

# 开启测试功能
include(CTest)

# 简要描述一下单元测试
add_test(
    # 单元测试的名字叫做 Case_Add
    NAME Case_Add

    # 对testAdd这个指令进行测试
    COMMAND testAdd 
)

# 将描述各平台安装目录的定义包含进来
include(GNUInstallDirs)

# 指定需要安装的二进制文件
install(TARGETS hello)

# 启用打包功能
include(CPack)
# 打包会收集我们在install命令中安装的二进制文件, 将其收录到一定的目录结构中, 并压缩到构建目录