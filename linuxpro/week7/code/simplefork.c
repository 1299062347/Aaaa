#include"ourhdr.h"
int globa = 4;
int main(void)
{
pid_t pid;
int vari = 5;
printf("before fork\n");
if((pid = fork()) <0){
	printf("fork error\n");
	exit(0);
}else if(pid = 0){
	globa++;
	vari--;
	printf("Child Changed\n");
	printf("chile:golba = %d vari = %d\n",globa,vari);
}else{
	printf("Parent did not changed \n");
	printf(" parent:golba = %d vari = %d\n",globa,vari);
	exit(0);
}
exit(0);
}
