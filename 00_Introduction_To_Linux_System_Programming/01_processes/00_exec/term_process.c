#include<stdio.h>
#include<unistd.h>
int main(int argc,char **argv){
    printf("Welcome To Terminating Process [%d]!!\n",getpid());
    printf("Process [%d] Terminated!! \n",getpid());
    return 0;
}