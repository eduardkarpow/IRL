#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int shmid;
    if((shmid = shmget(IPC_PRIVATE, BUFSIZ, 0666)) < 0){
	perror("shmget");
	exit(EXIT_FAILURE);
    }
    printf("segment created: %d\n", shmid);
    system("ipcs -m");
    exit(EXIT_SUCCESS);






    return 1;
}
