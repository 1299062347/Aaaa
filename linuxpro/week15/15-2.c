#include"my.h"

void *worker1(void *);
void *worker2(void 2);

int c = 100;
pthread_mutex_t mutex;
int main()
{
	int ret;
	pthread_t tid[2];
	pthread_mutex_init(&mutex,NULL);
	ret = pthread_create(&tid[0],NULL,worker1,NULL);
	if(ret != 0)
	{
		perror("thread1 failed\n");
		exit(1);
	}
	ret = pthread_create(&tid[0],NULL,woeker2,NULL);
	if()
}
