

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC);

    printf("Hellow world\n");

    if(fd == -1){
    	perror("Couldn't open file\n");
	return 1;
    }
    if(dup2(fd,1) == -1){
	perror("Error when duplicating the file descriptor");
	return 1;
    }

    printf("Text will be written into a file\n");
    close(fd);
    dup2(1, STDOUT_FILENO);

    return 1;


}
