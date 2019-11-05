#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{	
	char *args[] = {"/home/piggy/Desktop/Aaaa/Aaaa/linuxpro/week9/code/testpid","hello","word","NULL"};
	printf("pid = %d\n",getpid());
if(execv("./testpid" , args)<0)
perror("execve error");
}
