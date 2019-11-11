#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	FILE *fp;
	char buf[] = "hello world\n";
	if((fp = fopen("test_exit.txt","w")) == NULL)
	{
		perror("fail to fopen");
		return -1;
	}
	if(fputs(buf,fp) == EOF)
	{
		perror("fail to fputs");
		return -1;
	}
	exit(0);
}
