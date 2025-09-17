cmake_minimum_required(VERSION 3.18)

project(FunctionDemo)

function(print_args first second)
    message(STATUS "ARGC: ${ARGC}") # 实参个数
    message(STATUS "ARGV: ${ARGV}") # 实参列表, 实际上就是分号隔开的字符串

    math(EXPR end "${ARGC} - 1")    # 打印实参列表中的各个项
    foreach(i RANGE ${end})
        message(STATUS "ARGV${i}: ${ARGV${i}}")
    endforeach()

    message(STATUS "ARGN: ${ARGN}")
endfunction()

print_args(A B C D E)


function(sum x y)
    math(EXPR RESULT "${x} + ${y}")
    set(LOCAL_SUM ${RESULT})                            # 局部变量
    set(OUTPUT_SUM ${RESULT} PARENT_SCOPE)              # 父级作用域变量
    set(CACHE_SUM ${RESULT} CACHE STRING "result")      # 缓存变量
endfunction()

sum(3 5)

message(STATUS "LOCAL_SUM: ${LOCAL_SUM}")
message(STATUS "OUTPUT_SUM: ${OUTPUT_SUM}")
message(STATUS "CACHE_SUM: $CACHE{CACHE_SUM}")