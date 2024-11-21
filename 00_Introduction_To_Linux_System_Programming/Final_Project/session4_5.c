/**************************************************************************
 ***************************Libriaries*************************************
 **************************************************************************/

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

/**************************************************************************
 ***************************Text Replacement*******************************
 **************************************************************************/

#define MAX_CMD_SIZE 200
#define MAX_ARG_SIZE 100
#define MAX_ARG_NO   10

/**************************************************************************
 ****************************Func Prototypes*******************************
 **************************************************************************/

pid_t fork(void);
int execve(const char *pathname, char *const argv[], char *const envp[]);
void myEcho();
void myPwd();
void myCd();

/**************************************************************************
 ****************************Main Program**********************************
 **************************************************************************/

int main(int argc, char **argv)
{
    /*************************Local Variables Decleration******************/    
    pid_t fork_r; 		  /* fork function return id */ 
    char *cmd="test";    	  /* the input command */ 
    char **argc_ex = NULL; 	  /* first argument to execvp */
//  char *argv_ex[] = { NULL };   /* second argument to execve (deleted)*/
    int status;	                  /* empty integer for wait to get the status */
    char *tokened_command=NULL;   /* To store the command after slicing it */

    while(1) {

	printf("ezzat_shell>>");

	/* alocate a pointer in heap for the command */ 
	cmd = (char *)malloc(sizeof(char)*MAX_CMD_SIZE);

	/* get the command from user */
	fgets(cmd, MAX_CMD_SIZE, stdin);

	/* replace \n with \0 (NULL) */
	cmd[strlen(cmd) - 1] = '\0';	
	
	if(strcmp(cmd ,"exit")==0){
		printf("Good Bye :(\n");
		return -1;
	}

	/* creating a new process without deleting the parent  process */	
	fork_r = fork();

	/* the returned value is -ve which means that its an error state */
	if (fork_r < 0) {
	    printf("Error in excution\n");
	}
	
	/* the returned value is zero which means that we are in the child process*/
	else if (fork_r == 0) {
	    /* it means that the user entered a command + arguments not a simple commad */
	    if(index(cmd,' ') != NULL){
		 
		/* alocate the arg_ex */
		argc_ex = (char **) malloc( sizeof(char *) * MAX_ARG_NO);	  
		
		/* alocate the first argument*/
		argc_ex[0] = (char *) malloc( sizeof(char) * MAX_ARG_SIZE);

		/* alocate the command */
		tokened_command = (char*)malloc(100*sizeof(char));

	        /* get the command as the first word */
		tokened_command = strtok(cmd," ");
		
		/* get the other words until the user entered commands are finished all
		 * which means that we reached at the end of cmd which is \0 */
		int i=1;
		argc_ex[0]="";/* Don't remove this line */
		while( (argc_ex[i]=(char *)malloc(sizeof(char) * MAX_ARG_SIZE ) ) && (argc_ex[i]=strtok(NULL," ")) ){
			i++;
		}

		/*The user wants the built-in echo command*/
		if(strcmp(tokened_command,"myEcho")==0){
			for(int j=1;j<i;j++){
				printf("%s ",argc_ex[j]);
			}
			printf("\n");
		}

		/*The user wants the built-in cd command*/
		else if(strcmp(tokened_command,"myCd")==0){
                   if( chdir(argc_ex[1]) ){
		   	printf("Error in Path\n");
		   }
                 }

		else{	
			execvp(tokened_command,argc_ex);
		        /* if the code reached that line it means that an error occures and there is 
             		 * no process created :(
            		 */
            		printf("Exexution failed\n");
		}
		free(tokened_command);
		free(argc_ex);
	    	argc_ex = NULL;
	    }
		
	    else{
        	
		if(strcmp(cmd,"myPwd")==0){
			cmd = getcwd(cmd,100);
			if(cmd!=NULL){
				printf("%s\n",cmd);
			}
                }

		else{
	    		/* create a new process */
	    		execvp(cmd,argc_ex);
			/* if the code reached that line it means that an error occures and there is
             		 * no process created :(
             	 	 */
            		 printf("Exexution failed\n");

		}

		free(cmd);
	    }
	}

	/* the returned value is greater than 0 which is the parent process ID ,
	 * which means that we are in the parent process
	 */
	else if (fork_r > 0) {
	
	    /* waiting for the child process to end and then get back to parent */
	    wait(&status);
	}

	//free(tokened_command);
    }

    return 0;
}
