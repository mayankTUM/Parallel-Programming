#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define number_of_threads 2
#define STEPS 1000000
#define step_size 1.0/STEPS

struct pthread_args
{
  double lower;
  double upper;
  pthread_mutex_t mutex;
};

void *calculate_pi(void *ptr)
{
 double lsum=0.0;
 struct pthread_args *attr = ptr;
 pthread_mutex_lock(&(attr->mutex));
 double upper = attr->upper;
 double lower = 0.5 * step_size + attr->lower;
 attr->lower=attr->upper;
 attr->upper*=2;
 pthread_mutex_unlock(&(attr->mutex));
 while(lower<upper)
 {
   lsum += sqrt(1-lower*lower)*step_size;
   lower+=step_size;
 }
 double *temp = malloc(sizeof(double));
 *temp = lsum;
 return temp; 
}

int main(int argc, char **argv)
{
 void *lsum;
 double sum=0.0;
 pthread_t *thread;
 double low = 0.0;
 double upp = 1.0/(double)number_of_threads;
 struct pthread_args args = {low,upp,PTHREAD_MUTEX_INITIALIZER};
 thread = malloc(number_of_threads*sizeof(*thread));
 for(int i=0;i<number_of_threads;i++)
 {
    pthread_create(thread+i,NULL,&calculate_pi,&args);
 }
 for(int i=0;i<number_of_threads;i++)
 {
    pthread_join(thread[i],&lsum);
    sum+=*(double*)lsum;
 }
 sum*=4; 
 printf("Calculate PI is %.10lf\n",sum);
 printf("Error in PI is %.10lf\n",M_PI-sum); 
}
