cmake_minimum_required(VERSION 3.18)

project(DirectScopDemo)

set(SCOP "Parent Scop")

add_subdirectory(src)

message("main: ${SCOP}")