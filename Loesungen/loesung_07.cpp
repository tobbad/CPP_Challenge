// Bestimmt das kleinste gemeinsame Vielfachte (kgv)
// basic file operations
#include <iostream>
#include "library.h"
//#include "version.h"
using namespace std;
	
int main (int argc, char *argv[]) {
	int limite;

   std::cout << "Frendly numbers" << std::endl;
   std::cout << "Grenze: ";
   std::cin >> limite;
   print_amicables(limite);
   return 0;
}