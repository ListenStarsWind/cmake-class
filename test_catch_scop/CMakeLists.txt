cmake_minimum_required(VERSION 3.18)

project(CatchScopDemo)

set(OS "linux" CACHE STRING "os name" FORCE)

# message("OS: ${OS}")
message("OS: $CACHE{OS}")