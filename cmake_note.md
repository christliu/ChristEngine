## minimal

~~~cmake
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

PROJECT(demo1)

ADD_EXECUTABLE(demo1  main.cpp)
~~~



## Demo1

只有一个源文件，很简单如上minimal所示即可



## Demo2

将一个目录下所有的源文件编译链接。

* aux_source_directory(<dir> <variable>)

将dir目录下所有的source files名以variable变量代替。

~~~cmake
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

PROJECT(demo2)

AUX_SOURCE_DIRECTORY(./ DIR_SRCS)

ADD_EXECUTABLE(demo2  ${DIR_SRCS})
~~~



## Demo3

目录结构如下，mylib作为一个子目录，作为一个库链接到最终的可执行文件里。

~~~cpp
-- Demo3
--   |  -- CMakeLists.txt
--   |  -- main.cpp
--   |  -- mylib
--   |  --     | -- mymath.cpp
--   |  --     | -- mymath.hpp
--   |  --     | -- CMakeLists.txt
~~~

这种情况先写最里面的CMakeLists.txt

~~~cmake
aux_source_directory(. DIR_LIB_SRCS)

add_library(Mylib STATIC ${DIR_LIB_SRCS})
~~~

* ```
  add_library(<name> [STATIC | SHARED | MODULE]
              [EXCLUDE_FROM_ALL]
              [source1] [source2 ...])
  ```

意思是新目录里所有的源文件编译成Mylib这个静态库，如果想要编译成动态库，那么需要这样写

~~~cmake
add_library(Mylib SHARED ${DIR_LIB_SRCS})
~~~

再写最外面的

~~~cmake
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

PROJECT(demo3)

ADD_SUBDIRECTORY(./mylib)

AUX_SOURCE_DIRECTORY(./ DIR_SRCS)

ADD_EXECUTABLE(demo3  ${DIR_SRCS})

TARGET_LINK_LIBRARIES(demo3 Mylib)
~~~

* ```
  add_subdirectory(source_dir [binary_dir]
                   [EXCLUDE_FROM_ALL])
  ```

向cmake工程中添加子目录。

* ```
  target_link_libraries(<target> ... <item>... ...)
  ```

  target是由指令add_executable或者add_library创建出来的变量



## Demo4

Demo4的文件夹结构比Demo3更规范，将main.cpp放到一个专门的目录里去。

~~~cpp
-- Demo3
--   |  -- CMakeLists.txt
--   |  -- src
--   |  --     | -- main.cpp
--   |  --     | -- CMakeLists.txt
--   |  -- mylib
--   |  --     | -- mymath.cpp
--   |  --     | -- mymath.hpp
--   |  --     | -- CMakeLists.txt
~~~

main.cpp放到一个目录里，这个目录里也要写CMakeLists.txt

~~~cmake
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/mylib)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

AUX_SOURCE_DIRECTORY(./ DIR_SRCS)

ADD_EXECUTABLE(demo4 ${DIR_SRCS})

TARGET_LINK_LIBRARIES(demo4 Mylib)
~~~

* SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin) 这一行是为了规范化二进制的输出目录，也可以不写，不写的话最后生成的可执行文件会在build/src/ 这个目录下。

mylib下的CMakeLists.txt不用修改就可以使用，然而为了配合修改输出库的目录，可以修改为如下：

~~~cmake
AUX_SOURCE_DIRECTORY(. DIR_LIB_SRCS)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

ADD_LIBRARY(Mylib STATIC ${DIR_LIB_SRCS})
~~~

* SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib) 这一行可以将生成的Mylib.a放到build/lib目录下。PROJECT_BINARY_DIR 这个变量表示执行cmake命令的目录。

最后需要修改最顶层的CMakeLists.txt

~~~cmake
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

PROJECT(demo3)

ADD_SUBDIRECTORY(./mylib)

ADD_SUBDIRECTORY(./src)
~~~



## Demo5

cmake可以自定义编译宏。

指令ccmake可以查看和配置编译过程当中可以修改的宏定义。

具体参考https://github.com/AdamWSL/CMake_Tutorial/blob/master/demo5/