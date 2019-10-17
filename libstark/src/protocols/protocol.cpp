#include "protocol.hpp"
#include "common/Utils/Timing.hpp"
#include "common/Utils/specsPrint.hpp"
#include "languages/Acsp/AcspWitnessChecker.hpp"
#include "languages/Bair/BairWitnessChecker.hpp"
#include "protocols/Ali/prover.hpp"
#include "protocols/Ali/verifier.hpp"
#include "reductions/BairToAcsp/BairToAcsp.hpp"
#include <iostream>


namespace libstark {
namespace Protocols {

// the following are UBUNTU/LINUX ONLY terminal color codes.
#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

namespace {
const auto VERIFIER_COLOR = YELLOW;

void startColor(const char* color) {
    // std::cout<<color<<std::endl;
}

void resetColor() { startColor(RESET); }

void startProver() { startColor(MAGENTA); }

void startVerifier() { startColor(VERIFIER_COLOR); }

void startVerification() { startColor(GREEN); }

void startSpecs() { startColor(CYAN); }

void startCicleCount() { startColor(WHITE); }

std::string numBytesToString(uint64_t numBytes) {
    std::string suffix[] = {"Bytes",  "KBytes", "MBytes", "GBytes",
                            "TBytes", "PBytes", "EByte",  "ZByte"};

    int i = 0;
    double currSize = numBytes;
    while (currSize > 1024LL) {
        currSize /= 1024LL;
        i++;
    }

    return std::to_string(currSize) + " " + suffix[i];
}

std::string secondsToString(double seconds) {
    if (seconds >= 60LL * 60LL * 24LL) {
        return std::to_string(seconds / (60LL * 60LL * 24LL)) + " Days";
    }

    if (seconds >= 60LL * 60LL) {
        return std::to_string(seconds / (60LL * 60LL)) + " Hours";
    }

    if (seconds >= 60LL) {
        return std::to_string(seconds / (60LL)) + " Minutes";
    }

    return std::to_string(seconds) + " Seconds";
}

void printSpecs(const double proverTime, const double verifierTime,
                const uint64_t proofGeneratedBytes, const uint64_t proofSentBytes,
                const uint64_t queriedDataBytes) {
    startSpecs();
    specsPrinter specs("Protocol execution measurements");
    specs.addLine("Prover time", secondsToString(proverTime));
    specs.addLine("Verifier time", secondsToString(verifierTime));
    specs.addLine("Total IOP length", numBytesToString(proofGeneratedBytes));
    specs.addLine("Total communication complexity (STARK proof size)",
                  numBytesToString(proofSentBytes));
    specs.addLine("Query complexity", numBytesToString(queriedDataBytes));
    specs.print();

    resetColor();
}

}  // namespace

//create anf fill prover Msg field
std::vector<CryptoCommitment::hashDigest_t> commitments;
Ali::details::rawResults_t results;
libstark::Protocols::Fri::common::proverResponce_t RSProverWitess1;
libstark::Protocols::Fri::common::proverResponce_t RSProverComposition1;

//create and fill verifier Msg fields
unsigned int numRepetitions1;
Ali::details::randomCoeffsSet_t randomCoefficients1;
std::vector<std::vector<Algebra::FieldElement>> coeffsPi1;
std::vector<Algebra::FieldElement> Coeffspivec1;
std::vector<std::vector<Algebra::FieldElement>> coeffsChi1;
std::vector<Algebra::FieldElement> CoeffsChivec1;
Ali::details::rawQueries_t queries1;
std::vector<std::unique_ptr<TranscriptMessage>> RS_verifier_witness_msg1;
std::vector<std::unique_ptr<TranscriptMessage>> RS_verifier_composition_msg1;

//fun to deserialized dataResults
libstark::Protocols::Fri::common::state_t<std::vector<libstark::Protocols::CryptoCommitment::hashDigest_t>> dataResults1(nlohmann::json &Element ) {
    //deserialized dataResults.localState
    bool isTRUE5 = (Element.find("localState") != Element.end());
    if (isTRUE5) {
        auto RSLocalStateParsed = Element["localState"];
        for(auto & i : RSLocalStateParsed) {
            CryptoCommitment::hashDigest_t buffer1;
            std::string buff = base64_decode(i);
            buff.copy(buffer1.buffer, buff.length());
            RSProverWitess1.dataResults.localState.push_back(buffer1);
        }
    }
    //deserialized dataResults.subproofs
    bool isTrue6 = (Element.find("subproofs") != Element.end());
    Algebra::FieldElement ALFE;
    libstark::Protocols::Fri::common::state_t<std::vector<libstark::Protocols::CryptoCommitment::hashDigest_t>> second1;
    if (isTrue6) {

        auto RSSubproofsParced = Element["subproofs"];
        for (int i=0; i<RSSubproofsParced.size();i++) {
            //for each subproofs desertialized first
            bool isTrue7 = (RSSubproofsParced[i].find("first") != RSSubproofsParced[i].end());
            if (isTrue7) {
                auto RSSubproofsFirstParced = RSSubproofsParced[i]["first"];
                ALFE=Algebra::mapIntegerToFieldElement(0,64,RSSubproofsFirstParced);
            }
            //for each subproofs try to desertialized second
            bool isTrue8 = (RSSubproofsParced[i].find("second") != RSSubproofsParced[i].end());
            if (isTrue8) {
                auto RSSubproofsSecondParced = RSSubproofsParced[i]["second"];
                second1 = dataResults1(RSSubproofsSecondParced);
            }
        }
    }
    RSProverWitess1.dataResults.subproofs.clear();
    RSProverWitess1.dataResults.subproofs.insert(std::pair<Algebra::FieldElement, libstark::Protocols::Fri::common::state_t<std::vector<libstark::Protocols::CryptoCommitment::hashDigest_t>>>(ALFE, second1));
    return RSProverWitess1.dataResults;
};

//fun to deserialized dataResults RS_prover_cpmposition
libstark::Protocols::Fri::common::state_t<std::vector<libstark::Protocols::CryptoCommitment::hashDigest_t>> dataResults2(nlohmann::json &Element ) {
            //deserialized dataResults.localState
            bool isTRUE5 = (Element.find("localState") != Element.end());
            if (isTRUE5) {
                auto RSLocalStateParsed = Element["localState"];
                for(auto & i : RSLocalStateParsed) {
                    CryptoCommitment::hashDigest_t buffer1;
                    std::string buff = base64_decode(i);
                    buff.copy(buffer1.buffer, buff.length());
                    RSProverComposition1.dataResults.localState.push_back(buffer1);
                }
            }
            //deserialized dataResults.subproofs
            bool isTrue6 = (Element.find("subproofs") != Element.end());
            Algebra::FieldElement ALFE;
            libstark::Protocols::Fri::common::state_t<std::vector<libstark::Protocols::CryptoCommitment::hashDigest_t>> second1;
            if (isTrue6) {
                auto RSSubproofsParced = Element["subproofs"];
                for (int i=0; i<RSSubproofsParced.size();i++) {
                    //for each subproofs desertialized first
                    bool isTrue7 = (RSSubproofsParced[i].find("first") != RSSubproofsParced[i].end());
                    if (isTrue7) {
                        auto RSSubproofsFirstParced = RSSubproofsParced[i]["first"];
                        ALFE=Algebra::mapIntegerToFieldElement(0,64,RSSubproofsFirstParced);
                    }
                    //for each subproofs try to desertialized second
                    bool isTrue8 = (RSSubproofsParced[i].find("second") != RSSubproofsParced[i].end());
                    if (isTrue8) {
                        auto RSSubproofsSecondParced = RSSubproofsParced[i]["second"];
                        second1 = dataResults2(RSSubproofsSecondParced);
                    }
                }
            }
            RSProverComposition1.dataResults.subproofs.clear();
            RSProverComposition1.dataResults.subproofs.insert(std::pair<Algebra::FieldElement, libstark::Protocols::Fri::common::state_t<std::vector<libstark::Protocols::CryptoCommitment::hashDigest_t>>>(ALFE, second1));
            return RSProverComposition1.dataResults;
        };

bool executeProtocol(PartieInterface& prover, verifierInterface& verifier,
                     const bool onlyVerifierData) {
    double verifierTime = 0;
    double proverTime = 0;
    const uint64_t proofGeneratedBytes = verifier.expectedCommitedProofBytes();
    const uint64_t proofSentBytes = verifier.expectedSentProofBytes();
    const uint64_t queriedDataBytes = verifier.expectedQueriedDataBytes();

    Timer t;
    if (onlyVerifierData) {
        verifier.fillResultsAndCommitmentRandomly();
    } else {
        uint64_t msgNum = 1;
        startCicleCount();
        while (!verifier.doneInteracting()) {
            std::cout << "communication iteration #" << msgNum++ << ":";
            bool doStatusLoop = true;
            Timer roundTimer;
            // std::thread barManager([&]() {
            //     unsigned int sleepInterval = 10;
            //     unsigned int sleepTime = 10;
            //     while (doStatusLoop) {
            //         std::cout << "." << std::flush;
            //         for (unsigned int i = 0; (i < sleepTime) && doStatusLoop;
            //              i++) {
            //             std::this_thread::sleep_for(
            //                 std::chrono::milliseconds(sleepInterval));
            //         }
            //         sleepTime *= 2;
            //     }
            // });
            // TASK("interaction round #" + std::to_string(msgNum++));

            startVerifier();
            const auto vMsg = verifier.sendMessage();
            std::cout << vMsg->serialization() << std::endl;
            verifierTime += t.getElapsed();
            t = Timer();

//            try to deserialized verifier message
//-----------------------------------------------------------------------------------------------------------
            nlohmann::json parsedWitness = nlohmann::json::parse(vMsg->serialization());
            //done
            bool isWTRUE = (parsedWitness.find("numRepetitions") != parsedWitness.end());
            if(isWTRUE) {
                auto numRepetitionsPRS = parsedWitness["numRepetitions"];
                numRepetitions1 = std::stoul((const std::string) numRepetitionsPRS,0,0);
            }
                //TODO this shit
//            bool isWTRUE1 = (parsedWitness.find("randomCoefficients") != parsedWitness.end());
//            if (isWTRUE1) {
//                auto randomCoeffsPRS = parsedWitness["randomCoefficients"];
//                //check boundary
////                std::cout<<"---------------------------"<<std::endl;
////                std::cout<<randomCoeffsPRS<<std::endl;
////                std::cout<<"---------------------------"<<std::endl;
//                //check boundaryPolysMatrix
//                if (randomCoeffsPRS.find("boundaryPolysMatrix") != randomCoeffsPRS.end()){
//                    auto randomCoeefsBoundaryPolysPRS = randomCoeffsPRS["boundaryPolysMatrix"];
//                        std::cout<<randomCoeefsBoundaryPolysPRS<<std::endl;
//                    }
//
//                //ZK_mask_composition
//                if (parsedWitness.find("ZK_mask_composition") != parsedWitness.end()){
//
//                }
//
//            }
            //done
            bool isWTRUE2 = (parsedWitness.find("coeffsPi") != parsedWitness.end());
            if (isWTRUE2) {
                auto ceffsPiPRS = parsedWitness["coeffsPi"];
                for (int i=0; i<ceffsPiPRS.size();i++) {
                    for ( int j=0; j<ceffsPiPRS[i].size();j++) {
                        Coeffspivec1.push_back(Algebra::mapIntegerToFieldElement(0,64,ceffsPiPRS[i][j]));
                    }
                    coeffsPi1.push_back(Coeffspivec1);
                }
            }
            //done
            bool isWTRUE3 = (parsedWitness.find("coeffsChi") != parsedWitness.end());
            if (isWTRUE2) {
                auto ceffsChiPRS = parsedWitness["coeffsChi"];
                for (int i=0; i<ceffsChiPRS.size();i++) {
                    for ( int j=0; j<ceffsChiPRS[i].size();j++) {
                        CoeffsChivec1.push_back(Algebra::mapIntegerToFieldElement(0,64,ceffsChiPRS[i][j]));
                    }
                    coeffsChi1.push_back(CoeffsChivec1);
                }
            }
            
            bool isWTRUE4 = (parsedWitness.find("queries") != parsedWitness.end());
            bool isWTRUE5 = (parsedWitness.find("RS_verifier_witness_msg") != parsedWitness.end());
            bool isWTRUE6 = (parsedWitness.find("RS_verifier_composition_msg") != parsedWitness.end());

//-----------------------------------------------------------------------------------------------------------
//            end of deserialized verifier message




            startProver();
            prover.receiveMessage(*vMsg);
            const auto pMsg = prover.sendMessage();
//            std::cout << pMsg->serialization() << std::endl;
            proverTime += t.getElapsed();

            //--------------------------------------------------------------------------------------------------
            //deserialized prover message
            nlohmann::json parcedStr = nlohmann::json::parse(pMsg->serialization());
            bool isTRUE = (parcedStr.find("commitments") != parcedStr.end());
            bool isTRUE1 = (parcedStr.find("results") != parcedStr.end());
            bool isTRUE2 = (parcedStr.find("RS_prover_witness_msg") != parcedStr.end());
            bool isTRUE3 = (parcedStr.find("RS_prover_composition_msg") != parcedStr.end());

            //done
            if  (isTRUE) {
                auto CommitmentsParced = parcedStr["commitments"].get<nlohmann::json::array_t>();
                for( int i=0; i<CommitmentsParced.size(); i++) {
                    CryptoCommitment::hashDigest_t buffer1;
                    std::string buff = base64_decode(CommitmentsParced[i]);
                    buff.copy(buffer1.buffer, buff.length());
                    commitments.push_back(buffer1);
                }
            }

            if (isTRUE1) {
                auto ResultsBoundaryParced = parcedStr["results"]["boundary"].get<nlohmann::json::array_t>();
                for (int i=0;i<ResultsBoundaryParced.size();i++){
                    std::vector<libstark::Protocols::CryptoCommitment::hashDigest_t> boundary1;
                    for (int j=0; j<ResultsBoundaryParced[i].size();j++) {
                        CryptoCommitment::hashDigest_t buffer1;
                        std::string buff = base64_decode(ResultsBoundaryParced[i][j]);
                        buff.copy(buffer1.buffer, buff.length());
                        boundary1.push_back(buffer1);
                    }
                    results.boundary.push_back(boundary1);
                }
                auto ResultsZKMaskParced = parcedStr["results"]["ZK_mask_composition"].get<nlohmann::json::array_t>();
                for (int i=0;i<ResultsZKMaskParced.size();i++){
                    std::vector<libstark::Protocols::CryptoCommitment::hashDigest_t> ZK_mask_composition1;
                    for (int j=0; j<ResultsZKMaskParced[i].size();j++) {
                        CryptoCommitment::hashDigest_t buffer1;
                        std::string buff = base64_decode(ResultsZKMaskParced[i][j]);
                        buff.copy(buffer1.buffer, buff.length());
                        ZK_mask_composition1.push_back(buffer1);
                    }
                    results.ZK_mask_composition.push_back(ZK_mask_composition1);
                }
                auto ResultsBoundaryPolyParced = parcedStr["results"]["boundaryPolysMatrix"].get<nlohmann::json::array_t>();
                for(auto & i : ResultsBoundaryPolyParced) {
                    CryptoCommitment::hashDigest_t buffer1;
                    std::string buff = base64_decode(i);
                    buff.copy(buffer1.buffer, buff.length());
                    results.boundaryPolysMatrix.push_back(buffer1);
                }
            }

            if (isTRUE2) {
                auto RSwitnessParced = parcedStr["RS_prover_witness_msg"].get<nlohmann::json::array_t>();
                for (int i=0; i<RSwitnessParced.size();i++) {
                    nlohmann::json parcedRSw = nlohmann::json::parse(RSwitnessParced[i].dump());
                    //take element from RS_witness and fill proofConstructionComitments field in proverResponce_t
                    auto RSProofConstrParsed = parcedRSw["proofConstructionComitments"];
                    for(auto & i : RSProofConstrParsed) {
                        CryptoCommitment::hashDigest_t buffer1;
                        std::string buff = base64_decode(i);
                        buff.copy(buffer1.buffer, buff.length());
                        RSProverWitess1.proofConstructionComitments.push_back(buffer1);
                    }
                    auto RSDataResultsParsed = parcedRSw["dataResults"];
                    //deserialized dataResults
                    dataResults1(RSDataResultsParsed);
               }
            }

            if (isTRUE3) {
                auto RSCompositionParced = parcedStr["RS_prover_composition_msg"].get<nlohmann::json::array_t>();
                for (int i=0; i<RSCompositionParced.size();i++) {
                    nlohmann::json parcedRSC = nlohmann::json::parse(RSCompositionParced[i].dump());
                    //take element from RS_composition and fill proofConstructionComitments field in proverResponce_t
                    auto RSProofConstrParsed = parcedRSC["proofConstructionComitments"];
                    for(auto & i : RSProofConstrParsed) {
                        CryptoCommitment::hashDigest_t buffer1;
                        std::string buff = base64_decode(i);
                        buff.copy(buffer1.buffer, buff.length());
                        RSProverComposition1.proofConstructionComitments.push_back(buffer1);
                    }
                    auto RSDataResultsParsed = parcedRSC["dataResults"];
                    //deserialized dataResults
                    dataResults2(RSDataResultsParsed);
                }
            }
            //here need to collect prover message
//            libstark::Protocols::Ali::details::proverMsg::results = results;
//            libstark::Protocols::Ali::details::proverMsg::commitments = commitments;
//            libstark::Protocols::Ali::details::proverMsg::RS_prover_composition_msg.push_back(RSProverComposition1);
//            libstark::Protocols::Ali::details::proverMsg::RS_prover_witness_msg.push_back(RSProverWitess1);

            //end deserialized prover message
            //-----------------------------------------------------------------------


            {
                doStatusLoop = false;
                std::cout << "(" << roundTimer.getElapsed() << " seconds)"
                          << std::endl;
            }

            t = Timer();
            startVerifier();
            verifier.receiveMessage(*pMsg);
            startCicleCount();
        }
    }

    startVerification();
    const bool res = verifier.verify();
    verifierTime += t.getElapsed();
    std::cout << "Verifier decision: " << (res ? "ACCEPT" : "REJECT")<< std::endl;

    resetColor();
    printSpecs(proverTime, verifierTime, proofGeneratedBytes, proofSentBytes,
               queriedDataBytes);
    return res;
}

using std::max;
using std::pair;
using std::unique_ptr;
using std::vector;
using namespace Infrastructure;
using namespace Algebra;

namespace prn {

using std::string;
using std::to_string;

void printBairInstanceSpec(const BairInstance& instance) {
    specsPrinter specs("BAIR Specifications");
    specs.addLine("field size", "2^64");
    const uint64_t totalVars = instance.vectorsLen();
    specs.addLine("number of variables per state (w)", to_string(totalVars));
    specs.addLine("number of regular constraints (s)",
                  to_string(instance.constraintsAssignment().numMappings()));
    specs.addLine("number of permutation constraints",
                  to_string(instance.constraintsPermutation().numMappings()));
    specs.addLine("number of cycles (c)",
                  "(2^" + to_string(instance.domainSizeIndicator()) + ")-1");
    specs.addLine("degree of constraint system (d)",
                  to_string(PolynomialDegree::integral_t(
                      instance.constraintsAssignment().getMaximalDegree())));
    specs.addLine("degree of permutation constraint system",
                  to_string(PolynomialDegree::integral_t(
                      instance.constraintsPermutation().getMaximalDegree())));
    specs.addLine("number of boundary constraints (B)",
                  to_string(instance.boundaryConstraints().size()));

    // count amount of routed vars
    uint64_t amountRouted = 0;
    for (uint64_t i = totalVars; i < totalVars * 2; i++) {
        if (instance.constraintsPermutation().varUsed(i)) {
            amountRouted++;
        }
    }

    // count how many univariate constraints we have in CHI
    uint64_t univariateConstraintsTime = 0;
    vector<pair<UnivariatePolynomialGeneral, uint64_t> > univariatePolys;
    {
        const vector<PolynomialDegree> inputDegrees(totalVars * 2,
                                                    PolynomialDegree(1));
        for (const auto& c : instance.constraintsAssignment().constraints()) {
            uint64_t numVarsUsed = 0;
            uint64_t lastVarUsed = 0;
            for (uint64_t i = 0; i < totalVars * 2; i++) {
                if (c->isEffectiveInput(i)) {
                    numVarsUsed++;
                    lastVarUsed = i;
                }
            }
            if ((numVarsUsed == 1) && (lastVarUsed < totalVars)) {
                univariateConstraintsTime++;
                const auto degreeBound = c->getDegreeBound(inputDegrees);
                const uint64_t interpolationBasisSize =
                    ceil(Log2(PolynomialDegree::integral_t(degreeBound) + 1));
                const auto interpolationBasis =
                    getStandartBasis(interpolationBasisSize);
                const vector<FieldElement> orderedBasis(
                    interpolationBasis.begin(), interpolationBasis.end());

                // construct the evaluation
                vector<FieldElement> evaluation(POW2(interpolationBasisSize));
                {
                    vector<FieldElement> assignment(totalVars * 2);
                    for (uint64_t i = 0; i < evaluation.size(); i++) {
                        assignment[lastVarUsed] =
                            getSpaceElementByIndex(orderedBasis, zero(), i);
                        evaluation[i] = c->eval(assignment);
                    }
                }
                if ((numVarsUsed == 1) && (lastVarUsed < totalVars)) {
                    univariateConstraintsTime++;
                    const auto degreeBound = c->getDegreeBound(inputDegrees);
                    const uint64_t interpolationBasisSize = ceil(
                        Log2(PolynomialDegree::integral_t(degreeBound) + 1));
                    const auto interpolationBasis =
                        getStandartBasis(interpolationBasisSize);
                    const vector<FieldElement> orderedBasis(
                        interpolationBasis.begin(), interpolationBasis.end());

                    // construct the evaluation
                    vector<FieldElement> evaluation(
                        POW2(interpolationBasisSize));
                    {
                        vector<FieldElement> assignment(totalVars * 2);
                        for (uint64_t i = 0; i < evaluation.size(); i++) {
                            assignment[lastVarUsed] =
                                getSpaceElementByIndex(orderedBasis, zero(), i);
                            evaluation[i] = c->eval(assignment);
                        }
                        const UnivariatePolynomialGeneral poly(
                            evaluation, orderedBasis, zero());
                        // add poly to the menaged set
                        {
                            bool found = false;
                            for (auto& p : univariatePolys) {
                                if (p.first == poly) {
                                    p.second++;
                                    found = true;
                                    break;
                                }
                            }
                            if (!found) {
                                univariatePolys.push_back(
                                    pair<UnivariatePolynomialGeneral, uint64_t>(
                                        poly, 1));
                            }
                        }
                    }
                }
            }
        }

        uint64_t usedVarsAmount = 0;
        for (uint64_t i = 0; i < totalVars; i++) {
            if (instance.constraintsAssignment().varUsed(i)) {
                usedVarsAmount++;
            } else if (instance.constraintsPermutation().varUsed(i)) {
                usedVarsAmount++;
            } else if (instance.constraintsAssignment().varUsed(i +
                                                                totalVars)) {
                usedVarsAmount++;
            } else if (instance.constraintsPermutation().varUsed(i +
                                                                 totalVars)) {
                usedVarsAmount++;
            }
        }

        const uint64_t unroutedAmount = totalVars - amountRouted;

        specs.addLine("number of variables used by constraint systems",
                      to_string(usedVarsAmount));
        specs.addLine("number of variables routed", to_string(amountRouted));
        specs.addLine("number of variables not routed",
                      to_string(unroutedAmount));
    }

    specs.print();
}

void printAcspInstanceSpec(const AcspInstance& instance) {
    specsPrinter specs("ACSP Specifications");
    specs.addLine("field size", "2^64");
    specs.addLine("number of algebraic-registers (|\\Tau|)",
                  to_string(instance.witnessDegreeBound().size()));

    uint64_t numNeighbors = 0;
    for (const auto& vn : instance.neighborPolys()) {
        numNeighbors += vn.size();
    }

    specs.addLine("number of neighbors (|N|)", to_string(numNeighbors));
    specs.addLine("vanishing space size",
                  "2^" + to_string((int)Log2(instance.vanishingSet().size())));

    vector<PolynomialDegree> inputDegrees(1, PolynomialDegree(1));
    {
        for (uint64_t wIndex = 0; wIndex < instance.neighborPolys().size();
             wIndex++) {
            const PolynomialDegree witnessDeg =
                instance.witnessDegreeBound()[wIndex];
            for (const auto& n : instance.neighborPolys()[wIndex]) {
                inputDegrees.push_back(n->getDegreeBound(witnessDeg));
            }
        }
    }
    specs.addLine("composition degree bound",
                  to_string(PolynomialDegree::integral_t(
                      instance.constraintPoly().getDegreeBound(inputDegrees))));

    specs.print();
}

void printAprInstanceSpec(const AcspInstance& instance) {
    using namespace Ali::details::PCP_common;
    specsPrinter specs("APR Specifications");
    specs.addLine("field size", "2^64");
    specs.addLine("number of algebraic-registers (|\\Tau|)",
                  to_string(instance.witnessDegreeBound().size()));

    uint64_t numNeighbors = 0;
    for (const auto& vn : instance.neighborPolys()) {
        numNeighbors += vn.size();
    }

    specs.addLine("number of neighbors (|N|)", to_string(numNeighbors));
    specs.addLine("witness (f) evaluation space size (|L|)",
                  "2^" + to_string(basisForWitness(instance).basis.size()));
    specs.addLine("constraint (g) evaluation space size (|L_{cmp}|)",
                  "2^" + to_string(basisForConsistency(instance).basis.size()));
    const uint64_t maxDeg = ceil(Log2(PolynomialDegree::integral_t(
        maximalPolyDegSupported_Witness(instance))));
    specs.addLine(
        "witness (f) maximal rate (\\rho_{max})",
        "2^{-" + to_string(basisForWitness(instance).basis.size() - maxDeg) +
            "}");
    const int compDeg = ceil(Log2(PolynomialDegree::integral_t(
        composition_div_ZH_degreeBound(instance))));
    specs.addLine(
        "constraint (g) rate (\\rho_{cmp})",
        "2^{-" +
            to_string(basisForConsistency(instance).basis.size() - compDeg) +
            "}");

    {
        using namespace Ali::details::SoundnessParameters;
        specs.addLine("zero knowledge parameter (k)", "1");
        specs.addLine("rate parameter (R)", to_string(Eta));
        specs.addLine("constraints degree log (d)", to_string(compDeg));
    }

    specs.print();
}

}  // namespace prn

bool executeProtocol(const BairInstance& instance, const BairWitness& witness,
                     const unsigned short securityParameter, bool testBair,
                     bool testAcsp, bool testPCP) {
    const bool noWitness = !(testBair || testAcsp || testPCP);

    prn::printBairInstanceSpec(instance);
    unique_ptr<AcspInstance> acspInstance = CBairToAcsp::reduceInstance(
        instance,
        vector<FieldElement>(instance.constraintsPermutation().numMappings(),
                             one()),
        vector<FieldElement>(instance.constraintsAssignment().numMappings(),
                             one()));

    prn::printAcspInstanceSpec(*acspInstance);
    prn::printAprInstanceSpec(*acspInstance);

    if (testBair) {
        if (!BairWitnessChecker::verify(instance, witness)) {
            return false;
        }
    }

    // Reduce BAIR witness to ACSP witness
    unique_ptr<AcspWitness> acspWitness(nullptr);
    std::cout << noWitness << std::endl;
    if (!noWitness) {
        std::cout << "Constructing APR (ACSP) witness:";
        bool doStatusLoop = true;
        Timer reductionTimer;
        // std::thread barManager([&]() {
        //     std::cout << "START WORKING" << std::endl;
        //     unsigned int sleepInterval = 10;
        //     unsigned int sleepTime = 10;
        //     while (doStatusLoop) {
        //         std::cout << "." << std::flush;
        //         for (unsigned int i = 0; (i < sleepTime) && doStatusLoop; i++) {
        //             std::this_thread::sleep_for(
        //                 std::chrono::milliseconds(sleepInterval));
        //         }
        //         sleepTime *= 2;
        //     }
        // });
        acspWitness = CBairToAcsp::reduceWitness(instance, witness);
        doStatusLoop = false;
        // barManager.join();
        std::cout << "(" << reductionTimer.getElapsed() << " seconds)"
                  << std::endl;

        if (testAcsp) {
            if (!AcspWitnessChecker::verify(*acspInstance, *acspWitness)) {
                return false;
            }
        }
    }

    {
        using namespace Ali::Verifier;
        using namespace Ali::Prover;

        const auto RS_verifier = Biased_verifier;
        verifier_t verifier(instance, RS_verifier, securityParameter);

        if (testPCP) {
            const auto RS_prover = Biased_prover;
            prover_t prover(instance, *acspWitness, RS_prover);
            return Protocols::executeProtocol(prover, verifier, false);
        } else if (noWitness) {
            prover_t* prover_dummy = nullptr;
            return Protocols::executeProtocol(*prover_dummy, verifier, true);
        }
    }

    return true;
}

void simulateProtocol(const BairInstance& instance,
                      const unsigned short securityParameter) {
    BairWitness* witness_dummy = nullptr;
    Protocols::executeProtocol(instance, *witness_dummy, securityParameter,
                               false, false, false);
}

}  // namespace Protocols
}  // namespace libstark
