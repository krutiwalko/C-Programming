#include<stdio.h>

int main()
{
	int row;
	printf("Enter number of rows: ");
	scanf("%d",&row);
	for(int i=0; i<row; i++)
	{
		for(int j=0;j<i; j++){
			printf("01");
	   }
	   printf("\n");
	}
	
	return 0;
}
