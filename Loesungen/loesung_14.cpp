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
    
    printf("Given ISBN: %d\n",validate_isbn_10(isbn));
    printf("Good ISBN: %d\n",validate_isbn_10("0306406152"));
    printf("Bad  ISBN: %d\n",validate_isbn_10("0306406151"));

}