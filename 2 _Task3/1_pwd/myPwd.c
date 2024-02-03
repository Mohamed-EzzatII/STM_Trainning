
#include<stdio.h>
#include<string.h> /* To use strcmp,strcspn */
#include<unistd.h> /* To use getwd() */

#define PATH_MAX_SIZE 100
int main(int argc,char **argv){

	/* An pointer to char to store the output path*/
	char *buff = NULL;

	/* Check on the received command */
	if(argc == 1){
		buff = getcwd(buff,PATH_MAX_SIZE);
		if(buff!=NULL){
			printf("%s\n",buff);
			return 0;
		}
	}
	printf("Error!!\n");
	return 0;
}
