#include <stdio.h>

#define TEST_RANGE 10000

int Collatz(int number);

int main()
{
	int i, answer; 
	int sum = 0; 
	
	for (i=0; i<TEST_RANGE; i++) {
		printf("%dth: %d\n", i, Collatz_count(i));
		sum += Collatz_count(i);
	}
	printf("\nAverage #iterations: %.2f", (float)sum/TEST_RANGE);
	return 0;
}

int Collatz_count(int num) 
{
	int count = 0;
	while (num > 1) {
		if (num % 2 == 0) { 
			num /= 2;
		} else {
			num = num * 3 + 1;
		}
		count += 1;
	}
	return count;
}
