#include <stdio.h>
#include <stdlib.h>

int HornerRule(int coef[], int start, int degree, int x);

int main()
{
    int size = 5;
    int i = 0, count = 0;
    int result = 0;
    int x = 1;
    
    int *arr = (int *)malloc(size * sizeof(int));
    while (scanf("%d", &arr[count++]) != EOF) {
        //printf("## %d ##\n", count % size);
        if (count % size == size) 
            arr = realloc(arr, count+size);
    }
    count--;
    x = arr[count-1];
    printf("x = %d\n", x);
    count--;
    printf("count = %d\n", count);
    printf("f(x) := %d ", arr[0]);
    for (i=1; i<count; i++) 
        printf("+ (%d)*(%d)^(%d)", arr[i], x, i);
    printf("\n");
    result = poly(arr, 0, count-1, x);
    printf("result = %d\n", result);
    return 0;
}

int HornersRule(int c[], int i, int d, int x)
{
    if (i == d) return c[d];
    else 
        return c[i] + x*HornerRule(c, i+1, d, x);
}
