

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct user {
	char phone[50];
	char ac[50];
	char password[50];
	float balance;
};

int main(){
	struct user user,usr;
	char filename[50],phone[50],password[50],phone2[50];
	FILE *fp,*fptr;
	int option,choice;
	int amount;
	char cont = 'y';
	printf("\n ***Welcome Sir!***");
	printf("\n\n1. Register your account");
	printf("\n2. Login to your account");

	printf("\n\n -Please enter your choice:\t");
	scanf("%d",&option);
	if(option == 1){
		system("clear");
		printf("\nEnter your account number:\t");
		scanf("%s",user.ac);
		printf("Enter your phone number:\t");
		scanf("%s",user.phone);
		printf("Enter your new password:\t");
		scanf("%s",user.password);
		user.balance=0;
		stpcpy(filename,user.phone);
		fp=fopen(strcat(filename,".dat"),"w");
		fwrite(&user,sizeof(user),1,fp);
		if(fwrite != 0){
			printf("Account Succesfully registered");
		}
	}
	else if(option == 2){
		system("cls");
		printf("\nPhone No.:\t");
		scanf("%s",phone);
		printf("Password:\t");
		scanf("%s",password);
		fp = fopen(strcat(phone,".dat"),"r");
		if(fp == NULL) printf("Account number not registered");
		else {
			fread(&user,sizeof(struct user),1,fp);
			fclose(fp);
			if(!strcmp(password,user.password)){
				while(cont == 'y'){
				system("cls");
				printf("\n\n\n\n\n");

printf("\t\t\t\t\t-------------------------------------------\n");
printf("\t\t\t\t\t-------------------------------------------\n");
printf("\t\t\t\t\t                Welcome  \n");
printf("\t\t\t\t\t-------------------------------------------\n");
printf("\t\t\t\t\t \n");
printf("\t\t\t\t\t [1] Press 1 for balance inquiry \n");
printf("\t\t\t\t\t [2] Press 2 for adding fund \n");
printf("\t\t\t\t\t [3] Press 3 for cash withdraw \n");
printf("\t\t\t\t\t [4] Press 4 for online transfer \n");
printf("\t\t\t\t\t [5] Press 5 for changing password\n");



				switch(choice){
					case 1:
						printf("Your current balance is Tk %.2f",user.balance);
						break;

					case 2:
						system("cls");
						printf("Enter amount to be added:\t");
						scanf("%d",&amount);
						user.balance += amount;
						fp = fopen(phone,"w");
						fwrite(&user,sizeof(struct user),1,fp);
						if(fwrite !=0) printf("\n\nYou have deposited Tk.%d",amount);
						fclose(fp);
						break;

					case 3:
						system("cls");
						printf("Enter withdraw amount:\t");
						scanf("%d",&amount);
						if(amount % 500 != 0) printf("\nSorry amount should be multiple of 500");
						else if(amount>user.balance) printf("\nSorry insufficeint balance");
						else {
							user.balance -= amount;
						fp = fopen(phone,"w");
						fwrite(&user,sizeof(struct user),1,fp);
						if(fwrite !=0) printf("\n\nYou have withdrawn tk.%d",amount);
						fclose(fp);
						}
						break;

					case 4:
						printf("Please enter the phone number to trasnfer balance:\t");
						scanf("%s",phone);
						printf("Enter the amount to transfer:\t");
						scanf("%d",&amount);
						if(amount > user.balance) printf("\nSorry insufficent balance");
						else {
							fptr = fopen(strcat(phone,".dat"),"r");
							if(fptr==NULL) printf("Sorry number is not registered");
							else {
								fread(&usr,sizeof(struct user),1,fptr);
								fclose(fptr);

								usr.balance += amount;

								fptr = fopen(phone,"w");
								fwrite(&usr,sizeof(struct user),1,fptr);
								if(fwrite != 0){

									printf("Your trasfer is completed. You have trasnfered Tk.%d to %s",amount,usr.phone);
									fclose(fptr);
									user.balance -= amount;
									strcpy(filename,user.phone);
									fp = fopen(strcat(filename,".dat"),"w");
									fwrite(&user,sizeof(struct user),1,fp);
									fclose(fp);
								}
							}
						}
						break;
					case 5:
						printf("\n\nPlease enter your old password:\t");
						scanf("%s",password);
						if(!strcmp(password,user.password)){
							printf("\n\nPlease enter your new password:\t");
							scanf("%s",password);
							strcpy(user.password,password);
							strcpy(filename,user.phone);
							fp = fopen(strcat(filename,".dat"),"w");
							fwrite(&user,sizeof(struct user),1,fp);
							fclose(fp);
							printf("\nPassword succesfullly changed");
						}else printf("\nSorry your password is wrong");

					default:
					break;

				}//switch ends here


				printf("\n\nDo you want to continue?[ Press YES/NO ]:\t");
				scanf("%s",&cont);
				}
			}
			else {
				printf("Invalid password");
			}
		}
		printf("\n\n*** Thank you ***\n\n");
	}

	return 0;
}

