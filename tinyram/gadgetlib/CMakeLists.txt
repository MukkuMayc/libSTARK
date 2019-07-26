cmake_minimum_required(VERSION 3.14)
project(gadgetlib)

set(CMAKE_CXX_STANDARD 17)

include_directories(gadgetlib)
include_directories(gadgetlib/SHA)

set(LIBS fft algebralib libstark)

add_library(${PROJECT_NAME}
        # gadgetlib/examples/tutorial.cpp
        # gadgetlib/SHA/sha2.cpp
        # gadgetlib/SHA/sha2.hpp
        # gadgetlib/tests/constraint_UTEST.cpp
        # gadgetlib/tests/gadget_UTEST.cpp
        # gadgetlib/tests/gadgetlib2_test.cpp
        # gadgetlib/tests/protoboard_UTEST.cpp
        # gadgetlib/tests/variable_UTEST.cpp
        gadgetlib/common_use.cpp
        # gadgetlib/common_use.hpp
        gadgetlib/constraint.cpp
        # gadgetlib/constraint.hpp
        gadgetlib/gadget.cpp
        # gadgetlib/gadget.hpp
        gadgetlib/gadgetMacros.hpp
        gadgetlib/infrastructure.cpp
        # gadgetlib/infrastructure.hpp
        gadgetlib/protoboard.cpp
        # gadgetlib/protoboard.hpp
)

# set(MY_FLAGS -O3 -Wall -p -pthread -fmessage-length=0 -std=gnu++11)
file(READ ../../myflags.txt MY_FLAGS)
separate_arguments(MY_FLAGS NATIVE_COMMAND ${MY_FLAGS})
target_compile_options(${PROJECT_NAME} PUBLIC ${MY_FLAGS})


target_include_directories(gadgetlib PUBLIC .)
# target_include_directories(gadgetlib PUBLIC gadgetlib)
# target_include_directories(gadgetlib PUBLIC gadgetlib/SHA)

target_link_libraries(gadgetlib ${LIBS})
