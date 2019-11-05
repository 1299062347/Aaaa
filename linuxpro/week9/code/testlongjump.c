#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <errno.h>
#include<setjmp.h>
static jmp_buf g_stack_env;
static void fun1(void);
static void fun2(void);
void main(void)
{
	if(0 == setjmp(g_stack_env)){
	printf("normal flow\n");
	fun1();
}else{
	printf("long jump flow\n");
}
}

static void fun1(void)
{
	printf("Enter fun1\n");
	fun2();
}
static void fun2(void)
{
	printf("Enter fun2\n");
	longjmp(g_stack_env,1);
printf("leave fun2\n");
}
