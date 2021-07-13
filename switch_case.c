#include<stdio.h>
int main()
{
	printf("*****Food Menu*****\n");
	printf("1. French Fries, Rs 99\n2. Burger, Rs 129\n3. Sandwich, Rs 149\n");
	printf("4. Pasta, Rs 179\n5. Pizza, Rs 239\n");
	printf("\nEnter you choice: ");
	int choice;
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: printf("\nFood Item: French Fries\nPrice: 99\n");
		        break;
		case 2: printf("\nFood Item: Burger\nPrice: 129\n");
		        break;
		case 3: printf("\nFood Item: Sandwich\nPrice: 149\n");
		        break;
		case 4: printf("\nFood Item: Pasta\nPrice: 179\n");
		        break;
	    case 5: printf("\nFood Item: Pizza\nPrice: 239\n");
		        break;
		default: printf("\nInvalid input.\n");
		         break;
	}
	return 0;
}
