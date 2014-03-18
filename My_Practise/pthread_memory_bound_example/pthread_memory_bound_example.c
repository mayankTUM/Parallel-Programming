#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define ITERATIONS 100
#define INNER_ITERATIONS 10000

int main(int argv,char **argc)
{
  double *a;
  double *b;
  double sum = 0.0;
  a = malloc(INNER_ITERATIONS*sizeof(double));
  b = malloc(INNER_ITERATIONS*sizeof(double));
  for(int i=0;i<INNER_ITERATIONS;i++)
  {
    a[i] = i+1;
    b[i] = 1.0/(i+1);
  }

  for(int i=0;i<ITERATIONS;i++)
  {
    for(int j=0;j<INNER_ITERATIONS;j++)
    {
      sum = sum + a[j]*b[j];
    }
  }  
 printf("Dot Product of two matrices is %lf\n",sum);
}
