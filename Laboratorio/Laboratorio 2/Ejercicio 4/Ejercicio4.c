#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(void)
{
	pid_t pidR,pidW,pidT,pidS,pidL,pidP;
	
	pidR = fork();
	
	if(pidR==0)
	{
		printf("Soy el hijo de R, mi nombre es T\n");
		printf("Mi ID es: %d\n",getpid());
		printf("El ID de mi padre es: %d\n",getppid());
		
		pidT = fork();
		
		if(pidT==0)
		{
			printf("Soy el hijo de T, mi nombre es V\n");
			printf("Mi ID es: %d\n",getpid());
			printf("El ID de mi padre es: %d\n",getppid());
		}
	}
	if(pidR>0)
	{
		printf("Mi nombre es R, soy el padre de todos\n");
		printf("Mi ID es: %d\n",getpid());
		
		pidW = fork();
		if(pidW==0)
		{
			printf("Soy el hijo de R, mi nombre es W\n");
			printf("Mi ID es: %d\n",getpid());
			printf("El ID de mi padre es: %d\n",getppid());
			
			pidS = fork();
			if(pidS==0)
			{
				printf("Soy el hijo de W, mi nombre es S\n");
				printf("Mi ID es: %d\n",getpid());
				printf("El ID de mi padre es: %d\n",getppid());
			}
			if(pidS>0)
			{
				pidL = fork();
				
				if(pidL==0)
				{
					printf("Soy el hijo de W, mi nombre es L\n");
					printf("Mi ID es: %d\n", getpid());
					printf("El ID de mi padre es: %d\n",getppid());
					
					pidP = fork();
					if(pidP==0)
					{
						printf("Soy el hijo de L, mi nombre es P\n");
						printf("Mi ID es: %d\n",getpid());
						printf("El ID de mi padre es: %d\n",getppid());
					}
				}
			}
		}	
	}
}
