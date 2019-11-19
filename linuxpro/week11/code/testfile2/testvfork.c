#include"my.h"
#include<sys/wait.h>
int main(void)
{
	pid_t pid = -1;
pid_t ret = -1;
	int status = -1;
	int size;
	FILE *fd; 
	char buffer1[50],buffer2[50];
	char s[] = "Hello Linux!\n";
	pid = vfork();
	if (pid > 0)
	{
		// 父进程
		//sleep(1);
ret = wait(&status);
		printf("ret = %d\n",ret);
		printf("into parent.\n");
  		fgets(buffer2,12,fd);
		printf("father out :%s\n",buffer2);
 		fclose(fd);
		printf("father end\n");
	}
	else if (pid == 0)
	{
		// 子进程
		printf("into child\n");
		fd = fopen("buff2.txt", "r+");
		fgets(buffer1,12,fd);
		printf("father out :%s\n",buffer1);
		printf("child end\n");
	}
	else
	{
		perror("fork");
		return -1;
	}
	
	exit(0);
}

