#include"my.h"
#include<stdlib.h>
int main()
{
	int pid ;
	if((pid = fork())<=0)
	{
		perror("failed to fork\n");
		return -1;	
	}
	else if(pid == 0)
	{
		printf("%d :child is runing now\n",getpid());
		while(1);		
		printf("%d: child is exit now\n",getpid());
		exit(0);	
	}
	else
	{
		printf("%d :parent is runing now\n",getpid());
		while(1);		
		printf("%d: parent is exit now\n",getpid());
	}
	exit(0);
}
