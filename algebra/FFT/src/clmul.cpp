#ifdef __DEBUG__
#include "_Utilities.cpp"
#endif

const uint64_t TWO_POWER_63 = 0x8000000000000000;

//this function use 64-bit numbers for 128-bit careless multiplication
//it returns memory that have to be deleted outside the function!
inline uint64_t* _My_clmul(const uint64_t* a, const uint64_t* b, const int imm8) {

#ifdef __DEBUG__
	std::cout << "INPUT" << std::endl;
	print_hex(std::cout, a);
	print_hex(std::cout, b);
#endif

	uint64_t a64, b64;
	// a1 = ((imm8 & 1) == 0 ? a : (a >> 64));
	// b1 = ((imm8 & 16) == 0 ? b : (b >> 64));
	a64 = ((imm8 & 1) == 0 ? a[0] : a[1]);
	b64 = ((imm8 & 16) == 0 ? b[0] : b[1]);

#ifdef __DEBUG__
	std::cout << "TO64" << std::endl;
	print_hex(std::cout, a1);
	print_hex(std::cout, b1);
#endif

	// __uint128_t TEMP1, TEMP2;
	// TEMP1 = a1;
	// TEMP2 = b1;
	// uint64_t TEMP1, TEMP2;
	// TEMP1 = a1;
	// TEMP2 = b1;

#ifdef __DEBUG__
	std::cout << "TEMP" << std::endl;
	print_hex(std::cout, TEMP1);
	print_hex(std::cout, TEMP2);
#endif

	// __uint128_t dst = 0;
	// __uint128_t mult;
	uint64_t* dst = new uint64_t[2];
	uint64_t* mult = new uint64_t[2];
	dst[0] = dst[1] = 0;

	// for (int i = 0; i < 64; ++i) {
	// 	if ((TEMP1 & (on << i)) != 0) {
	// 		mult = TEMP2 << i;
	// 	}
	// 	else {
	// 		mult = 0;
	// 	}
	// 	dst ^= mult;
	// }
	
	if ((a64 & 1) > 0) {
		dst[0] = b64;
	}
	for (uint64_t i = 2, j = TWO_POWER_63 >> 1; i < TWO_POWER_63; i <<= 1, j >>= 1) {
		if ((a64 & i) > 0) {
			// uint64_t mult_less = b64 % (j << 1) * i;
			// uint64_t mult_ge = b64 / (j << 1);
			dst[0] ^= b64 % (j << 1) * i;
			dst[1] ^= b64 / (j << 1);
		}
	}
	if ((a64 & TWO_POWER_63) > 0) {
		// uint64_t mult_less = (b64 % 2) * (TWO_POWER_63);
		// uint64_t mult_ge = b64 / 2;
		dst[0] ^= (b64 % 2) * (TWO_POWER_63);
		dst[1] ^= b64 / 2;
	}

	// uint64_t one = 1;
	// dst = (dst | (one << 127)) ^ (one << 127);

	// dst[1] %= TWO_POWER_63;

#ifdef __DEBUG__
	std::cout << "ANSWER" << std::endl;
	print_hex(std::cout, dst);
#endif

	delete[] mult;
	return dst;
}