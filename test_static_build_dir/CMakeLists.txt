cmake_minimum_required(VERSION 3.18)

project(TestMyMath)

# 因为cmake是顺序执行, 所以必须先构建静态库再生成可执行程序
add_subdirectory(my_lib)
add_subdirectory(app)