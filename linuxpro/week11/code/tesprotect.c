#include<stdio.h>
#include<time.h>
void init_demon(void)

int main()
{
	FILE *fp;
	time_t t;
	init_demon();
	while(1)
	{
		sleep(10);
		if((fp = fopen("protect.log","a")) >= 0)
		{
			t = time(0);
			fprintf(fp , "protect is running,time is %s\n",asctime(localtime(&t)));
			fclose(fp);		
		}
	}
	return 0;
}
