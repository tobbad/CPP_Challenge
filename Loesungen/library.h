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
#include <iostream>
#include <iterator>


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
   constexpr ipv4() :data{ { 0 } } {}
   constexpr ipv4(unsigned char const a, unsigned char const b,
      unsigned char const c, unsigned char const d) :
      data{ { a,b,c,d } } {}
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

   constexpr unsigned long to_ulong() const noexcept
   {
      return
         (static_cast<unsigned long>(data[0]) << 24) |
         (static_cast<unsigned long>(data[1]) << 16) |
         (static_cast<unsigned long>(data[2]) << 8) |
         static_cast<unsigned long>(data[3]);
   }

   std::string to_string() const
   {
      std::stringstream sstr;
      sstr << *this;
      return sstr.str();
   }

   constexpr bool is_loopback() const noexcept
   {
      return (to_ulong() & 0xFF000000) == 0x7F000000;
   }

   constexpr bool is_unspecified() const noexcept
   {
      return to_ulong() == 0;
   }

   constexpr bool is_class_a() const noexcept
   {
      return (to_ulong() & 0x80000000) == 0;
   }

   constexpr bool is_class_b() const noexcept
   {
      return (to_ulong() & 0xC0000000) == 0x80000000;
   }

   constexpr bool is_class_c() const noexcept
   {
      return (to_ulong() & 0xE0000000) == 0xC0000000;
   }

   constexpr bool is_multicast() const noexcept
   {
      return (to_ulong() & 0xF0000000) == 0xE0000000;
   }

   ipv4& operator++()
   {
      *this = ipv4(1 + to_ulong());
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
};
template <class T, size_t R, size_t C>
class array2d
{
   typedef T                 value_type;
   typedef value_type*       iterator;
   typedef value_type const* const_iterator;

   std::vector<T> arr;
public:
   array2d() :arr(R*C) {}
   explicit array2d(std::initializer_list<T> l):arr(l) {}
   constexpr T* data() noexcept { return arr.data(); }
   constexpr T const * data() const noexcept { return arr.data(); }

   constexpr T& at(size_t const r, size_t const c) 
   {
      return arr.at(r*C + c);
   }

   constexpr T const & at(size_t const r, size_t const c) const
   {
      return arr.at(r*C + c);
   }

   constexpr T& operator() (size_t const r, size_t const c)
   {
      return arr[r*C + c];
   }

   constexpr T const & operator() (size_t const r, size_t const c) const
   {
      return arr[r*C + c];
   }

   constexpr bool empty() const noexcept
   {
      return R == 0 || C == 0;
   }

   constexpr size_t size(int const rank) const
   {
      if (rank == 1) return R;
      else if (rank == 2) return C;
      throw std::out_of_range("Rank is out of range!");
   }

   void fill(T const & value)
   {
      std::fill(std::begin(arr), std::end(arr), value);
   }

   void swap(array2d & other) noexcept
   {
      arr.swap(other.arr);
   }

   const_iterator begin() const { return arr.data(); }
   const_iterator end() const { return arr.data() + arr.size(); }
   iterator begin() { return arr.data(); }
   iterator end() { return arr.data() + arr.size(); }
};

template <class T, size_t R, size_t C>
void print_array2d(array2d<T, R, C> const & arr)
{
   for (size_t i = 0; i < R; ++i)
   {
      for (size_t j = 0; j < C; ++j)
      {
         std::cout << arr.at(i, j) << ' ';
      }

      std::cout << std::endl;
   }
}
unsigned int factorial(unsigned int n);
unsigned int binomial_koeffizent(unsigned int  n, unsigned int k);
unsigned int num_of_digits(unsigned int nr);
std::string einruecken(uint32_t cnt);
std::string pascal_dreieck(int32_t count_of_lines);

#endif
