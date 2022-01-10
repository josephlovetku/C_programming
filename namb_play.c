#include "namb.h"

int main()
{
   	int i, opt;	
	system("cls");
	generate(); // generate computers's number
	do {
		guessing(); // get input
		opt = match(input, target); 
	} while (opt == 0);
   	printf("\n");
   	return 0;    
}

