#ifndef LIBRARY_H
#define LIBRARY_H LIBRARY_H
using namespace std;
#include <vector>
#include <random>
#include <algorithm>
#include <array>
#include <functional>
#include <random>
#include <sstream>


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

bool validate_isbn_10(std::string isbn); 

class ipv4
{
   std::array<unsigned char, 4> data;
public:
   constexpr ipv4() :data{ {0} } {}
   constexpr ipv4(unsigned char const a, unsigned char const b, 
                  unsigned char const c, unsigned char const d):
      data{{a,b,c,d}} {}
   explicit constexpr ipv4(unsigned long a) :
      data{ { static_cast<unsigned char>((a >> 24) & 0xFF), 
              static_cast<unsigned char>((a >> 16) & 0xFF),
              static_cast<unsigned char>((a >> 8) & 0xFF),
              static_cast<unsigned char>(a & 0xFF) } } {}
   ipv4(ipv4 const & other) noexcept : data(other.data) {}
   ipv4& operator=(ipv4 const & other) noexcept 
   {
      data = other.data;
      return *this;
   }

   std::string to_string() const
   {
      std::stringstream sstr;
      sstr << *this;
      return sstr.str();
   } 

   constexpr unsigned long to_ulong() const noexcept
   {
      return
         (static_cast<unsigned long>(data[0]) << 24) |
         (static_cast<unsigned long>(data[1]) << 16) |
         (static_cast<unsigned long>(data[2]) << 8) |
         static_cast<unsigned long>(data[3]);
   }

   friend std::ostream& operator<<(std::ostream& os, const ipv4& a)
   {
      os << static_cast<int>(a.data[0]) << '.' 
         << static_cast<int>(a.data[1]) << '.'
         << static_cast<int>(a.data[2]) << '.'
         << static_cast<int>(a.data[3]);
      return os;
   }

   friend std::istream& operator>>(std::istream& is, ipv4& a)
   {
      char d1, d2, d3;
      int b1, b2, b3, b4;
      is >> b1 >> d1 >> b2 >> d2 >> b3 >> d3 >> b4;
      if (d1 == '.' && d2 == '.' && d3 == '.')
         a = ipv4(b1, b2, b3, b4);
      else
         is.setstate(std::ios_base::failbit);

      return is;
   }
   
   ipv4& operator++()
   {
       *this = ipv4(1+ to_ulong());
       return *this;
   }   
   
   ipv4& operator++(int)
   {
      ipv4 result(*this);
      ++(*this);
      return *this;
   }

   friend bool operator==(ipv4 const & a1, ipv4 const & a2) noexcept
   {
      return a1.data == a2.data;
   }

   friend bool operator!=(ipv4 const & a1, ipv4 const & a2) noexcept
   {
      return !(a1 == a2);
   }

   friend bool operator<(ipv4 const & a1, ipv4 const & a2) noexcept
   {
      return a1.to_ulong() < a2.to_ulong();
   }

   friend bool operator>(ipv4 const & a1, ipv4 const & a2) noexcept
   {
      return a2 < a1;
   }

   friend bool operator<=(ipv4 const & a1, ipv4 const & a2) noexcept
   {
      return !(a1 > a2);
   }

   friend bool operator>=(ipv4 const & a1, ipv4 const & a2) noexcept
   {
      return !(a1 < a2);
   }
   
   
   
};
#endif
