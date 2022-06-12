cmake_minimum_required(VERSION 3.22)
project(module LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MODULE_SOURCE_FILES1 src/module.cpp)
set(MODULE_SOURCE_FILES2 src/bal_problem.cpp)

add_library(module ${MODULE_SOURCE_FILES1})
add_library(bal_problem ${MODULE_SOURCE_FILES2})
 
find_package(Eigen3 REQUIRED HINTS ${CMAKE_SOURCE_DIR}/thirdparty/eigen/install/share/eigen3/cmake)
find_package(Ceres REQUIRED HINTS ${CMAKE_SOURCE_DIR}/thirdparty/ceres/install/lib/cmake/Ceres)

set(Eigen3_LIBS Eigen3::Eigen)
set(CERES_LIBS ${CERES_LIBRARIES})

set(Eigen3_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/thirdparty/eigen/install/include)
set(CERES_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/thirdparty/g2o/install/include)

# Path validation
message("Eigen3_LIBS            - ${Eigen3_LIBS}")
message("Eigen3_INCLUDE_DIRS    - ${Eigen3_INCLUDE_DIRS}")
message("CERES_LIBS             - ${CERES_LIBRARIES}")
message("CERES_INCLUDE_DIRS     - ${CERES_INCLUDE_DIRS}")


target_include_directories(module PUBLIC
                            include
                            # ${OpenCV_INCLUDE_DIRS}
                            ${Eigen3_INCLUDE_DIRS}
                            ${CERES_INCLUDE_DIRS}
                            # ${Pangolin_INCLUDE_DIRS}
                            )

target_link_libraries(module PUBLIC
                        # ${OpenCV_LIBS}
                        ${Eigen3_LIBS}
                        ${CERES_LIBS}
                        # ${PANGOLIN_LIBS}
                        )

target_include_directories(bal_problem PUBLIC
                        include
                        # ${OpenCV_INCLUDE_DIRS}
                        ${Eigen3_INCLUDE_DIRS}
                        ${CERES_INCLUDE_DIRS}
                        # ${Pangolin_INCLUDE_DIRS}
                        )

target_link_libraries(bal_problem PUBLIC
                    # ${OpenCV_LIBS}
                    ${Eigen3_LIBS}
                    ${CERES_LIBS}
                    # ${PANGOLIN_LIBS}
                    )