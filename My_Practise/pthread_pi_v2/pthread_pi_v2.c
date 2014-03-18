#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>
#define STEPS 1000000
#define step_size 1.0/STEPS 
struct pthread_args
{
	double lower;
	double upper;
        long thread_id;
};

void *calculate_pi(void *ptr)
{
   struct pthread_args *args = 	ptr;
   double lower = 0.5 * step_size + args->lower;
   double upper = args->upper;
   double *ret_sum = malloc(sizeof(double));
   double sum = 0.0;
   while(lower<upper)
   {
	sum = sum + step_size * sqrt(1-lower*lower);
	lower+=step_size;
   }
   *ret_sum = sum;
   return ret_sum; 	
}

int main(int argc, char** argv) {
   
   int num_threads = 5;
   pthread_t *thread;
   double sum = 0.0;
   void *arg;   
   struct pthread_args *thread_args;
   thread = malloc(num_threads * sizeof(*thread));
   thread_args = malloc(num_threads * sizeof(*thread_args));
   for(int i=0; i<num_threads; i++)
   {
	thread_args[i].thread_id = i;
	thread_args[i].lower = i * (1.0 / (double)num_threads);
        thread_args[i].upper = (i+1) * (1.0 / (double)num_threads);
        pthread_create(thread+i,NULL,&calculate_pi,thread_args+i); 
   } 
   for(int i=0; i<num_threads; i++)
   {
	pthread_join(thread[i],&arg);
	sum = sum + (*(double*)arg);
   }
   sum*=4;
   printf("Calculated PI is %.10lf\n",sum);
   printf("Error in PI is %.10lf\n",M_PI-sum);
}

