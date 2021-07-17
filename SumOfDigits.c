#include<stdio.h>

int total(int num)
{
	if(num == 0)
	{
    return 0;
  }
  return (num%10 + total(num/10));
}

int main()
{
	int num;
	printf("Enter any number: ");
	scanf("%d",&num);
	int sum = total(num);
	printf("Sum of %d is: %d",num,sum);
  return 0;	
}
