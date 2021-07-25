#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	int age;
	unsigned long long phone;
	char name[20],dept[20];
	float salary;
}data;

int main()
{
	int n,choice;
	data emp[20];
	while(1){
		printf("**********MENU**********");
		printf("\n1. Enter Employee Data\n2. Display Employee Data\n3. Exit\n");
		printf("Enter your choice: ");
	    scanf("%d",&choice);
	    if(choice == 3){
	    	break;
		}
	    
	    switch(choice){
		    case 1:
			   {
			     	printf("Enter Number of Employee: ");
	                scanf("%d",&n);
					for(int i=1; i<=n; i++){
		        		printf("\nEnter Employee Name: ");
        				scanf("%s",&emp[i].name);
		        		printf("Enter Employee Age: ");
		        		scanf("%d",&emp[i].age);
		        		printf("Enter Employee Phone Number: ");
		        		scanf("%llu",&emp[i].phone);
	        			printf("Enter Department Name: ");
		       			scanf("%s",&emp[i].dept);
		        		printf("Enter Salary: ");
		        		scanf("%f",&emp[i].salary);
		        		printf("\n");
            		}
            		break;
				}	
			case 2:
				{
					printf("**EMPLOYEES DETAILS**\n");
	            	for(int i=1; i<=n; i++){
	              		printf("\n------------------------------------------------\n");
	            		printf("Employee Number: %d\n",i);
		        	    printf("Name: %s\n",emp[i].name);
		        	    printf("Age: %d\n",emp[i].age);
		            	printf("Phone Number: %llu\n",emp[i].phone);
		            	printf("Department Name: %s\n",emp[i].dept);
		            	printf("Salary: %.2f\n",emp[i].salary);
		            	printf("------------------------------------------------\n");
	           		}
	           		break;
				}
		}
    }
	
	return 0;
}
