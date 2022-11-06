// Bestimmt das kleinste gemeinsame Vielfachte (kgv)
// basic file operations
#include <iostream>
#include "library.h"
//#include "version.h"
using namespace std;


int main (int argc, char *argv[]) {
	int limite=0;

   std::cout << "Grösste Primzahl unter gegebener Grenze" << std::endl;
   std::cout << "Grenze: ";
   std::cin >> limite;
   for (int i=limite;i>0;i--)
   {
	   if (isPrim(i)) {
	       std::cout << "Result is: " << i << std::endl;
		   return 0;
	   }
   }
  return 0;
}
