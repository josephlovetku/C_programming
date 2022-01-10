#include <stdio.h>
#include <math.h>
#define MAX_COUNT 100

int primeTest(int num);  // test if num is a prime number

int main()
{
    int num = 0;
    int count = 0;
    int result;
    
    printf("Please enter an integer: ");
    scanf("%d", &num); 
    printf("Result: ");
    num++; // start the testing from num+1
    
    do { 
        result = primeTest(num);
        if (result != 0) {
            printf("%d, ", num);
            count++;
        }
        num++;
    } while (count < MAX_COUNT);
    return 0;
}

int primeTest(int num)
{
    int i=0; 
    if (num == 0 || num == 1) return 0;
    else {
        int half = (int)sqrt(num); 
        for (i=2; i<=half; i++) {
            if (num%i == 0) 
                return 0;
        }
        return 1;
    }
}
