#ifndef LIBRARY_H
#define LIBRARY_H LIBRARY_H
#include <vector>
int gcd(int a, int b = 0);
int lcm(int a, int b);
bool isPrim(int limite);
int sum_proper_divisors(int num);
void print_abundant(int limit);
void print_amicables(int limit);
void print_narcissistics1(void);
std::vector<unsigned long long> prime_factors(unsigned long long limite);
void print_vector(std::vector<unsigned long long int>);
unsigned int gray_encode(unsigned int const num);
unsigned int gray_decode(unsigned int gray);
std::string to_binary(unsigned int value, unsigned int digits=5);
#endif