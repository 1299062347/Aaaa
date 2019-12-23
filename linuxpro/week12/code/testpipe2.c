#include"my.h"
int main()
{
	pid_t r;
	int r_num = 0;
	int pipefd[2];
	char buf[1];
int ret=1,ret1 = 1;
	memset(buf,0,sizeof(buf));
	if(pipe(pipefd)<0)
	{
		perror("pipe failed\n");
		return -1;
}
	r = fork();
	if(r<0)
	{
		perror("fork failed\n");
		return -1;
	}
	else if(r == 0)
	{
		close(pipefd[1]);
		sleep(5);
printf("%d",ret);
sleep(5);
printf("child\n");
while(ret1)
{
	read(pipefd[0],buf,1);
	printf(" %s",buf);	
	r_num++;
}
printf(" %d",r_num);
printf("child end\n");
		close(pipefd[0]);
		exit(0);
	}
	else
	{
		close(pipefd[0]);
while(ret)
{
	ret = write(pipefd[1],"1",1);
}
		printf("parent write ok\n");
		close(pipefd[1]);
		return 0;
}
	return 0;
}
