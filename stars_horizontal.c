#include <stdio.h>

#define MAX_INPUT 100

int main()
{
	int i=0, j=0, tmp=0, count=0, max = 0; 
	int inputArray[MAX_INPUT];
	
	while (scanf("%d", &tmp) != EOF) {
		if (tmp > max) max = tmp;
		inputArray[i] = tmp;
		i++;
		count++;
	} 
	for (i=0; i<max; i++) {
		for (j=0; j<count; j++) 
			if (inputArray[j]<max-i)
				printf(" ");
			else 
				printf("*");
		printf("\n");
	}
	return 0;
 } 
