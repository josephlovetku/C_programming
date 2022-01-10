#include "namb.h"

void generate()
{
    int i, j, num, again;
    int check_validity(int mat[]);
    
    srand((unsigned)time(NULL));
    
    do {
        target[0] = rand()%10;
        target[1] = rand()%10;
        target[2] = rand()%10;
        target[3] = rand()%10;
    } while (check_repeat(target));
}

int check_repeat(int numArray[])
{
	int i, j;
	for (i=0; i<4; i++) {
		for (j=i+1; j<4; j++) {
			if (numArray[i] == numArray[j]) {
				return 1; 
			}
                }
    	}
	return 0;
}

void guessing()
{
	int n;
	printf("Please input your sequence: ");
	scanf("%d", &n);
	int repeated_check = 0;
	input[0] = (int)(n/1000);
	input[1] = (int)((n-1000*input[0])/100);
	input[2] = (int)((n-1000*input[0]-100*input[1])/10);
	input[3] = (int)((n-1000*input[0]-100*input[1]-10*input[2])); 
}

int match(int guess[], int target[])
{
	return 0;
}

