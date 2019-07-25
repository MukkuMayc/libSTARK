cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 11)

project(libSTARK)

file(READ myflags.txt CMAKE_CXX_FLAGS)
set(CMAKE_VERBOSE_MAKEFILE on)

set(BUILD_DIR bin)

set(FFTLIB_SRC_DIR algebra/FFT/src)

set(ALGEBRALIB_DIR ${PROJECT_SOURCE_DIR}/algebra/algebralib)
set(LIBSTARK_DIR ${PROJECT_SOURCE_DIR}/libstark)
set(GADGETLIB3_DIR ${PROJECT_SOURCE_DIR}/tinyram/gadgetlib)
set(TINYRAM_DIR ${PROJECT_SOURCE_DIR}/tinyram/stark-tinyram)
set(DPM_DIR ${PROJECT_SOURCE_DIR}/starkdpm)
set(FFTLIB_DIR ${PROJECT_SOURCE_DIR}/algebra/FFT)

set(ALGEBRALIB_TESTS_DIR ${PROJECT_SOURCE_DIR}/algebra/algebralib-tests)
set(LIBSTARK_TESTS_DIR ${PROJECT_SOURCE_DIR}/libstark-tests)
set(TINYRAM_TESTS_DIR ${PROJECT_SOURCE_DIR}/tinyram/stark-tinyram-tests)

#END

set(LIBS gadgetlib fft algebralib libstark)
set(TESTS algebralib-tests libstark-tests stark-tinyram-tests)

add_subdirectory(${FFTLIB_DIR} bin/fftlib)
add_subdirectory(${ALGEBRALIB_DIR} bin/algebralib)
add_subdirectory(${LIBSTARK_DIR} bin/libstark)
add_subdirectory(${GADGETLIB3_DIR} bin/gadgetlib)

add_subdirectory(${TINYRAM_DIR})
add_subdirectory(${DPM_DIR})

# add_subdirectory(${ALGEBRALIB_TESTS_DIR})
# add_subdirectory(${LIBSTARK_TESTS_DIR})
# add_subdirectory(${TINYRAM_TESTS_DIR})
