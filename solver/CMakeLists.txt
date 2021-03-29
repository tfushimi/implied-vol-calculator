add_library(solver INTERFACE include/solver/bisection.hpp include/solver/newton.hpp)

target_include_directories(solver INTERFACE include)