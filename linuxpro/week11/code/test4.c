#include"my.h"
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
	int pid1,pid2 ,s1,s2,p1,p2;
	if((pid1 = fork())<=0 || (pid2 = fork())<=0)
	{
		perror("failed to fork\n");
		return -1;	
	}
	else if(pid1 == 0)
	{
		printf("%d :child1 is runing now\n",getpid());
				
		printf("%d: child1 is exit now\n",getpid());
		exit(120);	
	}
	else if(pid2 == 0)
	{
		printf("%d :child2 is runing now\n",getpid());
				
		printf("%d: child2 is exit now\n",getpid());
		exit(130);	
	}
	else
	{
		printf("%d :parent is waiting zomble now\n",getpid());
		p1 = wait(&s1);
		p2 = wait(&s2);
		if(WEXITSTATUS(s1) == 120)
		{
			printf("child1 p1 = %d\n",p1);
			printf("child2 p2 = %d\n",p2);
		}
		else if(WEXITSTATUS(s2) == 120)
		{
			printf("child1 p2 = %d\n",p2);
			printf("child2 p1 = %d\n",p1);
		}
		printf("parent end\n");
	}
}
