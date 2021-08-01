#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int i,j;
int main_exit;

struct date{
	int month,day,year;
};

struct data{
	char name[60];
	int acc_no,age;
	char address[60];
	char citizen[15];
	double phone;
	char acc_type[10];
	float amt;
	struct date dob;
	struct date deposit;
	struct date withdraw;
}add,upd,check,rem,transaction; //for different functions

void close(void){
	printf("\n\n\n\n\n\n\n Thank You!");
}

void fordelay(int j){
	int i,k;
	for(i=0;i<j;i++)
	{
		k=i;
	}
}

void newAcc(){
	int choice;
	FILE *fp;
	
	fp = fopen("record.dat","a+");
	account_no:
	system("cls");
	printf("\n\t\t ADD NEW ACCOUNT");
	printf("\nEnter Today's Date(dd/mm/yyyy): ");
	scanf("%d/%d/%d",&add.deposit.day,&add.deposit.month,&add.deposit.year);
	printf("\nEnter the Account Number: ");
	scanf("%d",&check.acc_no);
	while(fscanf(fp,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no,&add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,&add.address,&add.citizen,&add.phone,&add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
	{//read the details from file if the account exist or not
		if(check.acc_no == add.acc_no){
			printf("Account Number already in use!");
			fordelay(10000000);
				goto account_no; //if account already exist then it will go back and ask to insert different acc no
		}
	}
	add.acc_no = check.acc_no;
	printf("\nEnter the name: ");
	scanf("%s", add.name);
	printf("\nEnter the DOB(dd/mm/yy):");
	scanf("%d/%d/%d",&add.dob.day,&add.dob.month,&add.dob.year);
	printf("\nEnter the age: ");
	scanf("%d",&add.age);
	printf("\nEnter the Address: ");
	scanf("%s",add.address);
	printf("\nEnter the citizenship: ");
	scanf("%s",add.citizen);
	printf("\nEnter the phone number: ");
	scanf("%lf",&add.phone);
	printf("\nEnter the amount to deposit: ");
	scanf("%f",&add.amt);
	printf("\nType of Account:\n\t1. Saving\n\t2. Current\n\t3.Fixed1(for 1 year)\n\t4. Fixed2(for 2 year)\n\t5. Fixed3(for 3 year)");
	printf("\nEnter your choice: ");
	scanf("%s",add.acc_type);
	fprintf(fp,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizen,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
	fclose(fp);
	printf("\nAccount created successfully!");
	add_invalid:
	printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d",&main_exit);
	system("cls");
	if(main_exit==1){
		menu();
	}
	else if(main_exit==0){
		close();
	}
	else{
		printf("\nInvalid!\n");
		goto add_invalid;
	}
}

float interest(float t,float amount,int rate)
{
	float SI;
	SI = (rate*t*amount)/100.0;
	return SI;
}

void edit()
{
	int choice,n=0;
	FILE *old,*newR;
	old = fopen("record.dat","r");
	newR = fopen("newRecord.dat","w");
	printf("\nEnter the Account Number of Customer to Change:");
	scanf("%d",&upd.acc_no);
	while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,&add.address,&add.citizen,&add.phone,&add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF){
		if(add.acc_no == upd.acc_no){
			n=1;
			printf("\nWhich information do you want to change?\n1. Address\n2. Phone Number\n\nEnter your choice:");
			scanf("%d",&choice);
			system("cls");
			if(choice==1){
				printf("Enter the new Address:");
				scanf("%s",upd.address);
				fprintf(newR,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizen,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
				system("cls");
				printf("\nChanges Saved!\n");
	    	}
	    	else if(choice==2)
	    	{
	    		printf("Enter the new phone number:");
	    		scanf("%lf",&upd.phone);
	    		fprintf(newR,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizen,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
	    		system("cls");
	    		printf("\nChanges Saved!\n");
			}
	   }
	   else{
	   	fprintf(newR,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizen,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
	   }
    	fclose(old);
    	fclose(newR);
    	remove("record.dat");
    	rename("newRecord","record.dat");
    }
    if(n!=1){
    	system("cls");
    	printf("\nRecord Not Found!\n\n");
    	edit_invalid:
    	printf("\nEnter 0 to try again, 1 to return to main menu and 2 to exit: ");
    	scanf("%d",&main_exit);
    	system("cls");
    	if(main_exit == 1){
    		menu();
		}
		else if(main_exit==0){
			edit();
		}
		else{
			printf("\nInvalid!\n");
			goto edit_invalid;
		}
	}
	else{
		printf("\n\nEnter 1 to go to main menu and 0 to exit");
		scanf("%d",&main_exit);
		system("cls");
		if(main_exit==1){
			menu();
		}
		else{
			close();
		}
	}
}



void list()
{
	FILE *fp;
	fp = fopen("record.dat","r");
	int n =0;
	system("cls");
	printf("\nAccout Number\t\t\tName\t\tAddress\t\t\tPhone\n");
	while(fscanf(fp,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,&add.address,&add.citizen,&add.phone,&add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
	{
		printf("\n%6d\t\t\t%10s\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
		n++;
	}
	fclose(fp);
	if(n == 0)
	{
		system("cls");
		printf("\n No Records!\n");
	}
	list_invalid:
	printf("\nEnter 1 to goto the main menu and 0 to exit: ");
	scanf("%d",&main_exit);
	system("cls");
	if(main_exit == 1)
	{
		menu();
	}
	else if(main_exit == 0)
	{
		close();
	}
	else
	{
		printf("\nInvalid!\n");
		goto list_invalid;
	}
	
}

void erase()
{
	FILE *old,*newR;
	int n=0;
	old = fopen("record.dat","r");
	newR = fopen("newRecord.dat","w");
	printf("Enter the Account No. of the Customer you want to delete: ");
	scanf("%d",&rem.acc_no);
	while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,&add.address,&add.citizen,&add.phone,&add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
	{
		if(add.acc_no!=rem.acc_no)
		{
			fprintf(newR,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizen,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
		}
		else{
			n++;
			printf("\nRecord deleted Successfully!\n");
		}
	}
	fclose(old);
	fclose(newR);
	remove("record.dat");
	rename("new.dat","reocrd.dat");
	if(n == 0)
	{
		printf("\nRecord not found!\n");
		remove_invalid:
			printf("Enter 0 to try again, 1 to return to the main menu and 2 to exit: ");
			scanf("%d",&main_exit);
			if(main_exit == 1){
   				menu();
	    	}
			else if(main_exit == 2){
				close();
			}
			else if(main_exit == 0){
				display();
			}	
			else{
				system("cls");
				printf("\ninvalid!\n");
				goto remove_invalid;
			}
   }
   else{
   		printf("\nEnter 1 to go to the main menu and 0 to exit:");
   		scanf("%d",&main_exit);
   		if(main_exit == 1){
   			system("cls");
   			menu();
		}
		else{
			close();
		}
   }
}
	


void display()
{
	FILE *fp;
	int n=0, rate;
	int choice;
	float time, intrst;
	fp = fopen("record.dat","r");
	printf("Do you want to check your account by\n\t1.Account Number\n\t2. Name\n\tEnter your Choice:");
	scanf("%d",&choice);
	if(choice == 1){
		printf("Enter the Account Number: ");
		scanf("%d",&check.acc_no);
		
		while(fscanf(fp,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,&add.address,&add.citizen,&add.phone,&add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
		{
			if(add.acc_no == check.acc_no){
				system("cls");
				n=1;
				
				printf("\nAccount Number: %d\nName: %s\nDOB: %d/%d/%d\nAge: %d\nAddress: %s\nCitizenship: %s\nPhone Number: %.0lf\nType of Account: %s\nAmount Deposited: %.2f\nDate of Deposit: %d/%d/%d\n\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.deposit.year,add.age,add.address,add.citizen,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
				if(strcmpi(add.acc_type,"fixed1") == 0){
					time = 1.0;
					rate = 9;
					intrst = interest(time,add.amt,rate);
					printf("\nYou will get Rs%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year);
				}
				else if(strcmpi(add.acc_type,"fixed2") == 0){
					time = 2.0;
					rate = 11;
					intrst = interest(time,add.amt,rate);
					printf("\nYou will get Rs%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year);
				}
				else if(strcmpi(add.acc_type,"fixed3") == 0){
					time = 3.0;
					rate = 13;
					intrst = interest(time,add.amt,rate);
					printf("\nYou will get Rs%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year);
				}
				else if(strcmpi(add.acc_type,"saving") == 0){
					time = (1/12);
					rate = 8;
					intrst = interest(time,add.amt,rate);
					printf("\nYou will get Rs%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year);
				}
				else if(strcmpi(add.acc_type,"current") == 0){
					printf("\nYou will get no interest!\n");
				
				}
				
			}
		}
		
	}
	else if(choice == 2)
	{
		printf("Enter the name: ");
		scanf("%s",&check.name);
		while(fscanf(fp,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,&add.address,&add.citizen,&add.phone,&add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
		{
			if(strcmpi(add.name,check.name) == 0){
				system("cls");
				n=1;
				
				printf("\nAccount Number: %d\nName: %s\nDOB: %d/%d/%d\nAge: %d\nAddress: %s\nCitizenship: %s\nPhone Number: %.0lf\nType of Account: %s\nAmount Deposited: %.2f\nDate of Deposit: %d/%d/%d\n\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.deposit.year,add.age,add.address,add.citizen,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
				if(strcmpi(add.acc_type,"fixed1") == 0){
					time = 1.0;
					rate = 9;
					intrst = interest(time,add.amt,rate);
					printf("\nYou will get Rs%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year);
				}
				else if(strcmpi(add.acc_type,"fixed2") == 0){
					time = 2.0;
					rate = 11;
					intrst = interest(time,add.amt,rate);
					printf("\nYou will get Rs%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year);
				}
				else if(strcmpi(add.acc_type,"fixed3") == 0){
					time = 3.0;
					rate = 13;
					intrst = interest(time,add.amt,rate);
					printf("\nYou will get Rs%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year);
				}
				else if(strcmpi(add.acc_type,"saving") == 0){
					time = (1/12);
					rate = 8;
					intrst = interest(time,add.amt,rate);
					printf("\nYou will get Rs%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year);
				}
				else if(strcmpi(add.acc_type,"current") == 0){
					printf("\nYou will get no interest!\n");
				
				}
	       }
       }
   }
   fclose(fp);
   if(n!=1)
   {
   		system("cls");
   		printf("\nRecord not found!\n");
   		display_invalid:
   		printf("\n Enter 0 to try again, 1 to return to the main menu and 2 to exit:");
   		scanf("%d",&main_exit);
   		system("cls");
   		if(main_exit == 1){
   			menu();
		}
		else if(main_exit == 2){
			close();
		}
		else if(main_exit == 0){
			display();
		}
		else{
			system("cls");
			printf("\ninvalid!\n");
			goto display_invalid;
		}
   }
   else{
   		printf("\nEnter 1 to go to the main menu and 0 to exit:");
   		scanf("%d",&main_exit);
   		if(main_exit == 1){
   			system("cls");
   			menu();
		}
		else{
			system("cls");
			close();
		}
   }
   
}

void transact()
{
	int choice,n=0;
	FILE *old,*newR;
	old = fopen("record.dat","r");
	newR = fopen("newRecord.dat","w");
	
	printf("Enter the Account number of the Customer: ");
	scanf("%d",&transaction.acc_no);
	while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,&add.address,&add.citizen,&add.phone,&add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
	{
		if(add.acc_no == transaction.acc_no)
		{
			n = 1;
			if(strcmpi(add.acc_no,"fixed1") == 0 || strcmpi(add.acc_no,"fixed2") == 0 || strcmpi(add.acc_no,"fixed3") == 0)
			{
				printf("\nYou Cannot Deposit or Withdraw Cash in Fixed Account!\n");
				fordelay(1000000);
				system("cls");
				menu();
			}
			printf("\n Do you want to\n1.Deposit\n2. Withdraw\nEnter your choice:");
			scanf("%d",&choice);
			if(choice == 1)
			{
				printf("\nEnter the Amount you want to deposit:");
				scanf("%f",&transaction.amt);
				add.amt +=transaction.amt;
				fprintf(newR,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizen,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
				printf("\nDeposited Successfully!\n");
			}
			else{
				printf("Enter the Amount you want to withdraw:");
				scanf("%f",&transaction.amt);
				add.amt -=transaction.amt;
				fprintf(newR,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizen,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
				printf("\nWithdraw Successfully!\n");
			}
		}
		else{
			fprintf(newR,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizen,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
		}
	}
	fclose(old);
	fclose(newR);
	remove("record.dat");
	rename("new.dat","record.dat");
	if(n!=1)	
	{
		printf("\nRecord not found!");
		transact_invalid:
		printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
		scanf("%d",&main_exit);
		system("cls");
		if(main_exit == 0){
			transact();
		}
		else if(main_exit == 1){
			menu();
		}
		else if(main_exit == 2){
			close();
		}
		else{
			printf("\nInvalid!\n");
			goto transact_invalid;
		}
	}
	else{
		printf("Enter 1 to go to the main menu and 0 to exit");
		scanf("%d",&main_exit);
		system("cls");
		if(main_exit == 1){
			menu();
		}
		else{
			close();
		}
	}
}

void menu(void)
{
	int choice;
	system("cls"); //to clear the output screen
	printf("\t\t*Bank Management System*\n");
	printf("\n\t\tWelcome to the Main Menu\n");
	printf("\n1. Create New Account\n2. Update information of Existing Account\n3. For Transactions\n4. Check the Existing Account Details\n5. Removing Existing Account\n6. View Costumer's List\n7. Exit");
	printf("\nEnter your choice: ");
	scanf("%d",&choice);
	
	system("cls");
	switch(choice){
		case 1:
		{
			newAcc();
			break;
		}
		case 2:
		{
			edit();
			break;
		}
		case 3:
		{
			transact();
			break;
		}
		case 4:
		{
			display();
			break;
		}
		case 5:
		{
			erase();
			break;
		}
		case 6:
		{
			list();
			break;
		}
		case 7:
		{
			close();
			break;
		}
		default:
		{
			printf("\nTry Again!\n");
			menu();
			break;
		}
	}
}


int main()
{
	char pass[10],password[10] = "mycap";
	int i=0;
	printf("\n\n\t Enter the password: ");
	scanf("%s",pass);
	
    if(strcmp(pass,password)==0){
    	printf("\n\n Password match");
    	for(i=0; i<=6;i++) //check the string again and break down
    	{
    		fordelay(1000);
    		printf("."); //to check the loop
    	}
    	system("cls"); //clear the screen
    	menu();
    }
    else
    {
    	printf("\n\n Wrong Password");
    	login_try:
    	printf("\n\nEnter 1 to retry & 0 to exit");
    	scanf("%d",&main_exit);
    	if(main_exit == 1){
    		system("cls");
    		main();
    	}
    	else if(main_exit == 0){
    		system("cls");
    		close();
    	}
    	else{
    		printf("\n Invalid");
    		fordelay(1000);
    		system("cls");
    		goto login_try; //jump to main page

    	}
    }
    return 0;

}
