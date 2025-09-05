add_library(add STATIC add.cpp)

## 第三方库

# 添加静态库头文件的包含路径 
target_include_directories(add PRIVATE "/usr/local/include/private")
target_include_directories(add PUBLIC "/usr/local/include/public")
target_include_directories(add INTERFACE "/usr/local/include/interface")

# 添加库文件搜索路径
target_link_directories(add PRIVATE "/usr/local/lib/private")
target_link_directories(add PUBLIC "/usr/local/lib/public")
target_link_directories(add INTERFACE "/usr/local/lib/interface")

## 系统库
target_link_libraries(add INTERFACE "pthread")
