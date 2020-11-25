#include <stdio.h>
#include <omp.h>
#include "random.h"

//
// The monte carlo pi program
//

static long num_trials = 1000000;

int main ()
{
    long i;  long Ncirc = 0;
    double pi, x, y, test;
    double r = 1.0;   // radius of circle. Side of squrare is 2*r


    seed(-r, r);  // The circle and square are centered at the origin

    double rr=r*r; //made this one to avoid a recurrent operation  with the same result

    #pragma omp parallel
    {
        #pragma omp for reduction(+:Ncirc) private(x,y,test)
            for(i=0;i<num_trials; i++)
            {
                x = random();
                y = random();

                test = x*x + y*y;
                
                if (test <= r*r){
                #pragma omp critical  
                    Ncirc=Ncirc+1;

                }
            }
    }
    

    pi = 4.0 * ((double)Ncirc/(double)num_trials);
    printf("Ncirc, %ld\n",Ncirc);
    printf("\n %ld trials, pi is %f \n",num_trials, pi);

    return 0;
}
