/******************************************************************************

Get a coding sequence from an RNA seq with start codon ATG and 
stop codon TAA, TAG, or TGA.

Joseph Chuang-Chieh Lin
November 28, 2021

*******************************************************************************/
#include <stdio.h>
#include "positions.h"

int main()
{
    int i = 0;
    int count = 0;
    char rna_seq[10000];
    char ch; 
    int seq_start = 0;
    int seq_end = 0;
    
    while ((ch = getchar()) != EOF) {
        if (ch != '\n') {
            rna_seq[i++] = ch;
            count++;
        }
    }
    printf("count = %d\n", count);
    
    seq_start = RNA_Start(rna_seq, count);
    seq_end = RNA_Stop(rna_seq, count);
    
    if (seq_end != -1) {
        for (i=seq_start; i<seq_end; i++) 
            printf("%c", rna_seq[i]);
    }
    return 0;
}


