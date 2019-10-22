#include"ourhdr.h"
#define SIZE 512
int main (int arge, char *argv[])
{
char buf[SIZE];
if(setvbuf(stdin,buf,_IONBF,SIZE)!=0){
	perror("将标准输入 stdin的输入设置为无缓冲失败!n");
	return 1;
}
printf("将标准shuru stdin的输入设置为无缓冲成功!\n");
printf("stdin类xinwei:");
if(stdin ->_flags & _IO_UNBUFFERED)
{
printf("无缓冲\n");
}
else if (stdin->_flags & _IO_LINE_BUF)
{
printf("行缓冲\n");
}else{
printf("全缓冲\n");
}
printf("小为 %ld\n", stdin -> _IO_buf_end - stdin -> _IO_buf_base);
printf("述符为 %d\n", fileno( stdin));
if(setvbuf (stdin, buf,_IOFBF, SIZE) !=0)
{
 printf("修改标准输入 stdin的类型成功!\n");
	return 2;
}
printf("将标准shuru stdin的输入设置为无缓冲成功!\n");
printf("stdin类xinwei:");
if(stdin ->_flags & _IO_UNBUFFERED)
{
printf("无缓冲\n");
}
else if (stdin->_flags & _IO_LINE_BUF)
{
printf("行缓冲\n");
}else{
printf("全缓冲\n");
}
printf("小为 %ld\n", stdin -> _IO_buf_end - stdin -> _IO_buf_base);
printf("述符为 %d\n", fileno( stdin));
return 0;
}

