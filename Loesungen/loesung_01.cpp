// basic file operations
#include <iostream>
#include "getopt.h"
//#include "version.h"
using namespace std;

int main (int argc, char *argv[]) {
	int summe;
	int limite;
    int flags, opt;
   int nsecs, tfnd;

   nsecs = 0;
   tfnd = 0;
   flags = 0;
   while ((opt = getopt(argc, argv, "nt:")) != -1) {
	   switch (opt) {
	   case 'n':
		   flags = 1;
		   break;
	   case 't':
		   nsecs = atoi(optarg);
		   tfnd = 1;
		   break;
	   default: /* '?' */
		   fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",
				   argv[0]);
		   exit(EXIT_FAILURE);
	   }
   }
	for(int i=obtind; i<argc; i++){     
		std::cout << argv[i] << std::endl;
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