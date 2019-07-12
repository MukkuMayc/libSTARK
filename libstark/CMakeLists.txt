cmake_minimum_required(VERSION 3.14)
project(libstark)

set(CMAKE_CXX_STANDARD 11)


# include_directories(src/common/Algebra)
# include_directories(src/common/Infrastructure)
# include_directories(src/common/langCommon)
# include_directories(src/common/Utils)
# include_directories(src/languages/Acsp)
# include_directories(src/languages/Bair)
# include_directories(src/protocols)
# include_directories(src/protocols/Ali)
# include_directories(src/protocols/Ali/common_details)
# include_directories(src/protocols/Ali/verifier_details)
# include_directories(src/protocols/common)
# include_directories(src/protocols/common/CryptoCommitment)
# include_directories(src/protocols/Fri)
# include_directories(src/protocols/Fri/common)
# include_directories(src/protocols/Fri/verifier_details)
# include_directories(src/reductions/BairToAcsp)
# include_directories(src/reductions/BairToAcsp/Details)
# include_directories(src/reductions/BairToAcsp/Routing)
# include_directories(src/common/Infrastructure)

set(LIBS algebralib fft simde myfunctions)

add_library(${PROJECT_NAME}
        src/common/Algebra/FieldElementPredicate.hpp
        src/common/Algebra/FiniteSetInterface.hpp
        src/common/Algebra/LinearSpace.cpp
        src/common/Algebra/LinearSpace.hpp
        src/common/Algebra/MultiVarPoly.cpp
        src/common/Algebra/MultiVarPoly.hpp
        src/common/Algebra/MultiVarPolyIddo.hpp
        src/common/Algebra/ShiftedSubspacePolynomial.cpp
        src/common/Algebra/ShiftedSubspacePolynomial.hpp
        src/common/Infrastructure/Infrastructure.cpp
        src/common/Infrastructure/Infrastructure.hpp
        src/common/langCommon/Sequence.hpp
        src/common/Utils/ErrorHandling.cpp
        src/common/Utils/ErrorHandling.hpp
        src/common/Utils/specsPrint.cpp
        src/common/Utils/specsPrint.hpp
        src/common/Utils/TaskReporting.hpp
        src/common/Utils/Timing.cpp
        src/common/Utils/Timing.hpp
        src/languages/Acsp/AcspInstance.hpp
        src/languages/Acsp/AcspWitness.hpp
        src/languages/Acsp/AcspWitnessChecker.cpp
        src/languages/Acsp/AcspWitnessChecker.hpp
        src/languages/Acsp/RationalConstraintsSys.hpp
        src/languages/Bair/BairInstance.hpp
        src/languages/Bair/BairWitness.hpp
        src/languages/Bair/BairWitnessChecker.cpp
        src/languages/Bair/BairWitnessChecker.hpp
        src/languages/Bair/ConstraintsSys.cpp
        src/languages/Bair/ConstraintsSys.hpp
        src/protocols/Ali/common_details/common.cpp
        src/protocols/Ali/common_details/common.hpp
        src/protocols/Ali/verifier_details/queriesGen.cpp
        src/protocols/Ali/verifier_details/queriesGen.hpp
        src/protocols/Ali/prover.cpp
        src/protocols/Ali/prover.hpp
        src/protocols/Ali/verifier.cpp
        src/protocols/Ali/verifier.hpp
        src/protocols/common/CryptoCommitment/MerkleCommitment.cpp
        src/protocols/common/CryptoCommitment/MerkleCommitment.hpp
        src/protocols/common/proofs.cpp
        src/protocols/common/proofs.hpp
        src/protocols/common/queries.hpp
        src/protocols/common/verifier.cpp
        src/protocols/common/verifier.hpp
        src/protocols/Fri/common/common.cpp
        src/protocols/Fri/common/common.hpp
        src/protocols/Fri/verifier_details/queryGenerator.cpp
        src/protocols/Fri/verifier_details/queryGenerator.hpp
        src/protocols/Fri/prover.cpp
        src/protocols/Fri/prover.hpp
        src/protocols/Fri/verifier.cpp
        src/protocols/Fri/verifier.hpp
        src/protocols/protocol.cpp
        src/protocols/protocol.hpp
        src/reductions/BairToAcsp/Details/AcspRationalSystem.hpp
        src/reductions/BairToAcsp/Details/AcspSummandsPolynomial.cpp
        src/reductions/BairToAcsp/Details/AcspSummandsPolynomial.hpp
        src/reductions/BairToAcsp/Details/boundaryConstraints.hpp
        src/reductions/BairToAcsp/Details/common.hpp
        src/reductions/BairToAcsp/Details/commonDeffinitions.cpp
        src/reductions/BairToAcsp/Details/commonDeffinitions.hpp
        src/reductions/BairToAcsp/Details/commonInformation.hpp
        src/reductions/BairToAcsp/Details/commonMappings.cpp
        src/reductions/BairToAcsp/Details/commonMappings.hpp
        src/reductions/BairToAcsp/Details/constraints.cpp
        src/reductions/BairToAcsp/Details/constraints.hpp
        src/reductions/BairToAcsp/Details/constraintSystemsTestLocations.cpp
        src/reductions/BairToAcsp/Details/constraintSystemsTestLocations.hpp
        src/reductions/BairToAcsp/Details/instanceMappings.cpp
        src/reductions/BairToAcsp/Details/instanceMappings.hpp
        src/reductions/BairToAcsp/Details/neighborsConstructor.cpp
        src/reductions/BairToAcsp/Details/neighborsConstructor.hpp
        src/reductions/BairToAcsp/Details/spaces.cpp
        src/reductions/BairToAcsp/Details/spaces.hpp
        src/reductions/BairToAcsp/Details/witnessMappings.cpp
        src/reductions/BairToAcsp/Details/witnessMappings.hpp
        src/reductions/BairToAcsp/Details/witnessReduction.cpp
        src/reductions/BairToAcsp/Details/witnessReduction.hpp
        src/reductions/BairToAcsp/Routing/BenesNetwork.cpp
        src/reductions/BairToAcsp/Routing/BenesNetwork.hpp
        src/reductions/BairToAcsp/Routing/BitReverseButterfliesNetwork.cpp
        src/reductions/BairToAcsp/Routing/BitReverseButterfliesNetwork.hpp
        src/reductions/BairToAcsp/Routing/BtrflyBasedPermutation.cpp
        src/reductions/BairToAcsp/Routing/BtrflyBasedPermutation.hpp
        src/reductions/BairToAcsp/Routing/DeBruijnPermutationNet.cpp
        src/reductions/BairToAcsp/Routing/DeBruijnPermutationNet.hpp
        src/reductions/BairToAcsp/Routing/Deg2PermutationRoutingNet.hpp
        src/reductions/BairToAcsp/Routing/FoldNetwork.cpp
        src/reductions/BairToAcsp/Routing/FoldNetwork.hpp
        src/reductions/BairToAcsp/Routing/LongDeBruijnPermutationNet.cpp
        src/reductions/BairToAcsp/Routing/LongDeBruijnPermutationNet.hpp
        src/reductions/BairToAcsp/Routing/LongSymmetricDeBruijnNetwork.cpp
        src/reductions/BairToAcsp/Routing/LongSymmetricDeBruijnNetwork.hpp
        src/reductions/BairToAcsp/Routing/MatrixNetwork.hpp
        src/reductions/BairToAcsp/Routing/PermutationRoutingNet.cpp
        src/reductions/BairToAcsp/Routing/PermutationRoutingNet.hpp
        src/reductions/BairToAcsp/Routing/RoutingNetwork.hpp
        src/reductions/BairToAcsp/Routing/SymmetricDeBruijnNetwork.cpp
        src/reductions/BairToAcsp/Routing/SymmetricDeBruijnNetwork.hpp
        src/reductions/BairToAcsp/Routing/TandemNetwork.cpp
        src/reductions/BairToAcsp/Routing/TandemNetwork.hpp
        src/reductions/BairToAcsp/BairToAcsp.cpp
        src/reductions/BairToAcsp/BairToAcsp.hpp)

target_include_directories(${PROJECT_NAME} PUBLIC src)
target_include_directories(${PROJECT_NAME} PUBLIC src/common/Algebra)
target_include_directories(${PROJECT_NAME} PUBLIC src/common/Infrastructure)
target_include_directories(${PROJECT_NAME} PUBLIC src/common/langCommon)
target_include_directories(${PROJECT_NAME} PUBLIC src/common/Utils)
target_include_directories(${PROJECT_NAME} PUBLIC src/languages/Acsp)
target_include_directories(${PROJECT_NAME} PUBLIC src/languages/Bair)
target_include_directories(${PROJECT_NAME} PUBLIC src/protocols)
target_include_directories(${PROJECT_NAME} PUBLIC src/protocols/Ali)
target_include_directories(${PROJECT_NAME} PUBLIC src/protocols/Ali/common_details)
target_include_directories(${PROJECT_NAME} PUBLIC src/protocols/Ali/verifier_details)
target_include_directories(${PROJECT_NAME} PUBLIC src/protocols/common)
target_include_directories(${PROJECT_NAME} PUBLIC src/protocols/common/CryptoCommitment)
target_include_directories(${PROJECT_NAME} PUBLIC src/protocols/Fri)
target_include_directories(${PROJECT_NAME} PUBLIC src/protocols/Fri/common)
target_include_directories(${PROJECT_NAME} PUBLIC src/protocols/Fri/verifier_details)
target_include_directories(${PROJECT_NAME} PUBLIC src/reductions/BairToAcsp)
target_include_directories(${PROJECT_NAME} PUBLIC src/reductions/BairToAcsp/Details)
target_include_directories(${PROJECT_NAME} PUBLIC src/reductions/BairToAcsp/Routing)


target_link_libraries(${PROJECT_NAME}  ${LIBS})
# target_link_libraries(${PROJECT_NAME}  algebralib)