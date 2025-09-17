cmake_minimum_required(VERSION 3.18)

project(ListDemo)

# 创建列表 如果用;分隔就不要再带空格了, 否则会解析错误
set(SRCS "main.cpp;utils.cpp;math.cpp")

# 添加新项
list(APPEND SRCS "network.cpp")
message(STATUS "add: ${SRCS}")

# 移除元素
list(REMOVE_ITEM SRCS "math.cpp")
message(STATUS "remove: ${SRCS}")

# 排序
list(SORT SRCS)
message(STATUS "sort: ${SRCS}")

# 遍历列表
foreach(file ${SRCS})
    message(STATUS "file: ${file}")
endforeach()

# 求长度
list(LENGTH SRCS LEN)
message(STATUS "len: ${LEN}")