#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
void main()
{
	pid_t result;
	int r_num;
	int pipe_fd[2];
	char buf_r[100];
	memset(buf_r,0,sizeof(buf_r));
	if(pipe(pipe_fd)<0)
	{
		printf("pipe fault\n");
		exit(0);
	}
	result = fork();
	if(result<0)
	{
		perror("fork fault\n");
		exit(1);
	}
	else if(result == 0)
	{
		close(pipe_fd[1]);
		if((r_num = read(pipe_fd[0],buf_r,100))>0)
		{
			printf("child read from pipe %d , string is %s\n",r_num,buf_r);		
		}
		close(pipe_fd[0]);
		exit(0);	
	}
	else
	{
		close(pipe_fd[0]);
		if(write(pipe_fd[1],"first string",12) != -1)
		{
			printf("parent write into pipe first String\n");	
		}
		if(write(pipe_fd[1],"second string",13) != -1)
		{
			printf("parent write into pipe second String\n");	
		}
		close(pipe_fd[1]);
		waitpid(result,NULL,0);
		exit(0);
	}
}
