#include <iostream>
#include "library.h"
using namespace std;



int gcd(int a, int b) 
{
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


int isPrim(int limite)
{
	bool isPrim=false;
	if ((limite==1) || (limite==2))
		return false;
	else if ((limite%2==0) || (limite%3 ==0)) 
		return false;
	else
	{
		for (int i=5;i*i<limite;i+=6)
		{
			if (limite%i==0)
			{
				return false;
			}		
		}
		return true;
	}
}