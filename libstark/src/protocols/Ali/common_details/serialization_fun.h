//
// Created by daniil on 30.09.2019.
//
#include <string>
#include <vector>
#include "common.hpp"
#include "protocols/protocol.hpp"
#include "protocols/common/CryptoCommitment/MerkleCommitment.hpp"
#include "protocols/protocol.hpp"
#include "protocols/common/queries.hpp"
#include "languages/Acsp/AcspInstance.hpp"
#include <algebraLib/FieldElement.hpp>
#include <algebraLib/PolynomialDegree.hpp>
#include <vector>

#ifndef LIBSTARK_SERIALIZATION_FUN_H
#define LIBSTARK_SERIALIZATION_FUN_H

std::string VecOfBufferToStr(std::vector<libstark::Protocols::CryptoCommitment::hashDigest_t> Vector);
std::string commitmentsToStr(std::vector<libstark::Protocols::CryptoCommitment::hashDigest_t> Vector);
std::string results_boundaryToStr(std::vector<std::vector<libstark::Protocols::CryptoCommitment::hashDigest_t>> Vector);
std::string results_boundaryPolToStr(std::vector<libstark::Protocols::CryptoCommitment::hashDigest_t> Vector);
std::string results_ZKMToStr(std::vector<std::vector<libstark::Protocols::CryptoCommitment::hashDigest_t>> Vector);

std::string RS_prover_witness_msgToStr();
std::string RS_prover_composition_msgToStr();
//serialization for RS_prover_witness_msg, RS_prover_composition_msg in libSTARK/libstark/src/protocols/protocol.cpp



#endif //LIBSTARK_SERIALIZATION_FUN_H
