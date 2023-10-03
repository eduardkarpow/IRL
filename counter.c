#include <stdio.h>
#include <unistd.h>

#define MAX_COUNT 300

void ChildProccess(){
    /*for(int i = 0; i < MAX_COUNT; i++){
	printf("this is child, index = %d\n", i);
    }*/
    execl("/bin/ls", "ls", "-l", NULL);
}

void ParentProccess(){
    for(int i = 0; i < MAX_COUNT; i++){
	printf("this is parent, index = %d\n", i);
    }
}

int main(){
    int pid;
    pid = fork();
    if(pid != 0) {
	ParentProccess();
    } else{
	ChildProccess();
    }
    return 0;
}
