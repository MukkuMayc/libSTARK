cmake_minimum_required(VERSION 3.4)
project(algebralib)

set(CMAKE_CXX_STANDARD 11)

set(LIBS fft)

add_library(${PROJECT_NAME}
        # headers/algebraLib/AffinePolynomial.hpp
        src/AffinePolynomial.cpp
        # headers/algebraLib/AffineSpace.hpp
        src/AffineSpace.cpp
        # headers/algebraLib/BitExtract.hpp
        src/BitExtract.cpp
        # headers/algebraLib/CircuitPolynomial.hpp
        src/CircuitPolynomial.cpp
        # headers/algebraLib/ErrorHandling.hpp
        src/ErrorHandling.cpp
        # headers/algebraLib/FFT.hpp
        src/FFT.cpp
        # headers/algebraLib/FieldElement.hpp
        src/FieldElement.cpp
        headers/algebraLib/LinearizedPolynomial.hpp
        # headers/algebraLib/LinearPolynomial.hpp
        src/LinearPolynomial.cpp
        # headers/algebraLib/MappingsSys.hpp
        src/MappingsSys.cpp
        # headers/algebraLib/novelFFT.hpp
        src/novelFFT.cpp
        # headers/algebraLib/PolynomialDegree.hpp
        src/PolynomialDegree.cpp
        headers/algebraLib/PolynomialInterface.hpp
        # headers/algebraLib/SelectorSum.hpp
        src/SelectorSum.cpp
        # headers/algebraLib/SubspacePolynomial.hpp
        src/SubspacePolynomial.cpp
        # headers/algebraLib/UnivariatePolynomialGeneral.hpp
        src/UnivariatePolynomialGeneral.cpp
        # headers/algebraLib/variable.hpp
        src/variable.cpp
        headers/algebraLib/variable_operators.hpp
)


target_include_directories(${PROJECT_NAME} PUBLIC headers)
target_include_directories(${PROJECT_NAME} PUBLIC headers/algebraLib)

target_link_libraries(${PROJECT_NAME}  ${LIBS})