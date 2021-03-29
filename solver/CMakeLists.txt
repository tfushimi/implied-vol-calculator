add_library(solver INTERFACE include/solver/Bisection.hpp include/solver/NewtonRaphson.hpp)

target_include_directories(solver INTERFACE include)