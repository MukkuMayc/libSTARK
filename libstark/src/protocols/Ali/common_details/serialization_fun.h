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
#include "./../../../../../cbase64.h"
#ifndef LIBSTARK_SERIALIZATION_FUN_H
#define LIBSTARK_SERIALIZATION_FUN_H

nlohmann::json VecOfBufferToStr(std::vector<libstark::Protocols::CryptoCommitment::hashDigest_t> Vector);

nlohmann::json results_boundaryToStr(std::vector<std::vector<libstark::Protocols::CryptoCommitment::hashDigest_t>> Vector);




#endif //LIBSTARK_SERIALIZATION_FUN_H
