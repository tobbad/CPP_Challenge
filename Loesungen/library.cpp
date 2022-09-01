#include <iostream>
#include "library.h"
using namespace std;



int gcd(int a, int b) {
	std::cout << "a: " << a << " b: " << b << std::endl;
	if (b == 0) {
		//std::cout << "\tReturn \'" << a << "\'" <<std::endl;
		return a;
	}
	else {
		//std::cout << "\tReturn \'" << a % b << "\'" << std::endl;
		return gcd(b, a % b);
	}
}

int  lcm(int a, int b)
{
	int h = gcd(a, b);
	return h ? (a * (b / h)) : 0;
}

