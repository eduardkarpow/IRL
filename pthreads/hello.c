#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* PrintHello(void* data)
{
    pthread_t tid = (pthread_t)data;
    pthread_join(tid, NULL);
    sleep(1)
    printf("Hello from new thread (%u) -  got (%u)", data, pthread_self());
    pthread_exit(NULL);
}
int main(int argc, char* argv[])
{
    int rc;
    pthread_t thread_id;
    pthread_t tid = pthread_self();
    rc = pthread_create(&thread_id, NULL, PrintHello, (void*)tid);
    if(rc)
    {
	printf("\n ERROR: return code from pthread_create is %d \n", rc);
	exit(1);
    }
    sleep(1);
    printf("\n I am thread (%u) that created new thread (%u) ... \n", pthread_self(), thread_id);
    pthread_exit(NULL);

}
