cmake_minimum_required(VERSION 3.14)
project(fft)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME}
        src/Basis.cpp
        # src/Basis.h
        src/Definitions.cpp
        # src/Definitions.h
        src/Element.cpp
        # src/Element.h
        src/FFT.cpp
        # src/FFT.h
        src/Polynomials.cpp
        # src/Polynomials.h)
)

# set(MY_FLAGS -O3 -p -pthread -fmessage-length=0 -std=gnu++11)
file(READ ../../myflags.txt MY_FLAGS)
separate_arguments(MY_FLAGS NATIVE_COMMAND ${MY_FLAGS})
target_compile_options(${PROJECT_NAME} PUBLIC ${MY_FLAGS})

target_include_directories(${PROJECT_NAME} PUBLIC src)
