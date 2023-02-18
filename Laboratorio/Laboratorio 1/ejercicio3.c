#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>

void checkError (int fileDescriptor)
{
    if(fileDescriptor<0)
    {
        if(errno == EAGAIN)
        {
            printf("Archivo bloqueado");
        }
        else if(errno == EACCES)
        {
            printf("Problema de permisos para el archivo");
        }
        else if(errno == EBADF)
        {
            printf("Mal Descriptor del archivo");
        }
        else if(errno == ENOMEM)
        {
            printf("No hay suficiente memoria");
        }
        else if(errno == ENOENT)
        {
            printf("No hay tal archivo");
        }
        else if(errno == EINTR)
        {
            printf("Una llamada al sistema fue interrumpida");
        }
        else if(errno == ENOSYS)
        {
            printf("La llamada al sistema invocada no se encuentra implementada");
        }
        else
        {
            printf("Error desconocido");
        }
    }
}

int main(void)
{
    int fd,i;
    float numeros[5];
    fd = open("datos.txt",0);
    checkError(fd);
    read(fd,numeros,20);
    for(i=0;i<5;i++)
    {
        printf("%.1f ",numeros[i]);
    }
    close(fd);
    return 0;
}