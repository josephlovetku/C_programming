#include <stdio.h>
#include <stdlib.h>

void swap(int *first, int *second);

int main()
{
	int a = 5, b = 3; 
	printf("# Before swap:\n");
	printf("a = %d, b = %d\n", a, b);
	
	printf("# After swapping:\n");
	swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);
}

void swap(int *first, int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}
