#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int i = 0, count = 0;
    int *array;
    while (scanf("%d", &num) != EOF) {
        count++;
        if (count == 1) {
            array = (int *)malloc(sizeof(int));
        } else {
            array = realloc(array, sizeof(int)*(count));
        }
        array[count-1] = num;
        printf("## array[%d] = %d ##\n", count-1, array[count-1]);
    }
    // print the input array
    for (i=0; i<count; i++) 
        printf("array[%d] = %d\n", i, array[i]);

    return 0;
}
