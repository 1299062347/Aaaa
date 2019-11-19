#include"my.h"
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
	int pid ,s;
	if((pid = fork())<=0)
	{
		perror("failed to fork\n");
		return -1;	
	}
	else if(pid == 0)
	{
		printf("%d :child is runing now\n",getpid());
				
		printf("%d: child is exit now\n",getpid());
		while(1);
		exit(120);	
	}
	else
	{
		printf("%d :parent is waiting zomble now\n",getpid());
		while((pid = wait(&s)) != -1)
		{
			printf("%d: parent is exit now\n",getpid());
			if(WIFEXITED(s))
			{
				printf("child %d is exiting normally,exit code = %d\n",pid,WEXITSTATUS(s));				
			}
			else if(WIFSIGNALED(s))
			{
				printf("child %d exit by singnal,singal no = %d\n",pid , WTERMSIG(s));			
			}
			else
			{
				printf("Not know\n");
			}
		}		
		
	}
	exit(0);
}
