#include<stdio.h>
#include<pthread.h>

void* search1(void *args);
void* search2(void *args);
void* search3(void *args);
int divide(int number);

int array[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
int numberDivision1 = 0,numberDivision2 = 0,numberDivision3 = 0,state = 0,found_flag=0;
int subArray1[4] = {0}, subArray2[4] = {0}, subArray3[4] = {0};

int searchNumber = 6;

int main(void)
{
	int i = 0;
	
	numberDivision1 = divide(12);
	numberDivision2 = divide(12*2);
	numberDivision3 = divide(12*3);
	
	for(i=0;i<numberDivision1;i++)
	{
		subArray1[i] = array[i];
	}
	for(i=numberDivision1;i<numberDivision2;i++)
	{
		subArray2[i] = array[i];
	}
	for(i=numberDivision2;i<numberDivision3;i++)
	{
		subArray3[i] = array[i];
	}
	
	
	pthread_t thread_A, thread_B, thread_C;
	
	state = pthread_create(&thread_A,NULL,search1,NULL);
	pthread_join(thread_A,NULL);
	state = pthread_create(&thread_B,NULL,search2,NULL);
	pthread_join(thread_B,NULL);
	state = pthread_create(&thread_C,NULL,search3,NULL);
	pthread_join(thread_C,NULL);
	
	if(found_flag)
	{
		printf("Se encontro el numero :D\n");
	}
}

int divide(int number)
{
	int division=0;
	division = number/3;
	return division;	
}

void* search1(void *args)
{
	int i=0;
	
	for(i=0;i<4;i++)
	{
		if(searchNumber == subArray1[i])
		{
			found_flag = 1;
			pthread_exit(NULL);
		}
			
	}
	
}
void* search2(void *args)
{
	int i=0;
	
	for(i=0;i<4;i++)
	{
		if(searchNumber == subArray2[i])
		{
			found_flag = 1;
			pthread_exit(NULL);
		}
	}
	
}
void* search3(void *args)
{
	int i=0;
	
	for(i=0;i<4;i++)
	{
		if(searchNumber == subArray3[i])
		{
			found_flag = 1;
			pthread_exit(NULL);
		}
	}
}
