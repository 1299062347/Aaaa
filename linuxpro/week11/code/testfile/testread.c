#include"my.h"
int main()
{
	int fd, size;
	char buffer[20];
	fd = open("buff.txt", O_RDONLY);
    size = read(fd, buffer, sizeof(buffer));
    close(fd);
 	printf("testread out :%s\n", buffer);
	return 0;
}
