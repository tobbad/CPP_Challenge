// basic file operations
#include <iostream>
#include <string>
//#include "version.h"
using namespace std;

int main (int argc, char *argv[]) {
  int summe=0;	
  int limite=10+1;
  char *limitc=argv[0];
  limite=stoi(argv[0]);
  if (argc != 1)
  {
	  cout << "ERROR: Expected exactly 1 argument";
  }
  std::cout << "Summe aller durch 3 und 5 teilbahren Zahlen bis zu einer Anwender vorgegeben Limite\n";
  std::cout << "Limite " ;
  std::cin >> limite;
  std::cout << "Summiere bis " << limite << endl;
  for (int i=0;i<limite;i++)
  {
	  if ((i%3)==0 || (i%5)==0)
	  {
		  summe+=i;
	  }
	  std::cout << i << " "<< summe<< std::endl;
	  
  }
  std::cout << "Result is " << summe;
  return 0;
}