// Bestimmt das kleinste gemeinsame Vielfachte (kgv)
// basic file operations
#include <iostream>
#include "library.h"
//#include "version.h"
using namespace std;


int main (int argc, char *argv[]) {
	int a,b, res=0;

   std::cout << "Keinster gemeinsamer Vielfaches\n" << std::endl;
   std::cout << "a: ";
   std::cin >> a;
   std::cout << "b: ";
   std::cin >> b;
   std::cout << "Result is: " << res << std::endl;
   res = lcm(a, b);
   std::cout << "Result is: " << res << std::endl;
  return 0;
}
