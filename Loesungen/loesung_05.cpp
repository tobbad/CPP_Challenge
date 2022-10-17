// Bestimmt das kleinste gemeinsame Vielfachte (kgv)
// basic file operations
#include <iostream>
#include "library.h"
//#include "version.h"
using namespace std;


int main (int argc, char *argv[]) {
	int limite;

   std::cout << "Sexy Primzahlen mit 6 dazwischen" << std::endl;
   std::cout << "Grenze: ";
   std::cin >> limite;
   for (int i=1;i<limite;i++)
   {
	   if (isPrim(i) && isPrim(i+6)) {
	       std::cout << i <<  " ; " << i+6 <<std::endl;
	   }
   }
  return 0;
}