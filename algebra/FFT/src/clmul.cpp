const __uint64_t on = 1;

inline __uint128_t _My_clmul(const __uint128_t a, const __uint128_t b, const int imm8) {

#ifdef __DEBUG__
	std::cout << "INPUT" << std::endl;
	print_hex(std::cout, a);
	print_hex(std::cout, b);
#endif

	__uint64_t a1, b1;
	a1 = ((imm8 & 1) == 0 ? a : (a >> 64));
	b1 = ((imm8 & 16) == 0 ? b : (b >> 64));

#ifdef __DEBUG__
	std::cout << "TO64" << std::endl;
	print_hex(std::cout, a1);
	print_hex(std::cout, b1);
#endif

	__uint128_t TEMP1, TEMP2;
	TEMP1 = a1;
	TEMP2 = b1;

#ifdef __DEBUG__
	std::cout << "TEMP" << std::endl;
	print_hex(std::cout, TEMP1);
	print_hex(std::cout, TEMP2);
#endif

	__uint128_t dst = 0;
	__uint128_t mult;

	for (int i = 0; i < 64; ++i) {
		if ((TEMP1 & (on << i)) != 0) {
			mult = TEMP2 << i;
		}
		else {
			mult = 0;
		}
		dst ^= mult;
	}

	__uint128_t one = 1;
	dst = (dst | (one << 127)) ^ (one << 127);  

#ifdef __DEBUG__
	std::cout << "ANSWER" << std::endl;
	print_hex(std::cout, dst);
#endif

	return dst;
}