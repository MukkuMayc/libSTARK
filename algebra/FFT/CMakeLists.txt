cmake_minimum_required(VERSION 3.14)
project(fft)

set(CMAKE_CXX_STANDARD 11)

set(LIBS simde myfunctions)

add_library(${PROJECT_NAME}
        src/Basis.cpp
        src/Basis.h
        src/Definitions.cpp
        src/Definitions.h
        src/Element.cpp
        src/Element.h
        src/FFT.cpp
        src/FFT.h
        src/Polynomials.cpp
        src/Polynomials.h)

target_include_directories(${PROJECT_NAME} PUBLIC src)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME}  ${LIBS})