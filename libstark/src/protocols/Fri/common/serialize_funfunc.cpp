#include "serialize_funfunc.hpp"


nlohmann::json  ddSetToStr(std::set<unsigned long long> Set) {
    nlohmann::json Str = nlohmann::json::array();
    if (!Set.empty()) {
        std::for_each(Set.begin(), Set.end(), [&Str] (const unsigned long long &x) {

            Str.push_back(std::to_string(x));
        });
    }
    return Str;
}

nlohmann::json ddVecToStr(std::vector<Algebra::FieldElement> Vector) {

    nlohmann::json Str = nlohmann::json::array();
//        std::string Str = "[";
    if (!Vector.empty()) {
        for (int i = 0; i < Vector.size(); i++) {
            Str.push_back(nlohmann::json::parse(Vector[i].asString()));
        }
    }
//        Str += "]";
    return Str;
}
nlohmann::json ddVecOfVecOfALFEToStr(std::vector<std::vector<Algebra::FieldElement>> Vector) {
    nlohmann::json Str = nlohmann::json::array();
    if (!Vector.empty()) {
        for (int i = 0; i < Vector.size(); i++) {
            Str.push_back(ddVecToStr(Vector[i]));
        };
    }
    return Str;
}

