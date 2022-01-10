#include <stdio.h>

#define N 10

void quickSort(int a[], int low, int high); 
/*	a[]: the numbers in the array which are asked to be sorted 
	low: the leftmost index
	high: the rightmost index 								*/
int split(int a[], int low, int high); 
/*	split the array in two parts and return the middle index 
	such that the elements between low and middle are smaller 
	than the pivot and the elements between middle and high 
	are bigger than the pivot 								*/

int main()
{
	int a[N], i;
	
	printf("Enter %d numbers to be sorted: ", N);
	for (i=0; i<N; i++) {
		scanf("%d", &a[i]);
	}
	quickSort(a, 0, N-1); 
	
	printf("In sorted order: ");
	for (i=0; i<N; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	
	return 0;
}

void quickSort(int a[], int low, int high)
{
	int middle; 
	if (low >= high) return; // only one element to sort so we can just return
	middle = split(a, low, high);
	quickSort(a, low, middle-1);
	quickSort(a, middle+1, high);
}

int split(int a[], int low, int high)
{
	int pivot = a[low];
	
	while (1) {
		while (low < high && pivot <= a[high]) {
			high--;
		}
		if (low >= high) break;
		a[low++] = a[high];
		
		while (low < high && a[low] <= pivot) {
			low++;
		}
		if (low >= high) break;
		a[high--] = a[low];
	}
	a[high] = pivot;
	return high;
}
