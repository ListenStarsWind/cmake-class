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

下面, 我们说一下测试,

```shell
[wind@Ubuntu hello_world]$ # 首先我们需要有相应的测试代码
[wind@Ubuntu hello_world]$ ls
build  CMakeLists.txt  main.cpp
[wind@Ubuntu hello_world]$ touch test.cpp
[wind@Ubuntu hello_world]$ cat test.cpp
#include<iostream>
#include<cassert>

int main()
{
    assert(1 + 2 == 3);
    std::cout << "test passed!" << std::endl;
    return 0;
}[wind@Ubuntu hello_world]$ cat test.cpp
#include<iostream>
#include<cassert>

int main()
{
    assert(1 + 2 == 3);
    std::cout << "test passed!" << std::endl;
    return 0;
}[wind@Ubuntu hello_world]$ cat test.cpp
#include<iostream>
#include<cassert>

int main()
{
    assert(1 + 2 == 3);
    std::cout << "test passed!" << std::endl;
    return 0;
[wind@Ubuntu hello_world]$ # 随后我们要生成可执行的二进制测试文件
[wind@Ubuntu hello_world]$ cat CMakeLists.txt 
# 本项目所需的最低cmake版本
cmake_minimum_required(VERSION 3.18)

# 设置项目名称
project(helloWorld)

# 描述依赖关系及目标文件
add_executable(hello main.cpp)

[wind@Ubuntu hello_world]$ cat CMakeLists.txt 
# 本项目所需的最低cmake版本
cmake_minimum_required(VERSION 3.18)

# 设置项目名称
project(helloWorld)

# 描述依赖关系及目标文件
add_executable(hello main.cpp)

# 生成测试文件
add_executable(testAdd test.cpp)

# 开启测试功能
include(CTest)

# 简要描述一下单元测试
add_test(
    # 单元测试的名字叫做 Case_Add
    NAME Case_Add

    # 对testAdd这个指令进行测试
    COMMAND testAdd 
)
[wind@Ubuntu hello_world]$ cd build
[wind@Ubuntu build]$ cmake .
-- Configuring done
-- Generating done
-- Build files have been written to: /home/wind/cmakeClass/hello_world/build
[wind@Ubuntu build]$ cmake --build .
[ 25%] Building CXX object CMakeFiles/hello.dir/main.cpp.o
[ 50%] Linking CXX executable hello
[ 50%] Built target hello
[ 75%] Building CXX object CMakeFiles/testAdd.dir/test.cpp.o
[100%] Linking CXX executable testAdd
[100%] Built target testAdd
[wind@Ubuntu build]$ # 使用ctest就可以执行上述名为Case_Add的单元测试
[wind@Ubuntu build]$ ctest
Test project /home/wind/cmakeClass/hello_world/build
    Start 1: Case_Add
1/1 Test #1: Case_Add .........................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.01 sec
[wind@Ubuntu build]$ 与之类似的是make test
与之类似的是make: command not found
[wind@Ubuntu build]$ # 与之类似的make test
[wind@Ubuntu build]$ make test
Running tests...
Test project /home/wind/cmakeClass/hello_world/build
    Start 1: Case_Add
1/1 Test #1: Case_Add .........................   Passed    0.01 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.01 sec
[wind@Ubuntu build]$ # 当有多个单元测试时, 我们需要给ctest指明单元测试的名字, 在此处, 由于只有Case_Add一个, 所以不用指明名字
```

`add_test`的相关内容会在`CTestTestfile.cmake`文件中进行进一步解释, 然后在`makefile`上做进一步的落实

```shell
[wind@Ubuntu build]$ cat CTestTestfile.cmake
# CMake generated Testfile for 
# Source directory: /home/wind/cmakeClass/hello_world
# Build directory: /home/wind/cmakeClass/hello_world/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Case_Add "/home/wind/cmakeClass/hello_world/build/testAdd")
set_tests_properties(Case_Add PROPERTIES  _BACKTRACE_TRIPLES "/home/wind/cmakeClass/hello_world/CMakeLists.txt;17;add_test;/home/wind/cmakeClass/hello_world/CMakeLists.txt;0;")
[wind@Ubuntu build]$ cat makefile | head -72 | tail -5
cat: makefile: No such file or directory
[wind@Ubuntu build]$ cat Makefile | head -72 | tail -5
# Special rule for the target test
test:
        @$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running tests..."
        /usr/bin/ctest --force-new-ctest-process $(ARGS)
.PHONY : test
[wind@Ubuntu build]$ 
```

对于失败的测试来说

```shell
[wind@Ubuntu build]$ cat ../test.cpp
#include<iostream>
#include<cassert>

int main()
{
    assert(1 + 2 == 3);
    assert(1 + 2 == 4);
    std::cout << "test passed!" << std::endl;
    return 0;
}[wind@Ubuntu build]$ cmake --build .
Consolidate compiler generated dependencies of target hello
[ 50%] Built target hello
Consolidate compiler generated dependencies of target testAdd
[ 75%] Building CXX object CMakeFiles/testAdd.dir/test.cpp.o
[100%] Linking CXX executable testAdd
[100%] Built target testAdd
[wind@Ubuntu build]$ ./testAdd
testAdd: /home/wind/cmakeClass/hello_world/test.cpp:7: int main(): Assertion `1 + 2 == 4' failed.
Aborted (core dumped)
[wind@Ubuntu build]$ ctest
Test project /home/wind/cmakeClass/hello_world/build
    Start 1: Case_Add
1/1 Test #1: Case_Add .........................Subprocess aborted***Exception:   1.31 sec

0% tests passed, 1 tests failed out of 1

Total Test time (real) =   1.31 sec

The following tests FAILED:
          1 - Case_Add (Subprocess aborted)
Errors while running CTest
Output from these tests are in: /home/wind/cmakeClass/hello_world/build/Testing/Temporary/LastTest.log
Use "--rerun-failed --output-on-failure" to re-run the failed cases verbosely.
[wind@Ubuntu build]$ cat /home/wind/cmakeClass/hello_world/build/Testing/Temporary/LastTest.log
Start testing: Aug 31 22:39 CST
----------------------------------------------------------
1/1 Testing: Case_Add
1/1 Test: Case_Add
Command: "/home/wind/cmakeClass/hello_world/build/testAdd"
Directory: /home/wind/cmakeClass/hello_world/build
"Case_Add" start time: Aug 31 22:39 CST
Output:
----------------------------------------------------------
testAdd: /home/wind/cmakeClass/hello_world/test.cpp:7: int main(): Assertion `1 + 2 == 4' failed.
<end of output>
Test time =   1.31 sec
----------------------------------------------------------
Test Failed.
"Case_Add" end time: Aug 31 22:39 CST
"Case_Add" time elapsed: 00:00:01
----------------------------------------------------------

End testing: Aug 31 22:39 CST
[wind@Ubuntu build]$ 
```

`ctest`会在指定的目录下生成一份错误日志, 我们可以通过该日志查找错误细节. `ctest`会根据程序的返回值是否正常来判断测试是否通过, 对于异常的返回值, `ctest`就会进行计数统计, 并在最后呈现出来.

---

当单元测试完成之后, 我们就可以将二进制文件在项目组内共享, 让开发组的其他成员将其安装到自己的系统中, 从而进行协同开发.

首先我们依旧是在`CMakeList.txt`中加入新的内容

```shell
[wind@Ubuntu hello_world]$ cat CMakeLists.txt | head -29 | tail -5
# 将描述各平台安装目录的定义包含进来
include(GNUInstallDirs)

# 指定需要安装的二进制文件
install(TARGETS hello)
[wind@Ubuntu hello_world]$ cd build
[wind@Ubuntu build]$ rm -rf ./*
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
[wind@Ubuntu build]$ cmake --build .
[ 25%] Building CXX object CMakeFiles/hello.dir/main.cpp.o
[ 50%] Linking CXX executable hello
[ 50%] Built target hello
[ 75%] Building CXX object CMakeFiles/testAdd.dir/test.cpp.o
[100%] Linking CXX executable testAdd
[100%] Built target testAdd
[wind@Ubuntu build]$ # 因为是安装到系统目录中, 因此需要进行提权
[wind@Ubuntu build]$ sudo cmake --install .
-- Install configuration: ""
-- Installing: /usr/local/bin/hello
[wind@Ubuntu build]$ # 我们看到将其安装到了/usr/local/bin目录下
[wind@Ubuntu build]$ hello
hello world!
[wind@Ubuntu build]$ which hello
/usr/local/bin/hello
[wind@Ubuntu build]$ 
```

```shell
[wind@Ubuntu build]$ # make也有相对应的功能
[wind@Ubuntu build]$ sudo rm /isr/local/bin/hello
rm: cannot remove '/isr/local/bin/hello': No such file or directory
[wind@Ubuntu build]$ sudo rm /usr/local/bin/hello
[wind@Ubuntu build]$ sudo make install
Consolidate compiler generated dependencies of target hello
[ 50%] Built target hello
Consolidate compiler generated dependencies of target testAdd
[100%] Built target testAdd
Install the project...
-- Install configuration: ""
-- Installing: /usr/local/bin/hello
[wind@Ubuntu build]$ hello
hello world!
[wind@Ubuntu build]$ # 在Makefile中, 我们可以看到对应的install指令
[wind@Ubuntu build]$ cat Makefile | head -111 | tail -5
# Special rule for the target install
install: preinstall
        @$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
        /usr/bin/cmake -P cmake_install.cmake
.PHONY : install
[wind@Ubuntu build]$ # 可以看到其实质是让cmake 以脚本模式P 执行脚本cmake_install.cmake
[wind@Ubuntu build]$ # 而在cmake_install.cmake中, 就可以找到安装的核心逻辑
[wind@Ubuntu build]$ cat cmake_install.cmake | head -52 | tail -1
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/wind/cmakeClass/hello_world/build/hello")
[wind@Ubuntu build]$ # 将构建出来的hello文件安装到{CMAKE_INSTALL_PREFIX}/bin中
[wind@Ubuntu build]$ # 而CMAKE_INSTALL_PREFIX则在GNUInstallDirs依据具体平台被定义, 对于Linux来说, 就是/usr/local目录
[wind@Ubuntu build]$ # 在上述的安装中, 我们还生成了文件"install_manifest.txt", 它是一个资源清单, 可以检查安装是否有遗漏
[wind@Ubuntu build]$ cat install_manifest.txt
/usr/local/bin/hello[wind@Ubuntu build]$ 
```

---------

最后一个步骤是打包分发. 首先, 我们依旧需要为`CMakeLists.txt`中增加新的内容, 启动打包功能.

  ```cmake
  # 本项目所需的最低cmake版本
  cmake_minimum_required(VERSION 3.18)
  
  # 设置项目名称
  project(helloWorld)
  
  # 描述依赖关系及目标文件
  add_executable(hello main.cpp)
  
  # 生成测试文件
  add_executable(testAdd test.cpp)
  
  # 开启测试功能
  include(CTest)
  
  # 简要描述一下单元测试
  add_test(
      # 单元测试的名字叫做 Case_Add
      NAME Case_Add
  
      # 对testAdd这个指令进行测试
      COMMAND testAdd 
  )
  
  # 将描述各平台安装目录的定义包含进来
  include(GNUInstallDirs)
  
  # 指定需要安装的二进制文件
  install(TARGETS hello)
  
  # 启用打包功能
  include(CPack)
  # 打包会收集我们在install命令中安装的二进制文件, 将其收录到一定的目录结构中, 并压缩到构建目录
  ```

```shell
[wind@Ubuntu build]$ cmake .
-- Configuring done
-- Generating done
-- Build files have been written to: /home/wind/cmakeClass/hello_world/build
[wind@Ubuntu build]$ cmake --build .
Consolidate compiler generated dependencies of target hello
[ 50%] Built target hello
Consolidate compiler generated dependencies of target testAdd
[100%] Built target testAdd
[wind@Ubuntu build]$ # 不过此时若是直接执行cpack会报错
[wind@Ubuntu build]$ cpack
CPack: Create package using STGZ
CPack: Install projects
CPack: - Run preinstall target for: helloWorld
CPack: - Install project: helloWorld []
CMake Error at /home/wind/cmakeClass/hello_world/build/cmake_install.cmake:69 (file):
  file failed to open for writing (Permission denied):

    /home/wind/cmakeClass/hello_world/build/install_manifest.txt


CPack Error: Error when generating package: helloWorld
[wind@Ubuntu build]$ # 它在cmake_install.cmake:69行执行出错: 对于写文件"install_manifest.txt"没有权限
[wind@Ubuntu build]$ # 上面我们所说的"收录", 其实就是一种安装, 对于cpack来说, 其具体的逻辑包括三步
[wind@Ubuntu build]$ # 构建一个临时安装目录 # 将二进制文件装到临时目录中 # 将临时安装目录压缩
[wind@Ubuntu build]$ # 而安装是要在install_manifest.txt中记录的, 因此需要写入
[wind@Ubuntu build]$ # 对于安装逻辑来说, 没有install_manifest.txt就会创建, 有就会写入
[wind@Ubuntu build]$ # 而在之前的安装中, 即 cmake --install .中, 我们为了能将程序安装到系统中, 使用了sudo提权
[wind@Ubuntu build]$ # 这导致install_manifest.txt是以root身份创建的
[wind@Ubuntu build]$ ll install_manifest.txt
-rw-r--r-- 1 root root 20 Sep  1 10:26 install_manifest.txt
[wind@Ubuntu build]$ # 因此我们在打包时也需要加sudo权限
```

```shell
[wind@Ubuntu build]$ sudo cpack .
CPack: Create package using STGZ
CPack: Install projects
CPack: - Run preinstall target for: helloWorld
CPack: - Install project: helloWorld []
CPack: Create package
CPack: - package: /home/wind/cmakeClass/hello_world/build/helloWorld-0.1.1-Linux.sh generated.
CPack: Create package using TGZ
CPack: Install projects
CPack: - Run preinstall target for: helloWorld
CPack: - Install project: helloWorld []
CPack: Create package
CPack: - package: /home/wind/cmakeClass/hello_world/build/helloWorld-0.1.1-Linux.tar.gz generated.
CPack: Create package using TZ
CPack: Install projects
CPack: - Run preinstall target for: helloWorld
CPack: - Install project: helloWorld []
CPack: Create package
CPack: - package: /home/wind/cmakeClass/hello_world/build/helloWorld-0.1.1-Linux.tar.Z generated.
[wind@Ubuntu build]$ # 在打包之后, 那个临时安装目录便在构建目录中被创建
[wind@Ubuntu build]$ tree _CPack_Packages
_CPack_Packages
└── Linux
    ├── STGZ
    │   ├── helloWorld-0.1.1-Linux
    │   │   └── bin
    │   │       └── hello
    │   └── helloWorld-0.1.1-Linux.sh
    ├── TGZ
    │   ├── helloWorld-0.1.1-Linux
    │   │   └── bin
    │   │       └── hello
    │   └── helloWorld-0.1.1-Linux.tar.gz
    └── TZ
        ├── helloWorld-0.1.1-Linux
        │   └── bin
        │       └── hello
        └── helloWorld-0.1.1-Linux.tar.Z

10 directories, 6 files
[wind@Ubuntu build]$ ls
CMakeCache.txt  cmake_install.cmake  _CPack_Packages          CTestTestfile.cmake    hello                      helloWorld-0.1.1-Linux.tar.gz  install_manifest.txt  testAdd
CMakeFiles      CPackConfig.cmake    CPackSourceConfig.cmake  DartConfiguration.tcl  helloWorld-0.1.1-Linux.sh  helloWorld-0.1.1-Linux.tar.Z   Makefile              Testing
[wind@Ubuntu build]$ # 此时我们就可以把 helloWorld-0.1.1-Linux.tar.gz 发送到网络上供别人使用
[wind@Ubuntu build]$ tar xvf helloWorld-0.1.1-Linux.tar.g
tar: helloWorld-0.1.1-Linux.tar.g: Cannot open: No such file or directory
tar: Error is not recoverable: exiting now
[wind@Ubuntu build]$ tar xvf helloWorld-0.1.1-Linux.tar.gz
helloWorld-0.1.1-Linux/bin/
helloWorld-0.1.1-Linux/bin/hello
[wind@Ubuntu build]$ cd helloWorld-0.1.1-Linux/bin
[wind@Ubuntu bin]$ ls
hello
[wind@Ubuntu bin]$ ./hello
hello world!
[wind@Ubuntu bin]$ cd ../..
[wind@Ubuntu build]$ 
```

```shell
[wind@Ubuntu build]$ # CPackConfig.cmake是与pack有关的配置文件, 规定了包的格式, 名称, 版本
[wind@Ubuntu build]$ # 由于我们在CMakeLists.txt中之include(CPack), 因此配置都是默认的
[wind@Ubuntu build]$ # CPACK_GENERATOR决定生成包的类型
[wind@Ubuntu build]$ sed -n '29p' CPackConfig.cmake
set(CPACK_GENERATOR "STGZ;TGZ;TZ")
[wind@Ubuntu build]$ # 包名称
[wind@Ubuntu build]$ sed -n '43p' CPackConfig.cmake
set(CPACK_PACKAGE_FILE_NAME "helloWorld-0.1.1-Linux")
[wind@Ubuntu build]$ # 包名称由三个部分组成
[wind@Ubuntu build]$ # 项目名称
[wind@Ubuntu build]$ sed -n '46p' CPackConfig.cmake
set(CPACK_PACKAGE_NAME "helloWorld")
[wind@Ubuntu build]$ # 版本号, 默认0.1.1
[wind@Ubuntu build]$ sed -n '49p' CPackConfig.cmake
set(CPACK_PACKAGE_VERSION "0.1.1")
[wind@Ubuntu build]$ # 平台名
[wind@Ubuntu build]$ sed -n '65p' CPackConfig.cmake
set(CPACK_SYSTEM_NAME "Linux")
[wind@Ubuntu build]$ 
```

----------------

`cmake`还有脚本模式, 其形式是`cmake [-D <var>=<value>]... -P <cmake-script-file>`

脚本模式将不会生成中间产物, 执行起来会很干净, 是用于执行各类自动化任务.

`cmake`的命令模式可以调用外部命令, 具体如下

```shell
[wind@Ubuntu build]$ cmake -E
CMake Error: cmake version 3.22.1
Usage: cmake -E <command> [arguments...]
Available commands: 
  capabilities              - Report capabilities built into cmake in JSON format
  cat <files>...            - concat the files and print them to the standard output
  chdir dir cmd [args...]   - run command in a given directory
  compare_files [--ignore-eol] file1 file2
                              - check if file1 is same as file2
  copy <file>... destination  - copy files to destination (either file or directory)
  copy_directory <dir>... destination   - copy content of <dir>... directories to 'destination' directory
  copy_if_different <file>... destination  - copy files if it has changed
  echo [<string>...]        - displays arguments as text
  echo_append [<string>...] - displays arguments as text but no new line
  env [--unset=NAME]... [NAME=VALUE]... COMMAND [ARG]...
                            - run command in a modified environment
  environment               - display the current environment
  make_directory <dir>...   - create parent and <dir> directories
  md5sum <file>...          - create MD5 checksum of files
  sha1sum <file>...         - create SHA1 checksum of files
  sha224sum <file>...       - create SHA224 checksum of files
  sha256sum <file>...       - create SHA256 checksum of files
  sha384sum <file>...       - create SHA384 checksum of files
  sha512sum <file>...       - create SHA512 checksum of files
  remove [-f] <file>...     - remove the file(s), use -f to force it (deprecated: use rm instead)
  remove_directory <dir>... - remove directories and their contents (deprecated: use rm instead)
  rename oldname newname    - rename a file or directory (on one volume)
  rm [-rRf] <file/dir>...    - remove files or directories, use -f to force it, r or R to remove directories and their contents recursively
  sleep <number>...         - sleep for given number of seconds
  tar [cxt][vf][zjJ] file.tar [file/dir1 file/dir2 ...]
                            - create or extract a tar or zip archive
  time command [args...]    - run command and display elapsed time
  touch <file>...           - touch a <file>.
  touch_nocreate <file>...  - touch a <file> but do not create it.
  create_symlink old new    - create a symbolic link new -> old
  create_hardlink old new   - create a hard link new -> old
  true                      - do nothing with an exit code of 0
  false                     - do nothing with an exit code of 1

[wind@Ubuntu build]$ 
```

## 第三章

在上述过程中, 我们对`cmake`有了较为完整的了解, 接下来, 我们会模拟实际开发过程中的各类场景, 去学习更加复杂的`cmake`用法.

当我们把鼠标放在`cmake_minimum_required`上时, cmake扩展就会将该指令的文档网址给出.

![image-20250901153903497](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250901153903497.png)

`cmake_minimum_required`的作用就是限定`cmake`工具的最低版本, 当运行的`cmake`版本比`cmake_minimum_required`所要求的要低时, `cmake`就会返回错误并停止

```shell
[wind@Ubuntu hello_world]$ cd build
[wind@Ubuntu build]$ rm -rf ./*
rm: cannot remove './_CPack_Packages/Linux/STGZ/helloWorld-0.1.1-Linux/bin/hello': Permission denied
rm: cannot remove './_CPack_Packages/Linux/STGZ/helloWorld-0.1.1-Linux.sh': Permission denied
rm: cannot remove './_CPack_Packages/Linux/TZ/helloWorld-0.1.1-Linux.tar.Z': Permission denied
rm: cannot remove './_CPack_Packages/Linux/TZ/helloWorld-0.1.1-Linux/bin/hello': Permission denied
rm: cannot remove './_CPack_Packages/Linux/TGZ/helloWorld-0.1.1-Linux.tar.gz': Permission denied
rm: cannot remove './_CPack_Packages/Linux/TGZ/helloWorld-0.1.1-Linux/bin/hello': Permission denied
[wind@Ubuntu build]$ sudo rm -rf ./*
[sudo] password for wind: 
[wind@Ubuntu build]$ cmake --version
cmake version 3.22.1

CMake suite maintained and supported by Kitware (kitware.com/cmake).
[wind@Ubuntu build]$ sed -n '2p' ../CMakeList.txt
sed: can't read ../CMakeList.txt: No such file or directory
[wind@Ubuntu build]$ sed -n '2p' ../CMakeLists.txt
cmake_minimum_required(VERSION 3.23)
[wind@Ubuntu build]$ cmake ..
CMake Error at CMakeLists.txt:2 (cmake_minimum_required):
  CMake 3.23 or higher is required.  You are running version 3.22.1


-- Configuring incomplete, errors occurred!
[wind@Ubuntu build]$ 
```

并且, `cmake_minimum_required`实际上也可以指定区间, 比如`cmake_minimum_required(VERSION 3.18...4.0)`的意思是最低3.18, 最高4.0.

需要注意的是, 版本不符强行退出的功能是在2.6之后才有的, 所以当`cmake`的版本低于2.6时, 即使版本不符, 也只发出警报, 而不强行终止构建过程.此时可以在`cmake_minimum_required(3.18) `后面添加`FATAL_ERROR`以忽略警报. 需要注意的是, 该指令应该放在最前面, 以避免构建一半发现版本不对的情况发生.     另外不建议在`cmake`函数中使用该指令.

对于不同的Linux来说, 预装`cmake`的版本将有所不同

![image-20250901155737682](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250901155737682.png)

----------

`project`有两种形式, 我们上面用的都是基本形式, 除了基本形式之外, `poject`还有许多可选参数, 它们构成了`project`的完整形式

```cmake
project(<PROJECT-NAME> [<language-name>...])
project(<PROJECT-NAME>
        [VERSION <major>[.<minor>[.<patch>[.<tweak>]]]]
        [COMPAT_VERSION <major>[.<minor>[.<patch>[.<tweak>]]]]
        [DESCRIPTION <project-description-string>]
        [HOMEPAGE_URL <url-string>]
        [LANGUAGES <language-name>...])
```

`cmake`中存在一个内置变量, `PROJECT_NAME`, 用于描述项目名, `project`的基本功能就是确定这个内置变量的值. 而在后续指令中, 可以通过`${PROJECT_NAME}`的形式取到它的值, 并通过下划线构成其它名称的前缀. 比如当`PROJECT_NAME`是HelloWorld, 那么`${PROJECT-NAME}_static`就会被转换成`HelloWorld_static`.

而在cmake中, 便运用了这种方法, 参与到cmake的其它内置变量的命名方式, cmake中的其它内置变量的形式都是`<PROJECT_NAME>_NAME`, 比如, 对于`PROJECT_NAME`为`helloWorld`的, 便会生成`helloWorld_SOURCE_DIR, helloWorld_BINARY_DIR...`这种形式的内置变量, 你同样可以通过`${}`的形式来取到它们的值, 这种的好处是, 一个大项目, 会被拆分成许多小项目, 每个小项目都有自己的一堆内置变量, 但它们在最后汇总时不会重复, 因为前缀是不同的, 这样就实际实现了类似于命名域的功能.

`CMake` `project()` 可选参数说明

| 参数                                                   | 说明                                                         | 示例                                                |
| ------------------------------------------------------ | ------------------------------------------------------------ | --------------------------------------------------- |
| `VERSION <major>[.<minor>[.<patch>[.<tweak>]]]`        | 指定项目版本号，CMake 会生成 `<PROJECT-NAME>_VERSION` 变量以及相关分量变量（如 `_VERSION_MAJOR`、`_VERSION_MINOR`）。 | `project(MyApp VERSION 1.2.3.4)`                    |
| `COMPAT_VERSION <major>[.<minor>[.<patch>[.<tweak>]]]` | 指定项目兼容版本，通常在安装或导出配置时使用，确保依赖库能匹配兼容版本。 | `project(MyLib VERSION 2.1 COMPAT_VERSION 2.0)`     |
| `DESCRIPTION <project-description-string>`             | 为项目提供简要描述，生成 `<PROJECT-NAME>_DESCRIPTION` 变量。 | `project(HelloWorld DESCRIPTION "A demo project")`  |
| `HOMEPAGE_URL <url-string>`                            | 设置项目主页的 URL，生成 `<PROJECT-NAME>_HOMEPAGE_URL` 变量。 | `project(MyApp HOMEPAGE_URL "https://example.com")` |
| `LANGUAGES <language-name>...`                         | 指定支持的编程语言（默认是 C 和 CXX）。常见值：`C`、`CXX`、`Fortran`、`ASM` 等。 | `project(MyApp LANGUAGES C CXX Fortran)`            |

`cmake`含有指令`message`, 可以为我们打印这些内置变量的值, 其形式是` message([<mode>] "message text" ...)`, 使用打印功能选择`STATUS`

```shell
[wind@Ubuntu build]$ cat ../CMakeLists.txt | tail -2
message(STATUS "PROJECT-NAME: ${PROJECT_NAME}")
message(STATUS "helloWorld_SOURCE_DIR: ${helloWorld_SOURCE_DIR}")[wind@Ubuntu build]$ 
[wind@Ubuntu build]$ cmake .
-- PROJECT_NAME: helloWorld
-- helloWorld_SOURCE_DIR: /home/wind/cmakeClass/hello_world
-- Configuring done
-- Generating done
-- Build files have been written to: /home/wind/cmakeClass/hello_world/build
[wind@Ubuntu build]$ 
```

接下来我们介绍`project`的第二个参数`VERSION`, 在`cmake`中, 版本号被分成四个部分, `major`主版本号,`minor`次版本号, `patch`修订号, `tweak`微调号, 在`cmake`中, 可以通过`PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR, PROJECT_VERSION_PATCH, PROJECT_VERSION_TWEAK`可以取到, 它们共同构成了一份完整版本号`PROJECT_VERSION`

在`cmake`中, 版本号一般被用在三个场景, 一是使用`message`进行打印, 二是, 在`cmake, cpack`的版本配置文件中, 三是, 生成动静态库时用到的版本号

```shell
wind@Ubuntu build]$ cat ../CMakeLists.txt | head -8 | tail -5
# 设置项目名称
project(helloWorld
    VERSION 1.2.3.4
    LANGUAGES C CXX
)
[wind@Ubuntu build]$ cat ../CMakeLists.txt | tail -2
message(STATUS "helloWorld_VERSION: ${helloWorld_VERSION}")
message(STATUS "helloWorld_VERSION_MAJOR: ${helloWorld_VERSION_MAJOR}")[wind@Ubuntu build]$ 
[wind@Ubuntu build]$ cmake .
-- PROJECT_NAME: helloWorld
-- helloWorld_SOURCE_DIR: /home/wind/cmakeClass/hello_world
-- helloWorld_VERSION: 1.2.3.4
-- helloWorld_VERSION_MAJOR: 1
-- Configuring done
-- Generating done
-- Build files have been written to: /home/wind/cmakeClass/hello_world/build
[wind@Ubuntu build]$ 
```

-------

接下来介绍`LANGUAGES`这个可选参数, 该选项用于描述项目中所用到的语言, 以便于`cmake`去寻找支持项目的编译器链接器.

```txt
C, CXX (i.e. C++), CSharp (i.e. C#), CUDA, OBJC (i.e. Objective-C), OBJCXX (i.e. Objective-C++), Fortran, HIP, ISPC, Swift, ASM, ASM_NASM, ASM_MARMASM, ASM_MASM, and ASM-ATT.
```

在默认情况下, `LANGUAGES`将是`C CXX`. 在第一次构建时, `cmake`会在平台上寻找对应语言所需要的工具, 并进行一些测试, 确定工具的状态, 所支持的功能. 当没有`PROJECT`时, `cmake`会发出警告, 并将项目名称定为`Project`, 并开启默认的`C CXX`语言

```shell
[wind@Ubuntu build]$ cat ../CMakeLists.txt | head -8 | tail -5
# 设置项目名称
# project(helloWorld
#     VERSION 1.2.3.4
#     LANGUAGES C CXX
# )
[wind@Ubuntu build]$ rm -rf ./*
[wind@Ubuntu build]$ cmake ..
CMake Warning (dev) in CMakeLists.txt:
  No project() command is present.  The top-level CMakeLists.txt file must
  contain a literal, direct call to the project() command.  Add a line of
  code such as

    project(ProjectName)

  near the top of the file, but after cmake_minimum_required().

  CMake is pretending there is a "project(Project)" command on the first
  line.
This warning is for project developers.  Use -Wno-dev to suppress it.

-- The C compiler identification is GNU 13.3.0
-- The CXX compiler identification is GNU 13.3.0 ## 寻找C/C++所需要的编译器, 并判定执行标准
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done          ## cmake通过一个小的C程序, 测试编译器的特定功能(内存对齐, 传参方式, 数据布局, 文件格式, 可以被统称为ABI)
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- PROJECT_NAME: Project
-- helloWorld_SOURCE_DIR: 
-- helloWorld_VERSION: 
-- helloWorld_VERSION_MAJOR: 
-- Configuring done                             
-- Generating done                               ## 将测试结果放在对应文件中
-- Build files have been written to: /home/wind/cmakeClass/hello_world/build
[wind@Ubuntu build]$ 
```

```shell
[wind@Ubuntu build]$ cd /home/wind/cmakeClass/hello_world/build/CMakeFiles/3.22.1
[wind@Ubuntu 3.22.1]$ ls -a
.  ..  CMakeCCompiler.cmake  CMakeCXXCompiler.cmake  CMakeDetermineCompilerABI_C.bin  CMakeDetermineCompilerABI_CXX.bin  CMakeSystem.cmake  CompilerIdC  CompilerIdCXX
[wind@Ubuntu 3.22.1]$ ll # 如果同时存在不同版本的cmake, 会依据版本把测试结果放在不同的文件夹下
total 64
drwxrwxr-x  4 wind wind  4096 Sep  1 18:06 ./
drwxrwxr-x 34 wind wind  4096 Sep  1 18:06 ../
-rw-r--r--  1 wind wind  2441 Sep  1 18:06 CMakeCCompiler.cmake
-rw-r--r--  1 wind wind  5439 Sep  1 18:06 CMakeCXXCompiler.cmake
-rwxrwxr-x  1 wind wind 15968 Sep  1 18:06 CMakeDetermineCompilerABI_C.bin*
-rwxrwxr-x  1 wind wind 15992 Sep  1 18:06 CMakeDetermineCompilerABI_CXX.bin*
-rw-r--r--  1 wind wind   398 Sep  1 18:06 CMakeSystem.cmake
drwxrwxr-x  3 wind wind  4096 Sep  1 18:06 CompilerIdC/
drwxrwxr-x  3 wind wind  4096 Sep  1 18:06 CompilerIdCXX/
[wind@Ubuntu 3.22.1]$ cd -
/home/wind/cmakeClass/hello_world/build
[wind@Ubuntu build]$ # 刷新时, 依赖之前的测试结果
[wind@Ubuntu build]$ cmake .
CMake Warning (dev) in CMakeLists.txt:
  No project() command is present.  The top-level CMakeLists.txt file must
  contain a literal, direct call to the project() command.  Add a line of
  code such as

    project(ProjectName)

  near the top of the file, but after cmake_minimum_required().

  CMake is pretending there is a "project(Project)" command on the first
  line.
This warning is for project developers.  Use -Wno-dev to suppress it.

-- PROJECT_NAME: Project
-- helloWorld_SOURCE_DIR: 
-- helloWorld_VERSION: 
-- helloWorld_VERSION_MAJOR: 
-- Configuring done
-- Generating done
-- Build files have been written to: /home/wind/cmakeClass/hello_world/build
[wind@Ubuntu build]$ # 不会再进行测试

```

当语言设置有误时, `cmake`就不会调用涉及到的编译器链接器, 从而无法处理源代码报错.

----------

`include`可以加载指定的脚本文件或者模块到`CMakeList.txt`执行上下文中运行. 接下来要说的`include`的文件模块查找逻辑.

对于文件来说, 绝对路径直接加载, 相对路径相对的是`CMakeLists.txt`所在的目录. 对于模块来说, 首先在当前目录查找, 然后在`CMAKE_MODULE_PATH`变量中指定的路径下去查找

```shell
[wind@Ubuntu build]$ tree ..
..
├── build
├── CMakeLists.txt
├── sub
│   └── sub.cmake
└── test.cpp

2 directories, 3 files
[wind@Ubuntu build]$ cat ../CMakeLists.txt
cmake_minimum_required(VERSION 3.18)

project(TestInclude)

add_executable(test test.cpp)

message(STATUS "from top-level CMakeLists.txt")

# 打印源代码目录
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

# 打印当前执行cmake脚本的完整名称
message(STATUS "CMAKE_CURRENT_LIST_FILE: ${CMAKE_CURRENT_LIST_FILE}")

# 打印当前执行cmake脚本的完整目录
message(STATUS "CMAKE_CURRENT_LIST_DIR: ${CMAKE_CURRENT_LIST_DIR}")

# 包含子目录下的脚本
include(sub/sub.cmake)[wind@Ubuntu build]$ cat ../sub/sub.cmake
message(STATUS "from sub/sub.cmake")

# 打印源代码目录
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

# 打印当前执行cmake脚本的完整名称
message(STATUS "CMAKE_CURRENT_LIST_FILE: ${CMAKE_CURRENT_LIST_FILE}")

# 打印当前执行cmake脚本的完整目录
message(STATUS "CMAKE_CURRENT_LIST_DIR: ${CMAKE_CURRENT_LIST_DIR}")
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
-- from top-level CMakeLists.txt
-- CMAKE_CURRENT_SOURCE_DIR: /home/wind/cmakeClass/test_include
-- CMAKE_CURRENT_LIST_FILE: /home/wind/cmakeClass/test_include/CMakeLists.txt
-- CMAKE_CURRENT_LIST_DIR: /home/wind/cmakeClass/test_include
-- from sub/sub.cmake
-- CMAKE_CURRENT_SOURCE_DIR: /home/wind/cmakeClass/test_include
-- CMAKE_CURRENT_LIST_FILE: /home/wind/cmakeClass/test_include/sub/sub.cmake
-- CMAKE_CURRENT_LIST_DIR: /home/wind/cmakeClass/test_include/sub
-- Configuring done
-- Generating done
-- Build files have been written to: /home/wind/cmakeClass/test_include/build
[wind@Ubuntu build]$ 
```

从中我们可以看到的是, 由于被包含的文件或者模块是被加载到`CMakeLists.txt`的, 所以其源文件的目录始终都是`CMakeLists.txt`所在的目录, 没有发生变化, 而`CMAKE_CURRENT_LIST_FILE`和`CMAKE_CURRENT_LIST_DIR`则表现了被执行内容的来源, 展现了一定的调用链关系, 所以发生了变化, 真实反应了当前执行的文件或者模块.

---------

接下来说说`install`

`install`的作用就是把二进制可执行文件, 动静态库, 头文件, 配置文件拷贝到指定目录中. 

除了单纯的将相关文件部署到系统的指定目录中, `install`的其它意义在于, 它具有`cmake`自带的跨平台性, 并且, `install`所生成的配置文件脚本, 将会是`cpack`打包时, 临时安装目录的生成依据, `cpack`就相当于把程序安装到临时安装目录里

可以在`cmake`脚本中依据文件的类型后缀等将其部署到开发者所指定的目录.  `install`的参数如下

| 用法/参数                | 说明                                                         | 示例                                                      |
| ------------------------ | ------------------------------------------------------------ | --------------------------------------------------------- |
| `install(TARGETS ...)`   | 安装构建的目标（可执行文件、库等）。可以指定安装路径、类型。 | `install(TARGETS myapp DESTINATION bin)`                  |
| `install(FILES ...)`     | 安装普通文件。                                               | `install(FILES config.json DESTINATION etc/myapp)`        |
| `install(DIRECTORY ...)` | 安装整个目录（递归复制）。                                   | `install(DIRECTORY docs/ DESTINATION share/doc/myapp)`    |
| `install(PROGRAMS ...)`  | 安装脚本/程序文件（自动赋可执行权限）。                      | `install(PROGRAMS tools/myscript.sh DESTINATION bin)`     |
| `install(SCRIPT ...)`    | 安装时执行 CMake 脚本（`cmake -P` 执行）。                   | `install(SCRIPT install_extra.cmake)`                     |
| `install(CODE ...)`      | 内联 CMake 代码，在安装时执行。                              | `install(CODE "message(STATUS \"Installing...\")")`       |
| `DESTINATION <dir>`      | 指定安装目标路径（相对于 `CMAKE_INSTALL_PREFIX`）。          | `DESTINATION lib`                                         |
| `CONFIGURATIONS ...`     | 指定安装适用的构建类型（Debug/Release/RelWithDebInfo/MinSizeRel）。 | `CONFIGURATIONS Release`                                  |
| `COMPONENT <name>`       | 将安装项归类到某个组件，可用于分组件安装（`cpack` 用）。     | `COMPONENT Runtime`                                       |
| `PERMISSIONS ...`        | 指定文件权限（OWNER_READ, OWNER_WRITE, OWNER_EXECUTE 等）。  | `PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ`           |
| `RENAME <name>`          | 安装时重命名目标文件。                                       | `install(FILES old.conf DESTINATION etc RENAME new.conf)` |
| `OPTIONAL`               | 忽略不存在的文件/目录，不报错。                              | `install(FILES maybe.txt DESTINATION share OPTIONAL)`     |
| `EXPORT <export-name>`   | 导出目标，用于生成 `*Targets.cmake`，支持 `find_package`。   | `install(TARGETS mylib EXPORT mylibTargets)`              |
| `INCLUDES DESTINATION`   | 指定头文件安装路径，通常和 `install(TARGETS)` 一起用。       | `install(TARGETS mylib INCLUDES DESTINATION include)`     |

接下来我们打印一下`CMAKE_INSTALL_PREFIX`

```shell
[wind@Ubuntu build]$ cmake .
-- from top-level CMakeLists.txt
-- CMAKE_CURRENT_SOURCE_DIR: /home/wind/cmakeClass/test_include
-- CMAKE_CURRENT_LIST_FILE: /home/wind/cmakeClass/test_include/CMakeLists.txt
-- CMAKE_CURRENT_LIST_DIR: /home/wind/cmakeClass/test_include
-- CMAKE_INSTALL_PREFIX: /usr/local
-- Configuring done
-- Generating done
-- Build files have been written to: /home/wind/cmakeClass/test_include/build
[wind@Ubuntu build]$ cmake --build .
[ 50%] Building CXX object CMakeFiles/test.dir/test.cpp.o
[100%] Linking CXX executable test
[100%] Built target test
[wind@Ubuntu build]$ ls
CMakeCache.txt  CMakeFiles  cmake_install.cmake  Makefile  test
[wind@Ubuntu build]$ # 当安装过程中, 会在构建目录中生成cmake的安装脚本
[wind@Ubuntu build]$ sudo cmake --install .
[sudo] password for wind: 
-- Install configuration: ""
-- Installing: /usr/local/bin/test
[wind@Ubuntu build]$ ls
CMakeCache.txt  CMakeFiles  cmake_install.cmake  install_manifest.txt  Makefile  test

```

`install`分为三个阶段, 首先, 收集需要安装的文件, 接着, 生成安装脚本, `cmake_install.cmake`, 最后, 让`cmake`以命令模式执行该脚本. 完成安装过程. 在之前的内容中, 我们也使用指令展现过相应内容.

--------------

`add_executable`用于命令`cmake`从源代码生成一个可执行程序.

有两个参数`add_executable(<name> <options>... <sources>...)`, 第一个参数描述可执行文件的名字, 不加扩展名, 第二个参数则描述了生成源文件所需要的列表.

`add_executable`的一个需要关注的点是, 其所生成二进制中间文件相对于构建目录的相对位置与它所依赖的源文件相对于源目录的相对位置是严格相同的.

比如, 对于一个项目来说, 可能会有源文件和头文件之分, 于是你在源目录下又新建`src, include`这两个子文件夹

```shell
project/
├── CMakeLists.txt
├── src/
│   ├── main.cpp
│   └── util.cpp
├── include/
│   └── util.h
```

此时进行项目构建后, 会发现放置`.o`文件的`src`目录相对于`CMakeFiles`的相对目录`./src`与根目录中, `.cpp`文件相对于`CMakeLists.txt`的相对目录`.src`是相同的, 但最终的可执行文件依旧直接放在构建目录下.

```shell
build/
├── CMakeFiles/           # 中间文件，保持和源码目录一致的层级
│   └── src/              # src 下的 .o 文件和依赖关系
├── Makefile
├── cmake_install.cmake
└── myapp                 # 最终可执行文件
```

有时, 我们可能并不需要最终可执行文件, 我们需要的可能只是库文件,因此, 可能并不需要完全一致的镜像相对路径, 可能镜像相对路径太深了, 此时我们可以使用`RUNTIME_OUTPUT_DIRECTORY`对其进行重新设置, 生成到我们所希望的目录下.

--------

接下来我们学习使用`cmake`生成使用静态库. 我们知道静态库是对中间文件(`.o, .obj`)简单的打包归档, 在生成静态库是并不需要把多个`.o, .obj`进行链接, 而只是在静态库被真正使用的时候, 再进行相互链接.对于Linux来说, 其静态库的后缀是`.a`

接下来我们将生成并使用一个支持加减法的静态库

我们建立二级结构

```shell
[wind@Ubuntu my_math]$ tree .
.
├── app
│   ├── CMakeLists.txt
│   └── main.cpp
├── CMakeLists.txt
└── my_lib
    ├── CMakeLists.txt
    ├── include
    │   └── my_math.h
    └── src
        ├── add.cpp
        └── sub.cpp

4 directories, 7 files
[wind@Ubuntu my_math]$ 
```

根目录中的`CMkeLists.txt`不执行实际功能, 只负责执行流的调度. `my_lib`负责生成静态库, `app`则负责使用静态库

```shell
[wind@Ubuntu my_math]$ cd my_lib
[wind@Ubuntu my_lib]$ cat include/my_math.h
int add(int, int);
int sub(int, int);[wind@Ubuntu my_lib]$ 
[wind@Ubuntu my_lib]$ cat src/add.cpp
#include"my_math.h"
int add(int x, int y)
{
    return x + y;
}[wind@Ubuntu my_lib]$ cat src/sub.cpp
#include"my_math.h"
int sub(int x, int y)
{
    return x - y;
[wind@Ubuntu my_lib]$ 
```

```shell
[wind@Ubuntu my_math]$ cd app
[wind@Ubuntu app]$ cat main.cpp
#include<iostream>
#include"my_math.h"

int main()
{
    std::cout<<"3 + 4 == " << add(3,4) << std::endl;
    std::cout<<"3 - 4 == " << sub(3,4) << std::endl;
    return 0;
}   
[wind@Ubuntu app]$ cat CMakeLists.txt
# 搜集文件列表
file(GLOB SRC_LISTS "*.cpp")

# 构建目标
add_executable(main ${SRC_LISTS})

# 添加链接库列表
target_link_libraries(main PRIVATE MyMath)
[wind@Ubuntu app]$ cd ..
[wind@Ubuntu my_math]$ cat CMakeLists.txt
cmake_minimum_required(VERSION 3.18)

project(TestMyMath)

# 因为cmake是顺序执行, 所以必须先构建静态库再生成可执行程序
add_subdirectory(my_lib)
add_subdirectory(app)[wind@Ubuntu my_math]$ 
```

```shell
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
-- Build files have been written to: /home/wind/cmakeClass/my_math/build
[wind@Ubuntu build]$ ls
app  CMakeCache.txt  CMakeFiles  cmake_install.cmake  Makefile  my_lib
[wind@Ubuntu build]$ cmake --build .
[ 20%] Building CXX object my_lib/CMakeFiles/MyMath.dir/src/add.cpp.o
[ 40%] Building CXX object my_lib/CMakeFiles/MyMath.dir/src/sub.cpp.o
[ 60%] Linking CXX static library libMyMath.a
[ 60%] Built target MyMath
[ 80%] Building CXX object app/CMakeFiles/main.dir/main.cpp.o
[100%] Linking CXX executable main
[100%] Built target main
[wind@Ubuntu build]$ ls
app  CMakeCache.txt  CMakeFiles  cmake_install.cmake  Makefile  my_lib
[wind@Ubuntu build]$ cd my_lib
[wind@Ubuntu my_lib]$ ls
CMakeFiles  cmake_install.cmake  libMyMath.a  Makefile
[wind@Ubuntu my_lib]$ cd ..
[wind@Ubuntu build]$ cd app
[wind@Ubuntu app]$ ls
CMakeFiles  cmake_install.cmake  main  Makefile
[wind@Ubuntu app]$ ./main
3 + 4 == 7
3 - 4 == -1
[wind@Ubuntu app]$ cd ..
[wind@Ubuntu build]$ cd ..
```

下面是一个经过化简的文件树

```shell
.
├── app
│   ├── CMakeLists.txt
│   └── main.cpp
├── my_lib
│   ├── CMakeLists.txt
│   ├── include
│   │   └── my_math.h
│   └── src
│       ├── add.cpp
│       └── sub.cpp
├── CMakeLists.txt
└── build
    ├── app
    │   ├── main            # ← 可执行文件 (由 app/main.cpp 构建)
    │   └── CMakeFiles/...  # ← 构建中间文件
    ├── my_lib
    │   ├── libMyMath.a     # ← 静态库 (由 my_lib/src/*.cpp 构建)
    │   └── CMakeFiles/...  # ← 构建中间文件
    ├── CMakeCache.txt
    ├── CMakeFiles/...      # ← 全局的 CMake 配置文件
    └── Makefile
```

我们可以看到, 源目录中的`main.cpp`相对于`app`的位置也是构建目录中`main`相对于`app`的位置, `libMyMath.a`相对于`my_lib`的位置也是源目录中`add.cpp, sub.cpp`相对于`my_lib`的位置. 它们之间的相对路径是保持不变或者呈现镜像关系的.

在`cmake`中, 生成文件的布局被视为目标属性的一部分, 我们可以通过`set_target_properties`搭配它的各类参数对指定类型的目标设置对应的输出路径, 这些参数都是形如`xx_OUTPUT_DIRECTORY`的样子, 其前缀`xx`便描述了目标的类型

对于静态库来说, 是`ARCHIVE_OUTPUT_DIRECTORY`, 动态库是`RUNTIME_OUTPUT_DIRECTORY`, 可执行程序是`RUNTIME_OUTPUT_DIRECTORY`

```shell
[wind@Ubuntu my_math]$ # CMAKE_BINARY_DIR是构建根目录, 即build
[wind@Ubuntu my_math]$ tree .
.
├── app
│   ├── CMakeLists.txt
│   └── main.cpp
├── build
├── CMakeLists.txt
└── my_lib
    ├── CMakeLists.txt
    ├── include
    │   └── my_math.h
    └── src
        ├── add.cpp
        └── sub.cpp

5 directories, 7 files
[wind@Ubuntu my_math]$ cat my_lib/CMakeLists.txt | tail -4
# 修改默认输出路径
set_target_properties(MyMath PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)
[wind@Ubuntu my_math]$ cat app/CMakeLists.txt | tail -3
set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
[wind@Ubuntu my_math]$ cd build
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
-- Build files have been written to: /home/wind/cmakeClass/my_math/build
[wind@Ubuntu build]$ cmake --build .
[ 20%] Building CXX object my_lib/CMakeFiles/MyMath.dir/src/add.cpp.o
[ 40%] Building CXX object my_lib/CMakeFiles/MyMath.dir/src/sub.cpp.o
[ 60%] Linking CXX static library ../lib/libMyMath.a
[ 60%] Built target MyMath
[ 80%] Building CXX object app/CMakeFiles/main.dir/main.cpp.o
[100%] Linking CXX executable ../bin/main
[100%] Built target main
[wind@Ubuntu build]$ cd .. && tree .
```

化简如下

```shell.
.
├── app
│   ├── CMakeLists.txt
│   └── main.cpp
├── my_lib
│   ├── CMakeLists.txt
│   ├── include
│   │   └── my_math.h
│   └── src
│       ├── add.cpp
│       └── sub.cpp
├── CMakeLists.txt
└── build
    ├── bin
    │   └── main            # ← 可执行文件 (由 app/main.cpp 构建)
    ├── lib
    │   └── libMyMath.a     # ← 静态库 (由 my_lib/src/*.cpp 构建)
    ├── CMakeCache.txt
    ├── CMakeFiles/...      # ← 全局 CMake 配置与中间文件
    ├── Makefile
    └── my_lib
        └── CMakeFiles/...  # ← my_lib 子目录的中间构建文件

```

`cmake`的设计理念是基于目标的属性传递机制进行构建, 除了上面出现的两个`OUTPUT_DIRECTORY`, 还有许多目标属性, 详情见[官方文档](https://cmake.org/cmake/help/latest/manual/cmake-properties.7.html)

![image-20250902131225981](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250902131225981.png)

---------------

接下来我们介绍一下`cmake`的三大核心

`cmake`有三大属性: 目标  属性  API , 目标是我们想要的输出文件, 属性是描述目标种种性质的类似于键值表的序列, API则是我们对属性进行管理的工具, 这三者又通过目标属性传递机制结合起来, 构成了`cmake`这个现代化构建系统的基础.

目标的类型

|    类型    |          创建命令          |                         产物/说明                          |
| :--------: | :------------------------: | :--------------------------------------------------------: |
| EXECUTABLE |       add_executable       |                    生成二进制可执行文件                    |
|   STATIC   |  add_library(... STATIC)   |                       生成静态库文件                       |
|   SHARED   |  add_library(... SHARED)   |                       生成动态库文件                       |
|   MODULE   |  add_library(... MODULE)   | 一种特殊的, 使用dlopen`/`LoadLibrary运行时加载的动态库文件 |
|   OBJECT   |  add_library(... OBJECT)   |                 生成.o   .obj这种目标文件                  |
| INTERFACE  | add_library(... INTERFACE) |   本身不生成目标, 仅描述描述目标生成的依赖文件及编译细节   |
|  IMPORTED  | add_library(... IMPORTED)  |                引用磁盘上已有的外部依赖文件                |
|   ALIAS    |   add_library(... ALIAS)   |                   为本项目内的目标取别名                   |

目标属性分类

|          类型           |              作用域              |              典型读写命令               |            常用属性示例            |
| :---------------------: | :------------------------------: | :-------------------------------------: | :--------------------------------: |
|    Global(全局属性)     |        整个cmake运行周期         |  get/set_property(GLOBAL PROPERTY...)   |             CMAKE_ROLE             |
|   Directory(目录属性)   |      当前源码目录及其子目录      | get/set_property(DIRECTORY PROPERTY...) |        INCLUDE_DIRECTORIES         |
|    Target(目标属性)     | 单个构建目标(库, 可执行, 接口库) |  get/set_property(TARGET PROPERTY...)   | LINK_LIBRARIES INCLUDE_DIRECTORIES |
| Source File(源文件属性) |        单个源码, 资源文件        |     get/set_source_files_properties     |           COMOPILE_FLAGS           |
|     Test(测试属性)      |    由add_test()定义的单个测试    |       get/set_tests_properties()        |         WORKING_DIRECTORY          |
|      安装文件属性       |       install() 生成的安装       |        set_property(INSTALL...)         |               RPATH                |

属性的作用域与传播范围

|  关键字   | 对当前目标的构建影响 | 是否传播 | 对当前目标使用者的影响 | 解释             | 例子                                 |
| :-------: | :------------------: | :------: | :--------------------: | ---------------- | ------------------------------------ |
|  PRIVATE  |         生效         |    否    |         不生效         | 只自己用         | 制作面包的面粉品牌不公开             |
|  PUBLIC   |         生效         |    是    |          生效          | 自己-下游用      | 公开制作面包的面粉品牌               |
| INTERFACE |        不生效        |    是    |          生效          | 自己不用, 下游用 | 说明书, 说明用什么面粉制作, 不卖东西 |

操作目标属性的API

|     类型      |                    典型关键字(可选关键字)                    |                           主要作用                           |                      涉及的部分核心属性                      |
| :-----------: | :----------------------------------------------------------: | :----------------------------------------------------------: | :----------------------------------------------------------: |
| 通用读/写接口 |     set_target_properties() <br>get_target_properties()      |                   任意目标属性, 最底层API                    |                         任何prop_tgt                         |
| 编译阶段相关  | target_compile_definitions<br>target_compile_options<br>target_precompile_headers<br>target_include_directories<br>target_sources | 控制源文件编译: 宏定义;<BR>编译选项,语言特性,预编译头,<BR>包含目录,源文件列表 | COMPILE_DEFINITIONS<BR>COMPILE_OPTIONS<BR>COMPILE_FEATURES<BR>PRECOMPILE_HEADERS<BR>INCLUDE_DIRECTORIES<BR>SOURCES等 |
| 链接输出阶段  | target_link_libraries<br>target_link_options<br>target_link_directories |              配置目标被链接时库, 选项及搜索路径              | LINK_LIBRARIES<BR>INTERFACE_LINK_LIBRARIES<BR>LINK_OPTIONS<BR>INTERFACE_LINK_OPTIONSLINK_DIRECTORIES<BR>INTERFACE_LINK_DIRECTORIES |
| 安装打包阶段  |          install(TARGETS...)<BR>install(EXPORT...)           |   生成安装规则与包, 控制目标在安装树中的布局及其运行时行为   |     RUNTIME_OUTPUT_DIRECTORY<BR>LIBRARY_OUTPUT_DIRECTORY     |

`cmake`的工作流程

首先在配置阶段, 就是`cmake`读取`CMakeLists.txt`时, 如果是`add`形式的API, `cmake`会将其中对象加载注册到全局目标列表; 在生成阶段, 则依据这些目标属性, 生成`makefile`这类各平台自己的项目构建文件, 构建阶段, 会依据前面生成的构建文件进行编译链接; 安装期, 则是直接使用依据安装属性生成的`cmake_install.cmake`脚本

---

在[官方文档](https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html#manual:cmake-buildsystem(7))中, 我们可以看到`cmake`所支持的详细目标类型

`cmake`支持的二进制目标

![image-20250903103554402](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250903103554402.png)

支持的可执行程序

![image-20250903104204156](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250903104204156.png)

可执行程序, 导入程序, 别名可执行程序

支持的库文件, 包括普通库, 目标文件库, 接口库, 导入库, 接口库

![image-20250903104449241](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250903104449241.png)

指令皆可以在[指令手册](https://cmake.org/cmake/help/latest/manual/cmake-commands.7.html)中找到对应链接

![image-20250903104702033](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250903104702033.png)

-------

`cmake`为我们提供了`add_library`这个指令, 供我们生成库目标文件.形式为

```cmake
add_library(<name> [STATIC | SHARED | MODULE] [EXCLUDE_FROM_ALL] [<source>...])
```

- name: 库的名称, 不包含前缀lib和后缀 .a, .so
- STATIC | SHARED | MODULE : 表示生成库目标的类型
- <source\>: 构建库目标所需的源文件

目标库: 其实就是.o   .obj这类目标文件, 可以直接当源文件使用
静态库: .o文件经过打包归档形成的库
动态库: .o文件经过打包归档链接形成的库
模块库: 特殊的动态库, 通过dlopen`/`LoadLibrary在运行时使用
接口库: 向库的使用者规定库所需要的依赖文件, 库的使用方式, 不是库文件(gcc -l -L这些选项的参数)
导入库: 提供  为不兼容`cmake`, 老的库    的链接方案, 可以把磁盘上的外部库导入项目中
别名库: 为库起别名, 可以通过增加前缀后缀的方式, 把库的一些性质反映到名字上, 比如静态加后缀`_static`, 动态加`_shared`

---

`target_include_directories`负责将头文件的所在目录路径写入到`target`的属性列表中, 并依据`PUBLIC PRIVATE INTERFACE`关键字控制它们在依赖链中的传播方式, 对于`makefile`来说, 其最终会在`gcc -I`选项中被链接, `target_include_directories`支持多个路径的添加, 可以把同样传播属性的路径放在一块来写.

于此相关的是`INTERFACE_LIBRARY  INTERFACE_INCLUDE_DIRECTORIES`这两个目标属性, `INTERFACE_LIBRARY`中的路径仅会在项目内部被包含, 而不会在下游中生效, 而在`INTERFACE_INCLUDE_DIRECTORIES`中, 则会在下游调用链中存在. `PRIVATE`会把路径写入到`INTERFACE_LIBRARY`中, 而`INTERFACE`则是把路径写入到`INTERFACE_INCLUDE_DIRECTORIES`中,`PUBLIC`则是两个都写. 所以 `PUBLIC `目标自己包含, 使用目标的也包含,  `PRIVATE`仅自己包含, `INTERFACE`仅使用目标的包含. 

-------------

`target_link_libraries`相当于使用通用的`set`属性设置了`LINK_LIBRARIES`或者`INTERFACE_LINK_LIBRARIES`, 具体设置谁依靠传播路径关键字来进行判断, 具体形式形如

```cmake
target_link_libraries(<target>
					<PRIVATE | PUBLIC | INTERFACE> <item>...
					[<PRIVATE | PUBLIC | INTERFACE> <item>]...
)

set_target_properties(<target> PROPERITES
					LINK_LIBRARIES | INTERFACE_LINK_LIBRARIES <item>
)
```

`PRIVATE | PUBLIC | INTERFACE`这三个作用域关键字的作用和`target_include_directories`是完全相同的, 其背后的作用机理也是相同的.

---------------

我们将进行一场实验, 实验目的是通过实际实验观察`cmake`的INTERFACE_LINK_LIBRARIES的传递机制, 我们将设计两个简单的cmake项目, 其中项目A作为被使用方, 项目B作为使用方. 在项目A中, 我们将会使用`target_link_libraries`为A添加一系列的被写入`INTERFACE_LINK_LIBRARIES`目标属性的lib, 随后将项目A安装到系统中, 在项目B中查找并使用项目A, 并通过`cmake --build . -v`查看编译链接中涉及到的库, 与项目A对照, 从而直观体验`INTERFACE_LINK_LIBRARIES`供使用者使用的性质, 这两个项目, 不需要有实际功能, 并应尽量简便, 以便我们快速的进行实验.

```cpp
// libA.cpp
void fooA() {}

```

```cmake
# A的CmakeLists.txt
cmake_minimum_required(VERSION 3.15)
project(ProjectA LANGUAGES CXX)

# 1. 创建一个静态库 A
add_library(A STATIC libA.cpp)

# 2. 模拟一些依赖库
# 这里使用系统库作为例子，或者你可以用其他空库
target_link_libraries(A
    INTERFACE
        m           # 数学库
        pthread     # pthread库
)

# 3. 安装库
install(TARGETS A
        EXPORT ProjectAConfig
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include)

# 4. 安装导出文件，供find_package使用
install(EXPORT ProjectAConfig
        DESTINATION lib/cmake/ProjectA)

```

```cpp
// B-main.cpp
int main() {
    return 0;
}

```

```cmake
# B的CMakeLists.txt
cmake_minimum_required(VERSION 3.15)
project(ProjectB LANGUAGES CXX)

# 假设 ProjectA 已安装到系统路径中
find_package(ProjectA REQUIRED PATHS "/usr/local/lib/cmake/ProjectA" NO_DEFAULT_PATH)

add_executable(B main.cpp)

# 链接 ProjectA
target_link_libraries(B PRIVATE A)

```

```shell
[wind@Ubuntu interface_link_demo]$ mkdir A
[wind@Ubuntu interface_link_demo]$ mkdir B
[wind@Ubuntu interface_link_demo]$ cd A
[wind@Ubuntu A]$ touch CMakeLists.txt
[wind@Ubuntu A]$ touch libA.cpp
[wind@Ubuntu A]$ mkdir build
[wind@Ubuntu A]$ cd ..
[wind@Ubuntu interface_link_demo]$ cd B
[wind@Ubuntu B]$ touch CMakeLists.txt
[wind@Ubuntu B]$ touch main.cpp
[wind@Ubuntu B]$ mkdir build
[wind@Ubuntu B]$ cd ..
[wind@Ubuntu interface_link_demo]$ cd A
[wind@Ubuntu A]$ cd build/
[wind@Ubuntu build]$ cmake ..
-- The CXX compiler identification is GNU 13.3.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/wind/cmakeClass/interface_link_demo/A/build
[wind@Ubuntu build]$ cmake --build .
[ 50%] Building CXX object CMakeFiles/A.dir/libA.cpp.o
[100%] Linking CXX static library libA.a
[100%] Built target A
[wind@Ubuntu build]$ sudo cmake --install .
[sudo] password for wind: 
-- Install configuration: ""
-- Installing: /usr/local/lib/libA.a
-- Installing: /usr/local/lib/cmake/ProjectA/ProjectAConfig.cmake
-- Installing: /usr/local/lib/cmake/ProjectA/ProjectAConfig-noconfig.cmake
[wind@Ubuntu build]$ cd ..
[wind@Ubuntu A]$ cd ..
[wind@Ubuntu interface_link_demo]$ cd B
[wind@Ubuntu B]$ cd build/
[wind@Ubuntu build]$ cmake ..
-- The CXX compiler identification is GNU 13.3.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/wind/cmakeClass/interface_link_demo/B/build
[wind@Ubuntu build]$ cmake --build . -j -v
/usr/bin/cmake -S/home/wind/cmakeClass/interface_link_demo/B -B/home/wind/cmakeClass/interface_link_demo/B/build --check-build-system CMakeFiles/Makefile.cmake 0
/usr/bin/cmake -E cmake_progress_start /home/wind/cmakeClass/interface_link_demo/B/build/CMakeFiles /home/wind/cmakeClass/interface_link_demo/B/build//CMakeFiles/progress.marks
/usr/bin/gmake  -f CMakeFiles/Makefile2 all
gmake[1]: Entering directory '/home/wind/cmakeClass/interface_link_demo/B/build'
/usr/bin/gmake  -f CMakeFiles/B.dir/build.make CMakeFiles/B.dir/depend
gmake[2]: Entering directory '/home/wind/cmakeClass/interface_link_demo/B/build'
cd /home/wind/cmakeClass/interface_link_demo/B/build && /usr/bin/cmake -E cmake_depends "Unix Makefiles" /home/wind/cmakeClass/interface_link_demo/B /home/wind/cmakeClass/interface_link_demo/B /home/wind/cmakeClass/interface_link_demo/B/build /home/wind/cmakeClass/interface_link_demo/B/build /home/wind/cmakeClass/interface_link_demo/B/build/CMakeFiles/B.dir/DependInfo.cmake --color=
gmake[2]: Leaving directory '/home/wind/cmakeClass/interface_link_demo/B/build'
/usr/bin/gmake  -f CMakeFiles/B.dir/build.make CMakeFiles/B.dir/build
gmake[2]: Entering directory '/home/wind/cmakeClass/interface_link_demo/B/build'
[ 50%] Building CXX object CMakeFiles/B.dir/main.cpp.o
/usr/bin/c++    -MD -MT CMakeFiles/B.dir/main.cpp.o -MF CMakeFiles/B.dir/main.cpp.o.d -o CMakeFiles/B.dir/main.cpp.o -c /home/wind/cmakeClass/interface_link_demo/B/main.cpp
[100%] Linking CXX executable B
/usr/bin/cmake -E cmake_link_script CMakeFiles/B.dir/link.txt --verbose=1
/usr/bin/c++ CMakeFiles/B.dir/main.cpp.o -o B  /usr/local/lib/libA.a -lm -lpthread 
gmake[2]: Leaving directory '/home/wind/cmakeClass/interface_link_demo/B/build'
[100%] Built target B
gmake[1]: Leaving directory '/home/wind/cmakeClass/interface_link_demo/B/build'
/usr/bin/cmake -E cmake_progress_start /home/wind/cmakeClass/interface_link_demo/B/build/CMakeFiles 0
[wind@Ubuntu build]$ 
```

观察`/usr/bin/c++ CMakeFiles/B.dir/main.cpp.o -o B  /usr/local/lib/libA.a -lm -lpthread `我们可以看到, 在项目A中写入`INTERFACE_LINK_LIBRARIES`的库, 在项目B中都被一一链接.

如果将A改为动态库, 由于动态库自身已经包含了链接过程, 所以并不会看到-l的其它内容

最后把A从系统中删除, 避免污染系统

```shell
[wind@Ubuntu build]$ cd ../../
[wind@Ubuntu interface_link_demo]$ cd A/build/
[wind@Ubuntu build]$ sudo xargs rm < install_manifest.txt
[wind@Ubuntu build]$ 
```

在上述过程中, 目标`B`的链接有两个来源, 一是它自身就链接使用的`libA`, 二是`libA`中通过`INTERFACE_LINK_LIBRARIES`传递给`B`的哪些需要链接的库, 项目`B`的`cmake`就会通过读取项目`A`传递下来的`INTERFACE_LINK_LIBRARIES`, 从而知道还要链接哪些库. 而在实际开发过程中. 这个过程是递归的, 项目`B`依赖`libA`, `libA`在使用时需要数学库`m`和线程库`pthread`, 相对应的`m`和`pthread`也可能有自己的`INTERFACE_LINK_LIBRARIES`, 因此就需要进一步寻找, 但我们这里, 一方面`m`和`pthread`是动态库, 它在生成中自己内部已经链接过了, 另一方面, 这些库非常基础, 所以从设计理念上来说, 即使换成静态库, 也不一定能发现还需要其它库, 所以递归在这里就停止了.

不过在实际开发中, 我们有时不会把权限划分地特别细, 类似与C++都使用`public`继承, 在`cmake`中, 一般都是都是用`PUBLIC`权限关键字, 这样比较省事.

------------

下面, 我们再在上面实验的基础上, 再把头文件的搜索路径, 也就是`target_include_directories`添加进来.

我们建立如图的项目结构

```shell
[wind@Ubuntu test_target_link_libraries]$ tree .
.
├── build
├── CMakeLists.txt
├── main.cpp
└── src
    ├── add.cpp
    └── CMakeLists.txt

2 directories, 4 files
[wind@Ubuntu test_target_link_libraries]$ 
```

```cmake
# src下的CMakeLists.txt
add_library(add STATIC add.cpp)

## 第三方库

# 添加静态库头文件的包含路径 
target_include_directories(add PRIVATE "/usr/local/include/private")
target_include_directories(add PUBLIC "/usr/local/include/public")
target_include_directories(add INTERFACE "/usr/local/include/interface")

# 添加库文件搜索路径
target_link_directories(add PRIVATE "/usr/local/lib/private")
target_link_directories(add PUBLIC "/usr/local/lib/public")
target_link_directories(add INTERFACE "/usr/local/lib/interface")

## 系统库
target_link_libraries(add INTERFACE "pthread")

```

```cpp
// add.cpp
// 我们不写任何逻辑, 也不包含实际头文件这是因为CMakeLists.txt中包含的第三
// 方库, 实际上都不存在, 路径都是编的, 所以也没法包含, 我们只是让编译器走个过场

```

```cmake
# 顶层CMakeLists.txt
cmake_minimum_required(VERSION 3.18)

project(TestLinkLibrary 
    LANGUAGES CXX
)

add_subdirectory(src)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE add)

```

```cpp
// main.cpp
int main()
{
    return 0;
}

```

```shell
[wind@Ubuntu test_target_link_libraries]$ cd build
[wind@Ubuntu build]$ cmake ..
-- The CXX compiler identification is GNU 13.3.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/wind/cmakeClass/test_target_link_libraries/build
[wind@Ubuntu build]$ cmake --build . -v
/usr/bin/cmake -S/home/wind/cmakeClass/test_target_link_libraries -B/home/wind/cmakeClass/test_target_link_libraries/build --check-build-system CMakeFiles/Makefile.cmake 0
/usr/bin/cmake -E cmake_progress_start /home/wind/cmakeClass/test_target_link_libraries/build/CMakeFiles /home/wind/cmakeClass/test_target_link_libraries/build//CMakeFiles/progress.marks
/usr/bin/gmake  -f CMakeFiles/Makefile2 all
gmake[1]: Entering directory '/home/wind/cmakeClass/test_target_link_libraries/build'
/usr/bin/gmake  -f src/CMakeFiles/add.dir/build.make src/CMakeFiles/add.dir/depend
gmake[2]: Entering directory '/home/wind/cmakeClass/test_target_link_libraries/build'
cd /home/wind/cmakeClass/test_target_link_libraries/build && /usr/bin/cmake -E cmake_depends "Unix Makefiles" /home/wind/cmakeClass/test_target_link_libraries /home/wind/cmakeClass/test_target_link_libraries/src /home/wind/cmakeClass/test_target_link_libraries/build /home/wind/cmakeClass/test_target_link_libraries/build/src /home/wind/cmakeClass/test_target_link_libraries/build/src/CMakeFiles/add.dir/DependInfo.cmake --color=
gmake[2]: Leaving directory '/home/wind/cmakeClass/test_target_link_libraries/build'
/usr/bin/gmake  -f src/CMakeFiles/add.dir/build.make src/CMakeFiles/add.dir/build
gmake[2]: Entering directory '/home/wind/cmakeClass/test_target_link_libraries/build'
[ 25%] Building CXX object src/CMakeFiles/add.dir/add.cpp.o

# 静态库add-I选项
cd /home/wind/cmakeClass/test_target_link_libraries/build/src && /usr/bin/c++  -I/usr/local/include/private -I/usr/local/include/public  -MD -MT src/CMakeFiles/add.dir/add.cpp.o -MF CMakeFiles/add.dir/add.cpp.o.d -o CMakeFiles/add.dir/add.cpp.o -c /home/wind/cmakeClass/test_target_link_libraries/src/add.cpp

[ 50%] Linking CXX static library libadd.a
cd /home/wind/cmakeClass/test_target_link_libraries/build/src && /usr/bin/cmake -P CMakeFiles/add.dir/cmake_clean_target.cmake
cd /home/wind/cmakeClass/test_target_link_libraries/build/src && /usr/bin/cmake -E cmake_link_script CMakeFiles/add.dir/link.txt --verbose=1
/usr/bin/ar qc libadd.a CMakeFiles/add.dir/add.cpp.o
/usr/bin/ranlib libadd.a
gmake[2]: Leaving directory '/home/wind/cmakeClass/test_target_link_libraries/build'
[ 50%] Built target add
/usr/bin/gmake  -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/depend
gmake[2]: Entering directory '/home/wind/cmakeClass/test_target_link_libraries/build'
cd /home/wind/cmakeClass/test_target_link_libraries/build && /usr/bin/cmake -E cmake_depends "Unix Makefiles" /home/wind/cmakeClass/test_target_link_libraries /home/wind/cmakeClass/test_target_link_libraries /home/wind/cmakeClass/test_target_link_libraries/build /home/wind/cmakeClass/test_target_link_libraries/build /home/wind/cmakeClass/test_target_link_libraries/build/CMakeFiles/main.dir/DependInfo.cmake --color=
gmake[2]: Leaving directory '/home/wind/cmakeClass/test_target_link_libraries/build'
/usr/bin/gmake  -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
gmake[2]: Entering directory '/home/wind/cmakeClass/test_target_link_libraries/build'
[ 75%] Building CXX object CMakeFiles/main.dir/main.cpp.o

# 可执行程序main-I选项
/usr/bin/c++  -I/usr/local/include/public -I/usr/local/include/interface  -MD -MT CMakeFiles/main.dir/main.cpp.o -MF CMakeFiles/main.dir/main.cpp.o.d -o CMakeFiles/main.dir/main.cpp.o -c /home/wind/cmakeClass/test_target_link_libraries/main.cpp

[100%] Linking CXX executable main

# 可执行程序main -L 和 -l 选项
/usr/bin/cmake -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=1
/usr/bin/c++ CMakeFiles/main.dir/main.cpp.o -o main   -L/usr/local/lib/public  -L/usr/local/lib/interface  -Wl,-rpath,/usr/local/lib/public:/usr/local/lib/interface src/libadd.a -lpthread 

gmake[2]: Leaving directory '/home/wind/cmakeClass/test_target_link_libraries/build'
[100%] Built target main
gmake[1]: Leaving directory '/home/wind/cmakeClass/test_target_link_libraries/build'
/usr/bin/cmake -E cmake_progress_start /home/wind/cmakeClass/test_target_link_libraries/build/CMakeFiles 0
[wind@Ubuntu build]$ 
```

在子目录`src`中, 我们创建了一个静态库`add`, 由于是静态库, 没有链接, 所以在`libadd.a`的生成过程中, 并没有任何`/usr/local/lib`路径被链接.

我们通过`target_include_directories(add PRIVATE "/usr/local/include/private")`将该路径写入了`INCLUDE_DIRECTORIES`中
`target_include_directories(add PUBLIC "/usr/local/include/public")`将该路径写入了`INCLUDE_DIRECTORIES`和`INTERFACE_INCLUDE_DIRECTORIES`中
`target_include_directories(add INTERFACE "/usr/local/include/interface")`将该路径写入了`INTERFACE_INCLUDE_DIRECTORIES`中, 也就是说

对于静态库`add`来说, 其`INCLUDE_DIRECTORIES`包含的路径有`/usr/local/include/private`和`/usr/local/include/public`, 其`INTERFACE_INCLUDE_DIRECTORIES`包含的路径有`/usr/local/include/public`和`/usr/local/include/interface`

因此我们可以看到`/usr/bin/c++  -I/usr/local/include/private -I/usr/local/include/public`

另外, `target_link_directories(add PRIVATE "/usr/local/lib/private")`将该路径写入到`LINK_DIRECTORIES `中
`target_link_directories(add PUBLIC "/usr/local/lib/public")`将该路径写入到`LINK_DIRECTORIES`和`INTERFACE_LINK_DIRECTORIES`中
`target_link_directories(add INTERFACE "/usr/local/lib/interface")`将该路径写入到`INTERFACE_LINK_DIRECTORIES`中, 也就是说, `add`的`LINK_DIRECTORIES`中含有`/usr/local/lib/private`和`/usr/local/lib/public`, 而`INTERFACE_LINK_DIRECTORIES`含有`/usr/local/lib/public`和`/usr/local/lib/interface`

最后`target_link_libraries(add INTERFACE "pthread")`将`pthread`写入到`INTERFACE_LINK_LIBRARIES`中

而对于`main`可执行程序来说, `target_link_libraries(main PRIVATE add)`将`add`写入`LINK_LIBRARIES`中, 而对于其所使用的`add`来说, `main`作为使用者, 还会包含从`add`传播下来的`INTERFACE_INCLUDE_DIRECTORIES`, `INTERFACE_LINK_DIRECTORIES`,`INTERFACE_LINK_LIBRARIES`, 于是就有
`/usr/bin/c++ CMakeFiles/main.dir/main.cpp.o -o main   -L/usr/local/lib/public  -L/usr/local/lib/interface  -Wl,-rpath,/usr/local/lib/public:/usr/local/lib/interface src/libadd.a -lpthread `和`/usr/bin/c++  -I/usr/local/include/public -I/usr/local/include/interface  -MD -MT `

-----------

在之前, 我们曾粗略介绍了`cmake`操作目标属性的API

|     类型      |                    典型关键字(可选关键字)                    |                           主要作用                           |                      涉及的部分核心属性                      |
| :-----------: | :----------------------------------------------------------: | :----------------------------------------------------------: | :----------------------------------------------------------: |
| 通用读/写接口 |     set_target_properties() <br>get_target_properties()      |                   任意目标属性, 最底层API                    |                         任何prop_tgt                         |
| 编译阶段相关  | target_compile_definitions<br>target_compile_options<br>target_precompile_headers<br>target_include_directories<br>target_sources | 控制源文件编译: 宏定义;<BR>编译选项,语言特性,预编译头,<BR>包含目录,源文件列表 | COMPILE_DEFINITIONS<BR>COMPILE_OPTIONS<BR>COMPILE_FEATURES<BR>PRECOMPILE_HEADERS<BR>INCLUDE_DIRECTORIES<BR>SOURCES等 |
| 链接输出阶段  | target_link_libraries<br>target_link_options<br>target_link_directories |              配置目标被链接时库, 选项及搜索路径              | LINK_LIBRARIES<BR>INTERFACE_LINK_LIBRARIES<BR>LINK_OPTIONS<BR>INTERFACE_LINK_OPTIONSLINK_DIRECTORIES<BR>INTERFACE_LINK_DIRECTORIES |
| 安装打包阶段  |          install(TARGETS...)<BR>install(EXPORT...)           |   生成安装规则与包, 控制目标在安装树中的布局及其运行时行为   |     RUNTIME_OUTPUT_DIRECTORY<BR>LIBRARY_OUTPUT_DIRECTORY     |

接下来我们将详细说明它们

`set_target_properties() `和`get_target_properties()`是用来对`cmake`的各类属性进行读写操作的API接口.`cmake`的属性可以被分为 全局属性  目标属性   目录属性   测试属性 源文件属性  缓存条目属性 安装文件属性, 这七类, 这七类属性都可以用`get_target_properties`来取,         对于`cmake`属性的另外一种分法, 是将其分为依赖于目标的属性和不依赖目标, `cmake`自己的属性, 其中, 依赖于不依赖于目标属性的, 可以被视为一种全局变量, 可以使用`${}`直接转义, 而对于依赖于目标的那些属性, 就只能用`get_target_properties`来取. 除此之外, 还有"第八类" 用户自定义变量, 也可以用`${}`转义, 直接获取.   目标属性依赖于目标, 其它的六类是不依赖于目标的

基本形式为

```cmake
set_target_properties(<target1> <target2> ...
					PROPERTIES <prop1> <value1>
							  <prop2> <value2>...)
							  
get_target_properties(<variable> <target> <property>)
```

需要注意的是别名目标不能设置属性, 因为别名目标是只读的,

[在此处](https://cmake.org/cmake/help/latest/manual/cmake-properties.7.html#target-properties)列举了`cmake`的所有目标属性, 部分常见的属性进行了专门的接口特化, 使之能够更方便地进行设置.

 接下来我们就再新建一个项目, 并通过上面的两个接口对目标属性和安装属性进行设置

```shell
[wind@Ubuntu test_set_target_properties]$ tree .
.
├── build
├── CMakeLists.txt
├── main.cpp
└── src
    ├── add.cpp
    └── CMakeLists.txt

2 directories, 4 files
[wind@Ubuntu test_set_target_properties]$ 
```

```cmake
# 顶层CMakeLists.txt
cmake_minimum_required(VERSION 3.18)

project(TestProp
        LANGUAGES CXX
)

add_subdirectory(src)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE add)

```

```cpp
// main.cpp
#include<iostream>

int main()
{
    return 0;
}

```

```cmake
# src下的CMakeLists.txt
# 这次我们使用动态库
add_library(add SHARED add.cpp)

set_target_properties(add PROPERTIES

        ## 目标属性

            # 编译属性
                COMPILE_OPTIONS "-g"
                COMPILE_OPTIONS "-O3"
                COMPILE_OPTIONS "-fPIC"                  

                INCLUDE_DIRECTORIES "/public"
                INTERFACE_INCLUDE_DIRECTORIES "/interface"

            # 链接属性
                LINK_DIRECTORIES "/public"
                INTERFACE_LINK_DIRECTORIES "/interface"
                LINK_LIBRARIES "curl"
                INTERFACE_LINK_LIBRARIES "jsoncpp"             # sudo apt install libjsoncpp-dev

            # 输出属性
                RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
                ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"

            BUILD_RPATH "${CMAKE_BINARY_DIR}/lib"  # 为项目中的动态库文件临时链接提供方案, 这样就不需要将其安装到系统中

        ## 安装属性
            # 库在安装到系统后, BUILD_RPATH就会失效, 转而使用系统的安装路径
            INSTALL_RPATH "lib" #  实际上就是/usr/local/lib
            OUTPUT_NAME "add"
            VERSION "1.2.3"
            SOVERSION "20"      #  动态库的兼容版本, 描述库中所提供接口执行的标准, 为用户提供一种简便的验证接口是否还可用的方式
)

```

```cpp
// src下的add.cpp

```

```shell
[wind@Ubuntu test_set_target_properties]$ cd build
[wind@Ubuntu build]$ cmake ..
-- The CXX compiler identification is GNU 13.3.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/wind/cmakeClass/test_set_target_properties/build
[wind@Ubuntu build]$ cmake --build . -v
/usr/bin/cmake -S/home/wind/cmakeClass/test_set_target_properties -B/home/wind/cmakeClass/test_set_target_properties/build --check-build-system CMakeFiles/Makefile.cmake 0
/usr/bin/cmake -E cmake_progress_start /home/wind/cmakeClass/test_set_target_properties/build/CMakeFiles /home/wind/cmakeClass/test_set_target_properties/build//CMakeFiles/progress.marks
/usr/bin/gmake  -f CMakeFiles/Makefile2 all
gmake[1]: Entering directory '/home/wind/cmakeClass/test_set_target_properties/build'
/usr/bin/gmake  -f src/CMakeFiles/add.dir/build.make src/CMakeFiles/add.dir/depend
gmake[2]: Entering directory '/home/wind/cmakeClass/test_set_target_properties/build'
cd /home/wind/cmakeClass/test_set_target_properties/build && /usr/bin/cmake -E cmake_depends "Unix Makefiles" /home/wind/cmakeClass/test_set_target_properties /home/wind/cmakeClass/test_set_target_properties/src /home/wind/cmakeClass/test_set_target_properties/build /home/wind/cmakeClass/test_set_target_properties/build/src /home/wind/cmakeClass/test_set_target_properties/build/src/CMakeFiles/add.dir/DependInfo.cmake --color=
gmake[2]: Leaving directory '/home/wind/cmakeClass/test_set_target_properties/build'
/usr/bin/gmake  -f src/CMakeFiles/add.dir/build.make src/CMakeFiles/add.dir/build
gmake[2]: Entering directory '/home/wind/cmakeClass/test_set_target_properties/build'
[ 25%] Building CXX object src/CMakeFiles/add.dir/add.cpp.o
cd /home/wind/cmakeClass/test_set_target_properties/build/src && /usr/bin/c++ -Dadd_EXPORTS -I/public -fPIC -fPIC -MD -MT src/CMakeFiles/add.dir/add.cpp.o -MF CMakeFiles/add.dir/add.cpp.o.d -o CMakeFiles/add.dir/add.cpp.o -c /home/wind/cmakeClass/test_set_target_properties/src/add.cpp
[ 50%] Linking CXX shared library ../lib/libadd.so
cd /home/wind/cmakeClass/test_set_target_properties/build/src && /usr/bin/cmake -E cmake_link_script CMakeFiles/add.dir/link.txt --verbose=1
/usr/bin/c++ -fPIC -shared -Wl,-soname,libadd.so.20 -o ../lib/libadd.so.1.2.3 CMakeFiles/add.dir/add.cpp.o   -L/public  -Wl,-rpath,/home/wind/cmakeClass/test_set_target_properties/build/lib:/public -lcurl 
cd /home/wind/cmakeClass/test_set_target_properties/build/src && /usr/bin/cmake -E cmake_symlink_library ../lib/libadd.so.1.2.3 ../lib/libadd.so.20 ../lib/libadd.so
gmake[2]: Leaving directory '/home/wind/cmakeClass/test_set_target_properties/build'
[ 50%] Built target add
/usr/bin/gmake  -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/depend
gmake[2]: Entering directory '/home/wind/cmakeClass/test_set_target_properties/build'
cd /home/wind/cmakeClass/test_set_target_properties/build && /usr/bin/cmake -E cmake_depends "Unix Makefiles" /home/wind/cmakeClass/test_set_target_properties /home/wind/cmakeClass/test_set_target_properties /home/wind/cmakeClass/test_set_target_properties/build /home/wind/cmakeClass/test_set_target_properties/build /home/wind/cmakeClass/test_set_target_properties/build/CMakeFiles/main.dir/DependInfo.cmake --color=
gmake[2]: Leaving directory '/home/wind/cmakeClass/test_set_target_properties/build'
/usr/bin/gmake  -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
gmake[2]: Entering directory '/home/wind/cmakeClass/test_set_target_properties/build'
[ 75%] Building CXX object CMakeFiles/main.dir/main.cpp.o
/usr/bin/c++  -I/interface  -MD -MT CMakeFiles/main.dir/main.cpp.o -MF CMakeFiles/main.dir/main.cpp.o.d -o CMakeFiles/main.dir/main.cpp.o -c /home/wind/cmakeClass/test_set_target_properties/main.cpp
[100%] Linking CXX executable main
/usr/bin/cmake -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=1
/usr/bin/c++ CMakeFiles/main.dir/main.cpp.o -o main   -L/interface  -Wl,-rpath,/interface:/home/wind/cmakeClass/test_set_target_properties/build/lib lib/libadd.so.1.2.3 -ljsoncpp 
gmake[2]: Leaving directory '/home/wind/cmakeClass/test_set_target_properties/build'
[100%] Built target main
gmake[1]: Leaving directory '/home/wind/cmakeClass/test_set_target_properties/build'
/usr/bin/cmake -E cmake_progress_start /home/wind/cmakeClass/test_set_target_properties/build/CMakeFiles 0
[wind@Ubuntu build]$ 
```

我们看这一段

```cmake
[ 25%] Building CXX object src/CMakeFiles/add.dir/add.cpp.o
cd /home/wind/cmakeClass/test_set_target_properties/build/src && /usr/bin/c++ -Dadd_EXPORTS -I/public -fPIC -fPIC -MD -MT src/CMakeFiles/add.dir/add.cpp.o -MF CMakeFiles/add.dir/add.cpp.o.d -o CMakeFiles/add.dir/add.cpp.o -c /home/wind/cmakeClass/test_set_target_properties/src/add.cpp
```

我们发现详细的编译选项, `-g  -O3`并没有出现, 这是因为不同版本的`cmake`对于 `COMPILE_OPTIONS`的属性处理方式有些不同, 首先需要说明的是, 无论哪个版本的`cmake`, 都是把`COMPILE_OPTIONS`后面的参数当做一个参数传给编译器, 所以你不能写成`COMPILE_OPTIONS "-g -O3 -fPIC"`, 所以在上面, 我们把它拆开写了, 但拆开写为什么只有`fPIC`这一个参数被传给`cmake`呢? 这是因为在`cmake 3.24 +`之前, `COMPILE_OPTIONS`是覆盖写的, 所以最后一个选项覆盖掉了前两个选项, `3.24 +`之后变成了合并写, 所以就能都被传递, 为了解决我们当前覆盖写的问题, 我们可以使用`target_compile_options`这个指令为编译器增加选项, 这也是`cmake`官方所推荐的写法.

```cmake
# 这次我们使用动态库
add_library(add SHARED add.cpp)

# 添加编译选项
target_compile_options(add PRIVATE -g -O3 -fPIC)

set_target_properties(add PROPERTIES

        ## 目标属性

            # 编译属性
                INCLUDE_DIRECTORIES "/public"
                INTERFACE_INCLUDE_DIRECTORIES "/interface"

            # 链接属性
                LINK_DIRECTORIES "/public"
                INTERFACE_LINK_DIRECTORIES "/interface"
                LINK_LIBRARIES "curl"
                INTERFACE_LINK_LIBRARIES "jsoncpp"             # sudo apt install libjsoncpp-dev

            # 输出属性
                RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
                ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"

            BUILD_RPATH "${CMAKE_BINARY_DIR}/lib"  # 为项目中的动态库文件临时链接提供方案, 这样就不需要将其安装到系统中

        ## 安装属性
            # 库在安装到系统后, BUILD_RPATH就会失效, 转而使用系统的安装路径
            INSTALL_RPATH "lib" #  实际上就是/usr/local/lib
            OUTPUT_NAME "add"
            VERSION "1.2.3"
            SOVERSION "20"      #  动态库的兼容版本, 描述库中所提供接口执行的标准, 为用户提供一种简便的验证接口是否还可用的方式
)


```

```shell
[wind@Ubuntu build]$ rm -rf ./*
[wind@Ubuntu build]$ cmake ..
-- The CXX compiler identification is GNU 13.3.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/wind/cmakeClass/test_set_target_properties/build
[wind@Ubuntu build]$ cmake --build . -v
/usr/bin/cmake -S/home/wind/cmakeClass/test_set_target_properties -B/home/wind/cmakeClass/test_set_target_properties/build --check-build-system CMakeFiles/Makefile.cmake 0
/usr/bin/cmake -E cmake_progress_start /home/wind/cmakeClass/test_set_target_properties/build/CMakeFiles /home/wind/cmakeClass/test_set_target_properties/build//CMakeFiles/progress.marks
/usr/bin/gmake  -f CMakeFiles/Makefile2 all
gmake[1]: Entering directory '/home/wind/cmakeClass/test_set_target_properties/build'
/usr/bin/gmake  -f src/CMakeFiles/add.dir/build.make src/CMakeFiles/add.dir/depend
gmake[2]: Entering directory '/home/wind/cmakeClass/test_set_target_properties/build'
cd /home/wind/cmakeClass/test_set_target_properties/build && /usr/bin/cmake -E cmake_depends "Unix Makefiles" /home/wind/cmakeClass/test_set_target_properties /home/wind/cmakeClass/test_set_target_properties/src /home/wind/cmakeClass/test_set_target_properties/build /home/wind/cmakeClass/test_set_target_properties/build/src /home/wind/cmakeClass/test_set_target_properties/build/src/CMakeFiles/add.dir/DependInfo.cmake --color=
gmake[2]: Leaving directory '/home/wind/cmakeClass/test_set_target_properties/build'
/usr/bin/gmake  -f src/CMakeFiles/add.dir/build.make src/CMakeFiles/add.dir/build
gmake[2]: Entering directory '/home/wind/cmakeClass/test_set_target_properties/build'
[ 25%] Building CXX object src/CMakeFiles/add.dir/add.cpp.o
cd /home/wind/cmakeClass/test_set_target_properties/build/src && /usr/bin/c++ -Dadd_EXPORTS -I/public -fPIC -g -O3 -fPIC -MD -MT src/CMakeFiles/add.dir/add.cpp.o -MF CMakeFiles/add.dir/add.cpp.o.d -o CMakeFiles/add.dir/add.cpp.o -c /home/wind/cmakeClass/test_set_target_properties/src/add.cpp
[ 50%] Linking CXX shared library ../lib/libadd.so
cd /home/wind/cmakeClass/test_set_target_properties/build/src && /usr/bin/cmake -E cmake_link_script CMakeFiles/add.dir/link.txt --verbose=1
/usr/bin/c++ -fPIC -shared -Wl,-soname,libadd.so.20 -o ../lib/libadd.so.1.2.3 CMakeFiles/add.dir/add.cpp.o   -L/public  -Wl,-rpath,/home/wind/cmakeClass/test_set_target_properties/build/lib:/public -lcurl 
cd /home/wind/cmakeClass/test_set_target_properties/build/src && /usr/bin/cmake -E cmake_symlink_library ../lib/libadd.so.1.2.3 ../lib/libadd.so.20 ../lib/libadd.so
gmake[2]: Leaving directory '/home/wind/cmakeClass/test_set_target_properties/build'
[ 50%] Built target add
/usr/bin/gmake  -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/depend
gmake[2]: Entering directory '/home/wind/cmakeClass/test_set_target_properties/build'
cd /home/wind/cmakeClass/test_set_target_properties/build && /usr/bin/cmake -E cmake_depends "Unix Makefiles" /home/wind/cmakeClass/test_set_target_properties /home/wind/cmakeClass/test_set_target_properties /home/wind/cmakeClass/test_set_target_properties/build /home/wind/cmakeClass/test_set_target_properties/build /home/wind/cmakeClass/test_set_target_properties/build/CMakeFiles/main.dir/DependInfo.cmake --color=
gmake[2]: Leaving directory '/home/wind/cmakeClass/test_set_target_properties/build'
/usr/bin/gmake  -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
gmake[2]: Entering directory '/home/wind/cmakeClass/test_set_target_properties/build'
[ 75%] Building CXX object CMakeFiles/main.dir/main.cpp.o
/usr/bin/c++  -I/interface  -MD -MT CMakeFiles/main.dir/main.cpp.o -MF CMakeFiles/main.dir/main.cpp.o.d -o CMakeFiles/main.dir/main.cpp.o -c /home/wind/cmakeClass/test_set_target_properties/main.cpp
[100%] Linking CXX executable main
/usr/bin/cmake -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=1
/usr/bin/c++ CMakeFiles/main.dir/main.cpp.o -o main   -L/interface  -Wl,-rpath,/interface:/home/wind/cmakeClass/test_set_target_properties/build/lib lib/libadd.so.1.2.3 -ljsoncpp 
gmake[2]: Leaving directory '/home/wind/cmakeClass/test_set_target_properties/build'
[100%] Built target main
gmake[1]: Leaving directory '/home/wind/cmakeClass/test_set_target_properties/build'
/usr/bin/cmake -E cmake_progress_start /home/wind/cmakeClass/test_set_target_properties/build/CMakeFiles 0
[wind@Ubuntu build]$ 

```

然后我们可以看到

```shell
[ 25%] Building CXX object src/CMakeFiles/add.dir/add.cpp.o
cd /home/wind/cmakeClass/test_set_target_properties/build/src && /usr/bin/c++ -Dadd_EXPORTS -I/public -fPIC -g -O3 -fPIC -MD -MT src/CMakeFiles/add.dir/add.cpp.o -MF CMakeFiles/add.dir/add.cpp.o.d -o CMakeFiles/add.dir/add.cpp.o -c /home/wind/cmakeClass/test_set_target_properties/src/add.cpp
```

`-g -O3 -fPIC`都已经全部加上了, 并且, `-fPIC`默认也会带, 因此有两个. `-I/public`也验证了我们之前的说法.

```shell
/usr/bin/c++ -fPIC -shared -Wl,-soname,libadd.so.20 -o ../lib/libadd.so.1.2.3 CMakeFiles/add.dir/add.cpp.o   -L/public  -Wl,-rpath,/home/wind/cmakeClass/test_set_target_properties/build/lib:/public -lcurl 
cd /home/wind/cmakeClass/test_set_target_properties/build/src && /usr/bin/cmake -E cmake_symlink_library ../lib/libadd.so.1.2.3 ../lib/libadd.so.20 ../lib/libadd.so
```

`-L/public`, 也在我们的设置中, `/home/wind/cmakeClass/test_set_target_properties/build/lib:/public`中的`/public`是库文件的输出路径.也就是`        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"`这一设置, `-rpath`, `rpath`其实就是描述从哪里可以找到动态库, 在安装之前, 其内容就是`BUILD_RPATH`, `-lcurl`也印证了`        LINK_LIBRARIES "curl"`, 

这一段

```shell
[ 75%] Building CXX object CMakeFiles/main.dir/main.cpp.o
/usr/bin/c++  -I/interface  -MD -MT CMakeFiles/main.dir/main.cpp.o -MF CMakeFiles/main.dir/main.cpp.o.d -o CMakeFiles/main.dir/main.cpp.o -c /home/wind/cmakeClass/test_set_target_properties/main.cpp
```

我们可以看到`-I/interface`

```shell
/usr/bin/cmake -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=1
/usr/bin/c++ CMakeFiles/main.dir/main.cpp.o -o main   -L/interface  -Wl,-rpath,/interface:/home/wind/cmakeClass/test_set_target_properties/build/lib lib/libadd.so.1.2.3 -ljsoncpp 
```

可以看到`-L/interface  -rpath    -ljsoncpp `

上述过程便体现了`cmake`基于目标的属性设置加属性传递的现代化构建系统的优点.

-------------

下面介绍`add_subdirectory`, 该函数的作用是添加子目录到构建树中, `cmake`会自动进入到源码树的子目录, 执行位于子目录中的`CMakeLists.txt` 基本形式为

```cmake
add_subdirectory(source_dir [binary_dir] [EXCLUDE_FROM_ALL] [SYSTEM])
```

`add_subdirectory`是`cmake`构建层次结构的递归入口, 在`cmake`中, 有构建树和源代码树的说法, 源代码树就是存放源代码的文件树, 而, 构建树, 就是存放构建目标的文件树.`cmake`会进入`add_subdirectory`所描述的子目录下, 执行其中的`CMakeLists.txt`文件.如果我们后续不修改生成目录的话, `cmake`就会仿照源代码树的结构生成与之对应的子目录用来存放中间文件及构建目标.

子目录可以读取父目录下`set`(就是用户自定义)的变量, 也可以覆盖之后往下继续传递, 父目录则一般无法读取子目录下定义的变量, 除非使用`CACHE or PAPENT_SCOPE`.

另外需要注意的是, 对于已经完成构建的目标, 在所有目录中都能被链接.

下面, 我们对比`include`和`add_subdirectory`. `include`是把包含的脚本当做本目录的一部分立即执行, 而对于`add_subdirectory`来说, 则是进入一个新的目录作用域, 递归执行其中的`CMakeLists.txt`, 并为它构建相应的输出目录.

对于`add_subdirectory`

|          变量名          | 进入子目录后是否发生变化 |                 说明                 |
| :----------------------: | :----------------------: | :----------------------------------: |
| CMAKE_CURRENT_SOURCE_DIR |           变化           |       变为子目录的源代码树目录       |
| CMAKE_CURRENT_BINARY_DIR |           变化           |        变为子目录的构建树目录        |
| CMAKE_CURRENT_LIST_FILE  |           变化           | 变为子目录的CMakeLists.txt文件全路径 |
|  CMAKE_CURRENT_LIST_DIR  |           变化           |  变为子目录的CMakeLists.txt文件目录  |

对于`include`

|          变量名          | 进入子目录后是否发生变化 |                 说明                 |
| :----------------------: | :----------------------: | :----------------------------------: |
| CMAKE_CURRENT_SOURCE_DIR |          不变化          |       还是父目录的源代码树目录       |
| CMAKE_CURRENT_BINARY_DIR |          不变化          |        还是父目录的构建树目录        |
| CMAKE_CURRENT_LIST_FILE  |           变化           | 变为子目录的CMakeLists.txt文件全路径 |
|  CMAKE_CURRENT_LIST_DIR  |           变化           |  变为子目录的CMakeLists.txt文件目录  |

下面, 我们就通过实际打印来观察现象. 

我们就直接复用原先的`test_include`, 将其进行部分修改, 进行实验

```shell
[wind@Ubuntu test_add_sub_dir]$ tree .
.
├── build
├── CMakeLists.txt
├── sub
│   └── CMakeLists.txt
└── test.cpp

2 directories, 3 files
[wind@Ubuntu test_add_sub_dir]$ 
```

```cmake
# 顶层CMakeLists.txt
cmake_minimum_required(VERSION 3.18)

project(TestInclude)

add_executable(test test.cpp)

include(GNUInstallDirs)
install(TARGETS test)

message(STATUS "from top-level CMakeLists.txt")

# 打印源代码目录
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

# 打印构建目录
message(STATUS "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")

# 打印当前执行cmake脚本的完整名称
message(STATUS "CMAKE_CURRENT_LIST_FILE: ${CMAKE_CURRENT_LIST_FILE}")

# 打印当前执行cmake脚本的完整目录
message(STATUS "CMAKE_CURRENT_LIST_DIR: ${CMAKE_CURRENT_LIST_DIR}")

# 添加子目录
add_subdirectory(sub)

```

```cpp
// test.cpp
#include<iostream>

int main()
{
    return 0;
}

```

```cmake
# 子目录CMakeLists.txt
message(STATUS "from sub/sub.cmake")

# 打印源代码目录
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

# 生成构建目录
message(STATUS "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")

# 打印当前执行cmake脚本的完整名称
message(STATUS "CMAKE_CURRENT_LIST_FILE: ${CMAKE_CURRENT_LIST_FILE}")

# 打印当前执行cmake脚本的完整目录
message(STATUS "CMAKE_CURRENT_LIST_DIR: ${CMAKE_CURRENT_LIST_DIR}")

```

```shell
[wind@Ubuntu test_add_sub_dir]$ cd build
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
-- from top-level CMakeLists.txt
-- CMAKE_CURRENT_SOURCE_DIR: /home/wind/cmakeClass/test_add_sub_dir
-- CMAKE_CURRENT_BINARY_DIR: /home/wind/cmakeClass/test_add_sub_dir/build
-- CMAKE_CURRENT_LIST_FILE: /home/wind/cmakeClass/test_add_sub_dir/CMakeLists.txt
-- CMAKE_CURRENT_LIST_DIR: /home/wind/cmakeClass/test_add_sub_dir
-- from sub/sub.cmake
-- CMAKE_CURRENT_SOURCE_DIR: /home/wind/cmakeClass/test_add_sub_dir/sub
-- CMAKE_CURRENT_BINARY_DIR: /home/wind/cmakeClass/test_add_sub_dir/build/sub
-- CMAKE_CURRENT_LIST_FILE: /home/wind/cmakeClass/test_add_sub_dir/sub/CMakeLists.txt
-- CMAKE_CURRENT_LIST_DIR: /home/wind/cmakeClass/test_add_sub_dir/sub
-- Configuring done
-- Generating done
-- Build files have been written to: /home/wind/cmakeClass/test_add_sub_dir/build
[wind@Ubuntu build]$ cd ~/cmakeClass/test_include/build
[wind@Ubuntu build]$ rm -rf ./*
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
-- from top-level CMakeLists.txt
-- CMAKE_CURRENT_SOURCE_DIR: /home/wind/cmakeClass/test_include
-- CMAKE_CURRENT_BINARY_DIR: /home/wind/cmakeClass/test_include/build
-- CMAKE_CURRENT_LIST_FILE: /home/wind/cmakeClass/test_include/CMakeLists.txt
-- CMAKE_CURRENT_LIST_DIR: /home/wind/cmakeClass/test_include
-- from sub/sub.cmake
-- CMAKE_CURRENT_SOURCE_DIR: /home/wind/cmakeClass/test_include
-- CMAKE_CURRENT_BINARY_DIR: /home/wind/cmakeClass/test_include/build
-- CMAKE_CURRENT_LIST_FILE: /home/wind/cmakeClass/test_include/sub/sub.cmake
-- CMAKE_CURRENT_LIST_DIR: /home/wind/cmakeClass/test_include/sub
-- Configuring done
-- Generating done
-- Build files have been written to: /home/wind/cmakeClass/test_include/build
[wind@Ubuntu build]$ 
```

这些目录常被用来进行辅助文件定位, 用相对路径的方式.

---------

下面, 我们穿插一下`cmake`内部库文件的生成和定位方式

我们之前说过, 目标在`cmake`中的作用域是全局的, 引申我们在`Linux`中学习到的知识, `cmake`自身对于其中的各种目标也必然拥有系统性的管理机制. 实际上, 在`cmake`中有着专门描述目标的对象. 而这些对象中就包含着目标的种种属性. `cmake`真实通过对这些抽象目标对象的管理实现了对真实对象的管理.

在实际开发过程中, 比如在我们之前对于静态库的生成, 我们看到, 我们并没有直接告诉`cmake`该去哪里找静态库, 但`cmake`还是自己找到并且成功链接了.这就牵扯到`cmake`对于目标对象的管理机制. 具体来说, 可以分为四步

第一步.注册目标
当用户`add`一个目标之后, `cmake`就会构建一个与之相对应的目标对象放入自己的全局容器中

第二步.属性跟踪
无论如何, 用户都是通过接口的方式更新目标属性的, 而对于`cmake`的底层目标属性接口来说, 它都会自动将用户传入的信息写入或更新到目标对象中, 对于用户没有修改的属性, 自然使用默认的缺省值.

第三步.输出定位
`cmake`配置阶段结束后, 进入生成阶段, 生成器会遍历所有的目标对象, 根据目标对象上的各类信息, 结合平台自身的特点, 确定最终的输出路径, 并将其也记录入目标对象中

第四步:链接查询
`cmake`会通过查询原有的目标对象, 定位它们的实际位置, 并生成与之对应的目标生成链接规则, 并转录到具体的`makefile`指令中 

下面我们通过实际例子来验证上面的过程, 在其中, 我们会使用到配置生成阶段的一个生成器表达式, 用于获取目标的输出路径: `$<TARGET_FILE:tgt>`

我们套用之前的`MyMath`项目

```shell
[wind@Ubuntu test_static_build_dir]$ tree .
.
├── app
│   ├── CMakeLists.txt
│   └── main.cpp
├── build
├── CMakeLists.txt
└── my_lib
    ├── CMakeLists.txt
    ├── include
    │   └── my_math.h
    └── src
        ├── add.cpp
        └── sub.cpp

5 directories, 7 files
[wind@Ubuntu test_static_build_dir]$ 
```

```cmake
# 搜集文件列表
file(GLOB SRC_LISTS "*.cpp")

# 构建目标
add_executable(main ${SRC_LISTS})

# 添加链接库列表
target_link_libraries(main PRIVATE MyMath)

set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# 输出静态库路径
add_custom_command(                                             # 添加自定义命令
    TARGET main POST_BUILD                                      # 在目标main生成后执行
    COMMAND echo "输出静态库的全路径"                               
    COMMAND ${CMAKE_COMMAND} -E echo "$<TARGET_FILE:MyMath>"    # CMAKE_COMMAND是cmake指令的安装路径, 打印目标MyMath的生成路径
)
```

```shell
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
-- Build files have been written to: /home/wind/cmakeClass/test_static_build_dir/build
[wind@Ubuntu build]$ cmake --build .
[ 20%] Building CXX object my_lib/CMakeFiles/MyMath.dir/src/add.cpp.o
[ 40%] Building CXX object my_lib/CMakeFiles/MyMath.dir/src/sub.cpp.o
[ 60%] Linking CXX static library ../lib/libMyMath.a
[ 60%] Built target MyMath
[ 80%] Building CXX object app/CMakeFiles/main.dir/main.cpp.o
[100%] Linking CXX executable ../bin/main
输出静态库的全路径
/home/wind/cmakeClass/test_static_build_dir/build/lib/libMyMath.a
[100%] Built target main
[wind@Ubuntu build]$ 
```

# 完
