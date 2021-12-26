#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size = 0, batch_size = 10000;
	char ch;
	char *dna = (char *)malloc(sizeof(char)*batch_size);
	while ((ch = getchar()) != EOF) {
		if (ch != '\n') 
			dna[size++] = ch;
		if (size % batch_size == batch_size-1) {
			printf("** re-allocated again (%ld) **\n", size+1);
			dna = realloc(dna, size+batch_size);
		}
	}
	dna[size] = '\0';
	printf("size = %ld\n", size);
	free(dna)
	return 0;
}
 
