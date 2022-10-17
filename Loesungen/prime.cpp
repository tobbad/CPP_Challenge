// Bestimmt das kleinste gemeinsame Vielfachte (kgv)
// basic file operations
#include <iostream>
#include "library.h"
//#include "version.h"
using namespace std;


int main (int argc, char *argv[]) {
	int limite;

   std::cout << "Primzahlen bis zu einer Grenze" << std::endl;
   std::cout << "Grenze: ";
   std::cin >> limite;
   for (int i=2;i<limite;i++)
   {
	   if (isPrim(i)) {
	       std::cout << "Primzahl: " << i  <<std::endl;
	   }
   }
  return 0;
}