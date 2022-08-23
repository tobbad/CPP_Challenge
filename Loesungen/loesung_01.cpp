// basic file operations
#include <iostream>
#include "getopt.h"
#include <unistd.h>
#include "version.h"
using namespace std;

int main (int argc, char *argv[]) {
	int c;
	int aflag, bflag, cvalue;
	while ((c = getopt (argc, argv, "abc:")) != -1)
    switch (c) {
      case 'a':
        aflag = 1;
        break;
      case 'b':
        bflag = 1;
        break;
      case 'c':
        cvalue = optarg;
        break;
      case '?':
        if (optopt == 'c')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
	}
	for(int i=obtind; i<argc; i++){     
		std::stdout << argv[i] << std::endl;
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