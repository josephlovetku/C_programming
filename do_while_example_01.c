#include <stdio.h>

int main()
{
    int num = 0; 
    
    do { 
        printf("Please enter an integer: ");
        scanf("%d", &num); 
        if (num < 100) { 
            printf("The result: %d\n", num+1);
        }
    } while (num < 100);
    
    return 0;
}
