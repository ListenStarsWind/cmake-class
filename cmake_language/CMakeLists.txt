cmake_minimum_required(VERSION 3.18)

project(MessageDemo)

message("begin " "CMakeLists.txt")

message(STATUS "123")

# message(WARNING "this is a WARNING")
# message(SEND_ERROR "this is a SEND_ERROR")
message(FATAL_ERROR "this is a FATAL_ERROR")

message("end " "CMakeLists.txt")