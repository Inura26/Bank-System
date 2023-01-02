#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

struct new {
    char Fname[20];
    char Lname[20];
    char NIC[15];
    char Address[50];
    char PNumber[10];
    char gen[12];
    char mail[20];
    int PIN;
    char USER[20];
    char usname[10];
    int mainPIN;
    char usnameN[10];
    int RMenu;
    int accnum;
    char AName[30];
    int ABalance;
    char acc_num[15];
    char pass[15];
    int acc_num1;
    int ACCNUM;
    int amount;
};
struct trans {
    char bankB[20];
    char nameB[30];
    char numberB[20];
    int amountB;

};

void NEW();
void login();
void submenu1();
void balance();
void transfer();
void transcash();
void balanceC();
void UPDATE();
void DELETE();
void Yes();
void No();
void Exit();
void logout();
void User_Name();
void PIN_Number();
void UName();
void PIN();
void deposite();
void withdraw();
void transation();
void acdetails();
void recipt();

int accnum,pin1;

int main(){

    int option;

    system("cls");
    system("color 0A");
    printf("\n\n");
    printf("\t==============================================\n\n");
    printf("\t     ------Welcome to the City Bank------\n\n");
    printf("\t==============================================\n\n");

    printf("\t1.Creating new account\n\n");
    printf("\t2.Login\n\n");
    printf("\t3.Exit\n");
    printf("\n\t==============================================\n");
    printf("\n\tEnter your choice:");

    scanf("%d",&option);

    switch(option){
         case 1:
            NEW();
            break;
         case 2:
            login();
            break;
         case 3:
            Exit();
            break;
    }
    return 0;
    system("cls");
}

//##Creating a New Account##

void NEW(){

    struct new n1;

    system("color 0A");
    printf("\nEnter your first name:");
    scanf("%s",&n1.Fname);

    printf("\nEnter your Last name:");
    scanf("%s",&n1.Lname);

    printf("\nEnter NIC number:");
    scanf("%s",&n1.NIC);

    printf("\nEnter your city:");
    scanf("%s",&n1.Address);

    printf("\nEnter your Email:");
    scanf("%s",&n1.mail);

    printf("\nEnter your PhoneNumber:");
    scanf("%s",&n1.PNumber);

    printf("\n----------------------\n");

    printf("\nEnter your User name:");
    scanf("%s",&n1.usname);

    printf("\nEnter the PIN Number:");
    scanf("%d",&n1.PIN);

    printf("\nYour Account Number is %d \n",rand());

    printf("\nRenter Your Account number:\n");
    scanf("%d",&n1.ACCNUM);


    printf("\nEnter the Deposit Amount:");
    scanf("%d",&n1.amount);

    system("cls");

    printf("\t==============================================\n\n");

    printf("\n  !!Account Created Successfully!!\n");

    printf("\t==============================================\n\n");



    FILE *file;
    file = fopen("account_details.txt","a+");
    fwrite(&n1,sizeof(n1),1,file);
    fclose(file);

    printf("~~Please Press ENTER to Continue~~\n");


    getch();

    login();
    system("cls");
}


void Exit(){
    printf("");
    system("cls");
}

//##login to account##

void login(){

    int log = 0;

    system("color 0A");
    system("cls");
    printf("\n--Please Login to the Account--\n");

    printf("\nEnter Your Account Number:");
    scanf("%d",&accnum);
    printf("\nEnter your PIN Number:");
    scanf("%d",&pin1);


    FILE *file;

    struct new n1;

    file = fopen("account_details.txt","a+");


    while(fread(&n1,sizeof(n1),1,file)){
        if(accnum == n1.ACCNUM){
            if(pin1 == n1.PIN){
                log = 1;
                printf("\n!! Loging Successfully !!\n \n~~Please press the ENTER~~\n");
                getch();
                submenu1();
            }
        }
    }
    fclose(file);

    if(log == 0){
        printf("-----Invalid Username or Password----- \n");
        main();

    }
    system("cls");

}

//##Sub Menu and Other details##

void submenu1(){

    int selection;
    system("cls");
    system("color 0A");
    printf("\n\t==================City Bank===================\n\n");
    printf("\t          1.Check Account Balance\n");
    printf("\t          2.Check Your Account Details\n");
    printf("\t          3.Money Transfer\n");
    printf("\t          4.Money Deposite\n");
    printf("\t          5.Money Withdraw\n");
    printf("\t          6.Delete your account\n");
    printf("\t          7.Update your account\n");
    printf("\t          8.Log Out\n");
    printf("\t==============================================\n\n");

    printf("Enter Your Selection:");

    scanf("%d",&selection);

    switch(selection){
        case 1:
            balance();
            break;
        case 2:
            acdetails();
            break;
        case 3:
            transfer();
            break;
        case 4:
            deposite();
            break;
        case 5:
            withdraw();
            break;
        case 6:
            DELETE();
            break;
        case 7:
            UPDATE();
            break;
        case 8:
            logout();
            break;
    }
    system("cls");
}

//##Checking Balance##

void balance(){

    FILE *file;
    struct new n1;
    system("cls");
    file=fopen("account_details.txt","r");
    while(fread(&n1,sizeof(n1),1,file)){
        if(accnum==n1.ACCNUM){
        printf("\n\t==================City Bank===================\n\n");
        printf("\n\n\t---------------Balance--------------\n\n");
        printf("\tAccount holder's name : %s %s\n",n1.Fname,n1.Lname);
        printf("\tAccount Number        : %d\n",n1.ACCNUM);
        printf("\tAccount Balance       : Rs.%d\n",n1.amount);
        printf("\n\t==============================================\n\n");
        }

    }

    fclose(file);

    printf("~~Please Press ENTER to Continue~~");
    getch();

    submenu1();
    system("cls");
}


//##Account Details##

void acdetails(){

    FILE *file;
    struct new n1;

    file=fopen("account_details.txt","r");
    while(fread(&n1,sizeof(n1),1,file)){
        if(accnum==n1.ACCNUM){
        system("cls");
        printf("\t====================================\n\n");
        printf("\t----------Account Details-----------\n\n");
        printf("\tAccount holder's name : %s %s\n",n1.Fname,n1.Lname);
        printf("\tAccount Number        : %d\n",n1.ACCNUM);
        printf("\tUser name             : %s\n",n1.usname);
        printf("\tNIC Number            : %s\n",n1.NIC);
        printf("\tCity                  : %s\n",n1.Address);
        printf("\tEmail Address         : %s\n",n1.mail);
        printf("\tPhone Number          : %s\n",n1.PNumber);
        printf("\n\t====================================\n\n\n");
        }
    }

    fclose(file);
    printf("~~Please Press ENTER to Continue~~\n");
    getch();

    submenu1();
    system("cls");
}

//##Transfer Money login details##

void transfer(){

    int accnum;
    int tran=0;
    int pin2;

    struct new n1;
    system("cls");
    system("color 0A");
    printf("\n\t==================City Bank===================\n\n");
    printf("\nEnter your account number:");
    scanf("%d",&accnum);
    printf("\nEnter your PIN Number:");
    scanf("%d",&pin2);
    printf("\n\t==============================================\n\n");

    FILE *file;

    file = fopen("account_details.txt","r");
    while(fread(&n1,sizeof(n1),1,file)){
        if(accnum == n1.ACCNUM){
            if(pin2 == n1.PIN){
                transcash();
                tran=1;

            }
        }
    }
    fclose(file);
    if(tran == 0){
        system("cls");
        printf("----Invalid Your Account Number or Pin Number----");
        printf("~~Please Press ENTER to Continue~~");
        getch();
        submenu1();
    }

    system("cls");
}

//##Transfer money to other account##

void transcash(){

    char bankN;
    char numberB;
    char nameB;

    FILE *file;

    struct new n1;
    struct trans m1;


    file= fopen("transfer.txt","a+");

        system("cls");
         printf("\n\t==================City Bank===================\n\n");
         system("color 0A");
         printf("\nEnter the Reciever's bank:");
         scanf("%s",&m1.bankB);

         printf("\nEnter the Receiver's Account Number:");
         scanf("%s",&m1.numberB);

         recipt();


    fwrite(&m1,sizeof(m1),1,file);
    fprintf(file,"\n");
    fclose(file);

    system("cls");
    printf("~~Please Press ENTER to Continue~~");
    getch();

    submenu1();
    system("cls");

}

//##Print money transfer recipt##
void recipt(){

     FILE *file, *copy;
     int amountB = 0;
     char nameB[30];
     struct new n1;
     struct trans m1;
     file = fopen("account_details.txt","r");
     copy = fopen("copy.txt","w");

     while(fread(&n1,sizeof(n1),1,file)){
            if(accnum==n1.ACCNUM){

                    printf("\nEnter the Receiver,s Account Name:");
                    scanf("%s",&m1.nameB);

                    printf("\nAmount:");
                    scanf("%d",&amountB);

                    n1.amount -= amountB;


                    system("color 0A");
                    printf("\n\t==================City Bank===================\n\n");

                    time_t t = time(NULL);
                    printf("\tCurrent date and time is: %s\n",ctime(&t));
                    printf("\tReceiver's Account Name: %s \n",m1.nameB);
                    printf("\tTransferd Amount: Rs.%d \n",amountB);
                    printf("\tCurrent Account balance: Rs.%d \n\n",n1.amount);

                    printf("\n\t\t------ Thank You ! ------\n\n");
                    printf("\n\t==============================================\n\n");
     }
     fwrite(&n1,sizeof(n1),1,copy);
   }
   fclose(file);
   fclose(copy);

   file=fopen("account_details.txt","w");
    copy=fopen("copy.txt","r");
    while(fread(&n1,sizeof(n1),1,copy)){
        fwrite(&n1,sizeof(n1),1,file);
    }
    fclose(file);
    fclose(copy);
    system("cls");
}

//##Deposite Money##

void deposite(){

    FILE *file,*copy;
    int dep=0;
    struct new n1;

    file=fopen("account_details.txt","r");
    copy=fopen("copy.txt","w");

    while(fread(&n1,sizeof(n1),1,file)){
        if(accnum==n1.ACCNUM){
            printf("Enter the Amount:");
            scanf("%d",&dep);
            n1.amount+=dep;
            system("cls");
            printf("\n\t==================City Bank===================\n\n");
            printf("\n\tYou Deposited            Rs.%d\n",dep);
            printf("\tNew Account Balance is   Rs.%d\n\n",n1.amount);
            printf("\n\t==============================================\n\n");
        }
        fwrite(&n1,sizeof(n1),1,copy);
    }
    fclose(file);
    fclose(copy);

    file=fopen("account_details.txt","w");
    copy=fopen("copy.txt","r");
    while(fread(&n1,sizeof(n1),1,copy)){
        fwrite(&n1,sizeof(n1),1,file);
    }
    fclose(file);
    fclose(copy);

    printf("~~Please Press ENTER to Continue~~");
    getch();

    submenu1();
    system("cls");
}

//##Withdraw Money##

void withdraw(){

    FILE *file,*copy;
    int wid=0;
    struct new n1;

    file=fopen("account_details.txt","r");
    copy=fopen("copy.txt","w");

    while(fread(&n1,sizeof(n1),1,file)){
        if(accnum==n1.ACCNUM){
            printf("\nEnter the Amount: ");
            scanf("%d",&wid);
            if(wid<=n1.amount){
                n1.amount-=wid;
                system("cls");
                printf("\n\t==================City Bank===================\n\n");
                printf("\n\tYou Withdrawn            Rs.%d\n",wid);
                printf("\tNew Account Balance is   Rs.%d\n\n",n1.amount);
                printf("\n\t==============================================\n\n");
            }else{
                printf("---You don't have enough money---\n");
            }
        }
        fwrite(&n1,sizeof(n1),1,copy);
        }
    fclose(file);
    fclose(copy);

    file=fopen("account_details.txt","w");
    copy=fopen("copy.txt","r");

    while(fread(&n1,sizeof(n1),1,copy)){
        fwrite(&n1,sizeof(n1),1,file);
    }

    fclose(file);
    fclose(copy);

    printf("~~Please Press ENTER to Continue~~");
    getch();

    submenu1();
    system("cls");
}



//##Account Deleting##

void DELETE(){

    int pick;
    system("cls");
    system("color 0A");
    printf("Are you sure to delete this account\n");

    printf("1.Yes\n");
    printf("2.No\n");

    scanf("%d",&pick);
            switch(pick){
        case 1:Yes();
                break;
        case 2:No();
            break;
    }
    system("cls");
    }


void Yes(){
    FILE *file,*copy;
    struct new n1;
    file=fopen("account_details.txt","r");
    copy=fopen("copy.txt","w");
    while(fread(&n1,sizeof(n1),1,file)){
        if(accnum==n1.ACCNUM){
            system("color 0A");
            system("cls");
            printf("\nYour Account Deleted Successfully");
        }else{
            fwrite(&n1,sizeof(n1),1,copy);
        }
    }
    fclose(file);
    fclose(copy);

    file=fopen("account_details.txt","w");
    copy=fopen("copy.txt","r");
    while(fread(&n1,sizeof(n1),1,copy)){
        fwrite(&n1,sizeof(n1),1,file);
    }
    fclose(file);
    fclose(copy);
    printf("~~Please Press ENTER to Continue~~");
    getch();
    main();
    system("cls");
}

void No(){

    struct new n1;
    system("color 0A");
    printf("\nReturn to Menu\n");

    printf("~~Please Press ENTER to Continue~~");
    getch();


    submenu1();
    system("cls");
}

//##Account Update##

void UPDATE(){

    int choice;
    system("color 0A");
    system("cls");
    printf("Please Select what do you need to change\n");
    printf("1.Change User Name\n");
    printf("2.Change PIN Number\n");
    scanf("%d",&choice);

    switch (choice){

        case 1:UName();
            break;
        case 2:PIN();
                break;
    }
    system("cls");
}

void UName(){

    FILE *file,*copy;
    struct new n1;

    file=fopen("account_details.txt","r");
    copy=fopen("copy.txt","w");
    while(fread(&n1,sizeof(n1),1,file)){
        if(accnum==n1.ACCNUM){
            printf("Enter New User Name : ");
            scanf("%s",&n1.usname);
            printf("\n\n\tYour New User Name is %s\n\n\n",n1.usname);
        }
        fwrite(&n1,sizeof(n1),1,copy);
    }
    fclose(file);
    fclose(copy);

    file=fopen("account_details.txt","w");
    copy=fopen("copy.txt","r");
    while(fread(&n1,sizeof(n1),1,copy)){
        fwrite(&n1,sizeof(n1),1,file);
    }
    fclose(file);
    fclose(copy);

    printf("~~Please Press ENTER to Continue~~");
    getch();

    submenu1();
    system("cls");
}

void PIN(){

    FILE *file,*copy;
    struct new n1;

    file=fopen("account_details.txt","r");
    copy=fopen("copy.txt","w");
    while(fread(&n1,sizeof(n1),1,file)){
        if(accnum==n1.ACCNUM){
            printf("Enter New Pin : ");
            scanf("%d",&n1.PIN);
            printf("\n\n\tYour New Pin is %d\n\n\n",n1.PIN);
        }
        fwrite(&n1,sizeof(n1),1,copy);
    }
    fclose(file);
    fclose(copy);

    file=fopen("account_details.txt","w");
    copy=fopen("copy.txt","r");
    while(fread(&n1,sizeof(n1),1,copy)){
        fwrite(&n1,sizeof(n1),1,file);
    }
    fclose(file);
    fclose(copy);

    printf("~~Please Press ENTER to Continue~~");
    getch();

    submenu1();
    system("cls");
}

void logout(){
    main();
    system("cls");
}









