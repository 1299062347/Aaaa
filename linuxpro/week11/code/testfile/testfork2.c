#include"my.h"
#include <sys/wait.h>
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
		ret = wait(&status);
		printf("ret = %d\n",ret);
		fd = open("buff2.txt", O_RDONLY);
		printf("fd = %d\n",fd);
  		size = read(fd, buffer, sizeof(buffer));
		printf("father read :%s\n", buffer);
 		close(fd);
		return 0;
	}
	else if (pid == 0)
	{
		// 子进程
		printf("into child\n");
		char s[] = "Hello Linux!\n";
		fd = open("buff2.txt", O_WRONLY|O_CREAT);
   		write(fd, s, sizeof(s));
		printf("fd = %d\n",fd);
   		close(fd);
		fd = open("buff2.txt", O_RDONLY);
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

