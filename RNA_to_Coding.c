/******************************************************************************

Get a coding sequence from an RNA seq with start codon ATG and 
stop codon TAA, TAG, or TGA.

Joseph Chuang-Chieh Lin
November 28, 2021

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "RNA_Processing.h"

char CODON_FILE[50] = "C:/Users/josep/_programs/PL/codon_to_amino.csv";

int main()
{
    int i = 0;
    int count = 0;
    char rna_seq[10000]; // input RNA seq
    char coding_seq[1000]; // coding RNA seq
    int coding_length = 0;
    char ch; 
    int seq_start = 0;
    int seq_end = 0;
        
    while ((ch = getchar()) != EOF) {
        if (ch != '\n') {
            rna_seq[i++] = ch;
            count++;
        }
    }
    
    do {
	    seq_start = RNA_Start(rna_seq, seq_start, count);
	    if (seq_start == -1) break;
	    else {
			seq_end = RNA_Stop(rna_seq, seq_start, count);
			if (seq_end == -1) break;
		    else {
				coding_length = seq_end - seq_start;
			    printf("seq_start = %d, seq_end = %d\n", seq_start, seq_end);					    
			    printf("coding length = %d\n", coding_length);
			    
			    if (seq_end != -1) {
			        for (i=seq_start; i<seq_end; i++) 
			            printf("%c", rna_seq[i]);
			        printf("\n");
			        AminoAcid(rna_seq, seq_start, seq_end, CODON_FILE);
			        
			    }
			}
		}
		seq_start = seq_end + 3;
	} while (seq_start < count-2); 
    return 0;
}


