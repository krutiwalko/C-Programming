#include<stdio.h>

int isPrime(int num, int i)
{
	if(i == 1)
	{
		return 1;
	}
	else{
		if(num%i == 0)
		{
			return 0;
		}
		else{
			return isPrime(num,i-1);
		}
	}
	return 0;
}

int main()
{
	int num,i;
	printf("Enter any positive number: ");
	scanf("%d",&num);
	int half = isPrime(num,num/2);
	if(half == 1){
		printf("It is a Prime number.\n");
	}
	else
	{
		printf("Is is not a Prime number.\n");
	}
	return 0;
}
