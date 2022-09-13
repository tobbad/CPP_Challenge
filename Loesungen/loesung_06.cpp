// Bestimmt das kleinste gemeinsame Vielfachte (kgv)
// basic file operations
#include <iostream>
#include "library.h"
//#include "version.h"
using namespace std;


void print_abundant(int limit){
	for (int number=10;number<=limit;number++)
	{
		auto sum = sum_proper_divisors(number);
		if (sum>number){
			std::cout <<number << ", Abundance " << sum-number << std::endl;
		}
	}
	return;
}
	
	
int main (int argc, char *argv[]) {
	int limite;

   std::cout << "Abzundant number" << std::endl;
   std::cout << "Grenze: ";
   std::cin >> limite;
   print_abundant(limite);
   return 0;
}