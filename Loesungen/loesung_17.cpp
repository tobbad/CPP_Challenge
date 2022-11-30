// Bestimmt das kleinste gemeinsame Vielfachte (kgv)
// basic file operations
#include <iostream>
#include <random>
#include <algorithm>
#include <array>
#include <cassert>
#include <string>
#include "library.h"


//#include "version.h"
using namespace std;


int main (int argc, char *argv[]) {
   {
      std::cout << "test fill" << std::endl;

      array2d<int, 2, 3> a;
      a.fill(1);

      print_array2d(a);
   }

   {
      std::cout << "test operator()" << std::endl;
      array2d<int, 2, 3> a;

      for (size_t i = 0; i < a.size(1); ++i)
      {
         for (size_t j = 0; j < a.size(2); ++j)
         {
            a(i, j) = 1 + i * 3 + j;
         }
      }

      print_array2d(a);
   }

   {
      std::cout << "test move semantics" << std::endl;

      array2d<int, 2, 3> a{10,20,30,40,50,60};
      print_array2d(a);

      array2d<int, 2, 3> b(std::move(a));
      print_array2d(b);
   }

   {
      std::cout << "test swap" << std::endl;

      array2d<int, 2, 3> a { 1,2,3,4,5,6 };
      array2d<int, 2, 3> b { 10,20,30,40,50,60 };

      print_array2d(a);
      print_array2d(b);

      a.swap(b);

      print_array2d(a);
      print_array2d(b);
   }

   {
      std::cout << "test capacity" << std::endl;

      array2d<int, 2, 3> const a { 1,2,3,4,5,6 };

      for (size_t i = 0; i < a.size(1); ++i)
      {
         for (size_t j = 0; j < a.size(2); ++j)
         {
            std::cout << a(i, j) << ' ';
         }

         std::cout << std::endl;
      }
   }

   {
      std::cout << "test iterators" << std::endl;

      array2d<int, 2, 3> const a{ 1,2,3,4,5,6 };
      for (auto const e : a)
      {
         std::cout << e << ' ';
      }
      std::cout << std::endl;

      std::copy(
         std::begin(a), std::end(a), 
         std::ostream_iterator<int>(std::cout, " "));

      std::cout << std::endl;
   }
}
