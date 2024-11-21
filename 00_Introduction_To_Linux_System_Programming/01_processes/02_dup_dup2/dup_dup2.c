#include<stdio.h>
#include <unistd.h>
#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <fcntl.h>              /* Obtain O_* constant definitions */

#define STD_INPUT  0
#define STD_OUTPUT 1
#define STD_ERROR  2

#define DUP2_ERR -1

int dup(int oldfd);
int dup2(int oldfd, int newfd);

int main(){

    /* Open and create a file to output our text in */
    int fd_output = open("output.txt",O_WRONLY | O_CREAT | O_TRUNC,0644);

    /* Redirect the output to be in the output.txt file */
    if(dub2(STD_OUTPUT,fd_output) == DUP2_ERR){
        printf("Error Opening the file !!\n");
    }
    else{
        printf("Hello From The Process [%d] :)",getpid());
        close(fd_output);
    }
    return 0;

}