#include "omp.h"
#include <stdio.h>
#include <stdlib.h>

#define N        10000

#define SEED       2531
#define RAND_MULT  1366
#define RAND_ADD   150889
#define RAND_MOD   714025

int randy = SEED;
int flag = 0;

void fill_rand(int length, double *a)
{
    int i;
    for (i=0;i<length;i++) {
        randy = (RAND_MULT * randy + RAND_ADD) % RAND_MOD;
        *(a+i) = ((double) randy)/((double) RAND_MOD);
    }
    flag = 1;
    #pragma omp flush (flag)
}


double Sum_array(int length, double *a)
{
        while(!flag);
        int i;  double sum = 0.0;
        for (i=0;i<length;i++){
            sum += *(a+i);
        }
        return sum;    
}

int main()
{
    double *A, sum, runtime;
    A = (double *)malloc(N*sizeof(double));
    runtime = omp_get_wtime();
    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
                fill_rand(N, A);        
            #pragma omp section
                sum = Sum_array(N, A);  
        }
    }
    
        
        
    
    runtime = omp_get_wtime() - runtime;
    printf(" In %lf seconds, The sum is %lf \n",runtime,sum);
}
