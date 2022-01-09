#include <stdio.h>
#include <stdlib.h>

void find_two_largest(int a[], int n, int *largest, int *second_largest);

int main()
{
	int i, count = 0; 
	int num;
	int max, secMax;
	
	int *arr = (int *)malloc(sizeof(int));
	while (scanf("%d", &num) != EOF) {
		arr[count++] = num;
		arr = realloc(arr, count*sizeof(int)) ;
	}/*
	for (i=0; i<count; i++) {
		printf("%d ", arr[i]);
	}*/
	printf("count = %d\n", count);
	find_two_largest(arr, count, &max, &secMax);
	printf("largest: %d, second largest: %d\n", max, secMax);
}

void find_two_largest(int a[], int n, int *largest, int *second_largest)
{
	int i = 0; 
	if (n == 1) {
		*largest = a[0];
		*second_largest = a[0];
	} else {
		*largest = (a[0] > a[1])? a[0]: a[1];
		*second_largest = (a[0] > a[1])? a[1]: a[0];
		for (i=2; i<n; i++) {
			if (a[i] > *largest) {
				*second_largest = *largest;
				*largest = a[i];
			} else {
				if (a[i] > *second_largest) {
					*second_largest = a[i];
				}
			}
		}
	}
}
