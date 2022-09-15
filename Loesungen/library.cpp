#include <iostream>
#include <math.h>
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


bool isPrim(int limite)
{
	if ((limite==1) || (limite==2))
		return (limite>1);
	else
	{
		int upLim=floor(sqrt(limite));
		for (int i=2;i<upLim;i++)
		{
			if (limite%i==0)
			{
				return false;
			}		
		}
		return true;
	}
	return false;
}

int sum_proper_divisors(int num){
	int result=1;
	for (int i=2;i<std::sqrt(num);i++){
		if (num%i==0)
		{
			result+=(i==(num%i)?i:(i+num/i));
		}
	}
	//std::cout << num << " Sum " << result<< std::endl;
	return result;
}

void print_abundant(int limit){
	for (int number=10;number<=limit;number++)
	{
		auto sum = sum_proper_divisors(number);
		if (sum>number){
			std::cout <<number << ", Abundance " << sum-number << std::endl;
		}
	}
	return;
}

void print_amicables(int limit){
	for (int number=4;number<=limit;number++)
	{
		auto sum1 = sum_proper_divisors(number);
		if (sum1 < limit)
		{
			auto sum2 = sum_proper_divisors(sum1);
			if ((sum2==number) && (number!=sum1))
			{
				std::cout << number << "," << sum1 << std::endl;
			}
		}
	}
	return;
}
