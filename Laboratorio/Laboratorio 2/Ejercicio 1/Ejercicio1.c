#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>

int main(void)
{
	pid_t pid;
	
	int i, n=5;
	
	for(i=1;i<n;i++)
	{
		pid = fork();
		
		if(pid!=0)
		{	
			break;
		}
		if(pid==0)
		{
			printf("\nSoy el hijo numero %d\n",i);
			printf("Mi ID es: %d\n",getpid());
			printf("El ID de mi padre es: %d\n",getppid());
		}
	}
}
