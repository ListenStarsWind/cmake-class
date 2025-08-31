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
## 第二章

下面, 我们介绍使用cmake系列命令行工具进行项目构建的完整流程

![image-20250831173609218](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250831173609218.png)

1.  编写项目源代码和`CMakeLists.txt`文件
2. `cmake`依据`CMakeLists.txt`生成对应的`makefile`文件(或者是其它平台的相应文件), 格式是`cmake ../ -G  ""`
3. `makefile`通过调用编译器和连接器生成二进制目标文件
4. 对生成的二进制文件使用`ctest`进行测试
5. 将通过测试的二进制文件在项目组里本地共享使用
6. 将整个大的项目分发的网络中创造价值, 主要使用`cpack`进行打包分发

在[官方文档](https://cmake.org/cmake/help/latest/index.html)中, 我们看到, cmake系统共有三个命令行工具, 它们分别是`cmake  ctest  cpack`. 

`cmake`是`cmake`系列的核心工具, 负责构建系统的生成, 编译链接, 本地安装它还含有若干模式, 比如"命令行模式", "脚本模式". `ctest`和`cpack`的职责就比较单一, 单纯是测试和打包分发.

我们可以使用`cmake --help`来查看`cmake`的帮助视图

在最开头, 我们就可以看到`cmake`的三个使用方法

```shell
cmake [options] <path-to-source>
cmake [options] <path-to-existing-build>
cmake [options] -S <path-to-source> -B <path-to-build>
```

第一个指令, `cmake [options] <path-to-source>`是从无到有的进行系统构建, 比如我们上面用的`cmake ..`
第二个指令, `cmake [options] <path-to-existing-build>`是在构建系统已经生成完毕的情况下, 在`CMakeLists.txt`的部分配置修改后, 对构建系统进行刷新, 就字面形式来说, 它的格式其实和第一个指令是相同的, 不过路径稍有不同, 第一个指令下`build`是空的, 所以是`cmake ..`, 第二个指令`build`目录已经不是空的了, 它其中有一些文件就已经指明了`CMkeLists.txt`的所在路径, 所以虽然还是在`build`里, 但所给的路径是构建目录的`.`而不是源文件目录`..`
第三个指令也是从无到有的系统构建, 区别是它显式写明了源文件所在路径和生成路径, 在语法形式上更加清晰.

接下来是`cmake --build <dir> [<options>] [-- <build-tool-options>]`, 它其实就是`makefile`, 在构建系统生成的前提下, 生成目标二进制文件. 当然其它平台不是`makefile`, `cmake --build`无疑具有cmake的跨平台性.

`cmake --install <dir> [<options>]`是把cmake项目的可执行文件安装到系统中, 由于现在没有具体的应用场景, 我们就先不细说了, 接下来的实践操作再细说.

`cmake [-D <var>=<value>]... -P <cmake-script-file>` 和 `cmake -E <command> [<options>]`分别是脚本和命令行模式, 具体也是之后再说.

`ctest cpack`等遇到实际场景再说, 下面我们就以上面的`hello world`, 来演绎一遍完整的流程.

--------

使用`cmake`进行项目构建, 有两种做法, 它们分别叫做"源内构建"和"源外构建"两种, "源"指的是源代码, 内, 外描述的的`cmake`生成的文件是否和源文件混在一起, 其实, 在上面中, 我们用的就是源外构建, 我们在源代码和`CMakeLists.txt`的所在目录中又建立一个名为"build"的目录, 然后, 把`cmake`生成的文件都放在`build`子文件夹中, 实际上, 我们也可以把`build`放到源目录(即源代码和`CMakeLists.txt`所在的目录)之上的目录, 这其实也是一种源外构建.    源内构建则把`cmake`生成的文件和源文件混在一起, 这样不方便进行管理, 而且当想要重新生成一些文件时, 由于这些文件和源文件混在一起, 就容易误删源文件,这不太安全, 项目结构会显得乱糟糟的, 也不方便进行定位查询.

```shell
[wind@Ubuntu hello_world]$ ls
build  CMakeLists.txt  main.cpp
[wind@Ubuntu hello_world]$ cd build
[wind@Ubuntu build]$ ls
CMakeCache.txt  CMakeFiles  cmake_install.cmake  hello  Makefile
[wind@Ubuntu build]$ cd ..
[wind@Ubuntu hello_world]$ # 把build放上级目录也是源外构建
[wind@Ubuntu hello_world]$ rm -rf build
[wind@Ubuntu hello_world]$ ls
CMakeLists.txt  main.cpp
[wind@Ubuntu hello_world]$ cd ..
[wind@Ubuntu cmakeClass]$ mkdir build
[wind@Ubuntu cmakeClass]$ cd build
[wind@Ubuntu build]$ cmake ../hello_world
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
-- Build files have been written to: /home/wind/cmakeClass/build
[wind@Ubuntu build]$ ls
CMakeCache.txt  CMakeFiles  cmake_install.cmake  Makefile
[wind@Ubuntu build]$ make
[ 50%] Building CXX object CMakeFiles/hello.dir/main.cpp.o
[100%] Linking CXX executable hello
[100%] Built target hello
[wind@Ubuntu build]$ ./hello
hello world!
[wind@Ubuntu build]$ cd ..
[wind@Ubuntu cmakeClass]$ rm -rf build
[wind@Ubuntu cmakeClass]$ # 拷贝一份新项目做源内构建
[wind@Ubuntu cmakeClass]$ cp -rf ./hello_world ./hello_world_backup
[wind@Ubuntu cmakeClass]$ cd hello_world_backup
[wind@Ubuntu hello_world_backup]$ ls
CMakeLists.txt  main.cpp
[wind@Ubuntu hello_world_backup]$ cmake .
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
-- Build files have been written to: /home/wind/cmakeClass/hello_world_backup
[wind@Ubuntu hello_world_backup]$ ls
CMakeCache.txt  CMakeFiles  cmake_install.cmake  CMakeLists.txt  main.cpp  Makefile
[wind@Ubuntu hello_world_backup]$ make
[ 50%] Building CXX object CMakeFiles/hello.dir/main.cpp.o
[100%] Linking CXX executable hello
[100%] Built target hello
[wind@Ubuntu hello_world_backup]$ ls
CMakeCache.txt  CMakeFiles  cmake_install.cmake  CMakeLists.txt  hello  main.cpp  Makefile
[wind@Ubuntu hello_world_backup]$ cd ..
[wind@Ubuntu cmakeClass]$ rm -rf hello_world_backup
[wind@Ubuntu cmakeClass]$
```

关于源目录和构建目录

```shell
[wind@Ubuntu cmakeClass]$ cd hello_world
[wind@Ubuntu hello_world]$ mkdir build && cd build
[wind@Ubuntu build]$ cmake
Usage

  cmake [options] <path-to-source>
  cmake [options] <path-to-existing-build>
  cmake [options] -S <path-to-source> -B <path-to-build>

Specify a source directory to (re-)generate a build system for it in the
current working directory.  Specify an existing build directory to
re-generate its build system.

Run 'cmake --help' for more information.

[wind@Ubuntu build]$ # cmake [options] -S <path-to-source> -B <path-to-build>
[wind@Ubuntu build]$ # -S 是源文件目录， 即源代码和CMakeLists.txt所在的目录
[wind@Ubuntu build]$ # -B 是构建目录, 即cmake所生成的哪些构建文件所在的目录
[wind@Ubuntu build]$ ls
[wind@Ubuntu build]$ cmake -S .. -B .
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
[wind@Ubuntu build]$ 
```

假如我们对原来的`CMakeLists.txt`进行了略微修改, 现在要重新刷新一下构建目录, 此时我们就可以使用`cmake <path-to-build>`来进行刷新.

```shell
[wind@Ubuntu build]$ cmake .
-- Configuring done
-- Generating done
-- Build files have been written to: /home/wind/cmakeClass/hello_world/build
[wind@Ubuntu build]$ # 这里我实际没改, 可能现象略有不同
[wind@Ubuntu build]$ # 在build目录中, 有一些缓存文件, 比如CMakeCache.txt, 其内部存放着CMakeLists.txt的绝对路径, 因此, 当执行cmake . 时, cmake就可以通过这些缓存文件找到CMakeList.txt, 从而重新读取并刷新
[wind@Ubuntu build]$ cat CMakeCache.txt | head -306 | tail -3
//Source directory with the top level CMakeLists.txt file for this
// project
CMAKE_HOME_DIRECTORY:INTERNAL=/home/wind/cmakeClass/hello_world
[wind@Ubuntu build]$ ls /home/wind/cmakeClass/hello_world
build  CMakeLists.txt  main.cpp
[wind@Ubuntu build]$ 
```

在构建文件生成后, 那就要生成二进制目标文件了. 对于二进制目标文件的生成, 有两种方式, 一是`make`, 二是`cmake --build`, 我们更推荐`cmake --build`, 很明显, 它是`cmake`支持的, 所以具有跨平台性.而`make`当然就只能在`Linux`上运行. 另外, `make clean`对应`cmake --build <path-to-build> --target clean`.

```shell
[wind@Ubuntu build]$ ls
CMakeCache.txt  CMakeFiles  cmake_install.cmake  Makefile
[wind@Ubuntu build]$ make
[ 50%] Building CXX object CMakeFiles/hello.dir/main.cpp.o
[100%] Linking CXX executable hello
[100%] Built target hello
[wind@Ubuntu build]$ ./hello
hello world!
[wind@Ubuntu build]$ make clean
[wind@Ubuntu build]$ ls
CMakeCache.txt  CMakeFiles  cmake_install.cmake  Makefile
[wind@Ubuntu build]$ cmake --build .
[ 50%] Building CXX object CMakeFiles/hello.dir/main.cpp.o
[100%] Linking CXX executable hello
[100%] Built target hello
[wind@Ubuntu build]$ ./hello
hello world!
[wind@Ubuntu build]$ cmake --build . --target clean
[wind@Ubuntu build]$ ls
CMakeCache.txt  CMakeFiles  cmake_install.cmake  Makefile
[wind@Ubuntu build]$ 
```

---

使用`cmake --build`, 会调用各自平台的项目构建工具, 对于`Linux`来说, 使用的就是`make`, 在`cmake`的实际配置中, `cmake`会调用`gmake`, `gamke`是个软链接, 一种虚拟层, 它会依据实际的平台情况, 将`gmake`链接到对应的项目工具中

```shell
wind@Ubuntu build]$ cat CMakeCache.txt | head -110 | tail -2
//Path to a program.
CMAKE_MAKE_PROGRAM:FILEPATH=/usr/bin/gmake
[wind@Ubuntu build]$ ll /usr/bin/gmake
lrwxrwxrwx 1 root root 4 Apr  9  2024 /usr/bin/gmake -> make*
[wind@Ubuntu build]$ 
```

```shell
[wind@Ubuntu build]$ cmake --help | cat -n | head -41 | tail -1
    41    --build <dir>                = Build a CMake-generated project binary tree.
[wind@Ubuntu build]$ # 此处的<dir>就是cmake生成的那个目录, 即构建目录
```

---



  

  

  