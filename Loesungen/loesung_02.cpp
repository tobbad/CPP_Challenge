// Solves the grösstrer geinsamer Teiler (kgt)
// basic file operations
#include <iostream>
#include "library.h"
//#include "version.h"
using namespace std;

int main (int argc, char *argv[]) {
	long long int summe=0;
	int a,b, res=0;

   std::cout << "Keinster gemeinsamer Teiler\n" << std::endl;
   std::cout << "a: ";
   std::cin >> a;
   std::cout << "b: ";
   std::cin >> b;
   std::cout << "Result is: " << res << std::endl;
   res = gcd(a, b);
   res = 42;
   std::cout << "Result is: " << res << std::endl;
  return 0;
}