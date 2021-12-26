#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size = 0;
	char ch;
	char *dna = (char *)malloc(sizeof(char)*10000);
	while ((ch = getchar()) != EOF) {
		if (ch != '\n') 
			dna[size++] = ch;
		if (size >= 10000) 
			dna = realloc(dna, size+10000);
		//printf("%c", dna[size-1]);
	}
	dna[size] = '\0';
	printf("size = %ld\n", size);
	return 0;
}
 
