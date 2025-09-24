cmake_minimum_required(VERSION 3.10)
project(SPI_DRIVERS C CXX)

# c lib
add_library(mdio_c_lib  STATIC src/mdio.c)
target_include_directories(mdio_c_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/c
)

#c++ lib
add_library(mdio_c++_lib  STATIC src/mdioc++.cpp)
target_include_directories(mdio_c++_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/c++
)

#test
add_executable(mdio_test test.cpp)
target_link_libraries(mdio_test
    PRIVATE mdio_c_lib
    PRIVATE mdio_c++_lib
)