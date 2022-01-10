#ifndef _RNA_PROCESSING_H_
#define _RNA_PROCESSING_H_

int RNA_Stop(char RNA_Seq[], int start, int length); 
int RNA_Start(char RNA_Seq[], int start, int length); 
int AminoAcid(char Seq[], int start, int end, char cononFile[]);

#endif
