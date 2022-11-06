#ifndef LIBRARY_H
#define LIBRARY_H LIBRARY_H
using namespace std;
#include <vector>
#include <random>
#include <algorithm>
#include <array>
#include <functional>
#include <random>

int gcd(int a, int b = 0);
int lcm(int a, int b);
bool isPrim(int limite);
int sum_proper_divisors(int num);
void print_abundant(int limit);
void print_amicables(int limit);
void print_narcissistics(void);
std::vector<unsigned long long> prime_factors(unsigned long long limite);
void print_vector(std::vector<unsigned long long int>);
unsigned int gray_encode(unsigned int const num);
unsigned int gray_decode(unsigned int gray);
std::string to_binary(unsigned int value, unsigned int digits=5);
std::string to_roman(unsigned int number);
std::pair<unsigned long long, long> longest_collatz(unsigned long long limit);
template <  typename E = std::mt19937, typename D = std::uniform_real_distribution<>>double compute_pi(E& engine, D&dist, int samples=1000000){
    auto hit = 0;
    for (auto i=0;i<samples;i++)
    {
        auto x = dist(engine);
        auto y = dist(engine);
        if (y < std::sqrt(1-std::pow(x,2))) hit +=1;
    }
    return 4.0* hit /samples;
}


#endif
