#include"ourhdr.h"
char buf[] = {"write to stdout\n"};
int main()
{
	pid_t id;
	if(write(STDOUT_FILENO,buf,sizeof(buf)-1) != sizeof(buf)-1)
		perror("can not write");
	printf("printf ");
	id = fork();
	if(id<0)
	{
		perror("can not fork");
}
return 0;
}
