#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <errno.h>
int main()
{
    int ret;
    printf("call1:pid=%d,ppid=%d\n",getpid(),getppid());
    ret=system("./testmain2 123 abc hello ncu edu");
    printf("after calling! ret=%d\n",ret);
    return 0;
}

