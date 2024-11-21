#include <unistd.h>
#include <stdio.h>
int execv(const char *pathname, char *const argv[]);
int main(){
    printf("parent process id = [%d]\n",getpid());
    getchar();
    char *const __argv[] = {"ls",NULL};
    execvp("ls",__argv);
    printf("Error\n");
}