cmake_minimum_required(VERSION 3.14)
project(fft)

set(CMAKE_CXX_STANDARD 11)

add_library(${PROJECT_NAME}
        src/Basis.cpp
        # src/Basis.h
        src/Definitions.cpp
        # src/Definitions.h
        src/Element.cpp
        # src/Element.h
        src/FFT.cpp
        # src/FFT.h
        src/Polynomials.cpp)
        # src/Polynomials.h)

target_include_directories(${PROJECT_NAME} PUBLIC src)