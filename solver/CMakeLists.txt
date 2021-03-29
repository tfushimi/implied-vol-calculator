add_library(solver INTERFACE include/Bisection.hpp include/NewtonRaphson.hpp)

target_include_directories(solver INTERFACE include)