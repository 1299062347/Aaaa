#include"my.h"
#include <sys/wait.h>
#include<stdlib.h>
int main(void)
{
	pid_t pid = -1;
	pid_t ret = -1;
	int status = -1;
	int fd,size;
	char buffer[50];
	
	pid = fork();
	if (pid > 0)
	{
		// 父进程
		//sleep(1);

		printf("into parent.\n");
		char s[] = "Hello Linux!\n";
		fd = open("buff3.txt", O_WRONLY|O_CREAT);
   		write(fd, s, sizeof(s));
		printf("fd = %d\n",fd);
   		close(fd);
		return 0;
	}
	else if (pid == 0)
	{
		// 子进程
		sleep(2);
		printf("into child\n");
		
		fd = open("buff3.txt", O_RDONLY);
    	size = read(fd, buffer, sizeof(buffer));
   		close(fd);
 		printf("testread out :%s\n", buffer);
		return 0;
	}
	else
	{
		perror("fork");
		return -1;
	}
	
	return 0;
}

