include(GoogleTest)
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

include_directories(.)

include_directories(${TINYRAM_DIR}/src)

include_directories(${BUILD_DIR}/tinyram/stark-tinyram)

set(LIBS gadgetlib tinyram-lib ${GTEST_LIBRARIES})

add_executable(stark-tinyram-tests
	main.cpp
	ALUInputConsistenctUTEST.cpp
	ALU_UTEST.cpp
	traceConsistencyUTEST.cpp
	ConstraintsSystem2Bair_UTEST.cpp
	memory_UTEST.cpp
	transitionFunctionUTEST.cpp
	generalPupose_UTEST.cpp
	programs_UTEST.cpp
)

gtest_add_tests(TARGET stark-tinyram-tests)

target_link_libraries(stark-tinyram-tests ${LIBS})