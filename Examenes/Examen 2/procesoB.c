#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
	int fd,array[1000],i;
	fd = open("enteros.txt",2);
	
	for(i=0;i<1000;i++)
	{
		array[i] = i+1;
	}
	
	write(fd,array,sizeof(array));
	
	if(fd<0)
	{
		perror("Error");
		exit(1);
	}
	
	close(fd);
	return 3;
}
