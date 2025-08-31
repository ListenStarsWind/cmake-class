# camek

## 第一章

- 初识cmake

  cmake是一个跨平台的项目构建工具, 支持当前的主流开发平台, 它抹平了各平台上的种种差异, 使得开发者可以将更多的精力投入到实际的项目开发中, 提高了开发效率, 同时其语法简单, 信息密度高, 因而被越来越多的公司所采纳.

  我们所使用的开发环境是 vs code ssh + Ubuntu , 对于Ununtu来说, 我们可以使用

  ```bash
  sudo apt install cmake
  ```

  来安装cmake 工具, 并且再在code上安装`CMake   CMake IntelliSence   CMake Language Suppor   CMake Tools`这四个插件

  cmake项目的结构如下

  ```shell
  [wind@Ubuntu hello_world]$ tree .
  .
  ├── build
  │   ├── CMakeCache.txt
  │   ├── CMakeFiles
  │   │   ├── 3.22.1
  │   │   │   ├── CMakeCCompiler.cmake
  │   │   │   ├── CMakeCXXCompiler.cmake
  │   │   │   ├── CMakeDetermineCompilerABI_C.bin
  │   │   │   ├── CMakeDetermineCompilerABI_CXX.bin
  │   │   │   ├── CMakeSystem.cmake
  │   │   │   ├── CompilerIdC
  │   │   │   │   ├── a.out
  │   │   │   │   ├── CMakeCCompilerId.c
  │   │   │   │   └── tmp
  │   │   │   └── CompilerIdCXX
  │   │   │       ├── a.out
  │   │   │       ├── CMakeCXXCompilerId.cpp
  │   │   │       └── tmp
  │   │   ├── cmake.check_cache
  │   │   ├── CMakeDirectoryInformation.cmake
  │   │   ├── CMakeOutput.log
  │   │   ├── CMakeTmp
  │   │   ├── hello.dir
  │   │   │   ├── build.make
  │   │   │   ├── cmake_clean.cmake
  │   │   │   ├── compiler_depend.make
  │   │   │   ├── compiler_depend.ts
  │   │   │   ├── DependInfo.cmake
  │   │   │   ├── depend.make
  │   │   │   ├── flags.make
  │   │   │   ├── link.txt
  │   │   │   ├── main.cpp.o
  │   │   │   ├── main.cpp.o.d
  │   │   │   └── progress.make
  │   │   ├── Makefile2
  │   │   ├── Makefile.cmake
  │   │   ├── progress.marks
  │   │   └── TargetDirectories.txt
  │   ├── cmake_install.cmake
  │   ├── hello
  │   └── Makefile
  ├── CMakeLists.txt
  └── main.cpp
  
  9 directories, 33 files
  [wind@Ubuntu hello_world]$ 
  ```

  其中 `CMakeLists.txt`和`main.cpp`就分别是项目的cmake配置文件和源代码, 我们会专门创建一个`build`文件夹, 将cmake的生成内容存放在该文件夹下, 便于统一管理(项目清理就是删除`build`下的内容), 然后我们进入`build`文件夹, 执行`cmake ..`, `cmake`会在其后面所跟的目录寻找`CMakeLists.txt`, 构建项目.

  最基础的`CMakeLists.txt`包括三个内容

  ```cmake
  # 本项目所需的最低cmake版本
  cmake_minimum_required(VERSION 3.18)
  
  # 设置项目名称
  project(helloWorld)
  
  # 描述依赖关系及目标文件
  add_executable(hello main.cpp)
  
  ```

  下面是相关指令

  ```bash
  [wind@Ubuntu hello_world]$ tree .
  .
  ├── build
  │   ├── CMakeCache.txt
  │   ├── CMakeFiles
  │   │   ├── 3.22.1
  │   │   │   ├── CMakeCCompiler.cmake
  │   │   │   ├── CMakeCXXCompiler.cmake
  │   │   │   ├── CMakeDetermineCompilerABI_C.bin
  │   │   │   ├── CMakeDetermineCompilerABI_CXX.bin
  │   │   │   ├── CMakeSystem.cmake
  │   │   │   ├── CompilerIdC
  │   │   │   │   ├── a.out
  │   │   │   │   ├── CMakeCCompilerId.c
  │   │   │   │   └── tmp
  │   │   │   └── CompilerIdCXX
  │   │   │       ├── a.out
  │   │   │       ├── CMakeCXXCompilerId.cpp
  │   │   │       └── tmp
  │   │   ├── cmake.check_cache
  │   │   ├── CMakeDirectoryInformation.cmake
  │   │   ├── CMakeOutput.log
  │   │   ├── CMakeTmp
  │   │   ├── hello.dir
  │   │   │   ├── build.make
  │   │   │   ├── cmake_clean.cmake
  │   │   │   ├── compiler_depend.make
  │   │   │   ├── compiler_depend.ts
  │   │   │   ├── DependInfo.cmake
  │   │   │   ├── depend.make
  │   │   │   ├── flags.make
  │   │   │   ├── link.txt
  │   │   │   ├── main.cpp.o
  │   │   │   ├── main.cpp.o.d
  │   │   │   └── progress.make
  │   │   ├── Makefile2
  │   │   ├── Makefile.cmake
  │   │   ├── progress.marks
  │   │   └── TargetDirectories.txt
  │   ├── cmake_install.cmake
  │   ├── hello
  │   └── Makefile
  ├── CMakeLists.txt
  └── main.cpp
  
  9 directories, 33 files
  [wind@Ubuntu hello_world]$ rm -rf ./build/*
  [wind@Ubuntu hello_world]$ tree .
  .
  ├── build
  ├── CMakeLists.txt
  └── main.cpp
  
  1 directory, 2 files
  [wind@Ubuntu hello_world]$ cd build
  [wind@Ubuntu build]$ cmake ..
  -- The C compiler identification is GNU 13.3.0
  -- The CXX compiler identification is GNU 13.3.0
  -- Detecting C compiler ABI info
  -- Detecting C compiler ABI info - done
  -- Check for working C compiler: /usr/bin/cc - skipped
  -- Detecting C compile features
  -- Detecting C compile features - done
  -- Detecting CXX compiler ABI info
  -- Detecting CXX compiler ABI info - done
  -- Check for working CXX compiler: /usr/bin/c++ - skipped
  -- Detecting CXX compile features
  -- Detecting CXX compile features - done
  -- Configuring done
  -- Generating done
  -- Build files have been written to: /home/wind/cmakeClass/hello_world/build
  [wind@Ubuntu build]$ tree .
  .
  ├── CMakeCache.txt
  ├── CMakeFiles
  │   ├── 3.22.1
  │   │   ├── CMakeCCompiler.cmake
  │   │   ├── CMakeCXXCompiler.cmake
  │   │   ├── CMakeDetermineCompilerABI_C.bin
  │   │   ├── CMakeDetermineCompilerABI_CXX.bin
  │   │   ├── CMakeSystem.cmake
  │   │   ├── CompilerIdC
  │   │   │   ├── a.out
  │   │   │   ├── CMakeCCompilerId.c
  │   │   │   └── tmp
  │   │   └── CompilerIdCXX
  │   │       ├── a.out
  │   │       ├── CMakeCXXCompilerId.cpp
  │   │       └── tmp
  │   ├── cmake.check_cache
  │   ├── CMakeDirectoryInformation.cmake
  │   ├── CMakeOutput.log
  │   ├── CMakeTmp
  │   ├── hello.dir
  │   │   ├── build.make
  │   │   ├── cmake_clean.cmake
  │   │   ├── compiler_depend.make
  │   │   ├── compiler_depend.ts
  │   │   ├── DependInfo.cmake
  │   │   ├── depend.make
  │   │   ├── flags.make
  │   │   ├── link.txt
  │   │   └── progress.make
  │   ├── Makefile2
  │   ├── Makefile.cmake
  │   ├── progress.marks
  │   └── TargetDirectories.txt
  ├── cmake_install.cmake
  └── Makefile
  
  8 directories, 28 files
  [wind@Ubuntu build]$ make
  [ 50%] Building CXX object CMakeFiles/hello.dir/main.cpp.o
  [100%] Linking CXX executable hello
  [100%] Built target hello
  [wind@Ubuntu build]$ ./hello
  hello world!
  [wind@Ubuntu build]$ 
  ```

  

  

  