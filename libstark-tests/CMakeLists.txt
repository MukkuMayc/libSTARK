include(GoogleTest)
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

include_directories(.)

set(LIBS libstark ${GTEST_LIBRARIES})

# file(GLOB_RECURSE ${TEST_SRC_FILES} RELATIVE
# 	${PROJECT_SOURCE_DIR}/libstark-tests
# 	libstark-tests/*.cpp
# 	# libstark-tests/*/*.cpp
# )

set(TEST_SRC_FILES
	main.cpp
	MerkleCommitment_UTEST.cpp
	BairWitnessChecker_UTEST.cpp
	AcspWitnessChecker_UTEST.cpp
	lightCircLib/lightCircuit.cpp
	lightCircLib/lightCircGate.cpp
	lightCircLib/lightCircPoly.cpp
	lightCircLib/lightCircPoly_UTEST.cpp
	BairToAcsp/witnessReduction_UTEST.cpp
	BairToAcsp/RoutingNetwork_UTEST.cpp
	BairToAcsp/neighborsConstructor_UTEST.cpp
	BairToAcsp/constraints_UTEST.cpp
	BairToAcsp/boundaryConstraints_UTEST.cpp
	BairToAcsp/AcspSummandsPolynomial_UTEST.cpp
)

# message(STATUS "Test case source files: " ${TEST_SRC_FILES})

add_executable(libstark-tests
	main.cpp
	MerkleCommitment_UTEST.cpp
	BairWitnessChecker_UTEST.cpp
	AcspWitnessChecker_UTEST.cpp
	lightCircLib/lightCircuit.cpp
	lightCircLib/lightCircGate.cpp
	lightCircLib/lightCircPoly.cpp
	lightCircLib/lightCircPoly_UTEST.cpp
	BairToAcsp/witnessReduction_UTEST.cpp
	BairToAcsp/RoutingNetworks_UTEST.cpp
	BairToAcsp/neighborsConstructor_UTEST.cpp
	BairToAcsp/constraints_UTEST.cpp
	BairToAcsp/boundaryConstraints_UTEST.cpp
	BairToAcsp/AcspSummandsPolynomial_UTEST.cpp
)

gtest_add_tests(TARGET libstark-tests)

target_link_libraries(libstark-tests ${LIBS})