/*********************************************** 
 Normalize a vector to be of one-unit length

 Author: Joseph Chuang-Chieh Lin
 Date: December 26 2021
************************************************/

#include <stdio.h>
//#include <stdlib.h>
#include <math.h>


//float* normalized_vector(float *vector, int size);
void normalized_vector(float *vector, int size);

int main()
{
    int i;
    int size = 2; 
    float input_vector[size];
    //float *output;
    
    for (i=0; i<size; i++) 
        scanf("%f", &input_vector[i]);
        
    //output = normalized_vector(input_vector, size);
    normalized_vector(input_vector, size);
    
    for (i=0; i<size; i++) 
        //printf("%f ", output[i]);
        printf("%f ", input_vector[i]);
    return 0;
}

void normalized_vector(float *vector, int size)
{
    int i;
    float square_sum = 0;
    //float *output = (float *)malloc(sizeof(float)*size);
    
    for (i=0; i<size; i++) {
        square_sum += (*(vector+i))*(*(vector+i));
    }
    for (i=0; i<size; i++) {
        *(vector+i) /= sqrt(square_sum);
        //*(output+i) = *(vector+i)/sqrt(square_sum);
    }
    //return output;
}
