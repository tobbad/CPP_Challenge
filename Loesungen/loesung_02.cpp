// Solves the grösstrer geinsamer Teiler (kgt)
// basic file operations
#include <iostream>
//#include "version.h"
using namespace std;

int gcd(int a, int b=0) {
	std::cout << "a: " << a << " b: " << b << std::endl;
	if (b == 0) {
		std::cout << "\tReturn \'" << a << "\'" <<std::endl;
		return gcd(a);
	} else {
		std::cout << "\tReturn \'" << a % b << "\'" << std::endl;
		return gcd(b, a % b);
	}
}

int main (int argc, char *argv[]) {
	long long int summe=0;
	int a,b, res=0;

   std::cout << "Keinster gemeinsamer Teiler\n";
   std::cout << "a: ";
   std::cin >> a;
   std::cout << "b: ";
   std::cin >> b;
   res = gcd(a, b);
   std::cout << "Result is: " << res;


  return 0;
}