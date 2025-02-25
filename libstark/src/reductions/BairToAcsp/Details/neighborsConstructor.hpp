#ifndef NEIGHBORS_CONSTRUCTOR_HPP__
#define NEIGHBORS_CONSTRUCTOR_HPP__

#include "common.hpp"
#include "instanceMappings.hpp"
#include "constraintSystemsTestLocations.hpp"
#include <algebraLib/LinearPolynomial.hpp>

#include <array>
#include <vector>
#include <map>
#include <memory>

namespace libstark{
namespace BairToAcsp{

class AcspNeighbors{
public:
    typedef uint64_t polynomialIndicator_t;

    AcspNeighbors(const BairInstance& bairInstance,const common& commonDef, const instanceMappings& instanceMapping, const CS_testLocations& testLocations);
    std::vector<std::vector<std::unique_ptr<const Algebra::UnivariatePolynomialInterface> > > getNeighborPolynomials()const;
    uint64_t polynomialsNum()const;

    uint64_t locationOfId(const uint64_t layerId)const;
    uint64_t locationOfTwinLayer(const uint64_t layerId)const;
    uint64_t locationOfDeBruijn(const short dbNeighborId, const short affineCosetId ,const uint64_t layerId)const;
    uint64_t locationOfRoutingBit(const uint64_t layerId)const;
    uint64_t locationOfPermCS(polynomialIndicator_t poly, const uint64_t varId)const;
    bool   existsPermCS(polynomialIndicator_t poly, const uint64_t varId)const;
    uint64_t locationOfAssignmentCS(polynomialIndicator_t poly, const uint64_t varId, const uint64_t neighborVersion)const;
    bool   existsAssignmentCS(polynomialIndicator_t poly, const uint64_t varId)const;

    
private:

    struct NeighborLocation_stc{
        bool exists;
        uint64_t layer;
        uint64_t index;

        NeighborLocation_stc(): exists(false), layer(0), index(0){};
        NeighborLocation_stc(uint64_t index_): exists(true), layer(0), index(index_){};
        NeighborLocation_stc(uint64_t layer_, uint64_t index_): exists(true), layer(layer_), index(index_){};
    };

    struct PolyAndLayer_stc{
        Algebra::LinearPolynomial poly;
        uint64_t layer;

        PolyAndLayer_stc(const Algebra::LinearPolynomial& poly_):poly(poly_), layer(0){};
        PolyAndLayer_stc(const Algebra::LinearPolynomial& poly_, uint64_t layer_):poly(poly_), layer(layer_){};
        PolyAndLayer_stc compose(const Algebra::LinearPolynomial& p_)const{
            return PolyAndLayer_stc(poly.compose(p_),layer);
        }
    };

    //reduction common
    const common& commonDef_;
    const instanceMappings instanceMapping_;
    const CS_testLocations testLocations_;
    
    //usage map of constraint systems polynomials
    const std::map< polynomialIndicator_t, std::vector <bool> > permutationCS_usageVector_;
    const std::map< polynomialIndicator_t, std::vector <bool> > assignmentCS_usageVector_;

    //
    //neighbor polynomials
    //

    std::vector<std::vector<Algebra::LinearPolynomial>> neighbors_;
    std::vector<uint64_t> neighbors_witnessOffsets_;


    /******************************************
    * Neighbors locations
    ******************************************/

    //
    //locations for common neighbors
    //

    // Permutation constraint system neighbors
    std::map<polynomialIndicator_t , std::vector<NeighborLocation_stc>> locationOfPermCS_;
    
    // Assignment constraint system neighbors
    std::map<polynomialIndicator_t , std::vector<std::array<NeighborLocation_stc,2>>> locationOfAssignmentCS_;
    
    //
    //locations for routing network neighbors
    //
    
    // ID polynomial (aka x)
    std::vector<NeighborLocation_stc> locationOfId_;

    // Twin network layer access
    std::vector<NeighborLocation_stc> locationOfTwinLayer_;

    //accessed using the index [layer ID][DeBruijn neighbor][coset ID]
    std::vector<NeighborLocation_stc> locationOfDeBruijn_[2][4];
    
    //accessed using the layer ID
    std::vector<NeighborLocation_stc> locationOfRoutingBit_;

    /********************************************
    * private methods
    *********************************************/

    static std::vector<uint64_t> initOffsets(const std::vector<std::vector<Algebra::LinearPolynomial>>& src);
    struct NeighborLocation_stc addNeighbor(const struct PolyAndLayer_stc& neighbor);
    uint64_t retLocation(const struct NeighborLocation_stc& loc)const;
    void initRoutingNetworkNeighbors();
    Algebra::FieldElement getGenerator()const;
    static std::map<polynomialIndicator_t , std::vector<bool>> getCsUsageVector(const std::vector<std::unique_ptr<Algebra::PolynomialInterface>>& cs, uint64_t varsAmount);

    //neighbors constructors
    static Algebra::LinearPolynomial constructIdNeighbor();
    Algebra::LinearPolynomial constructTwinLayerNeighbor()const;
    void constructId();
    void constructTwinLayer();
    void constructDeBruijn();
    void constructRoutingBitAccess();
    void constructPermCS();
    void constructAssignmentCS();
    
    //neighbors constructor helper functions
    Algebra::LinearPolynomial applyShiftedLinearOperation(const uint64_t layer_id, const Algebra::LinearPolynomial operation)const;
    Algebra::LinearPolynomial constructLinearDeBruijn_N0()const;
    Algebra::LinearPolynomial constructLinearDeBruijn_N1()const;
    Algebra::FieldElement DeBruijn_fixRowIdCarry()const;
    Algebra::FieldElement DeBruijn_fixColumnIdCarry()const;
    Algebra::FieldElement DeBruijn_getFixByCoset(const short cosetId)const;
    PolyAndLayer_stc constructPermCS(const uint64_t nonPermElemId, const uint64_t varId)const;
    PolyAndLayer_stc constructAssignmentCS(const uint64_t nonPermElemId, const uint64_t varId, const bool withCarry)const;
    Algebra::LinearPolynomial moveFromPointToVarId(const Algebra::FieldElement src, const uint64_t varId)const;
    PolyAndLayer_stc moveFromPointToVarId_withLayer(const Algebra::FieldElement src, const uint64_t varId)const;
};


} //namespace BairToAcsp
} //namespace libstark


#endif //#ifdef NEIGHBORS_CONSTRUCTOR_HPP__
