#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *hello()
{
	printf("Hello world from pthread\n");
	return NULL;
}

int main(int argc, char **argv)
{
	int num_threads = 4;
	pthread_t *thread;
	thread = malloc(num_threads * sizeof(*thread));
        for(int i=0; i<num_threads; i++)
        {
		pthread_create(thread+i,NULL,&hello,NULL);
        }
        for(int i=0; i<num_threads; i++)
        {
		pthread_join(thread[i],NULL);
        }
	return 0;
}
