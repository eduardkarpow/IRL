#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void * PrintHello(void * data){
	int my_data = (int)data;

	printf("Hello from new thread %u - was created in iteration %d\n", pthread_self(), data);
	pthread_exit(NULL);

}

int main(){
	int rc;
	int thread_num = 10;
	pthread_t thread_id;

	for(int i = 0; i < thread_num; i++){
		rc = pthread_create(&thread_id, NULL, PrintHello, (void*)i);
		printf("I am thread %u, created new thread (%u) in iteration %d\n",pthread_self(), thread_id, i);
		if(i%4 == 0){
			printf("ok");
			sleep(1);
		}
	}
	pthread_exit(NULL);
}
