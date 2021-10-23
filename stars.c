#include <stdio.h>

#define MAX_INPUT 100

int main()
{
	int i=0, j=0, tmp=0, count=0; 
	int inputArray[MAX_INPUT];
	
	while (scanf("%d", &tmp) != EOF) {
		inputArray[i] = tmp;
		i++;
		count++;
	} 
	for (i=0; i<count; i++) {
		for (j=0; j<inputArray[i]; j++) 
			printf("*");
		printf("\n");
	}
	return 0;
 } 
