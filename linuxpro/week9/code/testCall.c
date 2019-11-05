#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
	printf("pid = %d ,ppid = %d\n",getpid(),getppid());
system("/home/piggy/Desktop/Aaaa/Aaaa/linuxpro/week9/code/testpid");
	printf("after calling");
}
