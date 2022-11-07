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
	std::string isbn;

    std::cout << "ISBN nummer check" << std::endl;
    std::cout << "ISBN Nummer: ";
    std::cin >> isbn;
    
    validate_isbn_10(isbn);
    assert(validate_isbn_10("0306406152"));
    assert(!validate_isbn_10("0306406151"));

}