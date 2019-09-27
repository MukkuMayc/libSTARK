#include <iostream>

int main() {
	typedef long long unsigned int cell_t;
	static const unsigned int log_bits_in_byte = 3;
	static const unsigned int bits_in_byte = 1<<log_bits_in_byte;
	static const unsigned int log_ord = 6;
	static const unsigned int ord = 1<<log_ord;
	static const unsigned int log_bits_in_cell =6;
	static const unsigned int bits_in_cell = 1<<log_bits_in_cell;
	static const unsigned int element_len = (ord>>log_bits_in_byte)/sizeof(cell_t);
 	std::cout<<element_len<<std::endl;
 	return 0;
}