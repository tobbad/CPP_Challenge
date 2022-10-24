// Bestimmt das kleinste gemeinsame Vielfachte (kgv)
// basic file operations
#include <iostream>
#include  <vector>
#include "library.h"

//#include "version.h"
using namespace std;


int main (int argc, char *argv[]) {
	std::cout << "Number\tBinary\tGray\tDecoded" << std::endl;
	std::cout << "------\t------\t----\t-------" << std::endl;
	for (unsigned int n=0;n<32;++n)
	{
		auto encg = gray_encode(i);
		auto decg = gray_decode(encg);
		std::cout << i  << "\t" << to_binary(i) << "\t" << to_binary(encg) << "\t" << decg << std::endl;
	}
		
    return 0;
}