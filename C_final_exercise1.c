#include <stdio.h>
#include <stdlib.h>

void avg_sum(double a[], int n, double *min, double *max, double *sum);

int main()
{
	int i, count = 0; 
	double num;
	double minimum, maximum, sum;
	
	double *arr = (double *)malloc(sizeof(double));
	while (scanf("%lf", &num) != EOF) {
		arr[count++] = num;
		arr = realloc(arr, count*sizeof(double)) ;
	}
	for (i=0; i<count; i++) {
		printf("%lf ", arr[i]);
	}
	avg_sum(arr, count, &minimum, &maximum, &sum);
	printf("min = %lf, max = %lf, sum = %lf", minimum, maximum, sum);
}

void avg_sum(double a[], int n, double *min, double *max, double *sum)
{
	int i = 0; 
	*sum = a[0];
	*min = a[0];
	*max = a[0];
	for (i=1; i<n; i++) {
		if (a[i] > *max) 
			*max = a[i];
		if (a[i] < *min)
			*min = a[i];
		*sum += a[i];
	}
}
