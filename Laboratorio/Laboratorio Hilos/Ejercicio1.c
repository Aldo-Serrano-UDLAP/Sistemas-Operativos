#include<stdio.h>
#include<pthread.h>

void* factorial1(void *args);
void* factorial2(void *args);
void* factorial3(void *args);
int divide(int number);

int number = 9;
int numberDivision1 = 0,numberDivision2 = 0,numberDivision3 = 0,initialNumber = 0,state = 0;
int result1=1,result2=1,result3=1;

int main(void)
{
	int finalResult = 0;
	numberDivision1 = divide(number);
	numberDivision2 = divide(number*2);
	numberDivision3 = divide(number*3);
	initialNumber = divide(number)-1;
	
	pthread_t thread_A, thread_B, thread_C;
	
	state = pthread_create(&thread_A,NULL,factorial1,NULL);
	pthread_join(thread_A,NULL);
	state = pthread_create(&thread_B,NULL,factorial2,NULL);
	pthread_join(thread_B,NULL);
	state = pthread_create(&thread_C,NULL,factorial3,NULL);
	pthread_join(thread_C,NULL);
	
	finalResult = result1*result2*result3;
	
	printf("Result 1 = %d\n",result1);
	printf("Result 2 = %d\n",result2);
	printf("Result 3 = %d\n",result3);
	
	printf("Final Result = %d\n",finalResult);
}

int divide(int number)
{
	int division=0;
	division = number/3;
	return division;	
}

void* factorial1(void *args)
{
	int i=0;
	
	for(i=numberDivision1;i>=numberDivision1-initialNumber;i--)
	{
		result1 *= i;
	}
	pthread_exit(NULL);
}
void* factorial2(void *args)
{
	int i=0;
	
	for(i=numberDivision2;i>=numberDivision2-initialNumber;i--)
	{
		result2 *= i;
	}
	pthread_exit(NULL);
}
void* factorial3(void *args)
{
	int i=0;
	
	for(i=numberDivision3;i>=numberDivision3-initialNumber;i--)
	{
		result3 *= i;
	}
	pthread_exit(NULL);
}
