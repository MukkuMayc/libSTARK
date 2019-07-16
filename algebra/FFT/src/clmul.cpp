#include <iostream>
#include "simde/x86/ssse3.h"
#include <exception>

// class __Myuint128 {
// 	uint64_t* data;
// public:
// 	__Myuint128(uint64_t* num) {
// 		data = new uint64_t[2];
// 	}

// 	uint64_t* operator&() {
// 		return data;
// 	}

// 	const uint64_t* operator&() const {
// 		return data;
// 	}

// 	__Myint128& operator=(__Myint128& b) {
// 		if (data != nullptr && b.data != nullptr) {
// 			data[0] = b.data[0];
// 			data[1] = b.data[1];
// 		}
// 	}
// }

const uint64_t TWO_POWER_63 = 0x8000000000000000;

//this function use 64-bit numbers for 128-bit careless multiplication
//it returns memory that have to be deleted outside the function!
inline void _My_clmulepi64_si128(const uint64_t* a, const uint64_t* b, const int imm8, uint64_t* dst) {

	uint64_t a64, b64;
	a64 = ((imm8 & 1) == 0 ? a[0] : a[1]);
	b64 = ((imm8 & 16) == 0 ? b[0] : b[1]);

	dst[0] = ((a64 & 1) > 0 ? b64 : 0);
	dst[1] = 0;

	for (uint64_t i = 2, j = TWO_POWER_63; i < TWO_POWER_63; i <<= 1, j >>= 1) {
		if ((a64 & i) > 0) {
			dst[0] ^= b64 % j * i;
			dst[1] ^= b64 / j;
		}
	}

	if ((a64 & TWO_POWER_63) > 0) {
		dst[0] ^= (b64 % 2) * TWO_POWER_63;
		dst[1] ^= b64 / 2;
	}
}