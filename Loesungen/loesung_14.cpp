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
	std::string isbn;

    std::cout << "Grösste Primzahl unter gegebener Grenze" << std::endl;
    std::cout << "Grenze: ";
    std::cin >> isbn;
    
    validate_isbn_10(isbn);
    assert(validate_isbn_10("0306406152"));
    assert(!validate_isbn_10("0306406151"));

}