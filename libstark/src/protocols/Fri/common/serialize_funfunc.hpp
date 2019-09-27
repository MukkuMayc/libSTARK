#include <string>
#include <vector>
#include<iterator>
#include <sstream>
#include <algebraLib/FieldElement.hpp>

std::string ddVecOfVecOfALFEToStr(std::vector<std::vector<Algebra::FieldElement>> Vector);
std::string ddVecToStr(std::vector<Algebra::FieldElement> Vector);
std::string ddSetToStr(std::set<unsigned long long> Set);
std::string ddALFEToStr (Algebra::FieldElement element);