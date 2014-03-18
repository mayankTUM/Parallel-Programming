#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define ITERATIONS 100
#define INNER_ITERATIONS 10000
#define num_threads 2;

struct pthread_args
{
 double *a;
 double *b;
}


int main(int argv,char **argc)
{
  pthread_t *thread;
  thread = malloc(num_threads * sizeof(*thread));
  struct pthread_args args;
  args = malloc(sizeof(args));
  args.a = malloc(INNER_ITERATIONS*sizeof(double));
  args.b = malloc(INNER_ITERATIONS*sizeof(double));
  for(int i=0;i<INNER_ITERATIONS;i++)
  {
    args.a[i] = i+1;
    args.b[i] = 1.0/(i+1);
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
