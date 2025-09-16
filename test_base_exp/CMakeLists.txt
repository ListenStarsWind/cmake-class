cmake_minimum_required(VERSION 3.18)

project(IfBasicExprDemo)

# 常量真
if(ON)
    message("ON: true")
else()
    message("ON: false")
endif()

# 常量真
if(1)
    message("1: true")
else()
    message("1: false")
endif()

# 常量假
if(0)
    message("0: true")
else()
    message("0: false")
endif()

# 常量假
if(OFF)
    message("OFF: true")
else()
    message("OFF: false")
endif()

# 常量真
if(1.1)
    message("1.1: true")
else()
    message("1.1: false")
endif()

# 常量假
if(MYPATH-NOTFOUND)
    message("MYPATH-NOTFOUND: true")
else()
    message("MYPATH-NOTFOUND: false")
endif()

# 字符串
if("rabbit")
    message("\"rabbit\": true")
else()
    message("\"rabbit\": false")
endif()

# 字面量为非假常量的变量
set(FOOD "carrot")
if(FOOD)
    message("FOOD(carrot): true")
else()
    message("FOOD(carrot): false")
endif()

set(QUESTION "IGNORE")
if(QUESTION)
    message("QUESTION(IGNORE): true")
else()
    message("QUESTION(IGNORE): false")
endif()

# 字符串
if("TRUE")
    message("\"TRUE\": true")
else()
    message("\"TRUE\": false")
endif()

# 环境变量
if($ENV{LOGNAME})
    message("LOGNAME: true")
else()
    message("LOGNAME: false")
endif()

# !
if(NOT NO)
    message("NOT NO: true")
else()
    message("NOT NO: false")
endif()

# &&
if("on" AND "off")
    message("\"on\" AND \"off\": true")
else()
    message("\"on\" AND \"off\": false")
endif()

# ||
if("on" OR "off")
    message("\"on\" OR \"off\": true")
else()
    message("\"on\" OR \"off\": false")
endif()

# 是否存在这种指令
if(COMMAND project)
    message("COMMAND project: true")
else()
    message("COMMAND project: false")
endif()

if(COMMAND ls)
    message("COMMAND ls: true")
else()
    message("COMMAND ls: false")
endif()

# 是否存在这样的目标
add_library(MyMath INTERFACE IMPORTED)
if(TARGET MyMath)
    message("TARGET MyMath: true")
else()
    message("TARGET MyMath: false")
endif()

# 是否定义这种变量

## 普通变量
if(DEFINED NAME)
    message("DEFINED NAME: true")
else()
    message("DEFINED NAME: false")
endif()

if(DEFINED FOOD)
    message("DEFINED FOOD: true")
else()
    message("DEFINED FOOD: false")
endif()

## 缓存变量
set(NAME "wind" CACHE STRING "name")
if(DEFINED NAME)
    message("DEFINED NAME: true")
else()
    message("DEFINED NAME: false")
endif()

## 环境变量
if(DEFINED ENV{PATH})
    message("DEFINED ENV{PATH}: true")
else()
    message("DEFINED ENV{PATH}: false")
endif()

# 是否存在这样的文件或目录, 并可读
if(EXISTS ${CMAKE_CURRENT_LIST_FILE})
    message([==[EXISTS ${CMAKE_CURRENT_LIST_FILE}: true]==])  # 这种写法是让它不要解引用[==[...]==]
else()
    message([==[EXISTS ${CMAKE_CURRENT_LIST_FILE}: false]==])
endif()

if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/main.cpp)
    message([==[EXISTS ${CMAKE_CURRENT_LIST_DIR}/main.cpp: true]==])
else()
    message([==[EXISTS ${CMAKE_CURRENT_LIST_DIR}/main.cpp: false]==])
endif()

# 空路径视为假
if(EXISTS "")
    message("EXISTS \"\": true")
else()
    message("EXISTS \"\": false")
endif()

# 不支持相对路径, 未定义行为
if(EXISTS "./CMakeLists.txt")
    message("EXISTS \"./CMakeLists.txt\": true")
else()
    message("EXISTS \"./CMakeLists.txt\": false")
endif()

# 给定字符串是否与正则表达式匹配
if(google MATCHES goo+gle)
    message("google MATCHES goo+gle: true")
else()
    message("google MATCHES goo+gle: false")
endif()

# a < b ?  按照实数大小进行比较
if("20" LESS "30")
    message("\"20\" LESS \"30\": true")
else()
    message("\"20\" LESS \"30\": false")
endif()

# a > b ?
if("1" GREATER "0")
    message("\"1\" GREATER \"0\": true")
else()
    message("\"1\" GREATER \"0\": false")
endif()

# a < b ? 按照字典序大小比较
if("abc" STRLESS "abd")
    message("\"abc\" STRLESS \"abd\": true")
else()
    message("\"abc\" STRLESS \"abd\": false")
endif()    

# a < b ? 
if("found" STRGREATER "eaten")
    message("\"found\" STRGREATER \"eaten\": true")
else()
    message("\"found\" STRGREATER \"eaten\": false")
endif()    

# 版本号的比较

## 客户端的应用版本
set(VERSION "1.2.8")

## 比1.3.0小, 说明是老版本, 有些功能不支持
if(VERSION VERSION_LESS "1.3.0")
    message("VERSION VERSION_LESS \"1.3.0\": true")
else()
    message("VERSION VERSION_LESS \"1.3.0\": false")
endif()