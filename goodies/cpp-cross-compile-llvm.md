# cpp-cross-compile-llvm

This is a note for how to cross compile from linux to windows using clang/llvm cross compiler.

# Background

The project targeting: https://github.com/hare1039/reverse-tunnel-cpp, depending on boost only.

Only `clang` can compile this project, so currently existing `gcc-mingw` toolchain will not help us.

Though `MSVC` do support cpp-coroutine, but it will have encounter many errors of no `co_await` in exceptions handlers.

Maybe that is another thing to write next...

# Setup
The docker image we need is this one: https://github.com/mstorsjo/llvm-mingw

You can directly pull the image from https://hub.docker.com/r/mstorsjo/llvm-mingw/

```
docker pull mstorsjo/llvm-mingw
```

Next, start the image, and mount project to `/work`: `docker run -it -v ${PWD}:/work mstorsjo/llvm-mingw bash`

Install tools such as `cmake` and `conan`.

Next, make a build folder and run `conan install .. --profile ../profiles/release` in there, and after conan 

create the default compiler set, you can directly Ctrl-C conan and add a new file (profile) called `clang` in `~/.conan/profiles/`

For example: 
```
[settings]
os=Windows
os_build=Linux
arch=x86
arch_build=x86_64
compiler=clang
compiler.version=8
compiler.libcxx=libc++
build_type=Release
[options]
[build_requires]
[env]
CC=i686-w64-mingw32-clang
CXX=i686-w64-mingw32-clang++
CONAN_CMAKE_FIND_ROOT_PATH=/opt/llvm-mingw/i686-w64-mingw32
AR=i686-w64-mingw32-ar
RANLIB=i686-w64-mingw32-ranlib
LD=i686-w64-mingw32-ld
STRIP=i686-w64-mingw32-strip
```

Next, we can start building our projects!

```
cd /work
mkdir build
cd build
conan install .. --profile ../profiles/release --build # this profile will automatic include profile 'clang'
                                                       # Please see boost notes below
cmake .. -DCMAKE_BUILD_TYPE=Release \
         -DCMAKE_C_COMPILER=i686-w64-mingw32-clang \
         -DCMAKE_CXX_COMPILER=i686-w64-mingw32-clang++ \
         -DCMAKE_SYSTEM_NAME=Windows \
         -DCMAKE_EXE_LINKER_FLAGS="-static"         
make VERBOSE=1
```

Why `VERBOSE=1`? Because it **WILL FAIL**

```
...
[ 50%] Linking CXX executable bin/reverse-tunnel.exe
/usr/bin/cmake -E cmake_link_script CMakeFiles/reverse-tunnel.dir/link.txt --verbose=1
/usr/bin/cmake -E remove -f CMakeFiles/reverse-tunnel.dir/objects.a
/opt/llvm-mingw/bin/i686-w64-mingw32-ar cr CMakeFiles/reverse-tunnel.dir/objects.a @CMakeFiles/reverse-tunnel.dir/objects1.rsp
/opt/llvm-mingw/bin/i686-w64-mingw32-clang++     -fcoroutines-ts -std=c++17 -O3 -DNDEBUG   -static     -Wl,--whole-archive CMakeFiles/reverse-tunnel.dir/objects.a -Wl,--no-whole-archive  -o bin/reverse-tunnel.exe -Wl,--out-implib,lib/libreverse-tunnel.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/reverse-tunnel.dir/linklibs.rsp
lld: error: unable to find library -llibboost_program_options
clang-8: error: linker command failed with exit code 1 (use -v to see invocation)
CMakeFiles/reverse-tunnel.dir/build.make:97: recipe for target 'bin/reverse-tunnel.exe' failed
make[2]: *** [bin/reverse-tunnel.exe] Error 1
make[2]: Leaving directory '/work/build'
CMakeFiles/Makefile2:67: recipe for target 'CMakeFiles/reverse-tunnel.dir/all' failed
make[1]: *** [CMakeFiles/reverse-tunnel.dir/all] Error 2
make[1]: Leaving directory '/work/build'
Makefile:83: recipe for target 'all' failed
make: *** [all] Error 2
```
Such like this.

The solution is open this file `CMakeFiles/reverse-tunnel.dir/linklibs.rsp`.

First remove the lib part of `-llibboost_program_options`, so it will become `-lboost_program_options`

and add two more library `-lwsock32 -lws2_32` behind `-lboost_program_options -lboost_system` and before `-lkernel32 ...`

So it will like this: `L/root/.conan/... -lboost_program_options -lboost_system -lwsock32 -lws2_32 -lkernel32 ...`

The library you need to add depends on your own project. This one depends on network, so it need socket support.

Save it, and do `make VERBOSE=1` again

This time it should work.


