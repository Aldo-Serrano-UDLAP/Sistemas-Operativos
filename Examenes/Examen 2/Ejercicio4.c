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
	int status=0;
	float res;
	pid_t pid_D,pid_E,pid_F;
	
	pid_F = fork();
	
	if(pid_F == 0)
	{
		return 14;
	}
	if(pid_F > 0)
	{
		pid_E = fork();
		if(pid_E == 0)
		{
			return 13;
		}
		if(pid_E > 0)
		{
			pid_D = fork();
			if(pid_D == 0)
			{
				return 2;
			}
			if(pid_D > 0)
			{
				waitpid(pid_D,&status,0);
				printf("El retorno es: %d\n",WEXITSTATUS(status));
				res = ((float)WEXITSTATUS(status)*2.0)-1.0;
				waitpid(pid_F,&status,0);
				printf("El retorno es: %d\n",WEXITSTATUS(status));
				res = res + ((float)WEXITSTATUS(status)/100.0);
				waitpid(pid_E,&status,0);
				printf("El retorno es: %d\n",WEXITSTATUS(status));
				res = res + (((float)WEXITSTATUS(status) + 3.0)/10000.0);
				printf("El resultado final es %f\n",res);
			}
		}
	}
	
}
