//#include "positions.h"

int RNA_Stop(char Seq[], int length) // Stop codon: TAA, TAG, or TGA
{
    int i=0, j=0;
    int found = 0;
    for (i=0; i<length-2; i++) {
        if (Seq[i] == 'T') {
            if (Seq[i+1] == 'A' && Seq[i+2] == 'A') {
                found = 1;
                return i;
            } else if (Seq[i+1] == 'A' && Seq[i+2] == 'G') {
                found = 1;
                return i;
            } else if (Seq[i+1] == 'G' && Seq[i+2] == 'A') {
                found = 1;
                return i;
            } else 
                continue;
        }
    }
    if (found == 0) 
        return -1;
}


int RNA_Start(char Seq[], int length) // Start codon: ATG
{
    int i=0, j=0;
    int found = 0;
    for (i=0; i<length-2; i++) {
        if (Seq[i] == 'A' && Seq[i+1] == 'T' && Seq[i+2] == 'G') {
                found = 1;
                return i;
        } else {
            continue;
        }
    }
    if (found == 0) 
        return -1;
}
