// Solves the grösstrer geinsamer Teiler (kgt)
// basic file operations
#include <iostream>
//#include "version.h"
using namespace std;

int gcd(int a, int b=0) {
	std::cout << "a: " << a << " b: " << b << std::endl;
	if (b == 0) {
		//std::cout << "\tReturn \'" << a << "\'" <<std::endl;
		return a;
	} else {
		//std::cout << "\tReturn \'" << a % b << "\'" << std::endl;
		return gcd(b, a % b);
	}
}

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