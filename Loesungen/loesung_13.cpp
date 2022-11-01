// Bestimmt das kleinste gemeinsame Vielfachte (kgv)
// basic file operations
#include <iostream>
#include <random>
#include <algorithm>
#include <array>
#include "library.h"

//#include "version.h"
using namespace std;


int main (int argc, char *argv[]) {
   std::random_device rd;
   auto seed_data = std::array<int, std::mt19937::state_size> {};
   std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
   std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
   auto eng = std::mt19937{ seq };
   auto dist = std::uniform_real_distribution<>{ 0, 1 };

   for (auto j = 0; j < 10; j++)
   {
      std::cout << compute_pi(eng, dist) << std::endl;
   }
}