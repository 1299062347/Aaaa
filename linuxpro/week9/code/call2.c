#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <errno.h>
int main()
{
    char *arg[]={"./testmain2","123","abc","hello","ncu","edu",NULL};
    int ret;
    printf("call1:pid=%d,ppid=%d\n",getpid(),getppid());
    ret=execvp("testmain2",arg);
    printf("after calling! ret=%d\n",ret);
    return 0;
}

