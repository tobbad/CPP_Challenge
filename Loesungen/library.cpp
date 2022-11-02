#include "library.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <bitset>
#include <functional>
#include <random>
#include <algorithm>
#include <array>



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
    if (limite<=3)
        return (limite>1);
    else if ((limite%2==0)||(limite%3==0)){
        return false;
    }
    else
    {
        int upLim=floor(sqrt(limite))+1;
        for (int i=2;i<upLim;i++)
        {
            if (limite%i==0)
            {
                return false;
            }       
        }
    }
    return true;
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

void print_narcissistics1(void)
{
    for (int i=1;i<=9;i++)
    {
        for (int j=1;j<=9;j++)
        {
            for (int k=1;k<=9;k++)
            {
                auto abc =100*i+10*j+k;
                auto arm = i*i*i+j*j*j+k*k*k;
                if (abc==arm)
                {
                    std::cout << arm << std::endl;
                }
            }
        }
        //std::cout << i << std::endl;
    }
}

std::vector<unsigned long long> prime_factors(unsigned long long number)
{
    std::vector<unsigned long long> factors;
    while (number%2==0) {
        factors.push_back(2);
        number /= 2;
    }
        
    for (unsigned long long i=3;i<=std::sqrt(number); i++)
    {
        while (number%i==0){
            factors.push_back(i);
            number /= i;
        }
    }
    if (number>2){
        factors.push_back(number);
    }

    return factors;
}

void print_vector(std::vector<unsigned long long int> vector)
{
    std::cout << "[ ";
    for (auto i:vector){
        std::cout << i << ", ";
    }
    std::cout << "]" << std::endl;
}

unsigned int gray_encode(unsigned int const num)
{
    return num ^ (num>>1);
}

unsigned int gray_decode(unsigned int gray)
{
    for (unsigned int bit=1<<31;bit>1;bit>>=1)
    {
        if (gray & bit) gray ^= bit>>1;
    }
    return gray;
}

std::string to_binary(unsigned int value, unsigned int digits)
{
    return std::bitset<32>(value).to_string().substr(32- digits, digits);
}

std::string to_roman(unsigned int number)
{
    std::vector<std::pair<unsigned int, char const*>> roman
    {
        { 1000, "M" },{ 900, "CM" },
        { 500, "D" },{ 400, "CD" },
        { 100, "C" },{ 90, "XC" },
        { 50, "L" },{ 40, "XL" },
        { 10, "X" },{ 9, "IX" },
        { 5, "V" },{ 4, "IV" },
        { 1, "I" }
    };
    printf("Enter\n");  
   std::string result;
   for (auto const & kvp : roman)
   {
      while (number >= kvp.first)
      {
         result += kvp.second;
         number -= kvp.first;
      }
   }

   return result;
}

std::pair<unsigned long long, long> longest_collatz(unsigned long long limit)
{
    long length = 0;
    unsigned long long number =0;

    std::vector<int> cache(limit+1,0);

    for (unsigned long long i=2;i<= limit; i++)
    {
        auto n = i;
        long steps = 0;
        while (n != 1 && n >= i)
        {
            if ((n % 2) == 0) n = n / 2;
            else n = n * 3 + 1;
            steps++;
        }
        cache[i] = steps + cache[n];
        
        if (cache[i] > length)
        {
            length = cache[i];
            number = i;
        }
    }
    return std::make_pair(number, length);
}

template <
   typename E = std::mt19937, 
   typename D = std::uniform_real_distribution<>>
double compute_pi(E& engine, D&dist, int samples)
{
    auto hit = 0;
    for (auto i=0;i<samples;i++)
    {
        auto x = dist(engine);
        auto y = dist(engine);
        if (y < std::sqrt(1-std::pow(x,2))) hit +=1;
    }
    return 4.0* hit /samples;
}