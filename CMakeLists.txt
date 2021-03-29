cmake_minimum_required(VERSION 3.0.0)

project(ImpliedVolatility VERSION 1.0.0)

set (CMAKE_CXX_STANDARD 17)

find_package(Boost 1.75 REQUIRED)

add_subdirectory(bsmodel)
add_subdirectory(solver)

add_executable(impliedVolCalculator main.cpp)

target_link_libraries(impliedVolCalculator bsmodel solver)