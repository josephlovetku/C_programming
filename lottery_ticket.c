#include <stdio.h>

#define LENGTH 6
#define LOTTERY 49

int lotteryTicket[100*LENGTH];
int lotteryArray[LOTTERY+1]; // like a dictionary

int main()
{
	int i = 0, j = 0;
	int count = 0;
	int number = 0;
	
	for (i=0; i<LOTTERY; i++) { // initialize the counts of each lottery number
		lotteryArray[i] = 0;
	}
	
	while ((scanf("%d", &number)) != EOF) { // read the input lottery numbers from the ticket
		if (number < 50 && number > 0) {		
			lotteryTicket[count] = number; // DO NOT USE i index except you reset i to be 0
			count++;
		}
	}
	// print lottery tickets in the ascending order
	for (i=0; i<count; i++) { 
		lotteryArray[lotteryTicket[i]] += 1;
		if (i%6 == 5) { // now we reach the end of a row
			for (j=1; j<=LOTTERY; j++) {
				if (lotteryArray[j] > 0) {
					printf("%d ", j);
				}
				lotteryArray[j] = 0;
			}
			printf("\n");
		}
	}

	return 0;
} 

