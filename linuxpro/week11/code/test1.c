#include"my.h"
#include <sys/wait.h>
#include<stdlib.h>
int main(void)
{
	pid_t pid = -1;
//pid_t ret = -1;
	//int status = -1;
	pid = fork();
	if (pid > 0)
	{
		// 父进程
		//sleep(1);
		//ret = wait(&status);
		//printf("ret = %d\n",ret);
		printf("into parent.\n");
		exit(0);
	}
	else if (pid == 0)
	{
		// 子进程
		sleep(2);
		printf("into child\n");
		return 0;
	}
	else
	{
		perror("fork");
		return -1;
	}
	
	return 0;
}

