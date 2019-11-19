#include<unistd.h>
#include<signal.h>
#include<sys/param.h>
#include<sys/types.h>
#include<sys/stat.h>
void init_demon(void)
{

	pid_t child1,child2;
	int i;
	child1 = fork();
	if(child>0){
		exit(0);
	}else if(child1<0)
	{
		perror("fork error");
		exit(1);
	}
	setsid();
	chdir("tmp");
	umask(0);
	for(i = 0 ;i<NOFILE;++i)
{
		close(i);
}
}
