#include <stdio.h>

int lottery[100][6]; // record at most 100 lottery tickets
int draw[6]; // the draw of the lottery

int main()
{
    int ticketOrder = 0, ticketCount = 0, num; 
    int i, j, k;
    int match; // record how many numbers are matched
    int prize = 0;
    
    // initialization
    for (i=0; i<100; i++) {
        for (j=0; j<6; j++) {
            lottery[i][j] = 0;
        }
    }
    // start reading lottery numbers
    while (scanf("%d", &num) != EOF) {
        if (ticketCount == 6) {
            ticketCount = 0;
            ticketOrder++;
        }
        lottery[ticketOrder][ticketCount++] = num;
        
    }
    for (j=0; j<6; j++) { 
        draw[j] = lottery[ticketOrder][j];
    }
    /*
    for (i=0; i<=ticketOrder; i++) {
        for (j=0; j<6; j++) { 
            printf("%d, ", lottery[i][j]);
        }
        printf("\n");
    }*/
    
    for (i=0; i<ticketOrder; i++) {
        match = 0;
        for (j=0; j<6; j++) {
            for (k=0; k<6; k++) {
                if (lottery[i][j] == draw[k]) match++;
            }
        }
        switch (match) {
            case 3: 
                prize += 400;
                break;
            case 4: 
                prize += 1000;
                break;
            case 5: 
                prize += 10000;
                break;
            case 6: 
                prize += 100000;
                break;
            default:
                break;
        }
        
    }
    printf("You win $%d!\n", prize);
    return 0;
}
