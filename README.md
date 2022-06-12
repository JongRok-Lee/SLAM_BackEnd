# CMake environment for SLAM BackEnd
> Ceres, Eigen3 built in

# 3rd party libraries
```
$ mkdir thirdparty && cd thirdparty
$ mkdir eigen && cd eigen
$ mkdir build && mkdir install

$ cd ..
$ mkdir ceres && cd ceres
$ mkdir build && mkdir install
```
## Eigen3 build
```
$ cd thirdparty/eigen && wget https://gitlab.com/libeigen/eigen/-/archive/3.3.9/eigen-3.3.9.tar.gz -O eigen.tar.gz
$ tar -zxvf eigen.tar.gz
$ cd ../build && cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=../install ../eigen-3.3.9
$ make -j
$ sudo make install

```

## Ceres build
```
$ cd thirdparty/ceres && wget http://ceres-solver.org/ceres-solver-2.1.0.tar.gz -O ceres.tar.gz
$ tar -zxvf ceres.tar.gz
$ cd ../build && cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=../install ../ceres-solver-2.1.0
```
### Change the Eigen directory to my Eigen of thridparty 
```
find_package(Eigen3 3.3 REQUIRED)
----->

find_package(Eigen3 3.3 REQUIRED HINTS /your_directory/SLAM_BackEnd/thirdparty/eigen/install/share/eigen3/cmake)
```
```
$ make -j7
$ sudo make install
```

# Run BA
## Simple BA
```
$ cd build
$ simpleBA ../sources/problem-16-22106-pre.txt
```
## BA
```
$ cd build
$ BA --input=../sources/problem-16-22106-pre.txt
```