#include <string>
#include <vector>
#include<iterator>
#include <sstream>
#include <algebraLib/FieldElement.hpp>
#include "algorithm"
#include "../../json.hpp"

nlohmann::json ddVecOfVecOfALFEToStr(std::vector<std::vector<Algebra::FieldElement>> Vector);
nlohmann::json ddVecToStr(std::vector<Algebra::FieldElement> Vector);
nlohmann::json ddSetToStr(std::set<unsigned long long> Set);
