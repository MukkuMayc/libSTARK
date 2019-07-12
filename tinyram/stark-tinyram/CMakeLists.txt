cmake_minimum_required(VERSION 3.14)
project(stark-tinyram)

set(CMAKE_CXX_STANDARD 11)

set(BUILD_DIR "bin")

include_directories(src/TinyRAM)
include_directories(src/TinyRAMtoBair/ConstraintSystemToBair)
include_directories(src/TinyRAMtoBair/RamToContraintSystem)

# set(FFTLIB_DIR "${PROJECT_SOURCE_DIR}/../../algebra/FFT")
# set(ALGEBRALIB_DIR "${PROJECT_SOURCE_DIR}/../../algebra/algebralib")
# set(LIBSTARK_DIR "${PROJECT_SOURCE_DIR}/../../libstark")
# set(GADGETLIB3_DIR "${PROJECT_SOURCE_DIR}/../../tinyram/gadgetlib")

set(LIBS gadgetlib fft algebralib libstark simde)

# add_subdirectory(${ALGEBRALIB_DIR} bin/algebralib)
# add_subdirectory(${LIBSTARK_DIR} bin/libstark)
# add_subdirectory(${GADGETLIB3_DIR} bin/gadgetlib)
# add_subdirectory(${FFTLIB_DIR} bin/fftlib)

add_executable(${PROJECT_NAME}
        src/TinyRAM/TinyRAMDefinitions.cpp
        src/TinyRAM/TinyRAMDefinitions.hpp
        src/TinyRAM/TinyRAMInstance.cpp
        src/TinyRAM/TinyRAMInstance.hpp
        src/TinyRAMtoBair/ConstraintSystemToBair/cs2Bair.cpp
        src/TinyRAMtoBair/ConstraintSystemToBair/cs2Bair.hpp
        src/TinyRAMtoBair/RamToContraintSystem/ALU.cpp
        src/TinyRAMtoBair/RamToContraintSystem/ALU.hpp
        src/TinyRAMtoBair/RamToContraintSystem/ALUInputConsistency.cpp
        src/TinyRAMtoBair/RamToContraintSystem/ALUInputConsistency.hpp
        src/TinyRAMtoBair/RamToContraintSystem/generalPurpose.cpp
        src/TinyRAMtoBair/RamToContraintSystem/generalPurpose.hpp
        src/TinyRAMtoBair/RamToContraintSystem/MemoryConsraints.cpp
        src/TinyRAMtoBair/RamToContraintSystem/MemoryConsraints.hpp
        src/TinyRAMtoBair/RamToContraintSystem/traceConsistency.cpp
        src/TinyRAMtoBair/RamToContraintSystem/traceConsistency.hpp
        src/TinyRAMtoBair/RamToContraintSystem/transitionFunction.cpp
        src/TinyRAMtoBair/RamToContraintSystem/transitionFunction.hpp
        src/main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC src)
target_include_directories(${PROJECT_NAME} PUBLIC src/TinyRAM)
target_include_directories(${PROJECT_NAME} PUBLIC src/TinyRAMtoBair/ConstraintSystemToBair)
target_include_directories(${PROJECT_NAME} PUBLIC src/TinyRAMtoBair/RamToContraintSystem)

target_link_libraries(${PROJECT_NAME}  ${LIBS})


install(TARGETS ${PROJECT_NAME} DESTINATION ${BUILD_DIR}/starktinyram)