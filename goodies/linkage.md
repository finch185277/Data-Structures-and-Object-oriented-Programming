# linkage

Linking library is a mess in c++. The order of the linking can make you like in hell.

No worries! There are some tips you can save your time!

# Basic -- what is linking

Linking is combining some already compiled code(`libraries`) into the file you are compiling with.
There are 2 kinds of library, static ones and dynamic ones. 
[Here from Geeks from Geeks](https://www.geeksforgeeks.org/static-vs-dynamic-libraries/) shows how to turn object files into a static library.

# Importent Compiler flags
In clang and gcc
```
-Ldir // means add "dir" to "library search path"
-lxxx // first, expand "xxx" into "libxxx.a" or "libxxx.so" or "libxxx.dylib".
         Next, search "library search path" and try to find this file.
-static // you can tell the compiler to use static library, or the compiler will choose for you.
```
For example, I want to link `libboost_system.a` in my code, I can write
```
clang++ -I${BOOST_PATH/include} -L${BOOST_PATH/lib} -static main.cpp -lboost_system
```

The *most inportant* thing here is that you specify your library *AFTER* your `main.cpp`. Why? this is because the linker will
start linking from the tail of the library list, towarding the front. 

For example, you got to be careful about the dependancy between the library when you static linking.
```
clang++ -std=c++17 -static -o run main.cpp -lboost_timer
``` 

will *fail* because `boost_timer` depends on `boost_chrono` and `boost_system`. So,
```
clang++ -std=c++17 -static -o run main.cpp -lboost_timer -lboost_chrono -lboost_system
```
is the correct command to compile. You need to tell the linker before it encounter any functions that it didn't know.

# Automatic tools
There is some automatic tools that can save a lot of time correcting building process.
[conan](https://github.com/conan-io/conan) and [cmake](https://github.com/conan-io/conan) are pretty good tools.

First, create a file `conanfile.txt` and enter the dependencies of your project.
```
[requires]
Poco/1.9.0@pocoproject/stable

[generators]
cmake
```

Next, create another file `CMakeLists.txt`
```
cmake_minimum_required(VERSION 3.0.0)
project(pjname)

add_definitions("-std=c++17")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(pjname main.cpp)
target_link_libraries(pjname ${CONAN_LIBS})
```

Next run
```
conan profile new default --detect
mkdir build && cd build
conan install .. --build=missing
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
```
And you can see that `conan` and `cmake` automatically linked with those required libraries.
