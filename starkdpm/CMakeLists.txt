cmake_minimum_required(VERSION 3.14)
project(stark-dpm)

set(BUILD_DIR "bin")

set(LIBS fft algebralib libstark)

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

file(READ ../compile_flags.txt COMPILE_FLAGS)
file(READ ../link_flags.txt    LINK_FLAGS)
separate_arguments(COMPILE_FLAGS NATIVE_COMMAND ${COMPILE_FLAGS})
separate_arguments(LINK_FLAGS    NATIVE_COMMAND ${LINK_FLAGS})

target_compile_options(${PROJECT_NAME} PUBLIC ${COMPILE_FLAGS})
target_link_options(${PROJECT_NAME} PUBLIC ${LINK_FLAGS})

target_link_libraries(${PROJECT_NAME}  ${LIBS})

target_include_directories(${PROJECT_NAME} PUBLIC .)


install(TARGETS stark-dpm DESTINATION .)
