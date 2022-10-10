// basic file operations
#include <iostream>
//#include "version.h"
using namespace std;

int main (int argc, char *argv[]) {
		long long int summe=0;
		int limite;

		std::cout << "Summe aller durch 3 und 5 teilbahren Zahlen bis zu einer Anwender vorgegeben Limite\n";
		std::cout << "Limite " ;
		std::cin >> limite;
		std::cout << "Summiere bis " << limite << endl;
		for (int i=0;i<=limite+1;i++)
		{
		if ((i%3)==0 || (i%5)==0)
		{
			summe+=i;
		    std::cout << i << " "<< summe<< std::endl;
		}

	}
	std::cout << "Result is " << summe;
	return 0;
}