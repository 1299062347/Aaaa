#include"my.h"

void sig(int signo , siginfo_t *info,void *context)
{
	printf("\nget signal :%d\n",signo);
	printf("signal number is %d\n",info->si_signo);
	printf("sneder pid %d \n",info->si_pid);
	printf("sigval = %d\n",info)
}

int main()
{
	struct sigaction new;
	sigemptyset(&new.sa_mask);
	new.sa_sigaction = sig;
	new.sa_flags |= SA_SIGINFO|SA_RESTART;
	if(sigaction(36,&new,NULL) == -1)
	{
		printf("set signal process mode \n");
	}
	while(1)
	{
		pause();
	}
	printf("Done\n");
	exit(0);
}
