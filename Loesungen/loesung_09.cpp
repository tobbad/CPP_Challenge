// Bestimmt das kleinste gemeinsame Vielfachte (kgv)
// basic file operations
#include <iostream>
#include  <vector>
#include "library.h"

//#include "version.h"
using namespace std;


int main (int argc, char *argv[]) {
	int limite;

   std::cout << "Grösste Primzahl unter gegebener Grenze" << std::endl;
   std::cout << "Grenze: ";
   std::cin >> limite;
   auto res = prime_factors(limite);
   print_vector(res);
   return 0;
}