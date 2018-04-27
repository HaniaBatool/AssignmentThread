#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int arrthread[1000];
int chunk_size = 100;


void * Add(void *arg)
{

	int start = (int)arg;
	int end = start + chunk_size;
	int sum=0;
	int i = 0;
	for(i=0 ; i<end ; i++){
		sum = sum + arrthread[i];
	}
	return ((void*)sum);
}

int main ()
{
    int s1,s2,s3,s4,s5,s6,s7,s8,s9,s10;
	pthread_t thread_t1, thread_t2, thread_t3, thread_t4, thread_t5, thread_t6, thread_t7, thread_t8, thread_t9, thread_t10;

	int i;
	for(i=0;i<1000;i++){
	arrthread[i] = i;
	}

	pthread_create(&thread_t1,NULL,Add,(void*)(0 * chunk_size));
	pthread_create(&thread_t2,NULL,Add,(void*)(1 * chunk_size));
	pthread_create(&thread_t3,NULL,Add,(void*)(2 * chunk_size));
	pthread_create(&thread_t4,NULL,Add,(void*)(3 * chunk_size));
	pthread_create(&thread_t5,NULL,Add,(void*)(4 * chunk_size));
    pthread_create(&thread_t6,NULL,Add,(void*)(5 * chunk_size));
    pthread_create(&thread_t7,NULL,Add,(void*)(6 * chunk_size));
    pthread_create(&thread_t8,NULL,Add,(void*)(7* chunk_size));
    pthread_create(&thread_t9,NULL,Add,(void*)(8 * chunk_size));
    pthread_create(&thread_t10,NULL,Add,(void*)(9 * chunk_size));

	pthread_join(thread_t1,(void**) & s1);
	pthread_join(thread_t2,(void**) & s2);
	pthread_join(thread_t3,(void**) & s3);
	pthread_join(thread_t4,(void**) & s4);
	pthread_join(thread_t5,(void**) & s5);
    pthread_join(thread_t6,(void**) & s6);
    pthread_join(thread_t7,(void**) & s7);
    pthread_join(thread_t8,(void**) & s8);
    pthread_join(thread_t9,(void**) & s9);
    pthread_join(thread_t10,(void**) & s10);
    int sum = s1+s2+s3+s4+s5+s6+s7+s8+s9+s10;
	
	printf("\nSum %d\n", sum);

	return 0;
}
