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
    ipv4 address(128,192,1,0);
    std::cout << address << std::endl;
    
    ipv4 ip;
    std::cin >>ip;
    if (!cin.fail()){
        std::cout << ip <<std::endl;
    }
        
    
    
}