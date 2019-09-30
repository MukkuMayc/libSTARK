//
// Created by daniil on 30.09.2019.
//

#include "serialization_fun.h"

std::string VecOfBufferToStr(std::vector<libstark::Protocols::CryptoCommitment::hashDigest_t> Vector) {
    std::string Str = "[";
    if (!Vector.empty()) {
        for (int i = 0; i < Vector.size() - 1; i++) {
            Str += std::string(Vector[i].buffer) + ", ";
        }
        Str+=std::string(Vector[Vector.size() - 1].buffer);
    }
    Str += "]";
    return Str;

};
//commitmentsToSTr
std::string commitmentsToStr(std::vector<libstark::Protocols::CryptoCommitment::hashDigest_t> Vector) {
    return VecOfBufferToStr(Vector);
};
//results.boundary ToStr
std::string results_boundaryPolToStr(std::vector<libstark::Protocols::CryptoCommitment::hashDigest_t> Vector){
    return VecOfBufferToStr(Vector);
};
//results.boundaryPoly ToStr
std::string results_boundaryToStr(std::vector<std::vector<libstark::Protocols::CryptoCommitment::hashDigest_t>> Vector){
    std::string Str = "[";
    if (!Vector.empty()) {
        for (int i = 0; i < Vector.size() - 1; i++) {
            Str += VecOfBufferToStr(Vector[i]) + ", ";
        }
        Str +=VecOfBufferToStr(Vector[Vector.size()-1]);
    }
    Str += "]";
    return Str;
};
//results.ZK_Mask ToStr
std::string results_ZKMToStr(std::vector<std::vector<libstark::Protocols::CryptoCommitment::hashDigest_t>> Vector) {
    return results_boundaryToStr(Vector);
};








std::string VecToStr(std::vector<Algebra::FieldElement> Vector) {
    std::string Str = "[";
    if (!Vector.empty()) {
        for (int i = 0; i < Vector.size() - 1; i++) {
            Str += Vector[i].asString() + ", ";
        }
        Str += Vector[Vector.size() - 1].asString();
    }
    Str += "]";
    return Str;
}

std::string VecOfVecOfALFEToStr(std::vector<std::vector<Algebra::FieldElement>> Vector) {
    std::string Str = "[";
    if (!Vector.empty()) {
        for (int i = 0; i < Vector.size() - 1; i++) {
            Str += VecToStr(Vector[i]) + ", ";
        }

        Str += VecToStr(Vector[Vector.size() - 1]);
    }
    Str += "]";
    return Str;
}
