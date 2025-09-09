# 收集源代码
file(GLOB SRC_LISTS "src/*.cpp")

# 添加构建目录
add_library(MyMath SHARED ${SRC_LISTS})

# 描述使用时的头文件寻找参考目录
target_include_directories(MyMath INTERFACE 
    # 使用生成器表达式描述路径 是cmake将目标安装后的include目录
    # 也就是 usr/local/include
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
    # 安装后头文件实际存在的位置是 usr/local/include/MyMath
    # 也就是说包含时是include(MyMath/XXX.h) 
    # 所以target_include_directories描述的不是头文件根目录, 而是参考目录
    # 这样做是为了形成类似命名域的形式, 防止冲突
)

# 设置库的输出目录
set_target_properties(MyMath PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    OUTPUT_NAME MyMath
    VERSION 1.2.3
    SOVERSION 20
)

# 安装动态库
include(GNUInstallDirs)

# 对目标MyMath安装:
install(TARGETS MyMath
    # 导出集合 : 是一个描述目标各类属性的集合, 其中的信息由cmake自己跟踪维护, 无需手动设置
    EXPORT MyMathTargets
    # 安装的目的地: 库文件安装目录  /usr/local/lib
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# 安装头文件
install(DIRECTORY include/
    # 安装到 usr/local/include/MyMath
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/MyMath
    # 只将 include/ 下符合规则 "*.h"的文件安装
    FILES_MATCHING PATTERN "*.h" 
)

# 将导出集合导出 到 构建树(构建目录)
export(EXPORT MyMathTargets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/MyMathTargets.cmake
)

# 安装导出集合 到 安装树(安装目录)
install(EXPORT MyMathTargets
    FILE MyMathTargets.cmake
    # 定义动态库命名域
    NAMESPACE MyMath::
    # 安装到  usr/local/lib/cmake/MyMath
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MyMath
)

# 生成find_package需要的配置文件
include(CMakePackageConfigHelpers)
# 使用自定义模版进行生成
configure_package_config_file(
    # 描述模版路径
    ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/MyMathConfig.cmake
    # 描述在何处可以找到这个脚本
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/MyMath"
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/MyMathConfig.cmake
    # 将脚本安装到指定目录
    DESTINATION "lib/cmake/MyMath"
)
