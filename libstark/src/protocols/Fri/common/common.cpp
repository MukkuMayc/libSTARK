#include "common.hpp"
#include <algebraLib/SubspacePolynomial.hpp>
#include "serialize_funfunc.hpp"
#include "../../Ali/common_details/serialization_fun.h"

namespace libstark{
namespace Protocols{
namespace Fri{
namespace common{

using std::vector;
using Algebra::FieldElement;
using Algebra::zero;
using Algebra::elementsSet_t;
using Algebra::SubspacePolynomial;
;

vector<FieldElement> getL0Basis(const vector<FieldElement>& BasisL, const bool L0isMSB){
	if(L0isMSB){
        return vector<FieldElement>(BasisL.end() - SoundnessParameters::dimReduction, BasisL.end());
    }
    
    return vector<FieldElement>(BasisL.begin(), BasisL.begin() + SoundnessParameters::dimReduction);
}

vector<FieldElement> getL1Basis(const vector<FieldElement>& BasisL, const bool L0isMSB){
	if(L0isMSB){
        return vector<FieldElement>(BasisL.begin(), BasisL.end() - SoundnessParameters::dimReduction);
    }
    return vector<FieldElement>(BasisL.begin() + SoundnessParameters::dimReduction, BasisL.end());
}

uint64_t getBasisLIndex_byL0L1indices(const vector<FieldElement>& BasisL, const uint64_t idxL0, const uint64_t idxL1, const bool L0isMSB){
	if(L0isMSB){
        const uint64_t BasisL1_size = BasisL.size() - SoundnessParameters::dimReduction;
        return idxL1 | (idxL0<<BasisL1_size);
    }
    
    return idxL0 | (idxL1<<SoundnessParameters::dimReduction);
}

vector<FieldElement> getColumnBasis(const vector<FieldElement>& L, const bool L0isMSB){
    const vector<FieldElement> L0Basis = getL0Basis(L, L0isMSB);
    const elementsSet_t rowsBasis(L0Basis.begin(), L0Basis.end());
    
    vector<FieldElement> basisForColumn(getL1Basis(L, L0isMSB));
    {
        const SubspacePolynomial q(rowsBasis);
        const FieldElement q_on_ZERO = q.eval(zero());
        for(FieldElement& e : basisForColumn){
            e = q.eval(e + q_on_ZERO);
        }
    }

    return basisForColumn;
}
    template<typename T>
    nlohmann::json state_t<T>::serialize() {
    nlohmann::json data = {
            {"localState", ddSetToStr(localState)}
    };
    std::for_each(subproofs.begin(), subproofs.end(), [&data] (std::pair<const Algebra::FieldElement, libstark::Protocols::Fri::common::state_t<rawQuery_t>> &element) {
    nlohmann::json tmp{
            {"first", nlohmann::json::parse(element.first.asString())},
            {"second", element.second.serialize()}
    };

    data["subproofs"].push_back(tmp);
});
    return data;
};

    template<typename T>
    nlohmann::json state_t<T>::serialize1() {
        nlohmann::json data = {
                {"localState", VecOfBufferToStr(localState)}
        };
        std::for_each(subproofs.begin(), subproofs.end(), [&data] (std::pair<const Algebra::FieldElement, libstark::Protocols::Fri::common::state_t<rawResult_t>> &element) {
            nlohmann::json tmp{
                    {"first", nlohmann::json::parse(element.first.asString())},
                    {"second", element.second.serialize1()}
            };

            data["subproofs"].push_back(tmp);
        });
        return data;
    };

nlohmann::json verifierRequest_t::serialization1() {
    nlohmann::json result = {
            {"proofConstructionQueries", ddVecOfVecOfALFEToStr(proofConstructionQueries)},
            {"dataQueries", dataQueries.serialize()}
    };
    return result;
};

nlohmann::json proverResponce_t::serialization1() {
    nlohmann::json result = {
            {"proofConstructionComitments", VecOfBufferToStr(proofConstructionComitments)},
            {"dataResults", dataResults.serialize1()}
    };
    return result;
};


unsigned short dimOfColumn(const unsigned short dimOfL){
    return dimOfL - SoundnessParameters::dimReduction;
}

} //namespace common
} //nmasepace Fri
} //namespace Protocols
} //namespace libstark
