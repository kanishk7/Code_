#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

//Prototype for thread_create: 
//int pthread_create(pthread_t * pth, pthread_attr_t *att, void * (*function), void * arg);

void* threadFunc(void* arg)
{
	char* str;
	int i = 0;
	str = (char*)arg;
	while(i<10)
	{
		usleep(1000);
		printf("Thread function says %s.\n", str);
		i++;
	}
	return NULL;
}

int main()
{
	pthread_t pth;
	int i = 0;
	int flag = pthread_create(&pth, NULL, threadFunc, "LOLMAXE LOL LOL LOLMAXE.");
	//pthread_join(pth, NULL);
	while(i < 10)
	{
		i++;
		printf("main() is running.\n");
		usleep(1);
	}

	return 0;
}
