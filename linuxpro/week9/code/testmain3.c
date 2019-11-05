#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <errno.h>
static void __attribute__ ((constructor)) before_main()
{
	printf("before main\n");
}
static void callback1()
{
	printf("1 after main\n");
}
static void callback2()
{
	printf("2 after main\n");
}
static void callback3()
{
	printf("3 after main\n");
}
int main(int argc,char *argv[])
{
   atexit(callback1);
   atexit(callback2);
   atexit(callback3);
   printf("main begin");
   for(int i=0;i<argc;i++)
       printf("test3:arg[%d]:%s\n",i,argv[i]);
   sleep(2);
   printf("main finish");
   return 0;

}

