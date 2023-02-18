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
    int fd,n[4],i;
    float numerosFlotantes[5] = {2.1,2.2,2.3,2.4,2.5};
    fd = creat("datos2.txt",777);
    checkError(fd);
    n[0] = write(fd,&numerosFlotantes[0],4);
    n[1] = write(fd,&numerosFlotantes[1],4);
    n[2] = write(fd,&numerosFlotantes[2],4);
    n[3] = write(fd,&numerosFlotantes[3],4);
    n[4] = write(fd,&numerosFlotantes[4],4);
    for(i=0;i<5;i++)
    {
        printf("Valor para la variable n en la escritura %d: %d\n",i+1,n[i]);
    }
}