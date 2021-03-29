set(Boost_INCLUDE_DIRS /usr/local/Cellar/boost/1.75.0_2/include)

include_directories(${Boost_INCLUDE_DIRS}) 

add_library(bsmodel src/BlackScholesFormula.cpp src/BSCallClass.cpp)

target_include_directories(bsmodel PUBLIC include)
