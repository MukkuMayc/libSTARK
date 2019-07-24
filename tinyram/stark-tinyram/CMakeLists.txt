cmake_minimum_required(VERSION 3.14)
project(stark-tinyram)

set(CMAKE_CXX_STANDARD 11)

set(BUILD_DIR "bin")

set(LIBS gadgetlib fft algebralib libstark)

add_library(tinyram-lib
        src/TinyRAM/TinyRAMDefinitions.cpp
        src/TinyRAM/TinyRAMInstance.cpp
        src/TinyRAMtoBair/ConstraintSystemToBair/cs2Bair.cpp
        src/TinyRAMtoBair/RamToContraintSystem/ALU.cpp
        src/TinyRAMtoBair/RamToContraintSystem/ALUInputConsistency.cpp
        src/TinyRAMtoBair/RamToContraintSystem/generalPurpose.cpp
        src/TinyRAMtoBair/RamToContraintSystem/MemoryConsraints.cpp
        src/TinyRAMtoBair/RamToContraintSystem/traceConsistency.cpp
        src/TinyRAMtoBair/RamToContraintSystem/transitionFunction.cpp
)

target_link_libraries(tinyram-lib  ${LIBS})

set(LIBS ${LIBS} tinyram-lib)

add_executable(${PROJECT_NAME}
        src/main.cpp
)

target_include_directories(tinyram-lib PUBLIC src)

target_link_libraries(${PROJECT_NAME}  ${LIBS})

install(TARGETS ${PROJECT_NAME} DESTINATION .)