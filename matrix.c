#include<stdio.h>

int main()
{
	
	int i,j, row,col;
	printf("Enter number of rows and columns(separated by space): \n");
	scanf("%d %d",&row,&col);
	int data[row][col];
	int *p=&data;
	int sum=0;
	printf("\nInput elements in the 3x3 matrix: \n");
	for(i=0; i<row; i++){
		for(int j=0;j<col;j++){
				printf("Element-[%d][%d]: ",i,j);
				scanf("%d",p);
				p++;
		}
	}
	p = data; //make sure the pointer is pointing back to array
	printf("The matrix elements are: \n");
	for(i=0; i<row; i++){
		for(j=0;j<col;j++){
			printf("%d ",*p);
			p++;
		}
		printf("\n");
	}
	p = data;
	for(i=0; i<row; i++){
		for(j=0;j<col;j++){
			if(i == j){
				sum = sum + *(p);
			}
			p++;
	    }
   }
   printf("\nThe sum of diagonal elements is: %d",sum);
   return 0;
}
