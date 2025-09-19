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

---------------

下面我们再详细说一下库的安装, 以使得其它用户可以使用`cmake`的`find_package`, 来查找并引用我们制作的静态库.

我们使用`curl`作为我们的示例进行讲解.

```shell
git clone git@github.com:curl/curl.git
cd curl
mkdir build && cd build
cmake .. -DBUILD_SHARED_LIBS=ON -DCMAKE_INSTALL_PREFIX=/usr/local
make -j$(nproc)
sudo make install
```

当把`curl`的源代码克隆并构建安装后, 我们就会发现, `curl`在构建安装之后, 我们可以找到四个这样的文件

```shell
[wind@Ubuntu build]$ sudo updatedb 
wind@Ubuntu build]$ locate curl.h
/home/wind/curl/include/curl/curl.h
/home/wind/curl/packages/OS400/ccsidcurl.h
/usr/local/include/curl/curl.h
[wind@Ubuntu build]$ locate libcurl.so
/usr/lib/x86_64-linux-gnu/libcurl.so.4
/usr/lib/x86_64-linux-gnu/libcurl.so.4.8.0
/usr/local/lib/libcurl.so
/usr/local/lib/libcurl.so.4
/usr/local/lib/libcurl.so.4.8.0
[wind@Ubuntu build]$ locate CURLConfig.cmake
/home/wind/curl/build/generated/CURLConfig.cmake
/usr/local/lib/cmake/CURL/CURLConfig.cmake
[wind@Ubuntu build]$ locate CURLTargets.cmake
/home/wind/curl/build/CMakeFiles/Export/8e83d16133499b505bf3986f4f209a65/CURLTargets.cmake
/usr/local/lib/cmake/CURL/CURLTargets.cmake
[wind@Ubuntu build]$
```

头文件和库文件就不说了, 我们要看的是两个安装到系统中的`cmake`脚本, 它们是我们在构建安装`curl`的时候, `cmake`依据源代码中的`CMakeLists.txt`自动为我们安装到系统中的. 它们指导下游的消费者该如何使用库文件. `find_package(CURL)`会读取`CURLConfig.cmake`, 它是入口性质的配置文件, 负责让`cmake`找到`CURLTargets.cmake`, 而`CURLTargets.cmake`又类似于使用模版, 会依据用户实际需求告诉用户如何使用`curl`.

比如`CURLTargets.cmake`中可以看到对头文件所在目录的描述.

```cmake
# Create imported target CURL::libcurl_shared
add_library(CURL::libcurl_shared SHARED IMPORTED)

set_target_properties(CURL::libcurl_shared PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
)

```

对于库文件, 由于用户可能有不同的需求, 比如`Debug/Release`的不同, 所以没有直接写, 而是让我们找`CURLTargets-*.cmake`这种文件

```cmake
file(GLOB _cmake_config_files "${CMAKE_CURRENT_LIST_DIR}/CURLTargets-*.cmake")
foreach(_cmake_config_file IN LISTS _cmake_config_files)
  include("${_cmake_config_file}")
endforeach()
```

```shell
[wind@Ubuntu build]$ ll /usr/local/lib/cmake/CURL
total 24
drwxr-xr-x 2 root root 4096 Sep  7 09:00 ./
drwxr-xr-x 4 root root 4096 Sep  7 09:00 ../
-rw-r--r-- 1 root root 3556 Sep  7 08:59 CURLConfig.cmake
-rw-r--r-- 1 root root 3011 Sep  7 08:59 CURLConfigVersion.cmake
-rw-r--r-- 1 root root 4004 Sep  7 08:59 CURLTargets.cmake
-rw-r--r-- 1 root root 1218 Sep  7 08:59 CURLTargets-noconfig.cmake
[wind@Ubuntu build]$ 
```

在这里就是`CURLTargets-noconfig.cmake`这个脚本

```cmake
# Import target "CURL::libcurl_shared" for configuration ""
set_property(TARGET CURL::libcurl_shared APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(CURL::libcurl_shared PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libcurl.so.4.8.0"
  IMPORTED_SONAME_NOCONFIG "libcurl.so.4"
  )
```

这里就指定了库文件的位置

对于使用方, 就可以使用`find_package`进行使用

```cmake
cmake_minimum_required(VERSION 3.18)
project(curl_demo LANGUAGES CXX)

# find_package会寻找安装的CURLConfig.cmake
find_package(CURL CONFIG REQUIRED)

add_executable(app main.cpp)

# 官方 Config 包导出CURL::libcurl目标(旧版本可能叫CURL:curl)
target_link_libraries(app PRIVATE CURL:libcurl)
```

在最后, `cmake`就会生成对于`GCC`的编译参数, 告诉`GCC`该包含什么头文件搜索目录, 又该去哪里找头文件

----------

下面, 我们站在发布者角度, 使用`cmake`发布一个简单的数学库到本机的公共目录中.

```shell
[wind@Ubuntu install_static_mymath]$ tree .
.
├── CMakeLists.txt
└── my_lib
    ├── CMakeLists.txt
    ├── Config.cmake.in
    ├── include
    │   └── math.h
    └── src
        ├── add.cpp
        └── sub.cpp

4 directories, 6 files
[wind@Ubuntu install_static_mymath]$
```

```cmake
# 顶层CMakeLists.txt
cmake_minimum_required(VERSION 3.18)

project(InstallMyMath LANGUAGES CXX)

add_subdirectory(my_lib)

```

```cmake
# 子目录CMakeLists.txt
# 收集源代码
file(GLOB SRC_LISTS "src/*.cpp")

# 添加构建目录
add_library(MyMath STATIC ${SRC_LISTS})

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
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

# 安装静态库
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
    # 定义静态库命名域
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
    INSTALL_DESTINATION "lib/cmake/MyMath"
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/MyMathConfig.cmake
    # 将脚本安装到指定目录
    DESTINATION "lib/cmake/MyMath"
)

```

```cmake
# Config.cmake.in
# 加载cmake包初始化脚本
@PACKAGE_INIT@
# 使用MyMathTargets.cmake中的信息生成MyMathConfig.cmake
include(${CMAKE_CURRENT_LIST_DIR}/MyMathTargets.cmake)
```

```shell
[wind@Ubuntu install_static_mymath]$ mkdir build && cd build
[wind@Ubuntu build]$ cmake .. && cmake --build . && sudo cmake --install .
-- The CXX compiler identification is GNU 13.3.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.5s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/install_static_mymath/build
[ 33%] Building CXX object my_lib/CMakeFiles/MyMath.dir/src/add.cpp.o
[ 66%] Building CXX object my_lib/CMakeFiles/MyMath.dir/src/sub.cpp.o
[100%] Linking CXX static library ../lib/libMyMath.a
[100%] Built target MyMath
-- Install configuration: ""
-- Installing: /usr/local/lib/libMyMath.a
-- Up-to-date: /usr/local/include/MyMath
-- Installing: /usr/local/include/MyMath/math.h
-- Installing: /usr/local/lib/cmake/MyMath/MyMathTargets.cmake
-- Installing: /usr/local/lib/cmake/MyMath/MyMathTargets-noconfig.cmake
-- Installing: /usr/local/lib/cmake/MyMath/MyMathConfig.cmake
[wind@Ubuntu build]$ 
```

当我们`find_package`时, `cmake`就会去`/usr/local/lib/cmake/MyMath/`路径下寻找`MyMathConfig.cmake`

```cmake
# 加载cmake包初始化脚本

####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was Config.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################
# 使用MyMathTargets.cmake中的信息生成MyMathConfig.cmake
include(${CMAKE_CURRENT_LIST_DIR}/MyMathTargets.cmake)
```

而`MyMathConfig.cmake`又会包含`MyMathTargets.cmake`, 与之前在`curl`上一样, 其内部又会导出目标并包含`MyMathTargets-*.cmak`

```cmake
# Create imported target MaMath::MyMath
add_library(MaMath::MyMath STATIC IMPORTED)

# Load information for each installed configuration.
file(GLOB _cmake_config_files "${CMAKE_CURRENT_LIST_DIR}/MyMathTargets-*.cmake")
foreach(_cmake_config_file IN LISTS _cmake_config_files)
  include("${_cmake_config_file}")
```

这就匹配到了`MyMathTargets-noconfig.cmake`

```cmake
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "MaMath::MyMath" for configuration ""
set_property(TARGET MaMath::MyMath APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(MaMath::MyMath PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libMyMath.a"
  )

list(APPEND _cmake_import_check_targets MaMath::MyMath )
list(APPEND _cmake_import_check_files_for_MaMath::MyMath "${_IMPORT_PREFIX}/lib/libMyMath.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

```

----

下面我们将作为软件的使用方, 使用上面我们所安装的数学库

```shell
[wind@Ubuntu test_MyMath]$ tree .
.
├── CMakeLists.txt
└── main.cpp

1 directory, 2 files
[wind@Ubuntu test_MyMath]$ 
```

```cmake
cmake_minimum_required(VERSION 3.18)

project(main LANGUAGES CXX)

add_executable(main main.cpp)

find_package(MyMath CONFIG REQUIRED)

target_link_libraries(main PRIVATE MyMath::MyMath)

```

```cpp
#include<iostream>
#include<MyMath/math.h>

int main()
{
    std::cout << add(3,4) << std::endl;
    std::cout << sub(3,4) << std::endl;
    return 0;
}
```

```shell
[wind@Ubuntu test_MyMath]$ mkdir build && cd build
[wind@Ubuntu build]$ cmake .. && cmake --build . -v
-- The CXX compiler identification is GNU 13.3.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.6s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_MyMath/build
Change Dir: '/home/wind/cmakeClass/test_MyMath/build'

Run Build Command(s): /usr/bin/cmake -E env VERBOSE=1 /usr/bin/gmake -f Makefile
/usr/bin/cmake -S/home/wind/cmakeClass/test_MyMath -B/home/wind/cmakeClass/test_MyMath/build --check-build-system CMakeFiles/Makefile.cmake 0
/usr/bin/cmake -E cmake_progress_start /home/wind/cmakeClass/test_MyMath/build/CMakeFiles /home/wind/cmakeClass/test_MyMath/build//CMakeFiles/progress.marks
/usr/bin/gmake  -f CMakeFiles/Makefile2 all
gmake[1]: Entering directory '/home/wind/cmakeClass/test_MyMath/build'
/usr/bin/gmake  -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/depend
gmake[2]: Entering directory '/home/wind/cmakeClass/test_MyMath/build'
cd /home/wind/cmakeClass/test_MyMath/build && /usr/bin/cmake -E cmake_depends "Unix Makefiles" /home/wind/cmakeClass/test_MyMath /home/wind/cmakeClass/test_MyMath /home/wind/cmakeClass/test_MyMath/build /home/wind/cmakeClass/test_MyMath/build /home/wind/cmakeClass/test_MyMath/build/CMakeFiles/main.dir/DependInfo.cmake "--color="
gmake[2]: Leaving directory '/home/wind/cmakeClass/test_MyMath/build'
/usr/bin/gmake  -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
gmake[2]: Entering directory '/home/wind/cmakeClass/test_MyMath/build'
[ 50%] Building CXX object CMakeFiles/main.dir/main.cpp.o
/usr/bin/c++    -MD -MT CMakeFiles/main.dir/main.cpp.o -MF CMakeFiles/main.dir/main.cpp.o.d -o CMakeFiles/main.dir/main.cpp.o -c /home/wind/cmakeClass/test_MyMath/main.cpp
[100%] Linking CXX executable main
/usr/bin/cmake -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=1
/usr/bin/c++ CMakeFiles/main.dir/main.cpp.o -o main  /usr/local/lib/libMyMath.a 
gmake[2]: Leaving directory '/home/wind/cmakeClass/test_MyMath/build'
[100%] Built target main
gmake[1]: Leaving directory '/home/wind/cmakeClass/test_MyMath/build'
/usr/bin/cmake -E cmake_progress_start /home/wind/cmakeClass/test_MyMath/build/CMakeFiles 0

[wind@Ubuntu build]$ 

```

我们看到在`Linking`的时候, 有`/usr/bin/c++ CMakeFiles/main.dir/main.cpp.o -o main  /usr/local/lib/libMyMath.a `, 也就是成功找到了我们的数学库

但我们没看到头文件的`-I`, 这是因为`/usr/local/include`是编译器默认寻找的路径, 所以不需要额外添加

```shell
[wind@Ubuntu build]$ g++ -v -x c++ -E /dev/null
Using built-in specs.
COLLECT_GCC=g++
OFFLOAD_TARGET_NAMES=nvptx-none:amdgcn-amdhsa
OFFLOAD_TARGET_DEFAULT=1
Target: x86_64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 13.3.0-6ubuntu2~24.04' --with-bugurl=file:///usr/share/doc/gcc-13/README.Bugs --enable-languages=c,ada,c++,go,d,fortran,objc,obj-c++,m2 --prefix=/usr --with-gcc-major-version-only --program-suffix=-13 --program-prefix=x86_64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/libexec --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-bootstrap --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-libstdcxx-backtrace --enable-gnu-unique-object --disable-vtable-verify --enable-plugin --enable-default-pie --with-system-zlib --enable-libphobos-checking=release --with-target-system-zlib=auto --enable-objc-gc=auto --enable-multiarch --disable-werror --enable-cet --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-offload-targets=nvptx-none=/build/gcc-13-fG75Ri/gcc-13-13.3.0/debian/tmp-nvptx/usr,amdgcn-amdhsa=/build/gcc-13-fG75Ri/gcc-13-13.3.0/debian/tmp-gcn/usr --enable-offload-defaulted --without-cuda-driver --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu --with-build-config=bootstrap-lto-lean --enable-link-serialization=2
Thread model: posix
Supported LTO compression algorithms: zlib zstd
gcc version 13.3.0 (Ubuntu 13.3.0-6ubuntu2~24.04) 
COLLECT_GCC_OPTIONS='-v' '-E' '-shared-libgcc' '-mtune=generic' '-march=x86-64'
 /usr/libexec/gcc/x86_64-linux-gnu/13/cc1plus -E -quiet -v -imultiarch x86_64-linux-gnu -D_GNU_SOURCE /dev/null -mtune=generic -march=x86-64 -fasynchronous-unwind-tables -fstack-protector-strong -Wformat -Wformat-security -fstack-clash-protection -fcf-protection -dumpbase null
ignoring duplicate directory "/usr/include/x86_64-linux-gnu/c++/13"
ignoring nonexistent directory "/usr/local/include/x86_64-linux-gnu"
ignoring nonexistent directory "/usr/lib/gcc/x86_64-linux-gnu/13/include-fixed/x86_64-linux-gnu"
ignoring nonexistent directory "/usr/lib/gcc/x86_64-linux-gnu/13/include-fixed"
ignoring nonexistent directory "/usr/lib/gcc/x86_64-linux-gnu/13/../../../../x86_64-linux-gnu/include"
#include "..." search starts here:
#include <...> search starts here:
 /usr/include/c++/13
 /usr/include/x86_64-linux-gnu/c++/13
 /usr/include/c++/13/backward
 /usr/lib/gcc/x86_64-linux-gnu/13/include
 /usr/local/include
 /usr/include/x86_64-linux-gnu
 /usr/include
End of search list.
# 0 "/dev/null"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "/dev/null"
COMPILER_PATH=/usr/libexec/gcc/x86_64-linux-gnu/13/:/usr/libexec/gcc/x86_64-linux-gnu/13/:/usr/libexec/gcc/x86_64-linux-gnu/:/usr/lib/gcc/x86_64-linux-gnu/13/:/usr/lib/gcc/x86_64-linux-gnu/
LIBRARY_PATH=/usr/lib/gcc/x86_64-linux-gnu/13/:/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/:/usr/lib/gcc/x86_64-linux-gnu/13/../../../../lib/:/lib/x86_64-linux-gnu/:/lib/../lib/:/usr/lib/x86_64-linux-gnu/:/usr/lib/../lib/:/usr/lib/gcc/x86_64-linux-gnu/13/../../../:/lib/:/usr/lib/
COLLECT_GCC_OPTIONS='-v' '-E' '-shared-libgcc' '-mtune=generic' '-march=x86-64'
[wind@Ubuntu build]$ 
```

我们看到`/usr/local/include`赫然在列

最后考虑到实验已经完成了, 那么我们就把自己的库从系统中卸载

```shell
[wind@Ubuntu build]$ pwd
/home/wind/cmakeClass/install_static_mymath/build
[wind@Ubuntu build]$ cat install_manifest.txt | xargs sudo rm -v
removed '/usr/local/lib/libMyMath.a'
removed '/usr/local/include/MyMath/math.h'
removed '/usr/local/lib/cmake/MyMath/MyMathTargets.cmake'
removed '/usr/local/lib/cmake/MyMath/MyMathTargets-noconfig.cmake'
removed '/usr/local/lib/cmake/MyMath/MyMathConfig.cmake'
[wind@Ubuntu build]$ 
```

------

下面, 我们重点介绍在上述安装过程中, 我们使用到的两个最核心的接口 `export`和`install`, 下面我们看看这两个指令是如何相互配合的.

整体来说, 比较简单, 其实就分为两步, (Foo指的是项目名)

- 第一步, 使用export 导出目标到 FooTargets.cmake文件
- 第二步, 将FooTargets.cmake安装到/usr/local/cmake/Foo/FooTargets.cmake

我们意识到, 对于目标来说, 它有很多属性, 让其交给目标的使用者来进行包含是不可靠的, 是不利于目标之间的传播的, 所以我们通过所谓的导出集合, 来将目标在构建过程中的目标属性一一收集, 并将其加一归档, 输出到一个文件当中, 并最终安装到系统中, 这样当用户需要使用目标, 就不必要太多操作, 直接使用`find_package`就相当于在自己的脚本中包含了所使用目标的各类属性.

在上面的脚本中

```cmake
EXPORT MyMathTargets
```

就是对目标`MyMath`定义了一个导出集合, 于是导出集合就会自动追踪并记录这个目标的各类属性,

```cmake
export(EXPORT MyMathTargets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/MyMathTargets.cmake
)
```

在构建完成后, 我们便把收集到到目标属性输出到构建树的`MyMathTargets.cmake`中

但此时构建树中的`MyMathTargets.cmake`只有目标属性, 没有安装属性, 没有安装属性的一个问题就是找不到安装到本地的目标, 所以在我们安装`MyMathTargets.cmake`的时候, 即把它从构建树安装到本地的时候, `cmake`会追加目标的安装属性, 这样, 最终, 本地安装的`MyMathTargets.cmake`也有安装属性.

----------

在上面的过程中, 我们学习了关于静态库的安装过程. 接下来我们将开始学习动态库的安装. 在正式进行学习之前, 我们先简要提一下有关动态库和静态库的区别.

其实, 在之前学习Linux的时候, 我们就已经对动静态库进行了专门的学习. 我们知道, 在生成阶段, 静态库生成`.o`是不需要带上与地址无关码, 即`-fPIC`选项, 而动态库则需要, 我们知道, 这是因为可执行程序对于动静态库的使用方式存在差异, 为了防止可执行程序在使用动态库时出现虚拟地址冲突, 动态库的地址采用的是不按照进程地址空间布局的那样的逻辑地址, 而是采用一种偏移量地址, 或者说是一种相对地址, 从而避免了与绝对地址(逻辑的)无关,  而在链接阶段, 静态库直接拷贝到可执行文件中, 动态库则是运行时触发缺页中断, 让动态链接器将动态库加载到内存当中进行使用. 动态库的优点是可以热更新, 缺点是有依赖关系.

插入: vcpkg是一个由微软维护的跨平台C/C++包管理器, 它可以使得第三方库的获取, 编译, 安装与集成像Python的pip或JaveScript的npm一样简单, 这尤其弥补了在Windows生态下"系统级包管理器"的缺失. 它是`cmake`上游, 也提供`.cmake`脚本.

对于具体的安装过程, 我们直接复用之前静态库的安装

```cmake
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

```

只有本文件有稍微的改变, 包括库的类型, 匹配类型的输出路径, 加点动态库的版本兼容版本, 其它几乎都不需要修改, 使用方由于使用的是`find_package`, 所以也不需要修改

```shell
[wind@Ubuntu build]$ cmake .. && cmake --build . && sudo cmake --install .
-- The CXX compiler identification is GNU 13.3.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.5s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/install_shared_mymath/build
[ 33%] Building CXX object my_lib/CMakeFiles/MyMath.dir/src/add.cpp.o
[ 66%] Building CXX object my_lib/CMakeFiles/MyMath.dir/src/sub.cpp.o
[100%] Linking CXX shared library ../lib/libMyMath.so
[100%] Built target MyMath
[sudo] password for wind: 
-- Install configuration: ""
-- Installing: /usr/local/lib/libMyMath.so.1.2.3
-- Installing: /usr/local/lib/libMyMath.so.20
-- Installing: /usr/local/lib/libMyMath.so
-- Up-to-date: /usr/local/include/MyMath
-- Installing: /usr/local/include/MyMath/math.h
-- Installing: /usr/local/lib/cmake/MyMath/MyMathTargets.cmake
-- Installing: /usr/local/lib/cmake/MyMath/MyMathTargets-noconfig.cmake
-- Installing: /usr/local/lib/cmake/MyMath/MyMathConfig.cmake
[wind@Ubuntu build]$ cd /home/wind/cmakeClass/test_MyMath/build
[wind@Ubuntu build]$ rm -rf ./*
[wind@Ubuntu build]$ cmake .. && cmake --build .
-- The CXX compiler identification is GNU 13.3.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.6s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_MyMath/build
[ 50%] Building CXX object CMakeFiles/main.dir/main.cpp.o
[100%] Linking CXX executable main
[100%] Built target main
[wind@Ubuntu build]$ ls
CMakeCache.txt  CMakeFiles  cmake_install.cmake  main  Makefile
[wind@Ubuntu build]$ ./main
7
-1
[wind@Ubuntu build]$ cd -
/home/wind/cmakeClass/install_shared_mymath/build
[wind@Ubuntu build]$ cat install_manifest.txt | xargs sudo rm -v
removed '/usr/local/lib/libMyMath.so.1.2.3'
removed '/usr/local/lib/libMyMath.so.20'
removed '/usr/local/lib/libMyMath.so'
removed '/usr/local/include/MyMath/math.h'
removed '/usr/local/lib/cmake/MyMath/MyMathTargets.cmake'
removed '/usr/local/lib/cmake/MyMath/MyMathTargets-noconfig.cmake'
removed '/usr/local/lib/cmake/MyMath/MyMathConfig.cmake'
[wind@Ubuntu build]$ 
```

稍微提一下, 对于`-fPIC`选项, `cmake`从`2.8.9`版本后对于动态库就会自动携带该选项, 所以, 对于我们当前的版本来说, 不需要手动添加.

---------

下面介绍`cmake`内部动态库的生成和定位流程

对于Linux来说, 当一个进程在进程地址空间里找不到所需动态库的物理地址时, 就会触发缺页中断, 从而"叫来"Linux中的动态链接加载器, 要求其将所需的动态库加载到物理内存中, 并与页表建立映射关系, 此时, 动态加载器会到以下几个地方喊顺序去寻找动态库或者其路径

- LD_LIBRARY_PATH 环境变量中列出的目录
- ELF 文件的 DT_RUNPATH
- 系统缓存/etc/ld.so.cache
- 默认目录, /lib, /usr/lib...

先在`LD_LIBRARY_PATH`里面找, 找所需库的绝对路径, 找不到去`DT_RUNPATH`

对于 ELF 文件来说, 它可能会自带所需动态库的路径, 比如刚刚我们生成的`main`

```shell
[wind@Ubuntu build]$ readelf -d main

Dynamic section at offset 0x2d78 contains 30 entries:
  Tag        Type                         Name/Value
 0x0000000000000001 (NEEDED)             Shared library: [libMyMath.so]
 0x0000000000000001 (NEEDED)             Shared library: [libstdc++.so.6]
 0x0000000000000001 (NEEDED)             Shared library: [libc.so.6]
 0x000000000000001d (RUNPATH)            Library runpath: [/usr/local/lib]
```

其中就指明了库的查找路径是`/usr/local/lib`, 如果还找不到, 就去查找`/etc/ld.so.cache`

`/etc/ld.so.cache`是一个缓存文件, 其内部类似哈希表, 直接记录着 库名 - 绝对路径, 它的使用方式是由用户在合适的时间执行`sudo ldconfig`,(或者安装删除动态库) 时, 系统会进行全盘扫描(安装卸载动态库也是全盘), 将扫描到的库和绝对路径写入该文件. `ldconfig -p`可以查看它的具体内容, 而且由于是缓存文件, 在内存中存储, 所以在使用时不涉及对应的物理动作

最后, 就是在默认目录下, 逐一扫描.

对于`cmake`来说, 它使用第二种, 也就是直接把所需库的目录写到可执行文件本身上. 我们可以从之前的一些指令片段上看到这一点

```shell
[100%] Linking CXX executable main
/usr/bin/cmake -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=1
/usr/bin/c++ CMakeFiles/main.dir/main.cpp.o -o main   -L/usr/local/lib/public  -L/usr/local/lib/interface  -Wl,-rpath,/usr/local/lib/public:/usr/local/lib/interface src/libadd.a -lpthread 

```

我们看到, 有一个`-Wl,-rpath`选项, 这个选项的含义就是让编译器把后面的那段路径直接写到可执行文件中. 链接时直接用这段路径找库文件. 这种ELF文件自带的路径, 一般被叫做`rpath`, 另外要说的一点是, ELF里面有两种搜索路径标签, 老版本的`DT_RPATH`和新版本的`DT_RUNPATH`.

对于`cmake`, `rpath`的路径会分时期变化. 在项目构建阶段, `rpath`是`CMAKE_BUILD_RPATH`, 我曾经说过, 对该属性的设置是为了让可执行目标即使在库文件没有安装的情况下, 仍能运行. 而如果把库给安装了, 那么`rpath`就会变成`CMAKE_INSTALL_RPATH`. 具体来说, 在同一个项目中, 如果我生成了一些动态库目标, 而最终的可执行程序也依赖于这个动态库, 那么, 如果你压根没写库文件安装, 那么它就一直把`CMAKE_BUILD_RPATH`作为`rpath`, 如果你写了库安装, 那么在安装时, `cmake`就会在原先的可执行程序上修改, 把`rpath`改成库安装的目录, 也就是`CMAKE_INSTALL_RPATH`.  如果库和可执行文件压根不在一个项目里, 那么`cmake`会直接把`find_package`找到的库目录当做`rpath`. `cmake`也提供了一些设置可以让用户接手`rpath`的具体设置, 不过实际过程中, 我们不会这样用, 所以我们不说.

---------

接下来我们比较一下`find_package`的两种模式, `modlue and  config`

`modlue`又叫做查找模式, 是给那些太老以至于没有进行`cmake`适配, 以及没有安装含有`config.cmake`等`cmake`配置文件的发行版进行使用的. `config`则是`cmake`推荐的模式, 由库的发布者直接提供库文件的定位以及使用信息, 下游不需要手动编写脚本, 直接使用上游提供好的导入目标进行使用.

在`modlue`模式下, 我们需要手动编写脚本, 去使用`find_library , find_path`等接口在磁盘中扫描(其实也不需要自己编写, 因为`cmake`的`modlue`模块往往已经自带了很多高质量的Find脚本), 在实际使用中, 除了上述的Find脚本外, 我们也需要手动添加头文件包含目录

```cmake
find_package(PNG REQUIRED)
target_include_directories(app PRIVATE /usr/local/include/....)
target_link_libraries(app RIVATE /isr/local/lib/...)
```

鉴于`moudlue`和`config`的工作模式, 有时我们也把`modlue`叫做"猜模式", 因为我们并不是库的发行方, 所以对于库文件的具体位置及属性类似于猜出来的., `config`就被叫做"定位模式", 因为这是库的发行者自己提供的, 他们当然清楚自己的库会往哪里安装, 有哪些属性.

对于`find_package`来说, 其默认行为, 也就是没有指定模式的时候, 会率先尝试`config`, 然后是`modlue`.

对于包的一些规范, 在行业内也有一定的规范. 对于绝大多数的库来说, 其命名一般是首字母大写, 比如`Boost, OpenCV Threads`, 当然也存在一些特殊情况, 比如`jsoncpp, CURL`. 对于`config.cmake`那些`config`模式依赖文件的具体位置, 都是在`/usr/local/lib/cmake/...`,, `modlue`所需要的`Find.cmake`比如`FindBoost.cmake` , 则会出现在`/usr/share/cmake-x.x/Modules/`目录下.

-------

接下来, 我们下载并安装一下`jsoncpp`

```shell
[wind@Ubuntu ~]$ git clone git@github.com:open-source-parsers/jsoncpp.git
[wind@Ubuntu ~]$ cd jsoncpp
[wind@Ubuntu jsoncpp]$ mkdir build && cd build
[wind@Ubuntu build]$ cmake ..
-- The CXX compiler identification is GNU 13.3.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- JsonCpp Version: 1.9.7
-- Looking for memset_s
-- Looking for memset_s - not found
-- Looking for C++ include clocale
-- Looking for C++ include clocale - found
-- Looking for localeconv
-- Looking for localeconv - found
-- Looking for C++ include sys/types.h
-- Looking for C++ include sys/types.h - found
-- Looking for C++ include stdint.h
-- Looking for C++ include stdint.h - found
-- Looking for C++ include stddef.h
-- Looking for C++ include stddef.h - found
-- Check size of lconv
-- Check size of lconv - done
-- Performing Test HAVE_DECIMAL_POINT
-- Performing Test HAVE_DECIMAL_POINT - Success
-- Found Python3: /usr/bin/python3 (found version "3.12.3") found components: Interpreter 
-- Configuring done (2.8s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/jsoncpp/build
[wind@Ubuntu build]$ cmake --build .
[  5%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_reader.cpp.o
[ 11%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_value.cpp.o
[ 17%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_writer.cpp.o
[ 23%] Linking CXX shared library ../../lib/libjsoncpp.so
[ 23%] Built target jsoncpp_lib
[ 29%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_static.dir/json_reader.cpp.o
[ 35%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_static.dir/json_value.cpp.o
[ 41%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_static.dir/json_writer.cpp.o
[ 47%] Linking CXX static library ../../lib/libjsoncpp.a
[ 47%] Built target jsoncpp_static
[ 52%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_object.dir/json_reader.cpp.o
[ 58%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_object.dir/json_value.cpp.o
[ 64%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_object.dir/json_writer.cpp.o
[ 64%] Built target jsoncpp_object
[ 70%] Building CXX object src/jsontestrunner/CMakeFiles/jsontestrunner_exe.dir/main.cpp.o
[ 76%] Linking CXX executable ../../bin/jsontestrunner_exe
[ 76%] Built target jsontestrunner_exe
[ 82%] Building CXX object src/test_lib_json/CMakeFiles/jsoncpp_test.dir/jsontest.cpp.o
[ 88%] Building CXX object src/test_lib_json/CMakeFiles/jsoncpp_test.dir/fuzz.cpp.o
[ 94%] Building CXX object src/test_lib_json/CMakeFiles/jsoncpp_test.dir/main.cpp.o
[100%] Linking CXX executable ../../bin/jsoncpp_test
Testing ValueTest/checkNormalizeFloatingPointStr: OK
Testing ValueTest/memberCount: OK
Testing ValueTest/objects: OK
Testing ValueTest/arrays: OK
Testing ValueTest/resizeArray: OK
Testing ValueTest/resizePopulatesAllMissingElements: OK
Testing ValueTest/getArrayValue: OK
Testing ValueTest/arrayIssue252: OK
Testing ValueTest/arrayInsertAtRandomIndex: OK
Testing ValueTest/null: OK
Testing ValueTest/strings: OK
Testing ValueTest/bools: OK
Testing ValueTest/integers: OK
Testing ValueTest/nonIntegers: OK
Testing ValueTest/compareNull: OK
Testing ValueTest/compareInt: OK
Testing ValueTest/compareUInt: OK
Testing ValueTest/compareDouble: OK
Testing ValueTest/compareString: OK
Testing ValueTest/compareBoolean: OK
Testing ValueTest/compareArray: OK
Testing ValueTest/compareObject: OK
Testing ValueTest/compareType: OK
Testing ValueTest/CopyObject: OK
Testing ValueTest/typeChecksThrowExceptions: OK
Testing ValueTest/offsetAccessors: OK
Testing ValueTest/StaticString: OK
Testing ValueTest/WideString: OK
Testing ValueTest/CommentBefore: OK
Testing ValueTest/zeroes: OK
Testing ValueTest/zeroesInKeys: OK
Testing ValueTest/specialFloats: OK
Testing ValueTest/precision: OK
Testing ValueTest/searchValueByPath: OK
Testing FastWriterTest/dropNullPlaceholders: OK
Testing FastWriterTest/enableYAMLCompatibility: OK
Testing FastWriterTest/omitEndingLineFeed: OK
Testing FastWriterTest/writeNumericValue: OK
Testing FastWriterTest/writeArrays: OK
Testing FastWriterTest/writeNestedObjects: OK
Testing StyledWriterTest/writeNumericValue: OK
Testing StyledWriterTest/writeArrays: OK
Testing StyledWriterTest/writeNestedObjects: OK
Testing StyledWriterTest/multiLineArray: OK
Testing StyledWriterTest/writeValueWithComment: OK
Testing StyledStreamWriterTest/writeNumericValue: OK
Testing StyledStreamWriterTest/writeArrays: OK
Testing StyledStreamWriterTest/writeNestedObjects: OK
Testing StyledStreamWriterTest/multiLineArray: OK
Testing StyledStreamWriterTest/writeValueWithComment: OK
Testing StreamWriterTest/writeNumericValue: OK
Testing StreamWriterTest/writeArrays: OK
Testing StreamWriterTest/writeNestedObjects: OK
Testing StreamWriterTest/multiLineArray: OK
Testing StreamWriterTest/dropNullPlaceholders: OK
Testing StreamWriterTest/enableYAMLCompatibility: OK
Testing StreamWriterTest/indentation: OK
Testing StreamWriterTest/writeZeroes: OK
Testing StreamWriterTest/unicode: OK
Testing StreamWriterTest/escapeControlCharacters: OK
Testing ReaderTest/parseWithNoErrors: OK
Testing ReaderTest/parseObject: OK
Testing ReaderTest/parseArray: OK
Testing ReaderTest/parseString: OK
Testing ReaderTest/parseComment: OK
Testing ReaderTest/streamParseWithNoErrors: OK
Testing ReaderTest/parseWithNoErrorsTestingOffsets: OK
Testing ReaderTest/parseWithOneError: OK
Testing ReaderTest/parseSpecialFloat: OK
Testing ReaderTest/strictModeParseNumber: OK
Testing ReaderTest/parseChineseWithOneError: OK
Testing ReaderTest/parseWithDetailError: OK
Testing ReaderTest/pushErrorTest: OK
Testing ReaderTest/allowNumericKeysTest: OK
Testing CharReaderTest/parseWithNoErrors: OK
Testing CharReaderTest/parseWithNoErrorsTestingOffsets: OK
Testing CharReaderTest/parseNumber: OK
Testing CharReaderTest/parseString: OK
Testing CharReaderTest/parseComment: OK
Testing CharReaderTest/parseObjectWithErrors: OK
Testing CharReaderTest/parseArrayWithErrors: OK
Testing CharReaderTest/parseWithOneError: OK
Testing CharReaderTest/parseChineseWithOneError: OK
Testing CharReaderTest/parseWithDetailError: OK
Testing CharReaderTest/parseWithStackLimit: OK
Testing CharReaderTest/testOperator: OK
Testing CharReaderStrictModeTest/dupKeys: OK
Testing CharReaderFailIfExtraTest/issue164: OK
Testing CharReaderFailIfExtraTest/issue107: OK
Testing CharReaderFailIfExtraTest/commentAfterObject: OK
Testing CharReaderFailIfExtraTest/commentAfterArray: OK
Testing CharReaderFailIfExtraTest/commentAfterBool: OK
Testing CharReaderFailIfExtraTest/parseComment: OK
Testing CharReaderAllowDropNullTest/issue178: OK
Testing CharReaderAllowNumericKeysTest/allowNumericKeys: OK
Testing CharReaderAllowSingleQuotesTest/issue182: OK
Testing CharReaderAllowZeroesTest/issue176: OK
Testing CharReaderAllowSpecialFloatsTest/specialFloat: OK
Testing CharReaderAllowSpecialFloatsTest/issue209: OK
Testing EscapeSequenceTest/readerParseEscapeSequence: OK
Testing EscapeSequenceTest/charReaderParseEscapeSequence: OK
Testing EscapeSequenceTest/writeEscapeSequence: OK
Testing BuilderTest/settings: OK
Testing BomTest/skipBom: OK
Testing BomTest/notSkipBom: OK
Testing IteratorTest/convert: OK
Testing IteratorTest/decrement: OK
Testing IteratorTest/reverseIterator: OK
Testing IteratorTest/distance: OK
Testing IteratorTest/nullValues: OK
Testing IteratorTest/staticStringKey: OK
Testing IteratorTest/names: OK
Testing IteratorTest/indexes: OK
Testing IteratorTest/constness: OK
Testing RValueTest/moveConstruction: OK
Testing FuzzTest/fuzzDoesntCrash: OK
Testing ParseWithStructuredErrorsTest/success: OK
Testing ParseWithStructuredErrorsTest/singleError: OK
Testing MemberTemplateAs/BehavesSameAsNamedAs: OK
Testing MemberTemplateIs/BehavesSameAsNamedIs: OK
Testing VersionTest/VersionNumbersMatch: OK
All 121 tests passed
[100%] Built target jsoncpp_test
[wind@Ubuntu build]$ sudo cmake --install .
-- Install configuration: "Release"
-- Installing: /usr/local/lib/pkgconfig/jsoncpp.pc
-- Installing: /usr/local/lib/cmake/jsoncpp/jsoncpp-targets.cmake
-- Installing: /usr/local/lib/cmake/jsoncpp/jsoncpp-targets-release.cmake
-- Installing: /usr/local/lib/cmake/jsoncpp/jsoncppConfigVersion.cmake
-- Installing: /usr/local/lib/cmake/jsoncpp/jsoncppConfig.cmake
-- Installing: /usr/local/lib/cmake/jsoncpp/jsoncpp-namespaced-targets.cmake
-- Installing: /usr/local/lib/libjsoncpp.so.1.9.7
-- Installing: /usr/local/lib/libjsoncpp.so.27
-- Installing: /usr/local/lib/libjsoncpp.so
-- Installing: /usr/local/lib/libjsoncpp.a
-- Installing: /usr/local/lib/objects-Release/jsoncpp_object/json_reader.cpp.o
-- Installing: /usr/local/lib/objects-Release/jsoncpp_object/json_value.cpp.o
-- Installing: /usr/local/lib/objects-Release/jsoncpp_object/json_writer.cpp.o
-- Installing: /usr/local/include/json/allocator.h
-- Installing: /usr/local/include/json/assertions.h
-- Installing: /usr/local/include/json/config.h
-- Installing: /usr/local/include/json/forwards.h
-- Installing: /usr/local/include/json/json.h
-- Installing: /usr/local/include/json/json_features.h
-- Installing: /usr/local/include/json/reader.h
-- Installing: /usr/local/include/json/value.h
-- Installing: /usr/local/include/json/version.h
-- Installing: /usr/local/include/json/writer.h
[wind@Ubuntu build]$ 
```

之后, 我们也可以在`/usr/local/lib/cmake/jsoncpp`下查看其与`find_package`有关的`cmake`配置脚本

```shell
[wind@Ubuntu jsoncpp]$ ll
total 32
drwxr-xr-x 2 root root 4096 Sep 10 10:07 ./
drwxr-xr-x 5 root root 4096 Sep 10 08:44 ../
-rw-r--r-- 1 root root 1124 Sep 10 10:05 jsoncppConfig.cmake
-rw-r--r-- 1 root root 2762 Sep 10 10:05 jsoncppConfigVersion.cmake
-rw-r--r-- 1 root root  431 Sep 10 08:41 jsoncpp-namespaced-targets.cmake
-rw-r--r-- 1 root root 5951 Sep 10 10:05 jsoncpp-targets.cmake
-rw-r--r-- 1 root root 2122 Sep 10 10:05 jsoncpp-targets-release.cmake
[wind@Ubuntu jsoncpp]$ 
```

`jsoncppConfig.cmake`是`find_package`的入口文件, 它会将`find_package`引导到`jsoncpp-targets.cmake`

而在`jsoncpp-targets.cmake`中, 我们可以看到

```cmake
# Compute the installation prefix relative to this file.
get_filename_component(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
```

`get_filename_component(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)`是把本文件的全路径`${CMAKE_CURRENT_LIST_FILE}`, 即`/usr/local/lib/cmake/jsoncpp/jsoncpp-targets.cmake`, 的上一级目录(`PATH`指令), 赋给`_IMPORT_PREFIX`, 于是第一次之后, `_IMPORT_PREFIX`就是`/usr/local/lib/cmake/jsoncpp`, 第二次就是`/usr/local/lib/cmake`, 第三次之后就是`/usr/local/lib`, 第四次之后就是`/usr/local`, 它通过这种相对路径的方式来适应各个平台下不同的安装规则, 并最终找到本地安装的根目录, 再基于此去寻找, 其它的库文件, 比如`/usr/local`下的`include`

`jsoncpp-targets.cmake`还包含了`soncpp-targets-*.cmake`, 在这里就是`jsoncpp-targets-release.cmake`, 在`jsoncpp-targets-release.cmake`中, 我们看到, 它描述了动态库的位置

```cmake
# Import target "jsoncpp_lib" for configuration "Release"
set_property(TARGET jsoncpp_lib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(jsoncpp_lib PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libjsoncpp.so.1.9.7"
  IMPORTED_SONAME_RELEASE "libjsoncpp.so.27"
  )
```

 还有静态库

```cmake
# Import target "jsoncpp_static" for configuration "Release"
set_property(TARGET jsoncpp_static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(jsoncpp_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libjsoncpp.a"
  )
```

目标库

```cmake
# Import target "jsoncpp_object" for configuration "Release"
set_property(TARGET jsoncpp_object APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(jsoncpp_object PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_OBJECTS_RELEASE "${_IMPORT_PREFIX}/lib/objects-Release/jsoncpp_object/json_reader.cpp.o;${_IMPORT_PREFIX}/lib/objects-Release/jsoncpp_object/json_value.cpp.o;${_IMPORT_PREFIX}/lib/objects-Release/jsoncpp_object/json_writer.cpp.o"
  )
```

接下来我们看看`jsoncpp-namespaced-targets.cmake`, 因为这和之后我们对于`jsoncpp`的使用密切相关

```cmake
if (NOT TARGET JsonCpp::JsonCpp)
    if (TARGET jsoncpp_static)
        add_library(JsonCpp::JsonCpp INTERFACE IMPORTED)
        set_target_properties(JsonCpp::JsonCpp PROPERTIES INTERFACE_LINK_LIBRARIES "jsoncpp_static")
    elseif (TARGET jsoncpp_lib)
        add_library(JsonCpp::JsonCpp INTERFACE IMPORTED)
        set_target_properties(JsonCpp::JsonCpp PROPERTIES INTERFACE_LINK_LIBRARIES "jsoncpp_lib")
    endif ()
endif ()

```

它的大意就是如果项目中没有(链接)`JsonCpp::JsonCpp`, 那么有目标`jsoncpp_static`它会先用静态库, 如果没有静态库, 再去使用`jsoncpp_lib`动态库.

-----

下面, 我们使用`Config`模式查找并使用`jsoncpp`

```shell
[wind@Ubuntu find_jsoncpp_config]$ tree .
.
├── CMakeLists.txt
└── main.cpp

1 directory, 2 files
[wind@Ubuntu find_jsoncpp_config]$ 
```

```cmake
cmake_minimum_required(VERSION 3.18)

project(JsoncppDemo LANGUAGES CXX)

# 使用C++11标准
set(CMAKE_CXX_STANDARD 11)

# REQUIRED找不到直接退出
find_package(jsoncpp CONFIG REQUIRED)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE JsonCpp::JsonCpp)

```

```cpp
#include<iostream>
#include<json/json.h>

int main()
{
    Json::Value root;
    root["name"] = "whisper";
    root["age"] = 18;

    Json::StreamWriterBuilder writer;
    std::string JsonStr = Json::writeString(writer, root);
    std::cout<<"root: \r\n" << JsonStr << std::endl;

    return 0;
}

```

```shell
[wind@Ubuntu find_jsoncpp_config]$ mkdir build && cd build
[wind@Ubuntu build]$ cmake ..
-- The CXX compiler identification is GNU 13.3.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.5s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/find_jsoncpp_config/build
[wind@Ubuntu build]$ cmake --build . -v
Change Dir: '/home/wind/cmakeClass/find_jsoncpp_config/build'

Run Build Command(s): /usr/bin/cmake -E env VERBOSE=1 /usr/bin/gmake -f Makefile
/usr/bin/cmake -S/home/wind/cmakeClass/find_jsoncpp_config -B/home/wind/cmakeClass/find_jsoncpp_config/build --check-build-system CMakeFiles/Makefile.cmake 0
/usr/bin/cmake -E cmake_progress_start /home/wind/cmakeClass/find_jsoncpp_config/build/CMakeFiles /home/wind/cmakeClass/find_jsoncpp_config/build//CMakeFiles/progress.marks
/usr/bin/gmake  -f CMakeFiles/Makefile2 all
gmake[1]: Entering directory '/home/wind/cmakeClass/find_jsoncpp_config/build'
/usr/bin/gmake  -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/depend
gmake[2]: Entering directory '/home/wind/cmakeClass/find_jsoncpp_config/build'
cd /home/wind/cmakeClass/find_jsoncpp_config/build && /usr/bin/cmake -E cmake_depends "Unix Makefiles" /home/wind/cmakeClass/find_jsoncpp_config /home/wind/cmakeClass/find_jsoncpp_config /home/wind/cmakeClass/find_jsoncpp_config/build /home/wind/cmakeClass/find_jsoncpp_config/build /home/wind/cmakeClass/find_jsoncpp_config/build/CMakeFiles/main.dir/DependInfo.cmake "--color="
gmake[2]: Leaving directory '/home/wind/cmakeClass/find_jsoncpp_config/build'
/usr/bin/gmake  -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
gmake[2]: Entering directory '/home/wind/cmakeClass/find_jsoncpp_config/build'
[ 50%] Building CXX object CMakeFiles/main.dir/main.cpp.o
/usr/bin/c++   -std=gnu++11 -MD -MT CMakeFiles/main.dir/main.cpp.o -MF CMakeFiles/main.dir/main.cpp.o.d -o CMakeFiles/main.dir/main.cpp.o -c /home/wind/cmakeClass/find_jsoncpp_config/main.cpp
[100%] Linking CXX executable main
/usr/bin/cmake -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=1
/usr/bin/c++ CMakeFiles/main.dir/main.cpp.o -o main  /usr/local/lib/libjsoncpp.a 
gmake[2]: Leaving directory '/home/wind/cmakeClass/find_jsoncpp_config/build'
[100%] Built target main
gmake[1]: Leaving directory '/home/wind/cmakeClass/find_jsoncpp_config/build'
/usr/bin/cmake -E cmake_progress_start /home/wind/cmakeClass/find_jsoncpp_config/build/CMakeFiles 0

[wind@Ubuntu build]$ ./main
root: 
{
        "age" : 18,
        "name" : "whisper"
}
[wind@Ubuntu build]$ 

```

我们这里链接的是`JsonCpp:JsonCpp`, 可以看到, 链接的静态库, 不过`jsoncpp-namespaced-targets.cmake`是没有目标`JsonCpp:JsonCpp`的时候才生效的, 所以此处静态库的链接应该是由其它文件所造成的, 为了避免产生歧义, 我们最好还是直接显式写具体的链接目标, 比如下面是链接`jsoncpp_lib`的

```shell
[wind@Ubuntu build]$ cmake --build . -v
Change Dir: '/home/wind/cmakeClass/find_jsoncpp_config/build'

Run Build Command(s): /usr/bin/cmake -E env VERBOSE=1 /usr/bin/gmake -f Makefile
/usr/bin/cmake -S/home/wind/cmakeClass/find_jsoncpp_config -B/home/wind/cmakeClass/find_jsoncpp_config/build --check-build-system CMakeFiles/Makefile.cmake 0
/usr/bin/cmake -E cmake_progress_start /home/wind/cmakeClass/find_jsoncpp_config/build/CMakeFiles /home/wind/cmakeClass/find_jsoncpp_config/build//CMakeFiles/progress.marks
/usr/bin/gmake  -f CMakeFiles/Makefile2 all
gmake[1]: Entering directory '/home/wind/cmakeClass/find_jsoncpp_config/build'
/usr/bin/gmake  -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/depend
gmake[2]: Entering directory '/home/wind/cmakeClass/find_jsoncpp_config/build'
cd /home/wind/cmakeClass/find_jsoncpp_config/build && /usr/bin/cmake -E cmake_depends "Unix Makefiles" /home/wind/cmakeClass/find_jsoncpp_config /home/wind/cmakeClass/find_jsoncpp_config /home/wind/cmakeClass/find_jsoncpp_config/build /home/wind/cmakeClass/find_jsoncpp_config/build /home/wind/cmakeClass/find_jsoncpp_config/build/CMakeFiles/main.dir/DependInfo.cmake "--color="
gmake[2]: Leaving directory '/home/wind/cmakeClass/find_jsoncpp_config/build'
/usr/bin/gmake  -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
gmake[2]: Entering directory '/home/wind/cmakeClass/find_jsoncpp_config/build'
[ 50%] Building CXX object CMakeFiles/main.dir/main.cpp.o
/usr/bin/c++   -std=gnu++11 -MD -MT CMakeFiles/main.dir/main.cpp.o -MF CMakeFiles/main.dir/main.cpp.o.d -o CMakeFiles/main.dir/main.cpp.o -c /home/wind/cmakeClass/find_jsoncpp_config/main.cpp
[100%] Linking CXX executable main
/usr/bin/cmake -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=1
/usr/bin/c++ CMakeFiles/main.dir/main.cpp.o -o main  -Wl,-rpath,/usr/local/lib /usr/local/lib/libjsoncpp.so.1.9.7 
gmake[2]: Leaving directory '/home/wind/cmakeClass/find_jsoncpp_config/build'
[100%] Built target main
gmake[1]: Leaving directory '/home/wind/cmakeClass/find_jsoncpp_config/build'
/usr/bin/cmake -E cmake_progress_start /home/wind/cmakeClass/find_jsoncpp_config/build/CMakeFiles 0

[wind@Ubuntu build]$ 
```

另外, 我们之前显式定义了C++的执行标准, 使用的是C++11, 这是有意而为之的, 如果我们注释掉, 会返现无法编译通过.

```shell
[wind@Ubuntu build]$ rm -rf ./*
[wind@Ubuntu build]$ cmake ..
-- The CXX compiler identification is GNU 13.3.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.5s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/find_jsoncpp_config/build
[wind@Ubuntu build]$ cmake --build . 
[ 50%] Building CXX object CMakeFiles/main.dir/main.cpp.o
[100%] Linking CXX executable main
/usr/bin/ld: CMakeFiles/main.dir/main.cpp.o: in function `main':
main.cpp:(.text+0x7e): undefined reference to `Json::Value::operator[](std::basic_string_view<char, std::char_traits<char> >)'
/usr/bin/ld: main.cpp:(.text+0xe6): undefined reference to `Json::Value::operator[](std::basic_string_view<char, std::char_traits<char> >)'
collect2: error: ld returned 1 exit status
gmake[2]: *** [CMakeFiles/main.dir/build.make:98: main] Error 1
gmake[1]: *** [CMakeFiles/Makefile2:83: CMakeFiles/main.dir/all] Error 2
gmake: *** [Makefile:91: all] Error 2
[wind@Ubuntu build]$ 
```

这是因为我们自己写的源代码和`jsoncpp`库存在有关C++标准的兼容问题, 首先, 我们需要知道, `cmake`如果不指定C++标准, 就会使用编译器默认的C++标准, 对于本机的编译器, 执行的是C++17标准

```shell
[wind@Ubuntu build]$ echo | g++ -dM -E -x c++ - | grep __cplusplus
#define __cplusplus 201703L
```

但我们从`jsoncpp`那里克隆下来的源代码, 里面显式指定的是使用C++11编译的, 所以我们的`jsoncpp`它是C++11, 关键在于, 在C++17引入了一个新的类型, `std::string_view`, 作为常量字符串的一种更优的替代, 并为此更新了函数重载规则: 常量字符串会被匹配到`std::string_view`类型, 而不再是`std::string`

所以如果我们不显示指定C++标准, 我们的项目用的是C++17, 而我们使用了

```cpp
root["name"] = "whisper";
root["age"] = 18;
```

在C++17里,它会使用 `Json::Value& operator[string_view]`, 但`jsoncpp`是用C++11编的, 没有这个接口, 所以链接失败

如果我们显式指定使用C++11, 因为C++11还没有`std::string_view`, 所以它还会重载到`Json::Value& operator[string]`

----------

下面我们介绍`ctest`的使用方法.

`ctest`是一个`cmake`的集成测试框架, 用于自动化执行项目测试. 支持多种测试类型(如单元测试, 性能测试), 并能生成详细的的测试报告.

`ctest`的基本命令就是

```cmake
ctest [<options>] [--test-dir <path-to-build>]
```

对于脚本, 则要先包含测试模块, 然后必须在顶层`CMakeLists.txt`中添加测试, 可供测试的包括, 可执行文件, `cmake`脚本或命令

```cmake
include(CTest)

# NAME 是为测试命名, COMMAND 是被测试文件, arg是参数
add_test(NAME <name> COMMAND <command> [<arg>...])
```

下面我们使用我们原先安装的数学库, 对其进行简单测试

首先, 由于我们之前已经把我们数学库给删了, 所以先再安装一下

```shell
[wind@Ubuntu CTest_myMath]$ cd ~/cmakeClass/install_shared_mymath/build/
[wind@Ubuntu build]$ ls
CMakeCache.txt  CMakeFiles  cmake_install.cmake  install_manifest.txt  lib  Makefile  my_lib
[wind@Ubuntu build]$ sudo cmake --install .
[sudo] password for wind: 
-- Install configuration: ""
-- Installing: /usr/local/lib/libMyMath.so.1.2.3
-- Installing: /usr/local/lib/libMyMath.so.20
-- Installing: /usr/local/lib/libMyMath.so
-- Up-to-date: /usr/local/include/MyMath
-- Installing: /usr/local/include/MyMath/math.h
-- Installing: /usr/local/lib/cmake/MyMath/MyMathTargets.cmake
-- Installing: /usr/local/lib/cmake/MyMath/MyMathTargets-noconfig.cmake
-- Installing: /usr/local/lib/cmake/MyMath/MyMathConfig.cmake
[wind@Ubuntu build]$ cd -
/home/wind/cmakeClass/CTest_myMath
[wind@Ubuntu CTest_myMath]$ 
```

接下里是目录结构

```shell
[wind@Ubuntu CTest_myMath]$ tree .
.
├── CMakeLists.txt
└── main.cpp

1 directory, 2 files
[wind@Ubuntu CTest_myMath]$ 
```

```cpp
#include<iostream>
#include<MyMath/math.h>
#include<cassert>

int main()
{
    assert(add(2,3) == 5);
    assert(sub(2,3) == -1);

    std::cout<<"Test OK!"<<std::endl;

    return 0;
}
```

```cmake
make_minimum_required(VERSION 3.18)

project(TestMyMath LANGUAGES CXX)

# 开启测试功能
include(CTest)

# 添加可执行测试文件
add_executable(main main.cpp)

# 查找MaMath库
find_package(MyMath CONFIG REQUIRED)

# 链接MyMath库
target_link_libraries(main PRIVATE MyMath::MyMath)

# 添加测试 到CTest
add_test(NAME TestMyMath COMMAND main)
```

```shell
[wind@Ubuntu CTest_myMath]$ mkdir build && cd build
[wind@Ubuntu build]$ cmake ..
-- The CXX compiler identification is GNU 13.3.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.5s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/CTest_myMath/build
[wind@Ubuntu build]$ cmake --build .
[ 50%] Building CXX object CMakeFiles/main.dir/main.cpp.o
[100%] Linking CXX executable main
[100%] Built target main
[wind@Ubuntu build]$ ctest
Test project /home/wind/cmakeClass/CTest_myMath/build
    Start 1: TestMyMath
1/1 Test #1: TestMyMath .......................   Passed    0.01 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.01 sec
[wind@Ubuntu build]$ 
```

`ctest`实际上就是执行构建之后生成的`CTestTestfile.cmake`脚本

```cmake
# CMake generated Testfile for 
# Source directory: /home/wind/cmakeClass/CTest_myMath
# Build directory: /home/wind/cmakeClass/CTest_myMath/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TestMyMath "/home/wind/cmakeClass/CTest_myMath/build/main")
set_tests_properties(TestMyMath PROPERTIES  _BACKTRACE_TRIPLES "/home/wind/cmakeClass/CTest_myMath/CMakeLists.txt;18;add_test;/home/wind/cmakeClass/CTest_myMath/CMakeLists.txt;0;")

```

​	我们看到, 全部(其实就一个)测试用例都被通过了. 接下来我们把它改成错的, 看看什么情况

```cpp
#include<iostream>
#include<MyMath/math.h>
#include<cassert>

int main()
{
    assert(add(2,3) == 5);
    assert(sub(2,3) == 1);

    std::cout<<"Test OK!"<<std::endl;

    return 0;
}
```

```shell
[wind@Ubuntu build]$ make clean
[wind@Ubuntu build]$ cmake --build .
[ 50%] Building CXX object CMakeFiles/main.dir/main.cpp.o
[100%] Linking CXX executable main
[100%] Built target main
[wind@Ubuntu build]$ ctest
Test project /home/wind/cmakeClass/CTest_myMath/build
    Start 1: TestMyMath
1/1 Test #1: TestMyMath .......................Subprocess aborted***Exception:   1.49 sec

0% tests passed, 1 tests failed out of 1

Total Test time (real) =   1.50 sec

The following tests FAILED:
          1 - TestMyMath (Subprocess aborted)
Errors while running CTest
Output from these tests are in: /home/wind/cmakeClass/CTest_myMath/build/Testing/Temporary/LastTest.log
Use "--rerun-failed --output-on-failure" to re-run the failed cases verbosely.
[wind@Ubuntu build]$ 
```

我们看到错误的同时还会为我们输出一份日志

```txt
Start testing: Sep 11 09:55 CST
----------------------------------------------------------
1/1 Testing: TestMyMath
1/1 Test: TestMyMath
Command: "/home/wind/cmakeClass/CTest_myMath/build/main"
Directory: /home/wind/cmakeClass/CTest_myMath/build
"TestMyMath" start time: Sep 11 09:55 CST
Output:
----------------------------------------------------------
main: /home/wind/cmakeClass/CTest_myMath/main.cpp:8: int main(): Assertion `sub(2,3) == 1' failed.
<end of output>
Test time =   1.49 sec
----------------------------------------------------------
Test Failed.
"TestMyMath" end time: Sep 11 09:55 CST
"TestMyMath" time elapsed: 00:00:01
----------------------------------------------------------

End testing: Sep 11 09:55 CST

```

```shell
[wind@Ubuntu CPack_mymath_shared]$ cd ~/cmakeClass/install_shared_mymath/build/
[wind@Ubuntu build]$ cat install_manifest.txt | xargs sudo rm -v
[sudo] password for wind: 
removed '/usr/local/lib/libMyMath.so.1.2.3'
removed '/usr/local/lib/libMyMath.so.20'
removed '/usr/local/lib/libMyMath.so'
removed '/usr/local/include/MyMath/math.h'
removed '/usr/local/lib/cmake/MyMath/MyMathTargets.cmake'
removed '/usr/local/lib/cmake/MyMath/MyMathTargets-noconfig.cmake'
removed '/usr/local/lib/cmake/MyMath/MyMathConfig.cmake'
[wind@Ubuntu build]$ 
```

-----------

接下来我们介绍`CPack`, `CPack`将基于`cmake`的`install`指令, 对需要打包的文件进行自动收集, 并生成指定格式的包格式, 比如`DEB RPM ZIP MSL DMG`, 而且它也可以进行依赖关系的配置. 规定包版本等功能.

我们还是以之前之前的, 那个有可执行程序的``mymath`为蓝本, 进行演示

```shell
[wind@Ubuntu cmakeClass]$ cp -rf my_math CPack_mymath_shared
[wind@Ubuntu cmakeClass]$ cd CPack_mymath_shared/
[wind@Ubuntu CPack_mymath_shared]$ rm -rf build
[wind@Ubuntu CPack_mymath_shared]$ tree .
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

5 directories, 7 files
[wind@Ubuntu CPack_mymath_shared]$
```

```cmake
# top
cmake_minimum_required(VERSION 3.18)

project(TestMyMath)

add_subdirectory(my_lib)

add_subdirectory(app)

# 要放在顶层最后一行, 否则收集文件可能不全
include(CPack)
```

```cmake
# src
file(GLOB SRC_LISTS "src/*.cpp")

# 使用源文件生成静态库MyMath
add_library(MyMath SHARED ${SRC_LISTS})

# 告诉cmake对于目标MyMath, 从哪里找到头文件
target_include_directories(MyMath PUBLIC
    # 构建阶段, 就以源代码上的头文件做包含路径
    "$<BUILD_INTERFACE:>${CMAKE_CURRENT_SOURCE_DIR}/include"
    # 安装阶段, 就以本地安装目录为准, 可以直接简写为include
    "#<INSTALL_INTERFACE:include>"
)

# 修改默认输出路径
set_target_properties(MyMath PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    OUTPUT_NAME MyMath
    VERSION 1.2.3
    SOVERSION 20
)

# 安装库文件
install(TARGETS MyMath)

# 安装头文件
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)

```

```cmake
# app
# 搜集文件列表
file(GLOB SRC_LISTS "*.cpp")

# 构建目标
add_executable(main ${SRC_LISTS})

# 添加链接库列表
target_link_libraries(main PRIVATE MyMath)

set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    # 添加构件时rpath
    BUILD_RPATH ${CMAKE_BINARY_DIR}/lib
    # 添加运行时rpath
    INSTALL_RPATH "\$ORIGIN/../lib" # ORIGIN是程序所在目录, 再向上以及就可以找到库目录, 这在构建和安装期都是成立的
)

install(TARGETS main)

```

由于之前没有安装, 所以我们的安装写的不是很规范, 比如, 我们没有包含`GNUInstallDirs`, 该模块内部包含了许多描述各平台位置的内置变量, 但我们在这里不用它的也可以, 另外, 有些`install`没有`DESTINATION`, 这样的话就使用默认, 也没什么大的影响, 不过如果真的要对外发布, 还是不要这样随意

```shell
[wind@Ubuntu CPack_mymath_shared]$ mkdir build && cd build
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
-- Configuring done (0.9s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/CPack_mymath_shared/build
[wind@Ubuntu build]$ cmake --build .
[ 20%] Building CXX object my_lib/CMakeFiles/MyMath.dir/src/add.cpp.o
[ 40%] Building CXX object my_lib/CMakeFiles/MyMath.dir/src/sub.cpp.o
[ 60%] Linking CXX shared library ../lib/libMyMath.so
[ 60%] Built target MyMath
[ 80%] Building CXX object app/CMakeFiles/main.dir/main.cpp.o
[100%] Linking CXX executable ../bin/main
[100%] Built target main
[wind@Ubuntu build]$ ls
app  bin  CMakeCache.txt  CMakeFiles  cmake_install.cmake  CPackConfig.cmake  CPackSourceConfig.cmake  lib  Makefile  my_lib
[wind@Ubuntu build]$ cpack
CPack: Create package using STGZ
CPack: Install projects
CPack: - Run preinstall target for: TestMyMath
CPack: - Install project: TestMyMath []
CPack: Create package
CPack: - package: /home/wind/cmakeClass/CPack_mymath_shared/build/TestMyMath-0.1.1-Linux.sh generated.
CPack: Create package using TGZ
CPack: Install projects
CPack: - Run preinstall target for: TestMyMath
CPack: - Install project: TestMyMath []
CPack: Create package
CPack: - package: /home/wind/cmakeClass/CPack_mymath_shared/build/TestMyMath-0.1.1-Linux.tar.gz generated.
CPack: Create package using TZ
CPack: Install projects
CPack: - Run preinstall target for: TestMyMath
CPack: - Install project: TestMyMath []
CPack: Create package
CPack: - package: /home/wind/cmakeClass/CPack_mymath_shared/build/TestMyMath-0.1.1-Linux.tar.Z generated.
[wind@Ubuntu build]$ ls
app  CMakeCache.txt  cmake_install.cmake  _CPack_Packages          install_manifest.txt  Makefile  TestMyMath-0.1.1-Linux.sh      TestMyMath-0.1.1-Linux.tar.Z
bin  CMakeFiles      CPackConfig.cmake    CPackSourceConfig.cmake  lib                   my_lib    TestMyMath-0.1.1-Linux.tar.gz
[wind@Ubuntu build]$ cp TestMyMath-0.1.1-Linux.tar.gz /tmp/
[wind@Ubuntu build]$ cd /tmp
[wind@Ubuntu tmp]$ tar xvf TestMyMath-0.1.1-Linux.tar.gz 
TestMyMath-0.1.1-Linux/include/
TestMyMath-0.1.1-Linux/include/my_math.h
TestMyMath-0.1.1-Linux/lib/
TestMyMath-0.1.1-Linux/lib/libMyMath.so.1.2.3
TestMyMath-0.1.1-Linux/lib/libMyMath.so
TestMyMath-0.1.1-Linux/lib/libMyMath.so.20
TestMyMath-0.1.1-Linux/bin/
TestMyMath-0.1.1-Linux/bin/main
[wind@Ubuntu tmp]$ cd TestMyMath-0.1.1-Linux/
[wind@Ubuntu TestMyMath-0.1.1-Linux]$ tree .
.
├── bin
│   └── main
├── include
│   └── my_math.h
└── lib
    ├── libMyMath.so -> libMyMath.so.20
    ├── libMyMath.so.1.2.3
    └── libMyMath.so.20 -> libMyMath.so.1.2.3

4 directories, 5 files
[wind@Ubuntu TestMyMath-0.1.1-Linux]$ cd bin
[wind@Ubuntu bin]$ ./main && ldd main
3 + 4 == 7
3 - 4 == -1
        linux-vdso.so.1 (0x00007ffd661bf000)
        libMyMath.so.20 => /tmp/TestMyMath-0.1.1-Linux/bin/./../lib/libMyMath.so.20 (0x0000745315a23000)
        libstdc++.so.6 => /lib/x86_64-linux-gnu/libstdc++.so.6 (0x0000745315600000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x0000745315200000)
        libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x0000745315934000)
        /lib64/ld-linux-x86-64.so.2 (0x0000745315a2f000)
        libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x0000745315906000)
[wind@Ubuntu bin]$ 
```

我们看到`/tmp/TestMyMath-0.1.1-Linux/bin/./../lib/libMyMath.so.20`用的正是`"\$ORIGIN/../lib"`

----

下面，我们将通过调用外部的 `protoc` 来练习 `cmake` 的命令模式。

首先简单介绍一下 `protoc`：它是一个将 `.proto` 文件转译成各种语言（如 C++、Java、Python 等）中类或结构体定义的工具。举个例子，在 `.proto` 文件里我们定义了一个 `Person` 消息结构，接着就可以用 `protoc` 把它生成对应的 C++ 类。

为什么要这样做呢？好处在于，它能从机制上确保协议的一致性。由于最初的 `.proto` 文件是统一的源头，不论前后端分别使用什么语言，都能通过各自生成的代码来共享同一份协议定义。

等到我们写好`.proto`后, 就可以让`cmake`调用`protoc`生成C++代码. 这就是`cmake`的命令模式, 即调用外部的命令行工具以完成更为复杂的功能.

在正式写代码之前, 我们先安装一下`protoc`

```shell
sudo apt install protobuf-compiler
```

接下来是项目结构

```shell
[wind@Ubuntu cmake_protoc]$ tree .
.
├── CMakeLists.txt
├── main.cpp
└── proto
    └── person.proto

2 directories, 3 files
[wind@Ubuntu cmake_protoc]$ 
```

```cmake
cmake_minimum_required(VERSION 3.18)

project(ProtocExample LANGUAGES CXX)

# 规定C++标准
set(CMAKE_CXX_STANDARD 11)

# 查找Protobuf库, 为proto的使用奠定基础: 包含需要用到的库文件/头文件
# 最低版本3.0
find_package(Protobuf 3.0 REQUIRED)

# 收集proto元消息文件
file(GLOB PROTO_FILES ${CMAKE_CURRENT_SOURCE_DIR}/proto/*.proto)

# 将来存放所有头文件 源文件全名称的集合
set(GEN_SRCS "") # *.pb.cc
set(GEN_HEADS "") # *.pb.h

# 创建proto的C++代码生成目录
set(PB_CPP_OUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/gen/cpp)
file(MAKE_DIRECTORY ${PB_CPP_OUT_DIR})

# 对PROTO_FILES下的所有文件进行循环操作
foreach(FILE ${PROTO_FILES})  # 将其中的每个文件取出, 用FILE指代
    # 获取原始文件中不带扩展名的基础名, 为将来生成的C++代码文件提供命名依据
    get_filename_component(BASE_NAME ${FILE} NAME_WE) # 如果原始文件是person.proto, 将把person取出放到BASE_NAME中

    # 将单个头文件源文件全名称追加到文件集合中
    list(APPEND GEN_SRCS "${PB_CPP_OUT_DIR}/${BASE_NAME}.pb.cc")
    list(APPEND GEN_HEADS "${PB_CPP_OUT_DIR}/${BASE_NAME}.pb.h")

    # 生成C++代码文件

    # 添加自定义指令
    add_custom_command(
        OUTPUT "${PB_CPP_OUT_DIR}/${BASE_NAME}.pb.cc" "${PB_CPP_OUT_DIR}/${BASE_NAME}.pb.h" # 指令输出文件, 将这些文件注册金cmake文件管理器
        COMMAND protoc # 使用外部命令行工具protoc
        ARGS --cpp_out=${PB_CPP_OUT_DIR} # 调用外部工具时的参数 输出cpp文件到指定目录下
            -I ${CMAKE_CURRENT_SOURCE_DIR}/proto # 告知protoc原始文件的搜索路径
            ${FILE} # protoc的操作文件
        DEPENDS ${FILE} # 自定义指令仅依赖于原始文件FILE
        COMMENT echo "从proto生成对应的C++代码"
        VERBATIM # 该指令不需要进行拆分优化, 保证搜索路径可以被正常传递
    )
    
endforeach()

# 添加自定义目标, 依赖于GEN_SRCS和GEN_HEADS两个文件集合
add_custom_target(generate_protobuf DEPENDS ${GEN_SRCS} ${GEN_HEADS})

# 配置阶段, 也就是cmake.. 阶段, cmake会执行foreach这个循环体, 它会把理应存在的文件全名称写入到GEN_SRCS和GEN_HEADS这两个文件集合中
# 并且, 由于cmake在自定义指令中发现将会生成某些文件, 于是也会将这些文件注册到自己的文件管理系统中, 并依据自定义指令, 为这些文件生成
# 对应的构建命令

# 而在构建阶段, 当试图构建自定义目标generate_protobuf时, cmake会读取两个文件集合中的文件信息, 并借助于自己的文件管理系统去寻找文件
# 文件管理器会发现文件是不存在的, 但在之前的注册信息中发现;了对应的生成方式, 于是文件管理器将这些文件构建指令交给cmake的其它相关组件
# 进行指令执行, 从而生成所需文件, 满足自定义目标的构建要求


# 将proto 生成的C++文件编译为静态库, 以方便它们作为一个整体供下游使用管理
add_library(MyPrto STATIC ${GEN_SRCS})
# cmake的普通目标不会通过文件管理器找文件, 也就是不能触发自动构建, 因此需要显示写明, 依赖于特定目标进行间接触发
add_dependencies(MyPrto generate_protobuf)
# 要求下游包含对应头文件
target_include_directories(MyPrto INTERFACE ${PB_CPP_OUT_DIR})
# 生成的C++源文件和头文件并不是完全自实现的, 它们还依赖于官方protobuf的相应文件
target_link_libraries(MyPrto PUBLIC protobuf::libprotobuf)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE MyPrto)
```

```cpp
#include<iostream>
#include"gen/cpp/person.pb.h"

int main()
{
    // 创建person对象
    example::Person person;
    person.set_name("whisper");
    person.set_id(12345);
    person.set_email("whisper@example.com");

    // 序列化person对象
    std::string serialized_data;
    person.SerializeToString(&serialized_data);
    std::cout<<"Serialized size: " << serialized_data.size()<<std::endl;


    // 反序列化person对象
    example::Person parsed_person;
    parsed_person.ParseFromString(serialized_data);
    std::cout<<parsed_person.DebugString();

    return 0;
}
```

```protobuf
/ 指定使用的 proto 语法版本
syntax = "proto3";

// 定义包名（命名空间），避免不同文件中消息名冲突
package example;

// 在 proto 中，消息由若干字段组成
// 每个字段都有一个唯一的编号（tag），编号才是序列化时真正传输的标识
// name、id、email 是字段名，方便在代码中引用
message Person {
    string name  = 1;  // 字段1：字符串类型
    int32  id    = 2;  // 字段2：32位整型
    string email = 3;  // 字段3：字符串类型
}

```

```shell
[wind@Ubuntu cmake_protoc]$ mkdir build && cd build
[wind@Ubuntu build]$ cmake .. && cmake --build .
-- The CXX compiler identification is GNU 13.3.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found Protobuf: /usr/lib/x86_64-linux-gnu/libprotobuf.so (found suitable version "3.21.12", minimum required is "3.0") 
-- Configuring done (0.9s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/cmake_protoc/build
[ 16%] Built target generate_protobuf
[ 33%] Building CXX object CMakeFiles/MyPrto.dir/gen/cpp/person.pb.cc.o
[ 50%] Linking CXX static library libMyPrto.a
[ 66%] Built target MyPrto
[ 83%] Building CXX object CMakeFiles/main.dir/main.cpp.o
[100%] Linking CXX executable main
[100%] Built target main
[wind@Ubuntu build]$ 
```

## 第四章

下面我们侧重于`cmake`常见命令的语法细节

`message`函数

在`cmake`中可以使用`message`命令打印消息. 函数的签名如下

```cmake
message([STATUS|WARNING|AUTHOR_WARNING|FATAL_ERROR|SEND_ERROR] "massage to display" ...)
```

其中第一个参数, 也就是`STATUS|WARNING|AUTHOR_WARNING|FATAL_ERROR|SEND_ERROR`这些, 描述的是信息的级别, 不同的级别将会对`cmake`的构建行为做出不同的影响, 该函数可缺省, 默认参数为`NOTICE`, 即无普通, 只是进行一下常规打印. `cmake`对于相邻字符串的处理方式与C/C++相同, 都是直接拼接成一个更长的字符串("hello " "word" = "hello world").

- FATAL_ERROR : 如果出现这种级别的消息, `cmake`将会停止脚本处理及生成构建文件, 并返回非零错误码.
- SEND_ERROR: `cmake`错误, 但仍会继续脚本, 但不会生成构建文件
- WARNING: 发出警告, 但脚本执行和构建文件生成仍将继续
- STATUS: 表示打印信息是用户关系的关键数据

其它不常用

下面我们实际演示一下.

```shell
[wind@Ubuntu cmake_language]$ tree .
.
└── CMakeLists.txt

1 directory, 1 file
[wind@Ubuntu cmake_language]$ 
```

```cmake
[wind@Ubuntu cmake_language]$ mkdir build && cd build
[wind@Ubuntu build]$ cat ../CMakeLists.txt 
cmake_minimum_required(VERSION 3.18)

project(MessageDemo)

message("begin " "CMakeLists.txt")
[wind@Ubuntu build]$ 
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
begin CMakeLists.txt
-- Configuring done (0.9s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/cmake_language/build
[wind@Ubuntu build]$ ls
CMakeCache.txt  CMakeFiles  cmake_install.cmake  Makefile
[wind@Ubuntu build]$ 
```

`Configuring done`就是`CMakeLists.txt`脚本读完了, `Generating done`就是像`MakeFile`那样的配置文件生成了. 另外我们也看到了相邻字符串合并.

```shell
[wind@Ubuntu build]$ printf "\nmessage(STATUS "123")" >> ../CMakeLists.txt 
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
begin CMakeLists.txt
-- 123
-- Configuring done (0.9s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/cmake_language/build
[wind@Ubuntu build]$ ls
CMakeCache.txt  CMakeFiles  cmake_install.cmake  Makefile
[wind@Ubuntu build]$ 
```

我们看到在表面上看起来就是多了两个`--`

对于`WARNING`, 我们可以看到它是有语法高亮的, 并继续处理脚本和生成文件

![image-20250913104550482](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250913104550482.png)

`SEND_ERROR`则是不生成构建文件

![image-20250913104910509](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250913104910509.png)

可以看到, 对于`SEND_ERROR`, 脚本仍旧继续进行, 打印了最后的"end CMakeLists.txt", 但并没有生成构建文件

对于`FATAL_ERROR`, 则连脚本都没有读完

![image-20250913105753751](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250913105753751.png)

在最后, 我们再简略说说其中某些等级的使用场景.

---------------

下面, 我们将介绍`cmake`中与变量相关的语法细节.

变量是`cmake`中的基本存储单位, 它们的值始终是字符串.`set`和`unset`命令显式地设置或者取消设置变量, 但其它指令也具有修改变量的语义. 变量名区分大小写, 并且几乎可以由任何文本组成, 但我们建议仅使用由数字字符加上`- _`所组成的名称.

与C/C++的变量类似, 在`cmake`中, 变量亦具有作用域的概念, 每个`set`和`unset`的变量, 都会在当前作用域开辟或释放一片空间.

`Block Scope`块作用域

使用`block() endblock()`语句, 可以类似C/C++`{}`一般, 创建一个局部作用域, 不过不常用

```cmake
block()
  set(MY_VAR "inner")
  message("Inside block: ${MY_VAR}")
endblock()
```

`Function Scope`函数作用域

使用`function() endfunction()`语句可以定义一段函数, 与C/C++中的函数类似, 这种`cmake`函数也可以有参数, 但没有返回值, 当使用被定义的函数时, 其也会有形参实参的概念, 函数内部局部变量的生命周期和函数相同

```cmake
# 定义一个叫f的函数
function(f x y)
  message("Inside: x=${x}, y=${y}")
endfunction()

# 使用函数
f(hello world)
```

`Directory Scope`目录作用域

在父级脚本定义的变量, 在子级脚本中会以C/C++引用的形式被继承下来, 作为对子级脚本作用域的初始化. 在`block() function()`外定义的变量即在本脚本的目录作用域中.

`Persistent Cache`持久缓存

在`set`时, 如果添加`CACHE STRING`参数, 则会将变量写入持久缓存, 即`cmake`自己的项目配置中, 这样在这个项目中的任何子目录都能使用该变量, 与C/C++类似, 持久缓存变量优先级低, 只在高优先级没有重名变量后才会被使用.

```cmake
# 在任意一个脚本中定义持久缓存变量
set(MY_VAR "new_value" CACHE STRING "desc" FORCE)
# 可以使用FORCE为缓存变量添加注释
# STRING表明变量类型, 也可以视为说明性设置
```

当我们使用`${}`(解引用)的时候, `cmake`会按照`Block Function Directory Cache`的先后顺序搜索变量, 这里的搜索先后顺序也能体现不同作用域变量的优先级. 如果变量无法被找到, 那就被视为空字符串. 同时, 在解引用时, 是否携带双引号都是可以的(`message(${val}) message("${val}")`), 解引用可以被嵌套使用, 即`${outer_${inner_variable}}_variable`, 将从内向外进行解引用. 对解引用添加特定字段, 可以要求其在特定的命名域下搜索变量, 比如`$ENV{variable}`表示从`cmake`自`shell`继承的环境变量里寻找, `$CAVHE{variable}`表示去持久缓存里寻找.

`cmake`自己也有内置变量, 就是我们之前常写的`CMAKE_`等前缀变量.

在`if()`语句中, 可以不使用`${}`直接使用变量, 即`if(variable)`, 除非含有特殊字段.

-----

下面, 我们就通过实际的代码测试更深入地了解其中有关变量的知识.

首先是关于函数作用域的

```shell
[wind@Ubuntu test_func_scop]$ tree .
.
└── CMakeLists.txt

1 directory, 1 file
[wind@Ubuntu test_func_scop]$ 
```

```cmake
cmake_minimum_required(VERSION 3.18)

project(FunctionScopDemo)

# 自定义并初始化变量
set(SCOP "Directory Scop")

# 函数定义
function(f)
    # 读取上级作用域变量
    message("func: ${SCOP}")
endfunction(f)

# 函数调用
f()
```

```shell
[wind@Ubuntu test_func_scop]$ mkdir build && cd build
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
func: Directory Scop
-- Configuring done (0.9s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_func_scop/build
```

当运行一个函数体时, `cmake`会直接把目录作用域中的变量直接全部复制拷贝一下, 当做函数体中的初始化变量, 而在函数运行完毕后, 其中的这些被复制的变量也会被一统释放, 就像栈帧那样.(只不过传参方式不太相同) 既然函数体里面已经有`SCOP`, 那么打印时自然直接使用了这个离得"最近"的`SCOP`, 所以打印`Directory Scop`.

下面演示在函数内部进行变量修改会发生什么

![image-20250914201759489](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250914201759489.png)

当`f`执行`  set(SCOP "Function Scop")`这个语句时, 因为函数体中本来就有`SCOP`(在进入函数体时就已经全部拷贝过了), 所以它还是选择对函数体里的`SCOP`进行修改, 而在第二次打印时, 由于打印语句在函数体里, 所以还是读取最近的`SCOP`, 这样就打印出了修改后的内容`Function Scop`. 

而在第三次打印, 由于我们在整个过程中始终没有对目录作用域的`SCOP`进行修改, 所以他还是原来的值`Directory Scop`

如果我们就是想修改目录作用域的`SCOP`, 就需要带上`PARENT_SCOPE` 

![image-20250914203624314](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250914203624314.png)

在这里, 由于我们的变量还是在进入函数时就已经被拷贝, 所以对于函数体里的`SCOP`, 它仍然是原值, `PARENT_SCOPE`会对目录作用域的`SCOP`造成影响, 可不会对函数体里的`SCOP`造成影响, 因此, 它始终是原值, 所以在第二次打印时显示`Directory Scop`, 而对第三次打印来说, 由于我们之前已经修改过了目录作用域里的`SCOP`, 所以打印了修改后的值`Function Scop`

所以关键的一点是, 我们要认识到, `cmake`对于变量的拷贝策略是采用"饿汉"模式, 它不是像Linux那种"惰性"或者"懒汉"拷贝: 用的时候就拷贝, 而是在一开始就进行拷贝, 这在下面的实验中, 也是成立的. 至于`cmake`为什么采用这种策略, 我个人的推测是可能为了降低自身的复杂度, 一方面, 脚本它也不会有太多的变量, 另一方面, 它也不至于有太多层, 所以全拷贝性能开销并不太, 她不像操作系统那样太注重对资源的利用率.

---

下面我们看看由父目录到子目录的情况, 

```shell
[wind@Ubuntu test_dir_scop]$ tree .
.
├── CMakeLists.txt
└── src
    └── CMakeLists.txt

2 directories, 2 files
[wind@Ubuntu test_dir_scop]$ 
```

我们将在父目录中定义一个变量, 然后, 在父目录脚本和子目录脚本中分别打印它们

```cmake
cmake_minimum_required(VERSION 3.18)

project(DirectScopDemo)

set(SCOP "Parent Scop")

add_subdirectory(src)

message("main: ${SCOP}")
```

```cmake
message("sub: ${SCOP}")

set(SCOP "Sub Scop")

message("sub: ${SCOP}")
```

```shell
[wind@Ubuntu test_dir_scop]$ mkdir build && cd build
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
sub: Parent Scop
sub: Sub Scop
main: Parent Scop
-- Configuring done (0.9s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_dir_scop/build
[wind@Ubuntu build]$ 
```

正如我们之前提到的, `cmake`使用的是"饿汉"拷贝, 在进入子目录时, 他就已经把父目录的变量都拷贝下来了, 对于子目录来说, 查找`SCOP`访问的都是子目录下那个被拷贝的`SCOP`, 所以子目录的整个过程都是在圈地自萌, 你打印的是自己的`	SCOP`, 修改的也是自己的`SCOP`,  第二次打印的还是自己的`SCOP`, 第三次打印, 由于父目录的`SCOP`始终没有被修改, 所以始终都是原始值.

同样的, 使用`PARENT_SCOPE`将会对原值进行修改

![image-20250914221331605](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250914221331605.png)

还是在`add_subdirectory`时就已经进行了全拷贝, 在子目录的唯一一次变量修改中, 改变的是父目录的变量, 所以子目录变量一直都是最开始拷贝下来的那个原值, 因此, 子目录的两次打印还是原值, 而对于第三次打印来说, 由于父目录变量被子目录修改, 所以变为了修改值. 

如果你想有一个全局唯一的变量, 那就请用持久缓存

----

接下来我们介绍持久缓存

缓存变量解决的是"信息在多次`cmake`在多次调用之间, 以及在整个源码树各目录之间如何共享并持久化"的问题. 当我们使用缓存变量时, `cmake`就会把缓存变量写到构建目录的`CmakeCatch.txt`文件中, 通过文件的持久化, 以及变量定义指令在初始执行和后续执行的不同行为, 来实现了跨次数, 跨目录的信息传递.

正如我们之前说的

```cmake
set(MY_VAR "new_value" CACHE STRING "desc")
```

可以设置缓存变量, 并且, 其在第一次项目配置和后续次项目配置的行为不同.

```shell
[wind@Ubuntu test_catch_scop]$ tree .
.
└── CMakeLists.txt

1 directory, 1 file
[wind@Ubuntu test_catch_scop]$ 
```

```cmake
cmake_minimum_required(VERSION 3.18)

project(CatchScopDemo)

set(OS "linux" CACHE STRING "os name")

message("OS: ${OS}")
message("OS: $CACHE{OS}")
```

```shell
[wind@Ubuntu test_catch_scop]$ mkdir build && cd build
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
OS: linux
OS: linux
-- Configuring done (0.9s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_catch_scop/build
[wind@Ubuntu build]$ 
```

在这之后, 我们就能从构建目录的`CmakeCatch.txt`找到它

![image-20250915083824770](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250915083824770.png)

另外, 由于解引用是按照一定顺序寻找的, 所以相比使用`message("OS: ${OS}")`, `message("OS: $CACHE{OS}")`显然是更好的.

对于第二次进行`cmake`配置, 或者说是`cmake`刷新的时候, 缓存变量仍会正常存在, 所以缓存变量是跨次数的.

![image-20250915084323711](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250915084323711.png)

在已有同名缓存变量存在的情况下, 相同的指令将不会起到覆写作用, 所以不同的配置次数现象将会不同

```cmake
cmake_minimum_required(VERSION 3.18)

project(CatchScopDemo)

set(OS "mac" CACHE STRING "os name")

# message("OS: ${OS}")
message("OS: $CACHE{OS}")
```

```shell
[wind@Ubuntu build]$ cmake .
OS: linux
-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_catch_scop/build
[wind@Ubuntu build]$ 
```

除非再加上`FORCE`选项, 否则都不会覆写

![image-20250915084917101](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250915084917101.png)

所以如果你不想让同样的`CmakeLists.txt`在你的目录和别人刚克隆下来的项目表现不同(克隆下来的没build)的话, 就可以带上这个行为, 让`cmake`每次配置行为相同

```cmake
cmake_minimum_required(VERSION 3.18)

project(CatchScopDemo)

set(OS "mac" CACHE STRING "os name" FORCE)

# message("OS: ${OS}")
message("OS: $CACHE{OS}")
```

```shell
[wind@Ubuntu test_catch_scop]$ mkdir build && cd build
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
OS: mac
-- Configuring done (0.9s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_catch_scop/build
[wind@Ubuntu build]$ 
```

```cmake
cmake_minimum_required(VERSION 3.18)

project(CatchScopDemo)

set(OS "linux" CACHE STRING "os name" FORCE)

# message("OS: ${OS}")
message("OS: $CACHE{OS}")
```

```shell
[wind@Ubuntu build]$ cmake .
OS: linux
-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_catch_scop/build
[wind@Ubuntu build]$ 
```

一直带上`FORCE`选项, 构建项目就会始终与`CmakeLists.txt`的内容为准, 而不会受到诸如配置次数, 文件修改的影响.

除此之外, 也可以在配置时, 在命令后加上`-Dname=value`选项来实现命令行的缓存变量覆写

![image-20250915090101274](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250915090101274.png)

如果同时使用`	FORCE`和命令行方式覆写, 最后会以`FORCE`的内容为准, 也就是`FORCE`的优先级更高

现在, 缓存文件是`win`, 接下来, `FORCE`是`linux`, 命令行是`mac`

![image-20250915090410603](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250915090410603.png)

-----

接下来我们说环境变量.

在一般情况下, `cmake`不会搜索环境变量, 除非是加上`ENV`选项. 具体来说, 环境变量有两种级别, 首先是`cmake`自己设置的环境变量, 对于这种环境变量, 在`cmake`进程结束后就自然结束. 而另一种, 则是`shell`的环境变量, `shell`作为操作系统的窗口, 将会锁系统一直运行, 它的环境变量, 具有持久性.

```shell
[wind@Ubuntu test_env_scop]$ tree .
.
└── CMakeLists.txt

1 directory, 1 file
[wind@Ubuntu test_env_scop]$
```

```cmake
cmake_minimum_required(VERSION 3.18)

project(EnvVarDemo)

message("env: $ENV{OS}")
```

```shell
[wind@Ubuntu test_env_scop]$ echo ${OS}

[wind@Ubuntu test_env_scop]$ mkdir build && cd build
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
env: 
-- Configuring done (0.9s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_env_scop/build
[wind@Ubuntu build]$ 
```

我们看到, `shell`的环境变量中并没有`OS`, 自然, 在`cmake`中也找不到这个变量, 所以被解释为了空字符串, 下面, 我们让`cmake`自己新建一个环境变量

```cmake
cmake_minimum_required(VERSION 3.18)

project(EnvVarDemo)

message("env: $ENV{OS}")

set(ENV{OS} "linux")

message("env: $ENV{OS}")
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
env: 
env: linux
-- Configuring done (0.9s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_env_scop/build
[wind@Ubuntu build]$ cmake .
env: 
env: linux
-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_env_scop/build
[wind@Ubuntu build]$ 
```

在我们把环境变量导入到`cmake`自己的地址空间之后, 我们看到, 就能打印出来了. 并且因为进程结束地址空间回收, 所以刷新的时候第一次还是没有看到它打印出来.

接下来我们在`shell`中导入相应的环境变量

```shell
[wind@Ubuntu build]$ export OS=mac
[wind@Ubuntu build]$ echo ${OS}
mac
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
env: mac
env: linux
-- Configuring done (0.9s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_env_scop/build
[wind@Ubuntu build]$ 
```

第一次读到的就是从`shell`那里继承下来的环境变量, 接下来`cmake`自己又对环境变量进行了修改, 所以第二次打印显示修改后的内容.

-----

下面我们说`cmake`中的`if`语句

`cmake`的`if`支持许多功能, 我们先来看第一个, 也是最常用的一个, 基本表达式

`if`可以对`()`中的表达式进行逻辑判断, 有以下几种规则

在`cmake`中, 定义了许多能表达真假的常量. 比如如果常量为`1, ON, YES, TRUE, Y`(忽略大小写)或非零数字(包括浮点数), 就是True. 如果常量是`0, OFF, NO, FALSE, N, IGNORE, NOTFOUND`(不区分大小写)空字符串或以后缀`-ONTFOUND`为结尾, 则为False, 当参数不属于这些常量时, 将会被视为变量或字符串, 受到下面两段的制约.

当括号中的内容是变量时, `cmake`会依据变量的值进行真假判断, 如果该变量被定义为一个非假常量的值则为真, 否则(包括变量未定义情况)都将被视为假. 注意环境变量不能通过这种方式进行测试, 如果解引用环境变量, 得到的结果将总是为假.

而对于字符串来说, 也就是带上引号的字符串, 将始终为假, 除非, 这个字符串是真值常量的字面量, 又或者, 对于4.0之前的`cmake`, 字符串的字面量是受`CMP0054`策略影响的字符串(这个没人用).

```sherll
[wind@Ubuntu test_base_exp]$ tree .
.
└── CMakeLists.txt

1 directory, 1 file
[wind@Ubuntu test_base_exp]$ 
```

```cmake
cmake_minimum_required(VERSION 3.18)

project(IfBasicExprDemo)

# 常量真
if(ON)
    message("ON: true")
else()
    message("ON: false")
endif()

# 常量真
if(1)
    message("1: true")
else()
    message("1: false")
endif()

# 常量假
if(0)
    message("0: true")
else()
    message("0: false")
endif()

# 常量假
if(OFF)
    message("OFF: true")
else()
    message("OFF: false")
endif()

# 常量真
if(1.1)
    message("1.1: true")
else()
    message("1.1: false")
endif()

# 常量假
if(MYPATH-NOTFOUND)
    message("MYPATH-NOTFOUND: true")
else()
    message("MYPATH-NOTFOUND: false")
endif()

# 字符串
if("rabbit")
    message("\"rabbit\": true")
else()
    message("\"rabbit\": false")
endif()

# 字面量为非假常量的变量
set(FOOD "carrot")
if(FOOD)
    message("FOOD(carrot): true")
else()
    message("FOOD(carrot): false")
endif()

set(QUESTION "IGNORE")
if(QUESTION)
    message("QUESTION(IGNORE): true")
else()
    message("QUESTION(IGNORE): false")
endif()

# 字符串
if("TRUE")
    message("\"TRUE\": true")
else()
    message("\"TRUE\": false")
endif()

# 环境变量
if($ENV{LOGNAME})
    message("LOGNAME: true")
else()
    message("LOGNAME: false")
endif()

```

```shell
[wind@Ubuntu test_base_exp]$ mkdir build && cd build
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
ON: true
1: true
0: false
OFF: false
1.1: true
MYPATH-NOTFOUND: false
"rabbit": false
FOOD(carrot): true
QUESTION(IGNORE): false
"TRUE": true
LOGNAME: false
-- Configuring done (0.9s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_base_exp/build
[wind@Ubuntu build]$ 
```

接下来我们看第二个场景, 逻辑运算, 可以使用`NOT AND OR`进行非运算, 与运算, 或运算.

```cmake
# !
if(NOT NO)
    message("NOT NO: true")
else()
    message("NOT NO: false")
endif()

# &&
if("on" AND "off")
    message("\"on\" AND \"off\": true")
else()
    message("\"on\" AND \"off\": false")
endif()

# ||
if("on" OR "off")
    message("\"on\" OR \"off\": true")
else()
    message("\"on\" OR \"off\": false")
endif()
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
ON: true
1: true
0: false
OFF: false
1.1: true
MYPATH-NOTFOUND: false
"rabbit": false
FOOD(carrot): true
QUESTION(IGNORE): false
"TRUE": true
LOGNAME: false
NOT NO: true
"on" AND "off": false
"on" OR "off": true
-- Configuring done (0.9s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_base_exp/build
[wind@Ubuntu build]$ 
```

下面我们说`if`的又一个功能: 存在性检测, 用于检测各种东西是否存在.

```cmake
# 是否存在这种指令
if(COMMAND project)
    message("COMMAND project: true")
else()
    message("COMMAND project: false")
endif()

if(COMMAND ls)
    message("COMMAND ls: true")
else()
    message("COMMAND ls: false")
endif()

# 是否存在这样的目标
add_library(MyMath INTERFACE IMPORTED)
if(TARGET MyMath)
    message("TARGET MyMath: true")
else()
    message("TARGET MyMath: false")
endif()

# 是否定义这种变量

## 普通变量
if(DEFINED NAME)
    message("DEFINED NAME: true")
else()
    message("DEFINED NAME: false")
endif()

if(DEFINED FOOD)
    message("DEFINED FOOD: true")
else()
    message("DEFINED FOOD: false")
endif()

## 缓存变量
set(NAME "wind" CACHE STRING "name")
if(DEFINED NAME)
    message("DEFINED NAME: true")
else()
    message("DEFINED NAME: false")
endif()

## 环境变量
if(DEFINED ENV{PATH})
    message("DEFINED ENV{PATH}: true")
else()
    message("DEFINED ENV{PATH}: false")
endif()
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
ON: true
1: true
0: false
OFF: false
1.1: true
MYPATH-NOTFOUND: false
"rabbit": false
FOOD(carrot): true
QUESTION(IGNORE): false
"TRUE": true
LOGNAME: false
NOT NO: true
"on" AND "off": false
"on" OR "off": true
COMMAND project: true
COMMAND ls: false
TARGET MyMath: true
DEFINED NAME: false
DEFINED FOOD: true
DEFINED NAME: true
DEFINED ENV{PATH}: true
-- Configuring done (0.9s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_base_exp/build
[wind@Ubuntu build]$ 
```

 接下里有关`if`的文件检测,

```cmake
# 是否存在这样的文件或目录, 并可读
if(EXISTS ${CMAKE_CURRENT_LIST_FILE})
    message([==[EXISTS ${CMAKE_CURRENT_LIST_FILE}: true]==])  # 这种写法是让它不要解引用[==[...]==]
else()
    message([==[EXISTS ${CMAKE_CURRENT_LIST_FILE}: false]==])
endif()

if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/main.cpp)
    message([==[EXISTS ${CMAKE_CURRENT_LIST_DIR}/main.cpp: true]==])
else()
    message([==[EXISTS ${CMAKE_CURRENT_LIST_DIR}/main.cpp: false]==])
endif()

# 空路径视为假
if(EXISTS "")
    message("EXISTS \"\": true")
else()
    message("EXISTS \"\": false")
endif()

# 不支持相对路径, 未定义行为
if(EXISTS "./CMakeLists.txt")
    message("EXISTS \"./CMakeLists.txt\": true")
else()
    message("EXISTS \"./CMakeLists.txt\": false")
endif()
```

```shell
[wind@Ubuntu build]$ cmake ..
ON: true
1: true
0: false
OFF: false
1.1: true
MYPATH-NOTFOUND: false
"rabbit": false
FOOD(carrot): true
QUESTION(IGNORE): false
"TRUE": true
LOGNAME: false
NOT NO: true
"on" AND "off": false
"on" OR "off": true
COMMAND project: true
COMMAND ls: false
TARGET MyMath: true
DEFINED NAME: true
DEFINED FOOD: true
DEFINED NAME: true
DEFINED ENV{PATH}: true
EXISTS ${CMAKE_CURRENT_LIST_FILE}: true
EXISTS ${CMAKE_CURRENT_LIST_DIR}/main.cpp: false
EXISTS "": false
EXISTS "./CMakeLists.txt": false
-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_base_exp/build
[wind@Ubuntu build]$ 
```

下面我们说有关`if`的比较

```cmake
# 给定字符串是否与正则表达式匹配
if(google MATCHES goo+gle)
    message("google MATCHES goo+gle: true")
else()
    message("google MATCHES goo+gle: false")
endif()

# a < b ?  按照实数大小进行比较
if("20" LESS "30")
    message("\"20\" LESS \"30\": true")
else()
    message("\"20\" LESS \"30\": false")
endif()

# a > b ?
if("1" GREATER "0")
    message("\"1\" GREATER \"0\": true")
else()
    message("\"1\" GREATER \"0\": false")
endif()

# a < b ? 按照字典序大小比较
if("abc" STRLESS "abd")
    message("\"abc\" STRLESS \"abd\": true")
else()
    message("\"abc\" STRLESS \"abd\": false")
endif()    

# a < b ? 
if("found" STRGREATER "eaten")
    message("\"found\" STRGREATER \"eaten\": true")
else()
    message("\"found\" STRGREATER \"eaten\": false")
endif()    
```

```shell
[wind@Ubuntu build]$ cmake ..
ON: true
1: true
0: false
OFF: false
1.1: true
MYPATH-NOTFOUND: false
"rabbit": false
FOOD(carrot): true
QUESTION(IGNORE): false
"TRUE": true
LOGNAME: false
NOT NO: true
"on" AND "off": false
"on" OR "off": true
COMMAND project: true
COMMAND ls: false
TARGET MyMath: true
DEFINED NAME: true
DEFINED FOOD: true
DEFINED NAME: true
DEFINED ENV{PATH}: true
EXISTS ${CMAKE_CURRENT_LIST_FILE}: true
EXISTS ${CMAKE_CURRENT_LIST_DIR}/main.cpp: false
EXISTS "": false
EXISTS "./CMakeLists.txt": false
google MATCHES goo+gle: true
"20" LESS "30": true
"1" GREATER "0": true
"abc" STRLESS "abd": true
"found" STRGREATER "eaten": true
-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_base_exp/build
[wind@Ubuntu build]$ 
```

下面我们说与`if`有关的版本号比较, 对于不同版本的客户端, 由于其所支持的功能可能不同, 因此服务端也应该有与之对应的行为.

```cmake
## 比1.3.0小, 说明是老版本, 有些功能不支持
if(VERSION VERSION_LESS "1.3.0")
    message("VERSION VERSION_LESS \"1.3.0\": true")
else()
    message("VERSION VERSION_LESS \"1.3.0\": false")
endif()
```

```shell
VERSION VERSION_LESS "1.3.0": true
-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_base_exp/build
[wind@Ubuntu build]$ 
```

对于`if`, 还有一些功能, 比如使用`PATH_EQUAL`进行路径匹配, 两个路径完全相同, 则返回真, 比如变量扩展, `cmake`的`if`编写早于`${}`编写的时间, 所以`if`对于其中的普通变量, 会自动进行解引用, 即对于普通变量`varl`, `if(varl)`和`if(${varl}`实际上是同一种写法, 注意, 缓存变量和环境变量不支持自动解引用, 还是需要`$CACHE{}`或者`$ENV{}`进行手动解引用.

---------

`cmake`中有两种循环语句, `foreach`和`while`, 下面我们介绍`cmake`中的`foreach`循环语法.

`foreach`的基本语法如下

```cmake
foreach(<loop_var> <items>)
  <commands>
endforeach()
```

其中, `loop_var`是循环变量, `items`是由分号或空格分隔的项列表, 每次迭代开始前, `loop_var`会被设置为当前项的值.对于循环体的变量, 与C/C++性质相同, 除此之外, 他也允许使用`break()`或`continue()`命令脱离正常的循环流.

```cmake
cmake_minimum_required(VERSION 3.18)

project(ForeachDemo)

foreach(X1 "1" "2;3;4" "abc")
    message(STATUS "X1: ${X1}")
endforeach()

```

```shell
[wind@Ubuntu test_foreach]$ mkdir build && cd build 
[wind@Ubuntu build]$ cmake ..
cmake: /usr/local/lib/libcurl.so.4: no version information available (required by cmake)
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
-- X1: 1
-- X1: 2;3;4
-- X1: abc
-- Configuring done (0.8s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_foreach/build
[wind@Ubuntu build]$ 
```

循环的项分别是`1   2;3;4   abc`这三个字符串

`RANGE`默认会从数字"0"开始, 一直以一的步长进行迭代, 直到到达并包含终止数字

```cmake
foreach(X2 RANGE 9)
    message(STATUS "X2: ${X2}")
endforeach()
```

 ```shell
 -- X2: 0
 -- X2: 1
 -- X2: 2
 -- X2: 3
 -- X2: 4
 -- X2: 5
 -- X2: 6
 -- X2: 7
 -- X2: 8
 -- X2: 9
 -- Configuring done (0.0s)
 -- Generating done (0.0s)
 -- Build files have been written to: /home/wind/cmakeClass/test_foreach/build
 [wind@Ubuntu build]$ 
 ```

`RANGE`也可以设置起始数字和步长

```cmake
foreach(X3 RANGE 10 20 3)
    message(STATUS "X3: ${X3}")
endforeach()
```

```shell
-- X3: 10
-- X3: 13
-- X3: 16
-- X3: 19
-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_foreach/build
[wind@Ubuntu build]$ 
```

`IN ITEMS`其实就是`foreach`的默认行为, 也就是第一种

```cmake
foreach(X4 IN ITEMS "1" "2;3;4" "abc")
    message(STATUS "X4: ${X4}")
endforeach()
```

```shell
-- X4: 1
-- X4: 2;3;4
-- X4: abc
-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_foreach/build
[wind@Ubuntu build]$ 
```

`IN LISTS`则是对变量进行遍历的选项, 其中的变量, 如果它们的值是允许的, 则会被再解析, 直到其不再是项列表

```cmake
set(L1 "1")
set(L2 "2;3;4")
set(L3 "abc")
foreach(X5 IN LISTS L1 L2 L3)
    message(STATUS "X5: ${X5}")
endforeach()
```

```shell
-- X5: 1
-- X5: 2
-- X5: 3
-- X5: 4
-- X5: abc
-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_foreach/build
[wind@Ubuntu build]$ 
```

下面我们来看`while`循环, `while`将在条件为真时不断循环, 与`foreach`相比, `while`的迭代是手动控制的, 而不是像`foreach`那样通过项列表进行迭代, 所以要注意循环体内对循环变量的调整, 以防止无线循环的出现.

```cmake
set(i 1)
# 当i <= 5时
while(i LESS_EQUAL 5)
    message(STATUS "i = ${i}")
    math(EXPR i "${i} + 1")   # i++
endwhile()
```

```shell
-- i = 1
-- i = 2
-- i = 3
-- i = 4
-- i = 5
-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_foreach/build
[wind@Ubuntu build]$ 
```

-----------

接下来, 我们说函数`list`, 该函数是为了对`cmake`的列表这种数据结构进行操作而生的, 之前我们也说过, 列表在`Cmake`中是一组由分号分隔的值.

`list`支持对列表的许多操作, 具体信息请查询[官方文档](https://cmake.org/cmake/help/latest/command/list.html), 下面, 我们将列举其中的部分常用操作

```cmake
Reading
  list(LENGTH <list> <out-var>)
  list(GET <list> <element index> [<index> ...] <out-var>)
  list(JOIN <list> <glue> <out-var>)
  list(SUBLIST <list> <begin> <length> <out-var>)

Search
  list(FIND <list> <value> <out-var>)

Modification
  list(APPEND <list> [<element>...])
  list(FILTER <list> {INCLUDE | EXCLUDE} REGEX <regex>)
  list(INSERT <list> <index> [<element>...])
  list(POP_BACK <list> [<out-var>...])
  list(POP_FRONT <list> [<out-var>...])
  list(PREPEND <list> [<element>...])
  list(REMOVE_ITEM <list> <value>...)
  list(REMOVE_AT <list> <index>...)
  list(REMOVE_DUPLICATES <list>)
  list(TRANSFORM <list> <ACTION> [...])

Ordering
  list(REVERSE <list>)
  list(SORT <list> [...])
```

```shell
[wind@Ubuntu test_list]$ tree .
.
└── CMakeLists.txt

1 directory, 1 file
[wind@Ubuntu test_list]$ 
```

```cmake
cmake_minimum_required(VERSION 3.18)

project(ListDemo)

# 创建列表 如果用;分隔就不要再带空格了, 否则会解析错误
set(SRCS "main.cpp;utils.cpp;math.cpp")

# 添加新项
list(APPEND SRCS "network.cpp")
message(STATUS "add: ${SRCS}")

# 移除元素
list(REMOVE_ITEM SRCS "math.cpp")
message(STATUS "remove: ${SRCS}")

# 排序
list(SORT SRCS)
message(STATUS "sort: ${SRCS}")

# 遍历列表
foreach(file ${SRCS})
    message(STATUS "file: ${file}")
endforeach()

# 求长度
list(LENGTH SRCS LEN)
message(STATUS "len: ${LEN}")
```

```shell
[wind@Ubuntu test_list]$ mkdir build && cd build
[wind@Ubuntu build]$ cmake ..
cmake: /usr/local/lib/libcurl.so.4: no version information available (required by cmake)
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
-- add: main.cpp;utils.cpp;math.cpp;network.cpp
-- remove: main.cpp;utils.cpp;network.cpp
-- sort: main.cpp;network.cpp;utils.cpp
-- file: main.cpp
-- file: network.cpp
-- file: utils.cpp
-- len: 3
-- Configuring done (0.8s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_list/build
[wind@Ubuntu build]$ 
```

----

接下来我们介绍函数. `cmake`的函数和C++函数差不了太多, 所以下面我们就主要介绍一下`cmake`函数和C++函数不同的地方.

首先, 在`cmake`的函数内, 会自动生成一组和参数有关的特殊变量

- ARGC       :   实参个数
- ARGV       :   由所有实参构成的项列表
- ARGV<n\>:  从零开始的第n个实参项
- ARGN       :  除去形参部分还剩下的实参列表

在`cmake`中, 函数的实参和形参在数量上可以不同, 因此形参和实参的分别更加明显. 在定义实参时, 你可以给它定义两个形参, 但实际调用时, 可以给他传递两个, 三个, 四个, 五个... 实参. 这样的话, 实参列表中的第三个, 第四个, 第五个项...就成为了剩余实参.

```shell
[wind@Ubuntu test_func]$ tree .
.
└── CMakeLists.txt

1 directory, 1 file
[wind@Ubuntu test_func]$
```

 ```cmake
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
 ```

```shell
[wind@Ubuntu test_func]$ mkdir build && cd build
[wind@Ubuntu build]$ cmake ..
cmake: /usr/local/lib/libcurl.so.4: no version information available (required by cmake)
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
-- ARGC: 5
-- ARGV: A;B;C;D;E
-- ARGV0: A
-- ARGV1: B
-- ARGV2: C
-- ARGV3: D
-- ARGV4: E
-- ARGN: C;D;E
-- Configuring done (0.8s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_func/build
[wind@Ubuntu build]$ 
```

与C/C++函数稍有不同的, `cmake`的函数在名义上是没有返回值的, 如果想要返回值, 无非通过两点

- 使用`PARENT_SCOPE`把返回值写到父级目录中
- 把返回值写到持久缓存里

```cmake
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
```

```shell
-- LOCAL_SUM: 
-- OUTPUT_SUM: 8
-- CACHE_SUM: 8
-- Configuring done (0.9s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/test_func/build
[wind@Ubuntu build]$ 
```

## 第五章

下面我们进入第五章, 这一章是对使用`cmake`构建的知名项目中的`cmake`代码进行分析.

首先是`jsoncpp`

我们使用下面的项目进行参考, 其中的`cmake`文件已被注释

```shell
git clone https://gitee.com/lizhengping189/jsoncpp.git
```

从中我们可以看到有七个`CMakeLists.txt`文件

```shell
[wind@Ubuntu jsoncpp]$ find -name "CMakeLists.txt"
./example/CMakeLists.txt
./src/jsontestrunner/CMakeLists.txt
./src/test_lib_json/CMakeLists.txt
./src/lib_json/CMakeLists.txt
./src/CMakeLists.txt
./include/CMakeLists.txt
./CMakeLists.txt
[wind@Ubuntu jsoncpp]$ 
```

第一个文件`./example/CMakeLists.txt`描述如何构建`jsoncpp`的演示代码, 第二个是`jsoncpp`的一个测试程序, 第三个也是测试程序, 第四个是最重要的, 描述动静态库链接的`CMakeLists.txt`, 第五个负责对源码进行编译, 第六个负责安装头文件, 第七个是顶层`CMakeLists.txt`.

接下来, 我们就来看看`cmake`提供的功能和函数是如何满足以下需求的

- 环境监测
- 针对不同编译器设置不同的编译选项
- 变量定义
- 功能开启选项
- 集成测试例子
- `cmake`版本兼容
- 导出到构建目录
- 导出到安装目录
- 安装头文件
- 安装pkg-config对应的pc配置文件
- 安装静态库和动态库
- 安装find_package的config模式配置文件

首先我们看环境监测.

在`cmake`的配置阶段, 它会依据当前主机, 所选生成器, 用户提供的工具链或环境变量, 对编译器, 平台, 库, 函数, 头文件等"环境信息"进行检测, 并把结果存入缓存变量, 随后, 所有的`CMakeLists.txt`文件都可以通过这些变量(或find_package/`cmake`模块)来做条件判断, 生成目标或添加编译选项.

比如, 相关的变量和设置有

- CMAKE_SYSTEM_NAME: 系统名, 比如Windows/Linux/Darwin(苹果内核)/Android
- CMAKE_SYSTEM_VERSION: 系统版本
- CMAKE_SYSTEM_PROCESSOR: CPU架构, 如x86_64, armv8
- CMAKE_HOST_SYSTEM_NAME: 配置机(host)的系统名
- CAMKE_CROSSCOMPILING: 布尔值, TRUE表示启用跨平台交叉编译

```shell
[wind@Ubuntu jsoncpp]$ mkdir build && cd build
[wind@Ubuntu build]$ cmake ..
cmake: /usr/local/lib/libcurl.so.4: no version information available (required by cmake)
-- The CXX compiler identification is Clang 18.1.3
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/clang++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- JsonCpp Version: 1.9.7
-- Looking for memset_s
-- Looking for memset_s - not found
-- Looking for C++ include clocale
-- Looking for C++ include clocale - found
-- Looking for localeconv
-- Looking for localeconv - found
-- Looking for C++ include sys/types.h
-- Looking for C++ include sys/types.h - found
-- Looking for C++ include stdint.h
-- Looking for C++ include stdint.h - found
-- Looking for C++ include stddef.h
-- Looking for C++ include stddef.h - found
-- Check size of lconv
-- Check size of lconv - done
-- Performing Test HAVE_DECIMAL_POINT
-- Performing Test HAVE_DECIMAL_POINT - Success
-- Found Python3: /usr/bin/python3 (found version "3.12.3") found components: Interpreter 
-- Configuring done (5.0s)
-- Generating done (0.1s)
-- Build files have been written to: /home/wind/jsoncpp/build
[wind@Ubuntu build]$ ls
bin             CMakeFiles           compile_commands.json  DartConfiguration.tcl  jsoncppConfig.cmake         lib       pkg-config  Testing
CMakeCache.txt  cmake_install.cmake  CTestTestfile.cmake    include                jsoncppConfigVersion.cmake  Makefile  src         version
[wind@Ubuntu build]$ 
```

我这台机器用的是`clang`, 默认情况下它会用`g++`, 但我在`~/.bashrc`指定它使用`clang`了.

我们看到它首先对使用的编译器进行了探测. 然后又进行了很多检查, 也就是中间的那堆`Looking for`.

在`./CMakeFiles/3.28.3/`下, 我们可以看到`cmake`的检查结果, 这里的`3.28.3`是`cmake`的版本

```shell
[wind@Ubuntu build]$ cd ./CMakeFiles/3.28.3/
[wind@Ubuntu 3.28.3]$ ls
CMakeCXXCompiler.cmake  CMakeDetermineCompilerABI_CXX.bin  CMakeSystem.cmake  CompilerIdCXX
[wind@Ubuntu 3.28.3]$ cmake --version
cmake: /usr/local/lib/libcurl.so.4: no version information available (required by cmake)
cmake version 3.28.3

CMake suite maintained and supported by Kitware (kitware.com/cmake).
[wind@Ubuntu 3.28.3]$ 
```

该目录下的`CMakeSystem.cmake`就描述了与平台体系相关的探测结果, `CMakeCXXCompiler.cmake `是和编译器相关的

![image-20250917123442297](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250917123442297.png)

除此之外, `cmake`为了适配各个平台下的生成器, 它自带了一堆`.rst`文件, 这些文件构成了`cmake`的生成器适配层, 可以将某个`cmake`指令翻译成对应的生成器指令, 是`cmake`得以跨平台的重要凭借

```shell
[wind@Ubuntu 3.28.3]$ ls /usr/share/cmake-*/Help/generator
'Borland Makefiles.rst'   Kate.rst                 'NMake Makefiles JOM.rst'    'Visual Studio 11 2012.rst'  'Visual Studio 17 2022.rst'      'Visual Studio 9 2008.rst'
 CodeBlocks.rst          'MinGW Makefiles.rst'     'NMake Makefiles.rst'        'Visual Studio 12 2013.rst'  'Visual Studio 6.rst'             VS_TOOLSET_HOST_ARCH_LEGACY.txt
 CodeLite.rst            'MSYS Makefiles.rst'      'Sublime Text 2.rst'         'Visual Studio 14 2015.rst'  'Visual Studio 7 .NET 2003.rst'   VS_TOOLSET_HOST_ARCH.txt
'Eclipse CDT4.rst'       'Ninja Multi-Config.rst'  'Unix Makefiles.rst'         'Visual Studio 15 2017.rst'  'Visual Studio 7.rst'            'Watcom WMake.rst'
'Green Hills MULTI.rst'   Ninja.rst                'Visual Studio 10 2010.rst'  'Visual Studio 16 2019.rst'  'Visual Studio 8 2005.rst'        Xcode.rst
[wind@Ubuntu 3.28.3]$ 
```

我们看到有正在被我们使用的`Makefile`, 有更高效率的`Ninja`, 还有一堆`Visual Studio`

`CMakeCXXCompiler.cmake`则描述了编译器探测结果, 

![image-20250918092226594](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250918092226594.png)

我们可以在项目中查询一个参数, 比如描述编译里类别的`CMAKE_CXX_COMPILER_ID`

![image-20250918092546609](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250918092546609.png)

之后我们就可以看到项目针对不同编译器所作出的适配

![image-20250918092800756](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250918092800756.png)

![image-20250918093529791](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250918093529791.png)

在项目配置阶段我们也能看到各种检查

```shell
-- Looking for memset_s
-- Looking for memset_s - not found
-- Looking for C++ include clocale
-- Looking for C++ include clocale - found
-- Looking for localeconv
-- Looking for localeconv - found
-- Looking for C++ include sys/types.h
-- Looking for C++ include sys/types.h - found
-- Looking for C++ include stdint.h
-- Looking for C++ include stdint.h - found
-- Looking for C++ include stddef.h
-- Looking for C++ include stddef.h - found
```

`memset_s`是一个内存初始化函数, 比`memset`更加安全, 各种意义上, 不过我们也可以看到, 本平台并不支持, 我们可以通过查询`check_function_exists`来搜索对应的`cmake`原码

```cmake
# 检查系统是否存在 memset_s 函数
include(CheckFunctionExists)
check_function_exists(memset_s HAVE_MEMSET_S)
# 若存在 memset_s 函数，则定义宏 HAVE_MEMSET_S
if(HAVE_MEMSET_S)
    add_definitions("-DHAVE_MEMSET_S=1")
endif()
```

 我们接着搜索宏定义`HAVE_MEMSET_S`, 就能看到这样的一个函数实现

```cpp
void deallocate(pointer p, size_type n) {
    // 这些操作在优化时不会被编译器移除，
    // unlike memset 意思是普通 memset 可能会被优化掉
#if defined(HAVE_MEMSET_S)
    memset_s(p, n * sizeof(T), 0, n * sizeof(T));
#elif defined(_WIN32)
    RtlSecureZeroMemory(p, n * sizeof(T));
#else
    std::fill_n(reinterpret_cast<volatile unsigned char*>(p), n, 0);
#endif

    // 使用全局 operator delete 释放内存
    ::operator delete(p);
}

```

这是一个C++经典的内存安全释放函数, 会先把内存快清零(保证不内存泄露地清零), 然后再释放, 防止直接释放带来的可能的内部敏感数据泄露. 在实际运行时, 因为我们没有定义宏`HAVE_MEMSET_S`, 也不是Windows, 因此最后会用C++标准的 `fill_n`.

还有检查头文件的

```cmake
# 检查是否存在 clocale 头文件
check_include_file_cxx(clocale HAVE_CLOCALE)
# 检查 clocale 头文件中是否存在 localeconv 符号
check_cxx_symbol_exists(localeconv clocale HAVE_LOCALECONV)
```

`clocale`涉及到对浮点数 / 数字的序列化处理, 所以`josncpp`需要特别检查

```cmake
# 若缺少必要的本地化功能支持
if(NOT (HAVE_CLOCALE AND HAVE_LCONV_SIZE AND HAVE_DECIMAL_POINT AND HAVE_LOCALECONV))
    # 输出警告信息
    message(WARNING "Locale functionality is not supported")
    if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.12.0)
        # 使用 CMake 3.12 及以上版本的新语法定义宏
        add_compile_definitions(JSONCPP_NO_LOCALE_SUPPORT)
    else()
        # 使用旧语法定义宏
        add_definitions(-DJSONCPP_NO_LOCALE_SUPPORT)
    endif()
endif()
```

还有`find_package`

```cmake
# 检查 CMake 版本是否大于等于 3.12.0
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.12.0)
    # CMake 3.12.0 及以上版本使用新的 Python3 模块，该模块比旧的 PythonInterp 更健壮
    find_package(Python3 COMPONENTS Interpreter)
    # 设置变量以兼容 CMake 版本小于 3.12.0 的情况
    set(PYTHONINTERP_FOUND ${Python3_Interpreter_FOUND})
    set(PYTHON_EXECUTABLE ${Python3_EXECUTABLE})
else()
    # 为旧版本 CMake 指定额外的 Python 版本，这里指定为 3.8
    set(Python_ADDITIONAL_VERSIONS 3.8)
    # 使用旧的 PythonInterp 模块查找 Python 3
    find_package(PythonInterp 3)
endif()
```

`josncpp`在功能上完全是C++实现的, 这里要Python可能只是测试或者代码演示需要

----------

接下来我们看看`jsoncpp`在`cmake`中如何定义和使用变量.

在此之前, 我们先回顾一下`cmake`中的和变量相关的知识

```cmake
# Set Normal Variable 一般变量
set(<variable> <value>... [PARENT_SCOPE])

# Set Cache Entry 缓存条目
set(<variable> <value>... CACHE <type> <docstring> [FORCE])

# Set Environment Variable 环境变量
set(ENV{<variable>} [<value>])
```

尽管`Cache Entry`有所谓"类型"的说法, 但是, 在`cmake`, 所有的变量, 在底层其实都是字符串, 只不过它们被真正使用时有着不同的解释方法, 从而有了类型这个概念.

对于变量来说, 在`if`中, 将默认为真, 除非变量不存在或者变量的值是假常量, 显式字符串则与之正好相反, 默认都为假, 除非字符串字面量为真常量.

如果我们搜索`set(`, 就能在`josncpp`中发现不少的变量定义

![image-20250918113323573](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250918113323573.png)

搜索`CACHE`就能找到缓存变量定义

![image-20250918113653581](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250918113653581.png)

当我们的变量以特定格式(以空格' '或分号分隔';')赋值时, 这个变量就会被解释为列表

```cmake
set(srcs a.c b.c c.c) # sets "srcs" to "a.c;b.c;c.c"
```

在`example/CMakeLists.txt`中, 我们就看到了列表的应用

```cmake
set(EXAMPLES
    readFromString
    readFromStream
    stringWrite
    streamWrite
)

# 遍历示例程序列表，为每个示例创建可执行文件
foreach(example ${EXAMPLES})
    # 创建可执行文件，源文件为对应子目录下的同名 .cpp 文件
    add_executable(${example} ${example}/${example}.cpp)
    # 为可执行文件添加公共包含目录，指向项目的 include 目录
    target_include_directories(${example} PUBLIC ${CMAKE_SOURCE_DIR}/include)
    # 将可执行文件与 jsoncpp_lib 库进行链接
    target_link_libraries(${example} jsoncpp_lib)
endforeach()
```

我们看到, 它以循环+列表的形式, 进行了批量化的示例程序目标添加

对于环境变量, 源码目录下到没有, 只有构建目录中存在

```shell
[wind@Ubuntu jsoncpp]$ grep 'ENV' build -rn
build/src/lib_json/cmake_install.cmake:47:      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libjsoncpp.so.1.9.7"
build/src/lib_json/cmake_install.cmake:48:      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libjsoncpp.so.27"
build/src/lib_json/cmake_install.cmake:62:      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libjsoncpp.so.1.9.7"
build/src/lib_json/cmake_install.cmake:63:      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libjsoncpp.so.27"
build/CMakeFiles/3.28.3/CMakeCXXCompiler.cmake:37:set(CMAKE_CXX_COMPILER_ENV_VAR "CXX")
build/cmake_install.cmake:50:  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/jsoncpp/jsoncpp-targets.cmake")
build/cmake_install.cmake:52:         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/jsoncpp/jsoncpp-targets.cmake"
build/cmake_install.cmake:55:      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/jsoncpp/jsoncpp-targets-*.cmake")
build/cmake_install.cmake:58:        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/jsoncpp/jsoncpp-targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
[wind@Ubuntu jsoncpp]$ 
```

------

接下来我们介绍在`cmake`项目中如何定义并使用"功能开关". 功能开关其实就是`cmake`中一些与项目功能有关的布尔变量, 不过因为经常被使用, 所以分化出了特定的接口.

`cmake`使用`option`这个接口, 供我们定义"功能开关", 由于这种功能性的开关是要跨构建次数的持久存在的, 所以它们都是被放进持久缓存的.

```cmake
option(<variable> "<help_text>" [value])
```

如果该变量之前并未设置(持久缓存或一般变量), 则将该变量设置进持久缓存, 在这种情况下, 如果`value`未提供, 将被缺省为`OFF`, 否则(在之前已有定义), 则该函数不进行任何操作.

当然你也可以不使用`option`, `set(<variable> [value] BOOL "" FORCE)`(FORCE表示强制更新, 之前存在同名缓存变量则覆写), 甚至是`-Dvariable=value`(这个也是强制刷新)

在`code`中搜索`option`字段, 就会发现`jsoncpp`定义了很多"功能开关"

![image-20250919083811150](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250919083811150.png)

项目配置阶段完成后, 我们亦能在`build/CMakeCache.txt`找到这些缓存变量

![image-20250919084238265](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250919084238265.png)

使用的时候就借助于`if`进行判断

![image-20250919084634104](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250919084634104.png)

![image-20250919085108420](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250919085108420.png)

-----

接下来我们看看`jsoncpp`的集成测试.

首先, 在顶层`CMakeLists.txt`中定义了`JSONCPP_WITH_TESTS`功能开关, 并设置成开启

```cmake
# 编译并（针对 jsoncpp_check）运行 JsonCpp 测试可执行文件的选项
option(JSONCPP_WITH_TESTS "Compile and (for jsoncpp_check) run JsonCpp test executables" ON)
```

同时, 顶层文件中也使用该功能开关判断是否启用测试模块

```cmake
# 若启用了编译并运行测试的选项
if(JSONCPP_WITH_TESTS)
    # 启用测试功能
    enable_testing()
    include(CTest)
endif()
```

而在`src`目录下, 也会对该功能开关进行检查, 如果开启, 则将添加两个测试子目录

```cmake
# 添加 lib_json 子目录到构建过程中
# 这会执行 lib_json 目录下的 CMakeLists.txt 文件，构建该目录下的代码
add_subdirectory(lib_json)

# 检查是否启用了编译并运行测试的选项
if(JSONCPP_WITH_TESTS)
    # 若启用了测试选项，添加 jsontestrunner 子目录到构建过程中
    # 这会执行 jsontestrunner 目录下的 CMakeLists.txt 文件，构建测试运行器相关代码
    add_subdirectory(jsontestrunner)
    # 添加 test_lib_json 子目录到构建过程中
    # 这会执行 test_lib_json 目录下的 CMakeLists.txt 文件，构建针对 lib_json 的测试代码
    add_subdirectory(test_lib_json)
endif()

```

其中, `jsontestrunner`是一个黑箱测试, 它将读取`json`文件到内存当中, 进行序列化和反序列化操作, 并判断是否符合预期;  `test_lib_json`则是后来新加的白箱测试, 主要是对`jsoncpp`中的`API`进行针对测试. 我们主要看`test_lib_json`

在`test_lib_json`中, 则定义了具体的测试内容

![image-20250919093100885](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250919093100885.png)

在末尾, 我们可以看到一个常见的有关测试的做法, 那就是构建完成后自动测试, 而不需要进行手动测试

```cmake
# 在构建后运行单元测试
# （默认的 CMake 工作流程会将测试结果隐藏在文件中，导致开发体验不佳）
if(JSONCPP_WITH_POST_BUILD_UNITTEST)
    # 为 jsoncpp_test 目标添加一个构建后命令
    add_custom_command(TARGET jsoncpp_test
        POST_BUILD
        # 构建后执行的命令为使用交叉编译模拟器（若有）运行 jsoncpp_test 可执行文件
        COMMAND ${CMAKE_CROSSCOMPILING_EMULATOR} $<TARGET_FILE:jsoncpp_test>
    )
endif()

```

它依据功能开关`JSONCPP_WITH_POST_BUILD_UNITTEST`, 决定是否在目标`jsoncpp_test`(也就是它自己)构建完成后, 自动进行测试, `${CMAKE_CROSSCOMPILING_EMULATOR}`和交叉编译有关, `$<TARGET_FILE:jsoncpp_test>`则是一个生成器表达式, 描述了测试程序的位置, 

```shell
[wind@Ubuntu build]$ cmake --build .
[  5%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_reader.cpp.o
[ 11%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_value.cpp.o
[ 17%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_writer.cpp.o
[ 23%] Linking CXX shared library ../../lib/libjsoncpp.so
[ 23%] Built target jsoncpp_lib
[ 29%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_static.dir/json_reader.cpp.o
[ 35%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_static.dir/json_value.cpp.o
[ 41%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_static.dir/json_writer.cpp.o
[ 47%] Linking CXX static library ../../lib/libjsoncpp.a
[ 47%] Built target jsoncpp_static
[ 52%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_object.dir/json_reader.cpp.o
[ 58%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_object.dir/json_value.cpp.o
[ 64%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_object.dir/json_writer.cpp.o
[ 64%] Built target jsoncpp_object
[ 70%] Building CXX object src/jsontestrunner/CMakeFiles/jsontestrunner_exe.dir/main.cpp.o
[ 76%] Linking CXX executable ../../bin/jsontestrunner_exe
[ 76%] Built target jsontestrunner_exe
[ 82%] Building CXX object src/test_lib_json/CMakeFiles/jsoncpp_test.dir/jsontest.cpp.o
[ 88%] Building CXX object src/test_lib_json/CMakeFiles/jsoncpp_test.dir/fuzz.cpp.o
[ 94%] Building CXX object src/test_lib_json/CMakeFiles/jsoncpp_test.dir/main.cpp.o
[100%] Linking CXX executable ../../bin/jsoncpp_test
Testing ValueTest/checkNormalizeFloatingPointStr: OK
Testing ValueTest/memberCount: OK
Testing ValueTest/objects: OK
Testing ValueTest/arrays: OK
Testing ValueTest/resizeArray: OK
Testing ValueTest/resizePopulatesAllMissingElements: OK
Testing ValueTest/getArrayValue: OK
Testing ValueTest/arrayIssue252: OK
Testing ValueTest/arrayInsertAtRandomIndex: OK
Testing ValueTest/null: OK
Testing ValueTest/strings: OK
Testing ValueTest/bools: OK
Testing ValueTest/integers: OK
Testing ValueTest/nonIntegers: OK
Testing ValueTest/compareNull: OK
Testing ValueTest/compareInt: OK
Testing ValueTest/compareUInt: OK
Testing ValueTest/compareDouble: OK
Testing ValueTest/compareString: OK
Testing ValueTest/compareBoolean: OK
Testing ValueTest/compareArray: OK
Testing ValueTest/compareObject: OK
Testing ValueTest/compareType: OK
Testing ValueTest/CopyObject: OK
Testing ValueTest/typeChecksThrowExceptions: OK
Testing ValueTest/offsetAccessors: OK
Testing ValueTest/StaticString: OK
Testing ValueTest/WideString: OK
Testing ValueTest/CommentBefore: OK
Testing ValueTest/zeroes: OK
Testing ValueTest/zeroesInKeys: OK
Testing ValueTest/specialFloats: OK
Testing ValueTest/precision: OK
Testing ValueTest/searchValueByPath: OK
Testing FastWriterTest/dropNullPlaceholders: OK
Testing FastWriterTest/enableYAMLCompatibility: OK
Testing FastWriterTest/omitEndingLineFeed: OK
Testing FastWriterTest/writeNumericValue: OK
Testing FastWriterTest/writeArrays: OK
Testing FastWriterTest/writeNestedObjects: OK
Testing StyledWriterTest/writeNumericValue: OK
Testing StyledWriterTest/writeArrays: OK
Testing StyledWriterTest/writeNestedObjects: OK
Testing StyledWriterTest/multiLineArray: OK
Testing StyledWriterTest/writeValueWithComment: OK
Testing StyledStreamWriterTest/writeNumericValue: OK
Testing StyledStreamWriterTest/writeArrays: OK
Testing StyledStreamWriterTest/writeNestedObjects: OK
Testing StyledStreamWriterTest/multiLineArray: OK
Testing StyledStreamWriterTest/writeValueWithComment: OK
Testing StreamWriterTest/writeNumericValue: OK
Testing StreamWriterTest/writeArrays: OK
Testing StreamWriterTest/writeNestedObjects: OK
Testing StreamWriterTest/multiLineArray: OK
Testing StreamWriterTest/dropNullPlaceholders: OK
Testing StreamWriterTest/enableYAMLCompatibility: OK
Testing StreamWriterTest/indentation: OK
Testing StreamWriterTest/writeZeroes: OK
Testing StreamWriterTest/unicode: OK
Testing StreamWriterTest/escapeControlCharacters: OK
Testing ReaderTest/parseWithNoErrors: OK
Testing ReaderTest/parseObject: OK
Testing ReaderTest/parseArray: OK
Testing ReaderTest/parseString: OK
Testing ReaderTest/parseComment: OK
Testing ReaderTest/streamParseWithNoErrors: OK
Testing ReaderTest/parseWithNoErrorsTestingOffsets: OK
Testing ReaderTest/parseWithOneError: OK
Testing ReaderTest/parseSpecialFloat: OK
Testing ReaderTest/strictModeParseNumber: OK
Testing ReaderTest/parseChineseWithOneError: OK
Testing ReaderTest/parseWithDetailError: OK
Testing ReaderTest/pushErrorTest: OK
Testing ReaderTest/allowNumericKeysTest: OK
Testing CharReaderTest/parseWithNoErrors: OK
Testing CharReaderTest/parseWithNoErrorsTestingOffsets: OK
Testing CharReaderTest/parseNumber: OK
Testing CharReaderTest/parseString: OK
Testing CharReaderTest/parseComment: OK
Testing CharReaderTest/parseObjectWithErrors: OK
Testing CharReaderTest/parseArrayWithErrors: OK
Testing CharReaderTest/parseWithOneError: OK
Testing CharReaderTest/parseChineseWithOneError: OK
Testing CharReaderTest/parseWithDetailError: OK
Testing CharReaderTest/parseWithStackLimit: OK
Testing CharReaderTest/testOperator: OK
Testing CharReaderStrictModeTest/dupKeys: OK
Testing CharReaderFailIfExtraTest/issue164: OK
Testing CharReaderFailIfExtraTest/issue107: OK
Testing CharReaderFailIfExtraTest/commentAfterObject: OK
Testing CharReaderFailIfExtraTest/commentAfterArray: OK
Testing CharReaderFailIfExtraTest/commentAfterBool: OK
Testing CharReaderFailIfExtraTest/parseComment: OK
Testing CharReaderAllowDropNullTest/issue178: OK
Testing CharReaderAllowNumericKeysTest/allowNumericKeys: OK
Testing CharReaderAllowSingleQuotesTest/issue182: OK
Testing CharReaderAllowZeroesTest/issue176: OK
Testing CharReaderAllowSpecialFloatsTest/specialFloat: OK
Testing CharReaderAllowSpecialFloatsTest/issue209: OK
Testing EscapeSequenceTest/readerParseEscapeSequence: OK
Testing EscapeSequenceTest/charReaderParseEscapeSequence: OK
Testing EscapeSequenceTest/writeEscapeSequence: OK
Testing BuilderTest/settings: OK
Testing BomTest/skipBom: OK
Testing BomTest/notSkipBom: OK
Testing IteratorTest/convert: OK
Testing IteratorTest/decrement: OK
Testing IteratorTest/reverseIterator: OK
Testing IteratorTest/distance: OK
Testing IteratorTest/nullValues: OK
Testing IteratorTest/staticStringKey: OK
Testing IteratorTest/names: OK
Testing IteratorTest/indexes: OK
Testing IteratorTest/constness: OK
Testing RValueTest/moveConstruction: OK
Testing FuzzTest/fuzzDoesntCrash: OK
Testing ParseWithStructuredErrorsTest/success: OK
Testing ParseWithStructuredErrorsTest/singleError: OK
Testing MemberTemplateAs/BehavesSameAsNamedAs: OK
Testing MemberTemplateIs/BehavesSameAsNamedIs: OK
Testing VersionTest/VersionNumbersMatch: OK
All 121 tests passed
[100%] Built target jsoncpp_test
[wind@Ubuntu build]$ ctest
Test project /home/wind/jsoncpp/build
    Start 1: jsoncpp_readerwriter
1/3 Test #1: jsoncpp_readerwriter ................   Passed    2.07 sec
    Start 2: jsoncpp_readerwriter_json_checker
2/3 Test #2: jsoncpp_readerwriter_json_checker ...   Passed    2.70 sec
    Start 3: jsoncpp_test
3/3 Test #3: jsoncpp_test ........................   Passed    0.01 sec

100% tests passed, 0 tests failed out of 3

Total Test time (real) =   4.79 sec
[wind@Ubuntu build]$ 
```

我们看到, 在`Linking CXX executable ../../bin/jsoncpp_test`, 就自动进行测试, 当然你也可以手动测试, 但测试信息没有自动测试更详细.

------

接下来我们以`jsoncpp`为例, 演示, `cmake`包管理的一些细节. 

在`cmake`中, 有一个`pkg-config`模块, 他会将使用`cmake --install .`安装的库的安装信息, 以编译器选项的形式直观明了地提供给用户. 我们之前说的, `CMake Config`(比如`jsoncppConfig.cmake jsoncpp-targets.cmake jsoncpp-namespaced-targets.cmake jsoncpp-targets-release.cmake`), 则关注与基于`cmake`自身的封装接口.

又或者这样说, `pkg-config`的工作场景是极简环境下的项目构建, 极简到只有编译器和底层生成器甚至都没有生成器只有编译器的场景, 它的特点是极简, 轻量化, 不依赖`cmake`这个工具, 是用来"外循环"用的, 而`CMake Config`则要基于`cmake`工具, 它为使用`cmake`安装库的封装接口, 和用`cmake`会用上述那些库的项目, 提供一个标准的, 统一的封装接口, 是用来"内循环"的.

在我们安装`jsoncpp`后, 会发现, 它给我们安装了一个`.pc`文件, 这里面就存储着`jsoncpp`的库信息, 并以编译选项的形式直接呈现在我们眼前, 由于它的轻便简短, 又是我们也把`.pc`叫做库的明信片.

```shell
[wind@Ubuntu build]$ sudo cmake --install .
[sudo] password for wind: 
-- Install configuration: "Release"
-- Installing: /usr/local/lib/pkgconfig/jsoncpp.pc
-- Installing: /usr/local/lib/cmake/jsoncpp/jsoncpp-targets.cmake
-- Installing: /usr/local/lib/cmake/jsoncpp/jsoncpp-targets-release.cmake
-- Installing: /usr/local/lib/cmake/jsoncpp/jsoncppConfigVersion.cmake
-- Installing: /usr/local/lib/cmake/jsoncpp/jsoncppConfig.cmake
-- Installing: /usr/local/lib/cmake/jsoncpp/jsoncpp-namespaced-targets.cmake
-- Installing: /usr/local/lib/libjsoncpp.so.1.9.7
-- Up-to-date: /usr/local/lib/libjsoncpp.so.27
-- Up-to-date: /usr/local/lib/libjsoncpp.so
-- Installing: /usr/local/lib/libjsoncpp.a
-- Installing: /usr/local/lib/objects-Release/jsoncpp_object/json_reader.cpp.o
-- Installing: /usr/local/lib/objects-Release/jsoncpp_object/json_value.cpp.o
-- Installing: /usr/local/lib/objects-Release/jsoncpp_object/json_writer.cpp.o
-- Installing: /usr/local/include/json/allocator.h
-- Installing: /usr/local/include/json/assertions.h
-- Installing: /usr/local/include/json/config.h
-- Installing: /usr/local/include/json/forwards.h
-- Installing: /usr/local/include/json/json.h
-- Installing: /usr/local/include/json/json_features.h
-- Installing: /usr/local/include/json/reader.h
-- Installing: /usr/local/include/json/value.h
-- Installing: /usr/local/include/json/version.h
-- Installing: /usr/local/include/json/writer.h
[wind@Ubuntu build]$ 
```

那接下来我们就看一下这`jsoncpp.pc`写了什么

```pc
prefix=/usr/local
exec_prefix=/usr/local
libdir=${exec_prefix}/lib
includedir=${prefix}/include

Name: jsoncpp
Description: A C++ library for interacting with JSON
Version: 1.9.7
URL: https://github.com/open-source-parsers/jsoncpp
Libs: -L${libdir} -ljsoncpp
Cflags: -I${includedir}

```

我们看到非常简短, 不过它并不是直接提供了编译器选项, 毕竟各个平台可能有各自的不同, 所以提供的事类似于模版的东西, 如果要使用它, 可以把这个文件交给`pkg-config`这个命令行工具来解析, 获得具体的编译选项.

```shell
[wind@Ubuntu build]$ pkg-config --cflags --libs jsoncpp
-I/usr/local/include -L/usr/local/lib -ljsoncpp 
```

`--cflags`是要求解析出头文件包含选项, `--libs`是要求解析出库文件链接选项, 这样的话, 我们就可以直接用编译器以命令行形式一步到位.

接下来, 我们拷贝之前的`find_jsoncpp_config`来进行演示

```shell
[wind@Ubuntu pkg_config_json]$ pkg-config --cflags --libs jsoncpp
-I/usr/local/include -L/usr/local/lib -ljsoncpp 
[wind@Ubuntu pkg_config_json]$ clang++ main.cpp -std=c++11 -I/usr/local/include -L/usr/local/lib -ljsoncpp -o main
[wind@Ubuntu pkg_config_json]$ ./main
root: 
{
        "age" : 18,
        "name" : "whisper"
}
[wind@Ubuntu pkg_config_json]$ 
```

注意要使用C++11, 之前我们说过的, 有版本兼容问题. 当然你用`g++`也是可以的

还有一种一步到位的写法

```shell
[wind@Ubuntu pkg_config_json]$ rm main
[wind@Ubuntu pkg_config_json]$ g++ main.cpp -std=c++11 $(pkg-config --cflags --libs jsoncpp) -o main
[wind@Ubuntu pkg_config_json]$ ./main
root: 
{
        "age" : 18,
        "name" : "whisper"
}
[wind@Ubuntu pkg_config_json]$ 
```

又或者, 我们也可以用`cmake`脚本来使用它

```cmake
cmake_minimum_required(VERSION 3.18)

project(pkg_confif_json LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. 引入 cmake 中的PkgConfig模块
find_package(PkgConfig REQUIRED)

# 2. 让 pkg-config 搜索 jsoncpp.pc，并⽣成 IMPORTED 目标
#    - JSONCPP     : 这是前缀，用来生成一系列变量 (JSONCPP_INCLUDE_DIRS、…)
#    - REQUIRED    : 找不到就报错并停止配置
#    - IMPORTED_TARGET : 额外创建 PkgConfig::JSONCPP 目标（推荐用法）
pkg_check_modules(JSONCPP REQUIRED IMPORTED_TARGET jsoncpp)

# 3. 添加你的可执行文件 / 库
add_executable(main main.cpp)

# 4. 通过导入目标 PkgConfig::JSONCPP，把所有使用需求一次性传播进来
target_link_libraries(main PRIVATE PkgConfig::JSONCPP)

# 可选：查看自动填充的属性（调试用）
# 读取 PkgConfig::JSONCPP 头文件路径 INTERFACE_INCLUDE_DIRECTORIES
get_target_property(_incs PkgConfig::JSONCPP INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "jsoncpp include dirs = ${_incs}")
```

```shell
[wind@Ubuntu pkg_config_json]$ mkdir build && cd build
[wind@Ubuntu build]$ cmake ..
-- The CXX compiler identification is Clang 18.1.3
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/clang++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found PkgConfig: /usr/bin/pkg-config (found version "1.8.1") 
-- Checking for module 'jsoncpp'
--   Found jsoncpp, version 1.9.7
-- jsoncpp include dirs = /usr/local/include
-- Configuring done (1.1s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wind/cmakeClass/pkg_config_json/build
[wind@Ubuntu build]$ cmake --build .
[ 50%] Building CXX object CMakeFiles/main.dir/main.cpp.o
[100%] Linking CXX executable main
[100%] Built target main
[wind@Ubuntu build]$ ./main
root: 
{
        "age" : 18,
        "name" : "whisper"
}
[wind@Ubuntu build]$ 
```



# 完
