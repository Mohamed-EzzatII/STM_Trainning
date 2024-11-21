#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 512

int main(){

    int fd_input,fd_output;
    char buff[BUFFER_SIZE];
    int read_size,write_size;

    /* Try to open input file in read-only access mode*/
    fd_input = open("input.txt",O_RDONLY);
    if(fd_input < 0){
        printf("Error while opening the input file!!\n");
        return -1;
    }
    printf("Input File with fd[%d] Opened Successfully!!\n",fd_input);

    /* Try to read data from the opened input file */
    read_size = read(fd_input,(void*)buff,BUFFER_SIZE );
    if(read_size == 0){
        printf("Empty Input File!!\n");
        if(close(fd_input)){
           printf("input file isn't closed!!\n");
        }

        return -1;
    }   
    else if(read_size == -1){
        printf("Error while reading the input file!!\n");
        if(close(fd_input)){
           printf("input file isn't closed!!\n");
        }
        return -1;
    }
    else{
        printf("Data Read Successfully from input file!!\n");
        printf("Read Data:\n%s\n",buff);
    }

    /* Try to open output file in write-only access mode
     * And create it if it doesn't exist ( O_CREAT Flag ) */
    fd_output = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(fd_output < 0){
        printf("Error while opening the input file!!\n");
        return -1;
    }
    printf("Output File with fd[%d] Opened Successfully!!\n",fd_output);

    /* Try to write data to the opened output file */
    write_size = write(fd_output,(const void*)buff,read_size);
   if(write_size == -1){
        printf("Error while writing the output file!!\n");
        if(close(fd_input)){
           printf("input file isn't closed!!\n");
        }
        if(close(fd_output)){
            printf("output file isn't closed!!\n");
        }
        return -1;
    }
    else{
        printf("Data Wrote Successfully to output file!!\n");
    }

    /* Close the opened files */
    if(close(fd_input)){
        printf("input file isn't closed!!\n");
    }
    if(close(fd_output)){
        printf("output file isn't closed!!\n");
    }
    return 0;
}