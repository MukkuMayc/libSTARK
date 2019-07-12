cmake_minimum_required(VERSION 3.14)
project(algebralib)

set(CMAKE_CXX_STANDARD 11)

set(LIBS fft)

add_library(${PROJECT_NAME}
        headers/algebraLib/AffinePolynomial.hpp
        headers/algebraLib/AffineSpace.hpp
        headers/algebraLib/BitExtract.hpp
        headers/algebraLib/CircuitPolynomial.hpp
        headers/algebraLib/ErrorHandling.hpp
        headers/algebraLib/FFT.hpp
        headers/algebraLib/FieldElement.hpp
        headers/algebraLib/LinearizedPolynomial.hpp
        headers/algebraLib/LinearPolynomial.hpp
        headers/algebraLib/MappingsSys.hpp
        headers/algebraLib/novelFFT.hpp
        headers/algebraLib/PolynomialDegree.hpp
        headers/algebraLib/PolynomialInterface.hpp
        headers/algebraLib/SelectorSum.hpp
        headers/algebraLib/SubspacePolynomial.hpp
        headers/algebraLib/UnivariatePolynomialGeneral.hpp
        headers/algebraLib/variable.hpp
        headers/algebraLib/variable_operators.hpp
        src/AffinePolynomial.cpp
        src/AffineSpace.cpp
        src/BitExtract.cpp
        src/CircuitPolynomial.cpp
        src/ErrorHandling.cpp
        src/FFT.cpp
        src/FieldElement.cpp
        src/LinearPolynomial.cpp
        src/MappingsSys.cpp
        src/novelFFT.cpp
        src/PolynomialDegree.cpp
        src/SelectorSum.cpp
        src/SubspacePolynomial.cpp
        src/UnivariatePolynomialGeneral.cpp
        src/variable.cpp)


target_include_directories(${PROJECT_NAME} PUBLIC headers)
target_include_directories(${PROJECT_NAME} PUBLIC headers/algebraLib)

target_link_libraries(${PROJECT_NAME}  ${LIBS})

# target_include_directories(${PROJECT_NAME} PUBLIC ../FFT/src)