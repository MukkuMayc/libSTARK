cmake_minimum_required(VERSION 3.4)
project(stark-dpm)

set(CMAKE_CXX_STANDARD 11)

set(BUILD_DIR "bin")

# include_directories(.)

# set(FFTLIB_DIR "${PROJECT_SOURCE_DIR}/../algebra/FFT")
# set(ALGEBRALIB_DIR "${PROJECT_SOURCE_DIR}/../algebra/algebralib")
# set(LIBSTARK_DIR "${PROJECT_SOURCE_DIR}/../libstark")

set(LIBS fft algebralib libstark)

# add_subdirectory(${ALGEBRALIB_DIR} bin/algebralib)
# add_subdirectory(${LIBSTARK_DIR} bin/libstark)
# add_subdirectory(${FFTLIB_DIR} bin/fftlib)

add_executable(${PROJECT_NAME}
        # AES160hashcLOCI.hpp
        AES160hashcLOCI_constraints.cpp
        AES160hashcLOCI_EvalPoly.cpp
        AES160hashcLOCI_GenWitness.cpp
        AES160hashcLOCI_instance.cpp
        AES160hashcLOCI_instance.hpp
        AES160hashcLOCI_witness.cpp
        main.cpp
)

target_link_libraries(${PROJECT_NAME}  ${LIBS})

target_include_directories(${PROJECT_NAME} PUBLIC .)


install(TARGETS stark-dpm DESTINATION .)
