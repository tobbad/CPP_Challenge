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
	auto res = longest_collatz(number);
	std:: cout <<  res.first << " " << res.second << std::endl;	
    return 0;
}