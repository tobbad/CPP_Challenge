// Bestimmt das kleinste gemeinsame Vielfachte (kgv)
// basic file operations
#include <iostream>
#include "library.h"
//#include "version.h"
using namespace std;
	
int main (int argc, char *argv[]) {
	int limite;

   std::cout << "Abzundant number" << std::endl;
   std::cout << "Grenze: ";
   std::cin >> limite;
   print_abundant(limite);
   return 0;
}