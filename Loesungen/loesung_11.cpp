// Bestimmt das kleinste gemeinsame Vielfachte (kgv)
// basic file operations
#include <iostream>
#include  <vector>
#include "library.h"

//#include "version.h"
using namespace std;


int main (int argc, char *argv[]) {
	int number;
    std::cout << "Zahl: ";
    std::cin >> number;
	auto res = to_roman(number);
	printf("%s", res);	
    return 0;
}