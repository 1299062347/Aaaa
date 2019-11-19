#include"my.h"
#include <sys/wait.h>
#include<stdlib.h>
int main(void)
{
	pid_t pid = -1;
	pid_t ret = -1;
	int status = -1;
	int fd = 0, size;
   	char s[] = "Hello Linux!\n", buffer[20];
	pid = vfork();
	if (pid > 0)
	{
		// 父进程
		//sleep(1);
		printf("into parent.\n");
		ret = wait(&status);
		printf("ret = %d\n",ret);
		printf("father before fd = %d\n",fd);
		fd = open("vbuff2.txt", O_RDONLY);
		printf("father read fd = %d\n",fd);
  		size = read(fd, buffer, sizeof(buffer));
		printf("father read :%s\n", buffer);
 		close(fd);
	}
	else if (pid == 0)
	{
		// 子进程
		sleep(1);
		printf("into child\n");
		printf("child before fd = %d\n",fd);
		printf("child before s = %s\n",s);
    	fd = open("vbuff2.txt", O_WRONLY|O_CREAT);
		printf("child write fd = %d\n",fd);
    	write(fd, s, sizeof(s));
    	close(fd);
		printf("child close fd = %d\n",fd);
		fd = open("vbuff2.txt", O_RDONLY);
		printf("child read fd = %d\n",fd);
    	size = read(fd, buffer, sizeof(buffer));
    	close(fd);
 		printf("testread out :%s\n", buffer);
	}
	else
	{
		perror("fork");
		return -1;
	}
	
	exit(0);
}

