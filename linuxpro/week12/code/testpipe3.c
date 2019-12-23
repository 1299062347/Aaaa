#include"my.h"
int main()
{
	pid_t c1,c2,c3;
	int r_num;
	int pipefd[2];
	char buf[4096];
	memset(buf,0,sizeof(buf));
	if(pipe(pipefd)<0)
	{
		perror("pipe failed\n");
		return -1;	
	}
c1 = fork();
c2 = fork();
c3 = fork();
	if(c1 == 0 && c2 != 0 && c3 != 0)
	{
		close(pipefd[0]);
		if(write(pipefd[1],"123456789",10) != -1)
		{
			printf("child1 write ok\n");			
		}
		close(pipefd[1]);
exit(0);
	}
	if(c1 != 0&&c2 == 0 && c3 != 0)
	{
sleep(5);
		if((r_num = read(pipefd[0],buf,100))>0)
		{
			printf("child2 read from pipe: %s,total = %d\n",buf,r_num);			
		}
		close(pipefd[0]);
		if(write(pipefd[1],"hello word",10) != -1)
		{
			printf("child2 write ok\n");			
		}
		close(pipefd[1]);
		exit(0);
	}
	if(c1 != 0&&c2 != 0 && c3 == 0)
	{
sleep(10);
		close(pipefd[1]);
		if((r_num = read(pipefd[0],buf,100))>0)
		{
			printf("child3 read from pipe: %s,total = %d\n",buf,r_num);			
		}
		close(pipefd[0]);
		exit(0);
	}
return 0;
}
