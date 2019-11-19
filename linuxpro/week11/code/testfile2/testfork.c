#include"my.h"
#include <sys/wait.h>
int main(void)
{
	pid_t pid1,pid2;
	int status = -1;
	int size;
	int pid;
	FILE *fd = fopen("buff.txt", "a+"); 
	char buffer[10];
	pid1 = fork();
	pid2 = fork();
	if(pid1 < 0)
	{
		perror("fork child1 error");
		exit(0);
	}
	if(pid2 < 0)
	{
		perror("fork child2 error");
		exit(1);
	}
	if (pid1 == 0&&pid2 != 0)
	{
		// 子进程
		
		printf("into child1\n");
		char str[] = {"123"};
int i;
		fputs(str,fd);
		printf("child1 end\n");
		return 0;
	}
	else if (pid2 == 0&&pid1 != 0)
	{
		// 子进程
		
		printf("into child2\n");
int i;
		char str[] = {"456"};
		fputs(str,fd);
		printf("child2 end\n");
		return 0;
	}
	else if(pid1 >0 && pid2 >0)
	{
		// 父进程
		//sleep(1);
		wait(&status);
		wait(&status);
		printf("into parent.\n");
  		fgets(buffer,sizeof(buffer),fd);
		printf("father out :%s\n",buffer);
 		fclose(fd);
	}
	
	return 0;
}

