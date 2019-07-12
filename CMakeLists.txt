cmake_minimum_required(VERSION 3.14)

project(libSTARK-my)

file(READ myflags.txt CMAKE_CXX_FLAGS)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -fopenmp")
set(CMAKE_VERBOSE_MAKEFILE on)
# SET(CMAKE_CXX_COMPILER /usr/bin/g++)

# set(CMAKE_CXX_COMPILER /usr/bin/clang++)
# set(CMAKE_C_COMPILER /usr/bin/clang)

#FROM MAKEFILE

set(BUILD_DIR bin)
#EXE_DIR					:= $(WD)/$(BUILD_DIR)
#BLDDIR					:= $(WD)/$(BUILD_DIR)

set(FFTLIB_SRC_DIR algebra/FFT/src)

set(ALGEBRALIB_DIR ${PROJECT_SOURCE_DIR}/algebra/algebralib)
set(LIBSTARK_DIR ${PROJECT_SOURCE_DIR}/libstark)
set(GADGETLIB3_DIR ${PROJECT_SOURCE_DIR}/tinyram/gadgetlib)
set(TINYRAM_DIR ${PROJECT_SOURCE_DIR}/tinyram/stark-tinyram)
set(DPM_DIR ${PROJECT_SOURCE_DIR}/starkdpm)
set(FFTLIB_DIR ${PROJECT_SOURCE_DIR}/algebra/FFT)
set(SIMDE_DIR ${PROJECT_SOURCE_DIR}/simde)
set(MYFUNCTIONS_DIR ${PROJECT_SOURCE_DIR}/MyFunctions)

set(ALGEBRALIB_TESTS_DIR ${PROJECT_SOURCE_DIR}/algebra/algebralib-tests)
set(STARK_TESTS_DIR ${PROJECT_SOURCE_DIR}/libstark-tests)
set(TINYRAM_TESTS_DIR ${PROJECT_SOURCE_DIR}/tinyram/stark-tinyram-tests)

#END

set(LIBS gadgetlib fft algebralib libstark simde myfunctions)
set(TESTS algebralib-tests libstark-tests stark-tinyram-tests)

add_subdirectory(${SIMDE_DIR} bin/simde)
add_subdirectory(${MYFUNCTIONS_DIR} bin/MyFunctions)
add_subdirectory(${FFTLIB_DIR} bin/fftlib)
add_subdirectory(${ALGEBRALIB_DIR} bin/algebralib)
add_subdirectory(${LIBSTARK_DIR} bin/libstark)
add_subdirectory(${GADGETLIB3_DIR} bin/gadgetlib)

add_subdirectory(${TINYRAM_DIR})
add_subdirectory(${DPM_DIR})