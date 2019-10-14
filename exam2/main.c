#include"mylist.h"
#include"stdio.h"
int main()
{
	int a[100],m,s;
	init(a);
	show(a,100);
	m = max(a,100);
	s = sum(a,100);
	printf("max = %d sum = %d",m,s);
	return 0;
}
