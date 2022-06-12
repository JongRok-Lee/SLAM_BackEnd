# CMake environment for SLAM BackEnd
> OpenCV, Eigen3, Pangolin built in

# Cmake folder hierarchy
## Top-level CMakeLists
```
cmake_minimum_required(VERSION 3.22)
project(SLAM LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(module)
add_compile_definitions(PROJECT_DIR="${CMAKE_SOURCE_DIR}")

add_executable(main examples/W15D3.cpp)

target_link_libraries(main PRIVATE module)
```
## Module CMakeLists
```
cmake_minimum_required(VERSION 3.22)
project(module LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MODULE_SOURCE_FILES src/module.cpp)

add_library(module ${MODULE_SOURCE_FILES})
 
find_package(OpenCV REQUIRED HINTS ${CMAKE_SOURCE_DIR}/thirdparty/OpenCV/install/lib/cmake/opencv4)
find_package(Eigen3 REQUIRED HINTS ${CMAKE_SOURCE_DIR}/thirdparty/Eigen3/install/share/eigen3/cmake)
find_package(Pangolin REQUIRED HINTS ${CMAKE_SOURCE_DIR}/thirdparty/Pangolin/install/lib/cmake/Pangolin)

set(Eigen3_LIBS Eigen3::Eigen)
set(PANGOLIN_LIBS ${Pangolin_LIBRARIES})

target_include_directories(module PUBLIC
                            include
                            ${OpenCV_INCLUDE_DIRS}
                            ${Eigen3_INCLUDE_DIRS}
                            ${Pangolin_INCLUDE_DIRS}
                            )

target_link_libraries(module PUBLIC
                        ${OpenCV_LIBS}
                        ${Eigen3_LIBS}
                        ${PANGOLIN_LIBS})
```
# 3rd party libraries
## OpenCV build
```
$ cd thirdparty/OpenCV && git clone https://github.com/opencv/opencv.git
$ cd ../build && cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=../install ../opencv
$ make -j
$ sudo make install

```

## Eigen3 build
```
$ cd thirdparty/OpenCV && git clone https://gitlab.com/libeigen/eigen.git
$ cd ../build && cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=../install ../eigen
$ make -j
$ sudo make install

```

## Pangolin build
```
$ cd thirdparty/OpenCV && git clone https://github.com/stevenlovegrove/Pangolin.git
$ cd ../build && cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=../install ../Pangolin
$ make -j
$ sudo make install

```


# Build error Case
## Pangolin's `.so` file load fail
`error while loading shared libraries: libpango_windowing.so: cannot open shared object file: No such file or directory`

> ### Soltion
> 
> Add path `thiredparty/Pangolin/install/lib` to system default path.
> 
> `$ cd /etc/ld.so.conf.d`
> 
> `$ sudo gedit SLAM.conf`
> 
> Add path `PERSONAL_PATH/thiredparty/Pangolin/install/lib`
>
> `$ sudo ldconfig`