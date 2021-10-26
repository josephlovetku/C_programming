/******************************************************************************

This is an exercise of TKU C Programming Language 1st Semester
Goal: Compute the overlapping area of two rectangles.
Input: x1, y1, x2, y2, x3, y3, x4, y4, 
    where (x1, y1) is the coordinate of the left-top vertex of rectangle 1
          (x2, y2) is the coordinate of the right-bottom vertex of rectangle 1
          (x3, y3) is the coordinate of the left-top vertex of rectangle 2
          (x4, y4) is the coordinate of the right-bottom vertex of rectangle 2
Output: a number which is equal to the overlapping area of rectangle 1 and 2.
*******************************************************************************/
#include <stdio.h>

int checkHorizonApart(int x1, int x2, int x3, int x4); // check if the two rectangles are horizontally apart
int checkVerticalApart(int y1, int y2, int y3, int y4); // check if the two rectangles are vertically apart
int calcArea(int x1, int y1, int x2, int y2); // calculate the area of a rectangle

int main()
{
    int x1, y1, x2, y2, x3, y3, x4, y4; // input coordinates
    int output_x1, output_y1, output_x2, output_y2; // output coordinates
    
    scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    if (checkHorizonApart(x1, x2, x3, x4) || checkVerticalApart(y1, y2, y3, y4)) {
        printf("0");
    } else {
        output_x1 = (x1 > x3)? x1: x3; 
        output_y1 = (y1 < y3)? y1: y3;
        output_x2 = (x2 < x4)? x2: x4;
        output_y2 = (y2 > y4)? y2: y4;
        printf("%d", calcArea(output_x1, output_y1, output_x2, output_y2));
    }
    return 0;
}

int checkHorizonApart(int x1, int x2, int x3, int x4) 
{
    if (x2 <= x3 || x4 <= x1) { 
        return 1;
    } else 
        return 0;
}

int checkVerticalApart(int y1, int y2, int y3, int y4) 
{
    if (y2 >= y3 || y4 >= y1) { 
        return 1;
    } else 
        return 0;
}

int calcArea(int x1, int y1, int x2, int y2)
{
    return (x2-x1)*(y1-y2);
}
