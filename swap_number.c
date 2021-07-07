#include<stdio.h>

int main()
{
	int a,b;
	printf("Enter two numbers separated by space: ");
	scanf("%d %d",&a,&b); //if a=1 and b=2
	printf("Before swapping: a=%d and b=%d\n",a,b);
	a=a+b; //a=3
	b=a-b; //b=3-2=1
	a=a-b; //a=3-1=2
	printf("After swapping: a=%d and b=%d",a,b);
	return 0;
}
