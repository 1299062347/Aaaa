#include"my.h"
int main()
{
    int fd, size;
    char s[] = "Hello Linux!\n", buffer[20];
    fd = open("buff.txt", O_WRONLY|O_CREAT);
	printf("w fd = %d\n",fd);
    write(fd, s, sizeof(s));
    close(fd);
	printf("c fd = %d\n",fd);
	fd = open("buff.txt", O_RDONLY);
	printf("r fd = %d\n",fd);
    size = read(fd, buffer, sizeof(buffer));
    close(fd);
 	printf("testread out :%s\n", buffer);
    return 0;
}
