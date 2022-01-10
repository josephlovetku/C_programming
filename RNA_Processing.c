#include "RNA_Processing.h"
#include <stdio.h>

int RNA_Stop(char Seq[], int start, int length) // Stop codon: TAA, TAG, or TGA
{
    int i=0, j=0;
    int found = 0;
    for (i=start; i<length-2; i+=3) {
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

int RNA_Start(char Seq[], int start, int length) // Start codon: ATG
{
    int i=0, j=0;
    int found = 0;
    for (i=start; i<length-2; i+=3) {
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

int AminoAcid(char Seq[], int start, int end, char codonFile[])
{
	char codon[64][4];
	char aminoAcid[64][2]; 
	int tableSize = 0;
	int i, j, found=0;
	
	FILE *fp = fopen(codonFile, "r"); 
	if (fp == NULL) { 
		printf("*** File opening error!\n");
		return -1; // cannot open the file
	}
	
	while (fscanf(fp, "%[^,\n]%*c%[^,\n]%*c", codon[tableSize], aminoAcid[tableSize]) != EOF) {
		tableSize++;
		if (ferror(fp)) {
			fclose(fp);
			return -2;
		}
		//printf("%s\t%s\n", codon[tableSize-1], aminoAcid[tableSize-1]);
	}
	fclose(fp); // close the file
	//printf("### tableSize = %d\n", tableSize);
	
	for (i=start; i<end; i+=3) {
		found = 0; // initializing the checking of successful searching 
		for (j=0; j<tableSize; j++) {
			if (Seq[i] == codon[j][0] && Seq[i+1] == codon[j][1] && Seq[i+2] == codon[j][2]) {
				printf("%s", aminoAcid[j]);
				found = 1;
				break;
			}
		}
		if (found == 0) printf("?"); 
	}
	printf("\n");
	return 0;
}


