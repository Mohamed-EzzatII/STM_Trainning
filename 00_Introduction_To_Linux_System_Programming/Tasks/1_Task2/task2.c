
#include<stdio.h>
#include<string.h>/* To use strcmp,strcspn */

#define MAX_COMMAND_SIZE 100

int main(){

	/* Create a variable to store the command */
	char inputString[MAX_COMMAND_SIZE]={'D','\0'};

	printf("*********************************************************\n");
	printf("\nWelcome to my command shell\n");
	printf("Please note that the max command size is 100\n\n");
	printf("*********************************************************\n");

        /* Compare the input command to exit,if the user
         * entered exit the program will terminate,else
         * the program will echo the entered command
         */
	while(strcmp(inputString,"exit")!=0){
		
		printf("mesa_mesa>");
		
		/* Get the command */
		fgets(inputString,100,stdin);

		/* replace new line(\n) with null operator*/
		inputString[strcspn(inputString,"\n")]='\0';

		/*echo the command*/
		printf("%s\n",inputString);
	}

	printf("Good Bye:)\n");

	return 0;
}
