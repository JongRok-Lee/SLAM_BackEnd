cmake_minimum_required(VERSION 3.22)
project(SLAM LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(module)
add_compile_definitions(PROJECT_DIR="${CMAKE_SOURCE_DIR}")

# add_executable(basicEX examples/1_helloworld.cpp)
# target_link_libraries(basicEX PRIVATE module)

# add_executable(numericDiff examples/2_helloworld_numeric_diff.cpp)
# target_link_libraries(numericDiff PRIVATE module)

# add_executable(analyticDiff examples/3_helloworld_analytic_diff.cpp)
# target_link_libraries(analyticDiff PRIVATE module)

# add_executable(powell examples/4_powell.cpp)
# target_link_libraries(powell PRIVATE module)

# add_executable(CF examples/5_curve_fitting.cpp)
# target_link_libraries(CF PRIVATE module)

# add_executable(robustCF examples/6_robust_curve_fitting.cpp)
# target_link_libraries(robustCF PRIVATE module)

# add_executable(simpleBA examples/7_simple_BA.cpp)
# target_link_libraries(simpleBA PRIVATE module)

# add_executable(RosenBrock examples/8_rosenbrock.cpp)
# target_link_libraries(RosenBrock PRIVATE module)

# add_executable(Beale examples/9_beale.cpp)
# target_link_libraries(Beale PRIVATE module)

add_executable(BA examples/10_BA.cpp)
target_link_libraries(BA PRIVATE module bal_problem)