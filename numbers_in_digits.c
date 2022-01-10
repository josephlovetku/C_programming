/******************************************************************************

Turn numbers into digits (seven-segement display)
Characters other than digits are ignored

Example: 
Input: 
491-9014
Output: 
     _           _   _   _              
|_| |_|   |     |_| | |  _| |_|         
  |  _|   |      _| |_| |_    | 

*******************************************************************************/
#include <stdio.h>
#define MAX_DIGITS 10

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);
char digits[4][MAX_DIGITS*4];
const int segment[10][7] = {
    {1,1,1,0,1,1,1}, {0,0,1,0,0,1,0}, {1,0,1,1,1,0,1}, {1,0,1,1,0,1,1}, {0,1,1,1,0,1,0},
    {1,1,0,1,0,1,1}, {1,1,0,1,1,1,1}, {1,0,1,0,0,1,0}, {1,1,1,1,1,1,1}, {1,1,1,1,0,1,1}
};


void clear_digits_array(void)
{
    int j = 0, i = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < MAX_DIGITS*4; j++) {
            digits[i][j] = ' ';
        }
    }
}

void process_digit(int digit, int position)
{
    int i = 0;
    for (i = 0; i < 7; i++) {
        if (segment[digit][i] == 1) {
            switch(i) {
                case 0: 
                    digits[0][1+position*4] = '_';
                    break;
                case 1: 
                    digits[1][0+position*4] = '|';
                    break;
                case 2: 
                    digits[1][2+position*4] = '|';
                    break;
                case 3: 
                    digits[1][1+position*4] = '_';
                    break;
                case 4: 
                    digits[2][0+position*4] = '|';
                    break;
                case 5: 
                    digits[2][2+position*4] = '|';
                    break;
                case 6: 
                    digits[2][1+position*4] = '_';
                    break;
            }
        }
    }
}

void print_digits_array(void)
{
    int a = 0, b = 0;
    for(a = 0; a < 3; a++) {
        for(b = 0; b < MAX_DIGITS*4; b++)
            printf("%c", digits[a][b]);
        printf("\n");
    }
}

int main() {
    char character_number = '\0';
    int position = 0;
    
    clear_digits_array();
    printf("Enter a number: ");
    while ((character_number = getchar()) != '\n') {
        int number = MAX_DIGITS;
        switch(character_number){
            case '0': 
                number = 0;
                break;
            case '1': 
                number = 1;
                break;
            case '2': 
                number = 2;
                break;
            case '3': 
                number = 3;
                break;
            case '4': 
                number = 4;
                break;
            case '5': 
                number = 5;
                break;
            case '6': 
                number = 6;
                break;
            case '7': 
                number = 7;
                break;
            case '8': 
                number = 8;
                break;
            case '9': 
                number = 9;
                break;
            default:
                number = -1;
                //printf("%c ignored", character_number);
                break;
        }
        if (number != -1)
            process_digit(number, position);
        position++;
    }
    printf("\n");
    print_digits_array();
    return 0;
}
