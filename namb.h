#ifndef _NAMB_H_
#define _NAMB_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int A, B;
int input[4]; // input sequence
int target[4]; // target sequence
void generate(void); // generate the target sequence
void guessing(void); // guessing for player
int match(int mat1[], int mat2[]); // check the matching result in nAmB
int check_repeat(int matrix[]); // check if there is any repeated integer 

#endif
