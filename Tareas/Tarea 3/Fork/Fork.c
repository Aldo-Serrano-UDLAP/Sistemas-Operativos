#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>

// Funcion que ejecuta una jerarquia de procesos
// Se desea escribir numeros en un archivo de texto y despues
// leerlos para mostrarlos en pantalla
int main(void)
{
	int fd, numeros[5] = {3,6,7,18,21},arreglo[5],i;
	pid_t pid = fork();
	printf("\n\n");
	fd = open("datos.txt",2);
	if(fd<0)
	{
		perror("Error");
	}
	if(pid == 0)
	{
		printf("Soy el proceso hijo\n");
		write(fd,numeros,sizeof(numeros));
		printf("Adios :D\n");
	}
	if(pid > 0)
	{
		sleep(3);
		printf("Soy el proceso padre\n");
		printf("Estos son los numeros que se escribieron:\n");
		read(fd,arreglo,20);
		for(i=0;i<5;i++)
		{
			printf("%d ",arreglo[i]);
		}
		printf("\nAdios :D\n");
	}
	close(fd);
	return 0;
}
