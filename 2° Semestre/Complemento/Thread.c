#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#define nThread 1000

void *do_stuff (void *param)
{	long thread_no = (long) param;
	printf ("Thread number %ld\n", thread_no);
	return (void *)(thread_no + 1);
}

int main()
{	pthread_t threads[nThread];
	long t;
	void *result;
	
	for (t=0; t<nThread; t++)
		pthread_create(&threads[t], NULL, do_stuff, (void*)t);

	for (t=0; t<nThread; t++)
	{	pthread_join(threads[t], &result);
		printf("\t\tThread %ld returned %ld\n", t, (long)result);
	}
}
