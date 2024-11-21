#include<stdio.h>
#include<unistd.h>
int main(int argc,char **argv){
    printf("Welcome To Non-Terminating Process [%d] !!\n",getpid());
    while(1);
    return 0;
}