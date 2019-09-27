//
// Created by daniil on 25.09.2019.
//
//#include "../../algebra/algebralib/headers/algebraLib/FieldElement.hpp"

#ifndef LIBSTARK_SERIALIZATION_FUNC_H
#define LIBSTARK_SERIALIZATION_FUNC_H

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include "../../algebra/algebralib/headers/algebraLib/FieldElement.hpp"

//helper func
    std::string VecOfStrToStr(std::vector<std::string> Vector) {
        std::string Str;
        std::for_each(Vector.begin(), Vector.end(), [&](const std::string &piece){ Str += piece; });
        return Str;
    }
std::string VecToStr(std::vector<Algebra::FieldElement> Vector) {
    std::ostringstream oss;

    if (!Vector.empty())
    {
        // Convert all but the last element to avoid a trailing ","
        std::copy(Vector.begin(), Vector.end()-1,
                  std::ostream_iterator<Algebra::FieldElement>(oss, ","));

        // Now add the last element with no delimiter
        oss << Vector.back();
    }
    return oss.str();
}
std::string VecOfVecOfALFEToStr(std::vector<std::vector<Algebra::FieldElement>> Vector) {
    std::string Str = "";
    for (int i=0; i<Vector.size(); i++) {
        Str+= VecToStr(Vector[i]);
    }
    return Str;
}
std::string SetToStr(std::set<unsigned long long> Set) {
    std::ostringstream stream;
    std::copy(Set.begin(), Set.end(), std::ostream_iterator<unsigned long long>(stream, ","));
    return stream.str();
}
std::string VecOfSetOfUintToStr(std::vector<std::set<unsigned long long>> Vector) {
    std::string Str = "";
    for (int i=0; i<Vector.size(); i++) {
        Str+= SetToStr(Vector[i]);
    }
    return Str;

}





#endif //LIBSTARK_SERIALIZATION_FUNC_H