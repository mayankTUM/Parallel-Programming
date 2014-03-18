#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *hello(void *ptr)
{
	printf("Hello world from pthread %d\n",*((int *)ptr));
	return NULL;
}

int main(int argc, char **argv)
{
	int num_threads = 4;
	pthread_t *thread;
        int *thread_args;
	thread = malloc(num_threads * sizeof(*thread));
        thread_args = malloc(num_threads * sizeof(int));
        for(int i=0; i<num_threads; i++)
        {
		thread_args[i] = i;
		pthread_create(thread+i,NULL,&hello,thread_args+i);
        }
        for(int i=0; i<num_threads; i++)
        {
		pthread_join(thread[i],NULL);
        }
	return 0;
}
