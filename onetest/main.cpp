#include <algebraLib/FFT.hpp>
#include <algebraLib/novelFFT.hpp>
#include <algebraLib/SubspacePolynomial.hpp>
#include <iostream>


using Algebra::FieldElement;
using Algebra::zero;
using Algebra::elementsSet_t;
using Algebra::generateRandom;
using Algebra::getStandartBasis;
using Algebra::IFFT;
using std::vector;

// FieldElement getElementFromOrderedBasis(const vector<FieldElement>& orderedBasis, uint64_t elementIndex){
//     FieldElement res = zero();
//     for(const auto& b: orderedBasis){
//         if (elementIndex%2 == 1) res+=b;
//         elementIndex>>=1;
//     }

//     return res;
// }

// FieldElement HornerEvaluation(const vector<FieldElement>& poly, const FieldElement x){
//     FieldElement res = zero();

//     for(long i = poly.size()-1; i>=0 ; i--){
//         res = (res*x) + poly[i];
//     }

//     return res;
// }


// void TEST(){
//     using Algebra::novelFFT;

//     // const unsigned short basisSize = 10;
//     const unsigned short basisSize = 5;
//     const uint64_t polyDeg = (1<<basisSize);
    
//     //construct the basis (just the standart basis)
//     elementsSet_t basisUnordered = getStandartBasis(basisSize);
//     vector<FieldElement> orderedBasis;
//     for(const auto& b : basisUnordered) orderedBasis.push_back(b);
//     const FieldElement shift = generateRandom();

	
// 	std::cout << "orderedBasis: " << std::endl;
// 	for(auto i: orderedBasis) {
// 		std::cout << i << std::endl;
// 	}

// 	std::cout << "shift: " << shift << std::endl;

//     //construct the evaluation
//     vector<FieldElement> polyCoeffs(polyDeg);
// // #pragma omp parallel for 
//     for(uint64_t i=0; i < polyDeg; i++){
//         polyCoeffs[i] = generateRandom();
//     }

//     std::cout << "polyCoeffs: " << std::endl;
//     for (auto i: polyCoeffs) {
//     	std::cout << i << std::endl;
//     }

//     //compute the FFT
//     vector<FieldElement> vals(1<<basisSize);
//     {
//         vector<vector<FieldElement>> polyCoeffs_multiple(1,polyCoeffs);
//         novelFFT FFT_obj(orderedBasis,std::move(polyCoeffs_multiple),1,Algebra::zero());
//         FFT_obj.FFT({shift},&vals[0],0);
//     }

//     std::cout << "val: \n" << vals[0] << std::endl;

//     //Test result
//     // for(uint64_t i=0; (i>>basisSize)==0; i++){
//     	uint64_t i = 0;
//         const FieldElement x = shift + getElementFromOrderedBasis(orderedBasis, i);
//         const FieldElement y = HornerEvaluation(polyCoeffs,x);
//         // EXPECT_EQ(vals[i],y);
//         std::cout << vals[i] << std::endl;
//         std::cout << y << std::endl;
//         assert(vals[i] == y);
//     // }
// }

int main() {
	FieldElement a, b;
	std::cout << a << std::endl;
	std::cout << generateRandom() << std::endl;
	return 0;
}