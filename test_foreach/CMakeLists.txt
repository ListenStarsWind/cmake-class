cmake_minimum_required(VERSION 3.18)

project(ForeachDemo)

foreach(X1 "1" "2;3;4" "abc")
    message(STATUS "X1: ${X1}")
endforeach()

foreach(X2 RANGE 9)
    message(STATUS "X2: ${X2}")
endforeach()

foreach(X3 RANGE 10 20 3)
    message(STATUS "X3: ${X3}")
endforeach()

foreach(X4 IN ITEMS "1" "2;3;4" "abc")
    message(STATUS "X4: ${X4}")
endforeach()

set(L1 "1")
set(L2 "2;3;4")
set(L3 "abc")
foreach(X5 IN LISTS L1 L2 L3)
    message(STATUS "X5: ${X5}")
endforeach()

set(i 1)
# 当i <= 5时
while(i LESS_EQUAL 5)
    message(STATUS "i = ${i}")
    math(EXPR i "${i} + 1")   # i++
endwhile()
