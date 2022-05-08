#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 100
struct book
{
    char name[50], stock[20], code[50];
    int price;
};
struct Login
{
    char fname[25];
    char lname[15];
    char username[10];
    int password,id;
};
void add(struct book a[], int size);
void view(struct book b[], int n);
void calculate(struct book c[], int m);
void search(struct book d[], int x);
void delete (struct book e[], int y);
void modify(struct book f[], int z);



int main()
{
    char user[50], pass[50];
    int input;
    struct book main[SIZE];
    //multiple user
    int userType;

    time_t now;
    time(&now);
    printf("\n\t\t\t\t\t%s",ctime(&now));

    //first page or login page
    printf("\n\t\t\t\t Welcome to NSU mart!");
    printf("\n\n\t\t\t\tLogin as:");
    printf("\n\n\t\t\t\t1) Admin:");
    printf("\n\n\t\t\t\t2) Customer:\n");
    printf("\n\n\t\t\t\tEnter your choice:");
    scanf("%d", &userType);

    //for admin
    if(userType==1)
    {
    printf("\n\n\t\t\t\tEnter username : ");
    fflush(stdin);
    gets(user);
    printf("\t\t\t\tEnter password : ");
    fflush(stdin);
    gets(pass);
        if (strcmp(user, "admin") == 0)
        {
            if (strcmp(pass, "123") == 0)
            {
                printf("\t\t\t\tLogin successful!\n\n");
            }
            else
            {
                printf("\n\t\t\t\tInvalid username or password! \n\t\t\t\tEXITING THE PROGRAM");
                return 0;
            }
        }
        else
        {
            printf("\n\t\t\t\tInvalid username! \n\t\t\t\tEXITING THE PROGRAM ");
            return 0;
        }

        system("cls");
        system("color E1");
        while (1)
        {
        printf("\n\t\t\t\t\t%s",ctime(&now));

        printf("                          ****************************************************\n");
        printf("                               WELCOME TO THE MAIN MENU OF NSU MART!\n");
        printf("                          ****************************************************\n\n");

        printf("\t\t\t\tYOU ARE LOGGED IN AS AN ADMIN             \n");
        printf("\t\t\t\t------------------------------------------\n");
        printf("\t\t\t\t|1.Calculate Bill                        |\n");
        printf("\t\t\t\t|2.View Books in stock                   |\n");
        printf("\t\t\t\t|3.Search Book in stock                  |\n");
        printf("\t\t\t\t|4.Add new book to stock                 |\n");
        printf("\t\t\t\t|5.Modify information of a book in stock |\n");
        printf("\t\t\t\t|6.Delete information of a book in stock |\n");
        printf("\t\t\t\t|0.To Exit Press 0                       |\n");
        printf("\t\t\t\t------------------------------------------\n");
        printf("\n\n");
        printf("\t\t\t\t Enter your choice: ");
            scanf("%d", &input);
            switch (input)
            {
            case 1:
                calculate(main, SIZE);
                break;
            case 2:
                view(main, SIZE);
                break;
            case 3:
                search(main, SIZE);
                break;
            case 4:
                add(main, SIZE);
                break;
            case 5:
                modify(main, SIZE);
                break;
            case 6:
                delete (main, SIZE);
                break;
            case 0:
                    printf("\t\t\t\tThank you. Have a great day!\n");
                return 0;
            default:
                printf("Invalid choice!");
            }
        }
    }
    //for customer
    if(userType==2)
    {
    int cho;
    printf("Press '1' for Register........... \nPress '2' for Login.........\n");
    scanf("%d",&cho);
    if(cho == 1)
    {
        system("CLS");
        registe();
    }
    else if(cho == 2)
    {
        system("CLS");
        login();
    }
    else
        printf("Incorrect option !!!!!!!!!!!.......Please correct option secleted");
            system("cls");
        system("color E1");
        if(login()){

        while (1)
        {
        printf("\n\t\t\t\t\t%s",ctime(&now));
        printf("                          ****************************************************\n");
        printf("                               WELCOME TO THE MAIN MENU OF NSU MART!\n");
        printf("                          ****************************************************\n\n");

        printf("\t\t\t\tYOU ARE LOGGED IN AS A CUSTOMER           \n");
        printf("\t\t\t\t------------------------------------------\n");
        printf("\t\t\t\t|1.View Books in stock                   |\n");
        printf("\t\t\t\t|2.Search Book in stock                  |\n");
        printf("\t\t\t\t|3.Calculate Bill                        |\n");
        printf("\t\t\t\t|0.To Exit Press 0                       |\n");
        printf("\t\t\t\t------------------------------------------\n");
        printf("\n\n");
        printf("\t\t\t\t Enter your choice: ");
            scanf("%d", &input);
            switch (input)
            {
            case 1:
                view(main, SIZE);
                break;
            case 2:
                search(main, SIZE);
                break;
            case 3:
                calculate(main, SIZE);
                break;
            case 0:
                    printf("\t\t\t\tThank you. Have a great day!\n");
                return 0;
            default:
                printf("\t\t\t\tInvalid choice!");
            }
        }
        }

    }
    else
    {
        printf("\n\t\t\t\tInvalid choice!\n");
    }
    return 0;
}


//all the functions are here
registe()
{
    FILE *log;
    log  = fopen("dataStoreFile.txt","w");
    if(log == NULL)
        printf("File doest not opened,some thing is error\n");
    else
    {
        printf("File create successfully\n");
        struct Login person1;

        printf("\nEnter Person First name : ");
        fflush(stdin);
        gets(person1.fname);

        printf("Enter Person Last name : ");
        gets(person1.lname);

        printf("Enter Person user name : ");
        gets(person1.username);

        printf("Enter Person ID : ");
        scanf("%d",&person1.id);

        printf("Enter Person Password : ");
        scanf("%d",&person1.password);
        fwrite(&person1,sizeof(person1),1,log);
        printf("\nFile data written successful");

        fclose(log);

        printf("\n\nYour user name is your UserID\n");
        printf("Now,Login with UserID and Password\n");
        printf("\nPress any key to continue......................\n");
        getch();
        system("CLS");
        login();
    }
}
login()
{
    char username[10];
    int password;
    FILE *log;
    log  = fopen("dataStoreFile.txt","r");
    if(log == NULL)
        printf("File doest not opened,some thing is error\n");
    else
    {
        struct Login person1;
        printf("UserID : ");
        scanf("%s",&username);
        printf("Password : ");
        scanf("%d",&password);
        while(fread(&person1,sizeof(person1),1,log))
        {
            if(strcmp(username,person1.username) == 0 && person1.password == password)
            {
                printf("Successfully Login\n");
            }
            else
            {
                printf("Please !!!!!.......... Enter your correct UserID and Password ");
            }
        }
        fclose(log);
    }
}
void add(struct book a[], int size)
{
    int i, option;
    FILE *fp;
    system("cls");
    printf("\n\n\n\t\t\t\tPress 1 to add items or 0 to rewrite all the details:");
    scanf("%d", &option);
    if (option == 1)
    {
        fp = fopen("customer_file.txt", "a");
        if (fp == NULL)
        {
            printf("\t\t\t\tFile could not be opened!");
        }
        system("cls");
        system("color E1");
        for (i = 0; i < size; i++)
        {
            printf("\n\t\t\t\tWrite the name of the item or press enter to go back:");
            printf("\n\t\t\t\tName:");
            fflush(stdin);
            gets(a[i].name);
            if (strcmp(a[i].name, "") == 0)
            {
                break;
            }
            printf("\t\t\t\tEnter code: ");
            fflush(stdin);
            gets(a[i].code);
            printf("\t\t\t\tEnter price: ");
            scanf("%d", &a[i].price);
            printf("\t\t\t\tStock: ");
            fflush(stdin);
            gets(a[i].stock);
        }
        fwrite(a, sizeof(struct book), i, fp);
        fclose(fp);
    }
    else
    {
        fp = fopen("customer_file.txt", "w");
        if (fp == NULL)
        {
            system("cls");
            printf("\t\t\t\tFile could not be opened!");
        }
        system("cls");
        for (i = 0; i < size; i++)
        {
            printf("\t\t\t\tWrite the name of the item or press enter to go back: ");
            fflush(stdin);
            gets(a[i].name);
            if (strcmp(a[i].name, "") == 0)
            {
                break;
            }
            printf("\t\t\t\tEnter code: ");
            fflush(stdin);
            gets(a[i].code);;
            printf("\t\t\t\tEnter price: ");
            scanf("%d", &a[i].price);
            printf("\t\t\t\tStock: ");
            fflush(stdin);
            gets(a[i].stock);
        }
        fwrite(a, sizeof(struct book), i, fp);
        fclose(fp);
    }
}

void view(struct book b[], int n)
{
    int i, count = 0;
    FILE *fp;
    fp = fopen("customer_file.txt", "r");
    if (fp == NULL)
    {
        printf("\t\t\t\tFile could not be opened!");
    }
    count = fread(b, sizeof(struct book), SIZE, fp);
    system("cls");
    system("color E1");
    for (i = 0; i < count; i++)
    {
        printf("\n\n\n\t\t\t\tBook's Name: %s\n\t\t\t\tCode: %s\n\t\t\t\tPrice: %dTk\n\t\t\t\tStock: %s\n", b[i].name, b[i].code, b[i].price, b[i].stock);
    }
    fclose(fp);
}

void calculate(struct book c[], int m)
{
    int i, q, count = 0, total = 0, again = 0;
    char cal[20];
    FILE *fp;
    fp = fopen("customer_file.txt", "r");
    if (fp == NULL)
    {
        printf("\t\t\t\tFile could not be opened!");
    }
    count = fread(c, sizeof(struct book), SIZE, fp);
    system("cls");
    system("color E1");
    while (1)
    {
        printf("\n\n\n\t\t\t\tEnter the code of the Book: ");
        fflush(stdin);
        gets(cal);
        int flag = 0;
        for (i = 0; i < count; i++)
        {
            if (strcmp(c[i].code, cal) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            printf("\t\t\t\tEnter quantity: ");
            scanf("%d", &q);
            total = c[i].price * q;
            printf("\n\t\t\t\tTotal amount: %d\n", total);
        }
        else
        {
            printf("\t\t\t\tInvalid code!\n");
        }
        printf("Press 1 to calculate another bill and 0 to go back: ");
        scanf("%d", &again);
        if (again == 0)
        {
            break;
        }
        else if (again == 1)
        {
            continue;
        }
    }
}

void search(struct book d[], int x)
{
    int i, count = 0, flag = 0, again = 0;
    char sea[20];
    FILE *fp;
    fp = fopen("customer_file.txt", "r");
    if (fp == NULL)
    {
        printf("\t\t\t\tFile could not be opened!");
    }
    count = fread(d, sizeof(struct book), SIZE, fp);
    system("cls");
    system("color E1");
    while (1)
    {
        printf("\n\n\n\t\t\t\tEnter the Book code you want to search for details: ");
        fflush(stdin);
        gets(sea);
        for (i = 0; i < count; i++)
        {
            if (strcmp(d[i].code, sea) == 0)
            {
                printf("\t\t\t\tBook's Name: %s\n\t\t\t\tPrice: %dTk\n\t\t\t\t\n\t\t\t\tStock: %s\n", d[i].name, d[i].price, d[i].stock);
                flag = 1;
                break;
            }
        }
        if (flag != 1)
        {
            printf("\t\t\t\tInvalid Book code!");
        }

        printf("\n\t\t\t\tPress 1 to search again or 0 to go back: ");
        scanf("%d", &again);
        if (again == 0)
        {
            break;
        }
        else if (again == 1)
        {
            continue;
        }
    }
    fclose(fp);
}
void delete (struct book e[], int y)
{
    int i, j, count = 0, flag = 0, again = 0;
    char del[20];
    FILE *fp;
    fp = fopen("customer_file.txt", "r");
    if (fp == NULL)
    {
        printf("\t\t\t\tFile could not be opened!");
    }
    count = fread(e, sizeof(struct book), SIZE, fp);
    fclose(fp);
    system("cls");
    system("color E1");
    while (1)
    {
        printf("\t\t\t\tEnter the Book code you want to delete: ");
        fflush(stdin);
        gets(del);
        for (i = 0; i < count; i++)
        {
            if (strcmp(e[i].code, del) == 0)
            {
                for (j = i; j < count - 1; j++)
                {
                    e[j] = e[j + 1];
                    flag = 1;
                    break;
                }
                --count;
            }
        }
        printf("\n\t\t\t\tPress 1 to delete more items or 0 to go back: ");
        scanf("%d", &again);
        if (again == 0)
        {
            break;
        }
        else if (again == 1)
        {
            continue;
        }
    }
    fp = fopen("customer_file.txt", "w");
    if (fp == NULL)
    {
        printf("\t\t\t\tFile could not be opened!");
    }
    fwrite(e, sizeof(struct book), count, fp);
    printf("\nGo to the view all Books section to see the updated list.\n");
    fclose(fp);
}

void modify(struct book f[], int z)
{
    int i, count = 0, again = 0;
    char ed[20], mod[20];
    FILE *fp;
    fp = fopen("customer_file.txt", "r");
    if (fp == NULL)
    {
        printf("\t\t\t\tFile could not be opened!");
    }
    count = fread(f, sizeof(struct book), SIZE, fp);
    fclose(fp);
    system("cls");
    system("color E1");
    while (1)
    {
        printf("\n\n\n\t\t\t\tEnter the Book code to edit its details: ");
        fflush(stdin);
        gets(ed);
        for (i = 0; i < z; i++)
        {
            if (strcmp(f[i].code, ed) == 0)
            {
                printf("\n\n\t\t\t\tWhat would you like to change?");
                printf("\n\n\t\t\t\tEnter (name/price/code/stock) : \n\t\t\t\t");
                fflush(stdin);
                gets(mod);
                if (strcmp(mod, "name") == 0)
                {
                    printf("\t\t\t\tEnter new name for the Book:");
                    fflush(stdin);
                    gets(f[i].name);
                    printf("\n\t\t\t\tNew name is set successfully!");
                    break;
                }
                else if (strcmp(mod, "stock") == 0)
                {
                    printf("\t\t\t\tEnter info about the Book's avalability:");
                    gets(f[i].stock);
                    printf("\n\t\t\t\tInfo about stock of the Book is updated successfully!");
                    break;
                }
                else if (strcmp(mod, "price") == 0)
                {
                    printf("\t\t\t\tEnter new price for the Book:");
                    scanf("%d", &f[i].price);
                    printf("\n\t\t\t\tNew price is updated successfully!");
                    break;
                }
                else if (strcmp(mod, "code") == 0)
                {
                    printf("\t\t\t\tEnter new code for the Book:");
                    gets(f[i].code);
                    printf("\n\t\t\t\tNew code is updated successfully!");
                    break;
                }
            }
        }
        printf("\n\t\t\t\tPress 1 to make more changes or 0 to go back: ");
        scanf("%d", &again);
        if (again == 0)
        {
            break;
        }
        else if (again == 1)
        {
            continue;
        }
    }

    fp = fopen("customer_file.txt", "w");
    if (fp == NULL)
    {
        printf("\t\t\t\tFile could not be opened!");
    }
    fwrite(f, sizeof(struct book), count, fp);
    fclose(fp);
}
