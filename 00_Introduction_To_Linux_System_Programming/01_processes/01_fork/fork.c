#include<unistd.h>
#include <sys/wait.h>
#include<stdio.h>
#include <sys/types.h>

int main(){

    pid_t pid = fork();
    if(pid > 0){
        printf("Parent process started [%d]\n",getpid());
        wait(NULL);
        printf("Parent Process Finished !!\n");
    }
    else if(pid == 0){
        printf("Child Process Started [%d]\n",getpid());
        printf("Child Process Parent [%d]\n",getppid());
        printf("Child Process Finished !!\n");
    }
    else{
        printf("i am not in the mode to fork:(\n");
    }
}