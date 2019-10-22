#include"stdio.h"
#include<stdlib.h>
#include"mylist.h"
#include<time.h>


void show(int *a,int n)
{
	int i;
	for(i=0 ;i<n ;i = i+4)
	printf("%d %d %d %d\n",a[i] ,a[i+1] ,a[i+2] ,a[i+3]);	
}

void init(int *a)
{
	int i;
	srand((int)time(0));
	for(i=0 ; i<100 ; i++)
	{
		a[i]=1+(int)(100.0*rand()/(RAND_MAX+1.0));	
	}
}
