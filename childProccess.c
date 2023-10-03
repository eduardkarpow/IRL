

#include <unistd.h>
#include <stdio.h>

int main() {
    int pid;
    printf("Original proccess with pid %d and ppid %d\n", getpid(), getppid());
    pid = fork();
    if(pid == 0) {
	printf("Parent proccess with pid %d and ppid %d\n", getpid(), getppid());
	printf("child's pid %d\n", pid);
    } else{
	printf("Child proccess with pid %d and ppid %d\n", getpid(), getppid());
    	execl("/bin/df", "df", NULL);
    }	
    printf("pid %d terminates\n", getpid());
    return 0;
    
}
