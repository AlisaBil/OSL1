#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main() {

    int status;
    pid_t child_pid;
    child_pid = fork();

    if (child_pid > 0) 
    {
        system("ps -o pid,ppid,stat,cmd");
        wait(&status);
        printf("\n\tПроцесс-зомби исчез:\n\n");
        system("ps -o pid,ppid,stat,cmd");
        sleep(60);
    } 
    else 
    {
        exit(0);
    }
}