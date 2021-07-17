#include<stdio.h>

int gcd(int a, int b)
{
	if(a==0)
	{
		return b;
	}
    return gcd(b%a,a);
}

int main()
{
	int a,b,i;
	printf("Enter two number separated by space: ");
	scanf("%d %d",&a,&b);
	printf("LCM of given two numbers is: %d\n",(a*b)/gcd(a,b));
	return 0;
}
