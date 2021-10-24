#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0, j = 0, max = 0;
    int guess = 0;
    int count = 0;
    int leftBound = 0;
    int rightBound = 0;
    
    printf("*** 猜數字遊戲 ***\n");
    printf("請輸入數字範圍 (0~ ?): ");
    scanf("%d", &max);
    printf("\n--- 好了, 遊戲開始! --- \n\n");
    system("pause");
    system("cls");
    j = max;
    rightBound = max;

    do {
        printf("你猜的是: ");
        scanf("%d", &guess);
        count++;
        if (guess > j) {
            printf("小一點...\n");
        } else if (guess < i) { 
            printf("大一點...\n");
        } else {         
            if (guess-i > j-guess) { // 左半邊剩比較多
                j = guess-1;
                //printf("i=%d, j=%d\n", i, j);
                if (i<j) printf("小一點!\n");
            } else { // 右半邊剩比較多
                i = guess+1;
                //printf("i=%d, j=%d\n", i, j);
                if (i<j) printf("大一點!\n");
            }
        }
    } while(i<j);
    printf("你猜對了!\n");
    printf("\n總共猜了 %d 次\n", count);
    return 0;
}
