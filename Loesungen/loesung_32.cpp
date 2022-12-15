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
   int count_of_lines;

   std::cout << "Pascal dreieck" << std::endl;
   
   std::cout << "Anzahl linien: ";
   std::cin >> count_of_lines;
   std::string res = pascal_dreieck(count_of_lines);
   std::cout << res << std::endl; 
}
