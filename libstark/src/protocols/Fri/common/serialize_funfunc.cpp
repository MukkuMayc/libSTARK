#include "serialize_funfunc.hpp"



std::string ddSetToStr(std::set<unsigned long long> Set) {
    std::ostringstream stream;
    std::copy(Set.begin(), Set.end(), std::ostream_iterator<unsigned long long>(stream, ","));
    return stream.str();
}

std::string ddVecToStr(std::vector<Algebra::FieldElement> Vector) {
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
std::string ddVecOfVecOfALFEToStr(std::vector<std::vector<Algebra::FieldElement>> Vector) {
    std::string Str = "";
    for (int i=0; i<Vector.size(); i++) {
        Str+= ddVecToStr(Vector[i]);
    }
    return Str;
}

std::string ddALFEToStr (Algebra::FieldElement element) {
    std::ostringstream oss;
    std::ostream_iterator<Algebra::FieldElement>(oss, ",");
    oss << element.asString();
    return oss.str();
}

std::string FFFElemToStr(FFF::Element element) {
    std::string Str ="";
    Str += element.c;

}
std::string FFFcellToStr(FFF::cell_t element) {
    std::string Str = "";
    Str += element.
}