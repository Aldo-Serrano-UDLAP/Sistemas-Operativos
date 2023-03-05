#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

void CheckError(int fd);
void PrintArray(int a[],int size);
void SumArray(int a[],int b[],int c[],int size);

int main(void)
{
	int fd,fd2,i; 
	int pares[] = {2,4,6,8,10,12,14,16,18,20};
	int impares[] = {1,3,5,7,9,11,13,15,17,19};
	int arregloPar[10],arregloImpar[10],arregloSuma[10];
	
	pid_t pid = fork();
	
	fd2 = open("Pares.txt",2);
	CheckError(fd2);
	
	if(pid==0)
	{
		write(fd2,pares,sizeof(pares));
		printf("Se escribieron los pares\n");
	}
	
	if(pid>0)
	{
		pid_t pid2 = fork();
		fd = open("Impares.txt",2);
		CheckError(fd);
			
		if(pid2==0)
		{
			write(fd,impares,sizeof(impares));
			printf("Se escribieron los impares\n");
		}
		if(pid2>0)
		{	
			sleep(3);
			read(fd2,arregloPar,sizeof(pares));
			printf("Estos son los numeros pares leidos:\n");
			PrintArray(arregloPar,10);
			
			read(fd,arregloImpar,sizeof(impares));
			printf("Estos son los numeros impares leidos:\n");
			PrintArray(arregloImpar,10);
			
			printf("El resultado de la suma de ambos arreglos es:\n");
			SumArray(arregloPar,arregloImpar,arregloSuma,10);
			PrintArray(arregloSuma,10);	
		}
	}
	close(fd);
	close(fd2);
	return 0;
}

void CheckError(int fd)
{
	if(fd<0)
	{
		perror("Error:");
	}
}

void PrintArray(int a[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void SumArray(int a[],int b[],int c[],int size)
{
	int i,*resultado[size];
	for(i=0;i<size;i++)
	{
		c[i] = a[i] + b[i];
	}
}


