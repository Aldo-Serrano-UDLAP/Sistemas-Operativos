#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

void PrintID(char name, int PID, int PPID);

int main(void)
{
	int fd, status,array[1000],i;
	pid_t pid_B,pid_C;
	pid_B = fork();
	
	if(pid_B == 0)
	{
		int resultado;
		PrintID('B',getpid(),getppid());
		resultado = execl("/home/aldo/Documents/Sistemas Operativos/Examen Segundo Parcial/procesoB","procesoB",NULL);
		return resultado;
	}
	if(pid_B > 0)
	{
		pid_C = fork();
		if(pid_C == 0)
		{
			sleep(3);
			PrintID('C',getpid(),getppid());	
		}
		if(pid_C > 0)
		{
			waitpid(pid_B,&status,0);
			printf("B termino de manera normal, status: %d\n",WEXITSTATUS(status));
			fd = open("enteros.txt",2);
			read(fd,array,sizeof(array));
			for(i=0;i<1000;i++)
			{
				printf("%d ",array[i]);
			}	
		}
	}
	
}
void PrintID(char name, int PID, int PPID)
{
	printf("Mi nombre es: %c\n",name);
	printf("Mi ID es: %d\n",PID);
	printf("EL ID de mi padre es %d\n",PPID);
}
