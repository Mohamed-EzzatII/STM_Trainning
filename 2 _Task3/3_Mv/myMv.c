#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(int argc,char **argv)
{

    /* File ID in process */
    int fd_src,fd_dest;

    /* Read & write bytes */
    int rd_src, wd_dest;

    /* Buffer at which we store the read file */
    unsigned char buf[100];

    if(argc != 3){
    printf(">>Error! please enter 2 file name or pathes as argument\n");
    return 0;
    }
    /* open File read only */
    fd_src = open(argv[1], O_RDONLY);
    
    if (fd_src < 0) {

	printf(">>Can not open the source file :(\n");
	return 0;
    }

    /* open File write */
    fd_dest = open(argv[2],O_CREAT|O_WRONLY|O_TRUNC,0644);

    if (fd_dest < 0) {

	    char *file_path = strcat(argv[2],"/");
	    file_path=strcat(file_path,argv[1]);

	/*It means that the file doesn't exist and we will move*/
	fd_dest = open(file_path,O_CREAT|O_WRONLY|O_TRUNC,0644);
	
	if(fd_dest < 0){
        printf(">>Can not open the dest file :(\n");
        return 0;
	}
    }

    while ((rd_src = read(fd_src, buf, 100)) != 0) {
	if (rd_src < 0) {
	    printf(">>Can not read from file:(\n");
	    return 0;
	}

	wd_dest = write(fd_dest, buf, rd_src);

	if (wd_dest < 0) {
	    printf(">>Can not write to  file:(\n");
	    return 0;
	}
    }

	unlink(argv[1]);
	close(fd_dest);
return 0;
}
