//
// Created by daniil on 30.09.2019.
//

#include "serialization_fun.h"

nlohmann::json VecOfBufferToStr(std::vector<libstark::Protocols::CryptoCommitment::hashDigest_t> Vector) {
    nlohmann::json Str = nlohmann::json::array();

    if (!Vector.empty()) {
        for (int i = 0; i < Vector.size(); i++) {
            Str.push_back(nlohmann::json::parse(Vector[i].toString()));
        }
    }

    return Str;

};

//results.boundaryPoly ToStr
nlohmann::json results_boundaryToStr(std::vector<std::vector<libstark::Protocols::CryptoCommitment::hashDigest_t>> Vector){
    nlohmann::json Str = nlohmann::json::array();
    if (!Vector.empty()) {
        for (int i = 0; i < Vector.size(); i++) {
            Str.push_back(VecOfBufferToStr(Vector[i]));
        };
    }
    return Str;
};