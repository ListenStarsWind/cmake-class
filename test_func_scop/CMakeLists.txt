cmake_minimum_required(VERSION 3.18)

project(FunctionScopDemo)

# 自定义并初始化变量
set(SCOP "Directory Scop")

# 函数定义
function(f)
    # 读取上级作用域变量
    message("func: ${SCOP}")
    # 修改变量
    set(SCOP "Function Scop" PARENT_SCOPE)
    message("func: ${SCOP}")
endfunction(f)

# 函数调用
f()

message("dir: ${SCOP}")
