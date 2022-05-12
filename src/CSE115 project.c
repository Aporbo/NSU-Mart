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
static int i = 0;
struct web
{
    char name[30], pass[30];
} w[99];
int n;
void login(void);
void reg(void);
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
    // multiple user
    int userType;

    time_t now;
    time(&now);
    printf("\n\t\t\t\t\t%s", ctime(&now));

    // first page or login page
    printf("\n\t\t\t\t Welcome to NSU mart!");
    printf("\n\n\t\t\t\tLogin as:");
    printf("\n\n\t\t\t\t1) Admin:");
    printf("\n\n\t\t\t\t2) Customer:\n");
    printf("\n\n\t\t\t\tEnter your choice:");
    scanf("%d", &userType);

    // for admin
    if (userType == 1)
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
            printf("\n\t\t\t\t\t%s", ctime(&now));

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
    // for customer
    if (userType == 2)
    {
        system("cls");
        // Menu//
    XY: // Label for the goto//
        printf("\n\n\n\t\t\t1. LOGIN\t\t2. REGISTER");
        printf("\n\n\n\t\t\t\tENTER YOUR CHOICE: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            system("cls");

            login();
            break;
        case 2:
            system("cls");

            reg();
            break;
        default:
            printf("\n\n\t\t\t\tNO MATCH FOUND");
            printf("\n\n\t\t\tPress Enter to re-Enter the choice");
            if (getch() == 13)
                system("cls");

            goto XY;
        }
    }
    else
    {
        printf("\n\t\t\t\tInvalid choice!\n");
    }
    return 0;
}

// all the functions are here
void reg()
{
    int z = 0;
    FILE *fp;                        // fp is the file pointer//
    char c, checker[30];             // c is temporary variable, checker is the input string//
    fp = fopen("Web_reg.txt", "a"); // File opened for appending//
    printf("\n\n\t\t\t\tWELCOME TO REGISTER ZONE");
    printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^");
    for (i = 0; i < 100; i++)
    {
        printf("\n\n\t\t\t\t  ENTER USERNAME: ");
        scanf("%s", checker);
        while (!feof(fp))
        {
            fread(&w[i], sizeof(w[i]), 2, fp);
            // checking whether user exist//
            if (strcmp(checker, w[i].name) == 0)
            {
                printf("\n\n\t\t\tUSERNAME ALREDY EXISTS");
                system("cls");
                reg();
            }
            else
            {
                strcpy(w[i].name, checker);
                break;
            }
        }
        printf("\n\n\t\t\t\t  DESIRED PASSWORD: ");
        while ((c = getch()) != 13) // 13 refers to carriage return//
        {
            w[i].pass[z++] = c;
            printf("%c", '*');
        }
        fwrite(&w[i], sizeof(w[i]), 1, fp);
        fclose(fp);
        printf("\n\n\tPress enter if you agree with Username and Password");
        if ((c = getch()) == 13)
        {
            system("cls");
            printf("\n\n\t\tYou are successfully registered");
            printf("\n\n\t\tTry login your account??\n\n\t\t  ");
            printf("> PRESS 1 FOR YES\n\n\t\t  > PRESS 2 FOR NO\n\n\t\t\t\t");
            scanf("%d", &n);
            switch (n)
            {
            case 1:
                system("cls");
                login();
                break;
            case 2:
                system("cls");
                printf("\n\n\n\t\t\t\t\tTHANK YOU FOR REGISTERING");
                break;
            }
        }
        break;
    }
    getch();
}
void login()
{
    int input;
    time_t now;
    time(&now);
    FILE *fp;
    char c, name[30], pass[30];
    int z = 0;
    int checku, checkp;
    struct book main[SIZE];
               // checkuser name and check password//
    fp = fopen("Web_reg.txt", "r"); // opening in read mode//
    printf("\n\n\t\t\t\tWELCOME TO LOG IN ZONE");
    printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^");
    for (i = 0; i < 1000; i++)
    {
        printf("\n\n\t\t\t\t  ENTER USERNAME: ");
        scanf("%s", name);
        printf("\n\n\t\t\t\t  ENTER PASSWORD: ");
        while ((c = getch()) != 13)
        {
            pass[z++] = c;
            printf("%c", '*');
        }
        pass[z] = '\0';
        while (!feof(fp))
        {
            fread(&w[i], sizeof(w[i]), 1, fp);
            checku = strcmp(name, w[i].name);
            checkp = strcmp(pass, w[i].pass);
            if (checku == 0 && checkp == 0)
                break;
        }
        if (checku == 0 && checkp == 0)
        {
            system("cls");
            printf("\n\n\n\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!");
            printf("\n\n\n\t\t\t\tWELCOME, HAVE A NICE DAY");

            printf("Successfully Login\n");
            system("cls");
            system("color E1");
            while (1)
            {
                printf("\n\t\t\t\t\t%s", ctime(&now));
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
        else if (checku == 0 && checkp != 0)
        {
            printf("\n\n\n\t\t\tWRONG PASSWORD!! Not %s??", name);
            printf("\n\n\t\t\t\t  (Press 'Y' to re-login)");
            if (getch() == 'y' || getch() == 'Y')
                login();
        }
        else
        {
            printf("\n\n\n\t\t\tYou are not a Registered User\n \t\t\tPress enter to register yourself");
            if (getch() == 13)
                system("cls");
            reg();
        }
    }
    getch();
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
            gets(a[i].code);
            ;
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
