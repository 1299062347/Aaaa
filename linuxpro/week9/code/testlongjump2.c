#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <errno.h>
#include<setjmp.h>
static jmp_buf g_stack_env;
static void fun1(int *a,int *b,int *c);
void main(void)
{
int a = 1,b = 2,c = 3;
	if(0 == setjmp(g_stack_env)){
	printf("normal flow\n");
printf("1:a = %d,b = %d , c = %d\n",a,b,c);
	fun1(&a,&b,&c);
}else{
	printf("long jump flow\n");
}
}

static void fun1(int *a,int *b,int *c)
{
	printf("Enter fun1\n");
++(*a);
++(*b);
++(*c);
printf("2:a = %d,b = %d , c = %d\n",*a,*b,*c);

longjmp(g_stack_env,1);
printf("leave fun1");
}
