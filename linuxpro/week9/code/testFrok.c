#include <sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/resource.h>
#include"ourhdr.h"
int global1 = 1;
int global2;
void main()
{
int i = 10;
static int k = 20;
int status;
pid_t result;
result = fork();
int fd, size;
char c[] = "child w\n",  f[] = "father w\n",buffer[80];
int opri,npri;

if(result == -1)
{
	perror("fork error");
    
	exit;
}
else if(result == 0)
{
	sleep(10);
	printf("child\n");
	opri = getpriority(PRIO_PROCESS,getpid());
	printf("old pri %d\n",opri);
	//fd = open("/tmp/temp", O_WRONLY|O_CREAT);
   // write(fd, c, sizeof(c));
}
else
{
	
	//wait(&status);
 	//fd = open("/tmp/temp", O_RDONLY);
   // size = read(fd, buffer, sizeof(buffer));
   // close(fd);
    //printf("f out:%s", buffer);	
	//npri = nice(3);
	setpriority(PRIO_PROCESS,getppid(),3);
	sleep(10);
	printf("father\n");
	opri = getpriority(PRIO_PROCESS,getppid());
	printf("old pri %d\n",opri);
    

}
	exit;
}
