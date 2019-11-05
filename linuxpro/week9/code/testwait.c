#include <sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>
#include"ourhdr.h"
int main(void)
{
	pid_t pid = -1;
	pid_t ret = -1;
	int status = -1;
	int fd,size;
    char buff[20];
	char f[] = "father";
	char c[] = "child";
	pid = fork();
	if (pid > 0)
	{
		// 父进程
		//sleep(1);
		printf("into parent.\n");
		ret = wait(&status);
		if(fd = open("forktofile", O_WRONLY|O_CREAT)<0)
		{
			perror("father open error!\n");
		}
		if(write(fd,f,sizeof(f))!=sizeof(f))
		{
			perror("write error!\n");
		}
		size =  read(fd, buff, sizeof(buff));
		close(fd);
		printf("parent out %s", buff);
	}
	else if (pid == 0)
	{
		// 子进程
		printf("into child\n");
		if(fd = open("forktofile",O_RDWR|O_CREAT)<0)
		{
			perror("child open error!\n");
		}
		if(write(fd,c,sizeof(c))!=sizeof(c))
		{
			perror("write error!\n");
		}
		
		size =  read(fd, buff, sizeof(buff));
		close(fd);
		printf("child out:%s", buff);
		//exit(0);
	}
	else
	{
		perror("fork");
		return -1;
	}
	
	return 0;
}

