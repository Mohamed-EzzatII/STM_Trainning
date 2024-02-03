#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

#define PATH_MAX_SIZE 100
#define MAX_COMMAND_SIZE 100
#define TRUE 1
#define FALSE 0

int main(){

	/* Create a variable to store the command */
	char inputString[MAX_COMMAND_SIZE]={'D','\0'};

	printf("*********************************************************\n");
	printf("\nWelcome to my command shell\n");
	printf("Please note that the max command size is 100\n\n");
	printf("*********************************************************\n");
	
	char *command=NULL;
	char *arg1=NULL;
	char *arg2=NULL;

        /* Compare the input command to exit,if the user
         * entered exit the program will terminate,else
         * the program will echo the entered command
         */
	while(strcmp(inputString,"exit")!=0){
		
		printf("ezzat>");
		
		/* Get the command */
		fgets(inputString,100,stdin);

		/* replace new line(\n) with null operator*/
		inputString[strcspn(inputString,"\n")]='\0';

		/* Slice the inputString */
		command=strtok(inputString," ");
		arg1 = strtok(NULL," ");
		arg2 = strtok(NULL," ");

		if(command == NULL)
		{
			printf("\nError! Re-enter the command \n");

		}
		else if(!strcmp(command, "myPwd"))
		{
			/* Check on the received command */
			if(arg1 == NULL){
				arg2 = getcwd(arg2,PATH_MAX_SIZE);
				if(arg2!=NULL){
					printf("%s\n",arg2);
				}		
			}
			else
				printf("Error!!\n");
		}
		else if(!strcmp(command, "myEcho"))
		{
			if(arg1 == NULL){
				printf("\n");
			}

			else{
				printf("%s\n",arg1);
			}

		}
		else if(!strcmp(command, "myMv"))
		{
			/* File ID in process */
    			int fd_src=-1,fd_dest=-1;

    			/* Read & write bytes */
    			int rd_src=-1, wd_dest=-1;

   			/* Buffer at which we store the read file */
    			unsigned char buf[100];
			
			int noError = TRUE;
    			if(arg2 == NULL || arg1==NULL){
    				printf("Error !,please enter 2 file name or pathes as argument\n");
   				noError=FALSE;	
		       	}
    
			else{
				/* open File read only */
				fd_src = open(arg1, O_RDONLY);
			}
    			if ( fd_src < 0 ) {

				printf(">>Can not open the source file :(\n");
				break;
   			 }

			if(noError){

   			 /* open File write */
  			 fd_dest = open(arg2,O_CREAT|O_WRONLY|O_TRUNC,0644);
			}
   			 if (fd_dest < 0) {

	   			 char *file_path = strcat(arg2,"/");
	   			 file_path=strcat(file_path,arg1);

				/*It means that the file doesn't exist and we will move*/
				fd_dest = open(file_path,O_CREAT|O_WRONLY|O_TRUNC,0644);

				if(fd_dest < 0){
        				printf(">>Can not open the dest file :(\n");
        				break;
				}
    			}
			 if(noError){

   				 while ((rd_src = read(fd_src, buf, 100)) != 0) {
					if (rd_src < 0) {
	    					printf(">>Can not read from file:(\n");
	    					noError=FALSE;
					}
					
					if(noError){
					wd_dest = write(fd_dest, buf, rd_src);
					}

					if (wd_dest < 0) {
	    					printf(">>Can not write to  file:(\n");
	    					break;
					}
    				}
	                        unlink(arg1);
                	        close(fd_dest);
		
			 }

		}
		else if(!strcmp(command,"exit")){
		}
		else{
			printf("Unknown Commad\ntry again\n");
		}
		
	}

	printf("Good Bye:)\n");

	return 0;
}
