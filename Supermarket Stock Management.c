#include <stdio.h>
#include <windows.h> //gotoxy() Sleep()
#include <stdlib.h> // exit function
#include <conio.h> //goto //getch

#define ENTER 13
#define TAB 9
#define BKSP 8
#define SPACE 32

void welcomescreen();
void gotoxy(short x, short y);
void password(int x);
void changepass();
void mainmenu();
void addproduct();
void displayproducts();
void deleteproduct();
void modify();
void search();

struct Product
{
    char id[10];
    char name[30];
    float price;
    int quantity;
};


struct Product p;

char Username[20],Password[20];
int flag=0;

int main()
{
    SetConsoleTitle("SUPERMARKET STOCK MANAGEMENT");
    welcomescreen();

    FILE *t;

    system("cls");
    system("color 30");

    t=fopen("info.bin","rb");

    if(t==NULL)
    {
        gotoxy(45,5);
        printf("No login details set yet.");
        gotoxy(44,6);
        printf("--------------------------");
        flag=1;
        changepass();
    }

    else
    {
        fread(&Username, sizeof(Username), 1,t);
        fread(&Password, sizeof(Password), 1,t);
    }
    fclose(t);

    if(flag==0)
        password(1);
    system("cls");
    system("color 0B");

    while(1)
    {
        int x;
        gotoxy(40,4);
        printf("----------------------------------");
        gotoxy(40,5);
        printf("1. Change login information.");
        gotoxy(40,6);
        printf("2. Add products.");
        gotoxy(40,7);
        printf("3. Display all products.");
        gotoxy(40,8);
        printf("4. Delete a product.");
        gotoxy(40,9);
        printf("5. Search a product.");
        gotoxy(40,10);
        printf("6. Modify a product's information.");
        gotoxy(40,11);
        printf("7. Exit.");
        gotoxy(40,12);
        printf("----------------------------------");
        gotoxy(40,14);
        printf("Enter your choice: ");
        scanf("%d",&x);
        switch(x)
        {
        case 1:
        {
            system("cls");
            changepass();
            system("cls");
            password(0);
            system("cls");
            break;
        }
        case 2:
        {
            system("cls");
            addproduct();
            system("cls");
            break;
        }
        case 3:
        {
            system("cls");
            displayproducts();
            system("cls");
            break;
        }

        case 4:
        {
            system("cls");
            deleteproduct();
            system("cls");
            break;
        }
        case 5:
        {
            system("cls");
            search();
            system("cls");
            break;
        }
        case 6:
        {
            system("cls");
            modify();
            system("cls");
            break;
        }


        case 7:
        {
            system("cls");
            gotoxy(35,4);
            printf("\t-------------------------------");
            gotoxy(40,5);
            printf("   The program is terminated");
            gotoxy(35,6);
            printf("\t-------------------------------");
            exit(1);
        }
        }
    }

    getch();
    return 0;
}

void search()
{
    char tempid[10];
    int flag=0;
    FILE *test;
    test=fopen("save.bin","rb");

    if(test==NULL)
        printf("\n\n\t\t\t\t\tNo products available to search");
    else
    {
        printf("\n\n\t\t\t\tEnter ID number of Product to search: ");
        scanf("%s",tempid);

        while((fread(&p,sizeof(p),1,test))==1)
        {
            if(strcmp(p.id,tempid)==0)
            {
                flag=1;
                printf("\n\n\t\t\t\t   -Product Name: %s", p.name);
                printf("\n\n\t\t\t\t   -Product Price: %.2lf BDT", p.price);
                printf("\n\n\t\t\t\t   -Product Quantity: %d pcs", p.quantity);
                printf("\n\n\t\t\t\t   -Total Investment on this product: %.2f BDT", p.price*p.quantity);

                break;
            }
        }
        if (flag==0)
            printf("\n\n\t\t\t\t\t   RECORD NOT FOUND");
    }

    fclose(test);

    printf("\n\n\nPress any key to go back to main menu....");

    getch();
}

void modify()
{
    password(3);
    system("cls");
    int flag=0;
    char tempid[10];

    FILE *test;
    test=fopen("save.bin","rb+"); //read and write but not overwrite
    if(test==NULL)
        printf("\n\n\t\t\t\t\tNo products available to modify");
    else
    {
        printf("\n\n\t\t\t\tEnter ID number of Product to modify: ");
        scanf("%s",tempid);


        while((fread(&p,sizeof(p),1,test))==1)
        {
            if(strcmp(p.id,tempid)==0)
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
            int size=sizeof(p);
    label:
            fseek(test,-size,SEEK_CUR);
            printf("\n\n\t\t\t\t\t\tRecord Found\n\t\t\t");
            printf("\n\n\t\t\tProduct Name: %s\n\t\t\t",p.name);
            printf("\n\n\t\t\tEnter New Data for the Product\n");

            printf("\n\n\t\t\tEnter product name: ");
            fgets(p.name, 100, stdin);
            fgets(p.name, 100, stdin);

            if(strlen(p.name)>20)
            {
                printf("\a\n\n\t\t\t    The name is too long. Press any key to enter information again.");
                getch();
                system("cls");
                goto label;
            }
            p.name[strlen(p.name)-1]='\0';


            printf("\n\t\t\tEnter product Price: ");
            scanf("%f", &p.price);


            printf("\n\t\t\tEnter product Quantity: ");
            scanf("%d", &p.quantity);


            fwrite(&p,sizeof(p),1,test);
        }

        else
            printf("\n\n\t\t\t\t\t\tRECORD NOT FOUND");
    }
    fclose(test);
    printf("\n\n\nPress any key to go back to main menu....");

    getch();

}

void deleteproduct()
{
    password(3);
    system("cls");
    int flag=0;
    char tempid[5];
    FILE *temp;
    FILE *test;

    test=fopen("save.bin","rb");// read
    if(test==NULL)
    {
        gotoxy(45,3);
        printf("No product saved to delete");
        printf("\n\n\tPress any key to go back to main menu..");
        getch();
    }

    else
    {
        temp=fopen("savetemp.bin","wb");// overwrite
        if(temp==NULL)
        {
            gotoxy(45,4);
            printf("\n\n\t\t\t\t\tCould not create a temp file");
            printf("\n\n\tPress any key to go back to main menu..");
            getch();
        }

        else
        {
            gotoxy(40,4);
            printf("Enter Product ID to Delete the Record");
            gotoxy(47,6);
            printf("ID No. : ");
            scanf("%s",tempid);
            gotoxy(39,7);
            printf("---------------------------------------");
            while((fread(&p,sizeof(p),1,test))==1)
            {
                if(strcmp(p.id,tempid)==0)
                {
                    flag=1;
                    gotoxy(40,9);
                    printf("Record Deleted for");
                    gotoxy(46,11);
                    printf("Name: %s",p.name);
                    gotoxy(46,13);
                    printf("Price: %.2f", p.price);
                    gotoxy(46,15);
                    printf("Quantity:%d", p.quantity);
                    printf("\n\n\tPress any key to continue..");
                    getch();
                    continue;
                }

                fwrite(&p,sizeof(p),1,temp);
            }
            if(flag==0)
            {
                printf("\n\n\t\t\t\t\tNO PRODUCT FOUND WITH THE INFORMATION\n\t");
                printf("\n\n\tPress any key to continue..");
                getch();
            }

        }
    }

    fclose(test);
    fclose(temp);

    remove("save.bin");
    rename("savetemp.bin","save.bin");


}

void addproduct()
{
    struct Product check;
    char choice;
    int len;


    FILE *test;

    test=fopen("save.bin","ab+"); // append and read

    if(test==NULL)
    {
        printf("FIle error");
    }

    else
    {
    label:
        gotoxy(40,3);
        printf("__________________________");
        gotoxy(40,4);
        printf("Entry menu to add products");
        gotoxy(40,5);
        printf("__________________________");

        gotoxy(37,7);
        printf("Enter 4 digit ID number: ");
        scanf("%s", p.id);
        len=strlen(p.id);
        if(len!=4)
        {
            printf("\a\n\t\t\tThe ID you entered is %d digits. Please enter again..\n", len);
            getch();
            system("cls");
            goto label;
        }
        else
        {
            fseek(test, 0,SEEK_SET);
            while((fread(&check,sizeof(check),1,test))==1)
            {
                if(strcmp(p.id,check.id)==0)
                {
                    printf("\a\n\n\t\t\tThis ID is already taken. Please enter a new ID.\n");
                    getch();
                    system("cls");
                    goto label;
                }
            }

        }
        gotoxy(37,9);
        printf("Enter product name: ");
        fgets(p.name, 100, stdin);
        fgets(p.name, 100, stdin);

        if(strlen(p.name)>20)
        {
            printf("\a\n\n\t\t\t    The name is too long. Press any key to enter information again.");
            getch();
            system("cls");
            goto label;
        }
        p.name[strlen(p.name)-1]='\0';

        gotoxy(37,11);
        printf("Enter product Price: ");
        scanf("%f", &p.price);

        gotoxy(37,13);
        printf("Enter product Quantity: ");
        scanf("%d", &p.quantity);

        fseek(test, 0,SEEK_END);
        fwrite(&p, sizeof(p), 1,test);

    }

label1:
    printf("\n\n\t\t\t\tDo you want to add more products? (Y/N):   ");
    scanf(" %c", &choice);

    if(choice=='Y'||choice=='y')
    {
        system("cls");
        goto label;
    }
    else if(choice!='N'&&choice!='n')
    {
        printf("\n\t\t\t\tPlease enter a valid choice");
        goto label1;
    }

    fclose(test);

}

void displayproducts()
{
    double sum=0,invest=0;
    gotoxy(10,3);
    printf("_____________________________________________________________________________________________________");
    gotoxy(10,4);
    printf("                                          STOCK DETAILS");

    gotoxy(10,5);
    printf("_____________________________________________________________________________________________________");
    gotoxy(10,6);
    printf("S/N");
    gotoxy(18,6);
    printf("[ID]");
    gotoxy(30,6);
    printf("[NAME]");
    gotoxy(53,6);
    printf("[PRICE/BDT]");
    gotoxy(70,6);
    printf("[QUANTITY/PCS]");
    gotoxy(90,6);
    printf("[TOTAL PRICE/BDT]");

    gotoxy(10,7);
    printf("_____________________________________________________________________________________________________");
    gotoxy(10,7);
    printf("_____________________________________________________________________________________________________");

    int pos=9,i=1;

    FILE *test;

    test=fopen("save.bin","rb");

    if(test==NULL)
    {
        gotoxy(43,11);
        printf("**No product added to display**");
    }
    else
    {
        while((fread(&p,sizeof(p),1,test))==1)
        {
            gotoxy(10,pos);
            printf("%d.", i++);
            gotoxy(18,pos);
            printf("%s",p.id);
            gotoxy(30,pos);
            printf("%s",p.name);
            gotoxy(53,pos);
            printf(" %7.2f",p.price);
            gotoxy(72,pos);
            printf("%6d",p.quantity);
            gotoxy(93,pos);
            sum=p.price*p.quantity;
            printf("%9.2lf", sum);
            pos+=2;
            invest=invest+sum;
        }
        gotoxy(40,pos+2);
        printf("CURRENT INVESTMENT: %.2lf BDT", invest);
    }
    fclose(test);

    gotoxy(0,pos+5);

    printf("Press any key to go back to main menu...");
    getch();

}

void changepass()
{
    char ch;
    int i=0;

    gotoxy(40,7);
    printf("    Enter New Username: ");
    scanf("%s", Username);

    gotoxy(40,10);
    printf("    Enter New Password: ");

    while(1)
    {
        ch=getch();

        if(ch==ENTER)
        {
            Password[i]='\0';
            break;
        }
        else if(ch==BKSP)
        {
            if(i>0)
            {
                i--;
                printf("\b \b");
            }
        }
        else if(ch==TAB||ch==SPACE)
        {
            continue;
        }
        else
        {
            Password[i]=ch;
            i++;
            printf("*");
        }

    }
    FILE *test;

    test=fopen("info.bin","wb");



    if(test==NULL)
    {
        printf("File error");
    }
    else
    {
        fwrite(&Username, sizeof(Username), 1,test);
        fwrite(&Password, sizeof(Password), 1,test);

    }
    fclose(test);
    gotoxy(35,13);
    printf("New info successfully saved");
    gotoxy(36,14);
    printf("Press any key to continue...");
    getch();
    system("cls");
}

void welcomescreen()
{
    system("color B0");
    gotoxy(35,3);
    printf("--------------------------------------------------\n");
    gotoxy(35,4);
    printf("--------------------------------------------------\n");
    gotoxy(37,5);
    printf("Welcome to Supermarket Stock Management System");
    gotoxy(35,6);
    printf("--------------------------------------------------\n");
    gotoxy(35,7);
    printf("--------------------------------------------------\n");
    gotoxy(40,10);
    printf("  *Project Done by Mahir Shahriar Tamim*\n");
    gotoxy(45,14);
    printf(" North South University- CSE115");

    gotoxy(35,18);
    printf("Press any key to proceed...");
    getch();

}

void gotoxy(short x, short y)
{
    COORD pos= {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

int tryy=0;
void password(int x)
{
    system("cls");
    char d[25]="Login Panel";
    char ch,pass[10],user[10];
    int i=0,j;
    if(x==1)
    {

        gotoxy(30,4);
        for(j=0; j<20; j++)
        {
            if(tryy==0)
                Sleep(20); // Sleep is in millisecond. sleep is in second.
            printf("*");
        }
        for(j=0; j<11; j++)
        {
            if(tryy==0)
                Sleep(25);
            printf("%c",d[j]);
        }
        for(j=0; j<20; j++)
        {
            if(tryy==0)
                Sleep(20);
            printf("*");
        }

    }
    else if(x==3)
    {
         gotoxy(26,4);
         printf("You need to enter username and password to Modify/Delete a product.");
    }

    if(tryy!=3)
    {
        gotoxy(42,6);
        printf("\t   Attempt %d", tryy+1);
    }
    else
    {
        gotoxy(42,6);
        printf("\tLAST ATTEMPT!!", tryy+1);
    }


    gotoxy(40,8);
    printf("Enter Username: ");
    scanf("%s", user);

    gotoxy(40,10);
    printf("Enter Password: ");

    while(1)
    {
        ch=getch();

        if(ch==ENTER)
        {
            pass[i]='\0';
            break;
        }
        else if(ch==BKSP)
        {
            if(i>0)
            {
                i--;
                printf("\b \b");
            }
        }
        else if(ch==TAB||ch==SPACE)
        {
            continue;
        }
        else
        {
            pass[i]=ch;
            i++;
            printf("*");
        }

    }

    if((strcmp(pass,Password)==0)&&(strcmp(user,Username)==0))
    {
        tryy=0;
        gotoxy(35,15);
        printf("Username and Password matched");
        gotoxy(35,16);
        printf("\tPress any key to countinue...");
        getch();
    }
    else
    {
        tryy++;
        gotoxy(35,15);
        printf("\a\t  Warning!! Incorrect Info");
        gotoxy(15,17);
        printf("**More than 3 attempts will result in deletion of all data. Press any key to countinue...**");
        if(tryy>3)
        {
            //system("c:\\windows\\system32\\shutdown /s");
            remove("save.bin");
            remove("info.bin");
            system("cls");
            gotoxy(35,4);
            printf("\t-----------------------------");
            gotoxy(46,5);
            printf(" All data deleted");
            gotoxy(35,6);
            printf("\t-----------------------------");

            exit(1);
        }

        getch();
        if(x==1)
            password(1);
        else
            password(3);
    }

}
