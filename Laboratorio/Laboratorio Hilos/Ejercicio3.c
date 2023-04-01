#include<stdio.h>
#include<pthread.h>

int array[5] = {0};
void* verify(void *args);

int main(void)
{
	int i=0,status=0;
	pthread_t thread_A;
	
	status = pthread_create(&thread_A,NULL,verify,NULL);
	
	for(i=0;i<5;i++)
	{
		printf("Escribe un valor para el arreglo\n");
		scanf("%d",&array[i]);
	}
	pthread_join(thread_A,NULL);
	printf("Hemos terminado\n");
	
}

void* verify(void *args)
{
	int i=0;
	while(1)
	{
		for(i=0;i<5;i++)
		{
			if(array[i]!=0&&i!=4)
			{
				printf("%d\n",array[i]);
				array[i] = 0;
			}
			if(array[i]!=0&&i==4)
			{
				printf("%d\n",array[i]);
				array[i] = 0;
				pthread_exit(NULL);
			}
		}
	}	
}
