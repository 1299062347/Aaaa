#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
	printf("pid = %d ,ppid = %d\n",getpid(),getppid());
}
