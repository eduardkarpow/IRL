#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int alarmFlag = 0;
void alarmHandler();

int main(){
     
    signal(SIGINT, SIG_IGN);
    signal(SIGALRM, alarmHandler);

    printf("Your console has been blocked send money to 2200987687654321\n");
    alarm(10);
    while(!alarmFlag){
	pause();
    } 
    
    printf("Loop ends here\n");
    return 0;
}


void alarmHandler(){
    alarmFlag = 1;   
    signal(SIGINT, SIG_DFL);
}
