
#include <stdio.h>  //standard input output header file.
#include <string.h> //String header file to use strings
#include <stdlib.h> // standard library to use dynamic memroy allocation

char subject[4][40] = {"Fundamental of computer application", "C language", "Languager & communication", "Physics"}; // global string variable
typedef struct student                                                                                               // structure typedef data type which have uncertain objects.
{
    int rno;
    char name[20];
    char m_name[25]; // variables which will conatain data
    char f_name[25];
    char gmail[30];
    long long phnum;
    struct sub
    { // nested structure to contain subjects marks
        int marks;
    } sub[4];
    char address[30];
    int total;
    float per;
} student; // structure object which can have different other objects

void create() // create function to which is stands for to create data
{
    student *s, s1;
    int n, i, j;
    printf("Enter how many students data you want to enter: ");
    scanf("%d", &n);
    FILE *ptr;                                 //  file pointer to use file handling to store data for long time use
    ptr = fopen("class_management.txt", "w");  // file open in write mode
    s = (student *)calloc(n, sizeof(student)); // dynamic memory allocation to make a fix block of memory
    for (i = 0; i < n; i++)
    {
        s[i].total = 0;
        s[i].per = 0;
        printf("\n\nEnter student Roll num:");
        scanf("%d", &s[i].rno);
        fflush(stdin);

        printf("Enter Name of Student:");
        scanf("%[^\n]s", &s[i].name);
        fflush(stdin);
        printf("Enter student father name: ");
        scanf("%[^\n]s", &s[i].f_name);
        fflush(stdin);
        printf("Enter student mother name: ");
        scanf("%[^\n]s", &s[i].m_name);
        fflush(stdin);
        printf("Contact number of student: ");
        scanf("%lld", &s[i].phnum);
        fflush(stdin);
        printf("Enter student Gmail ID: ");
        scanf("%[^\n]s", &s[i].gmail);
        fflush(stdin);
        printf("Enter student address: ");
        scanf("%[^\n]s", &s[i].address); // to take the information of each student
        fflush(stdin);
        for (j = 0; j < 4; j++)
        {
            printf("Enter marks of sub %s: ", subject[j]);
            scanf("%d", &s[i].sub[j].marks);
            s[i].total += s[i].sub[j].marks;
        }
        s[i].per = s[i].total / 4.0;
        fwrite(&s[i], sizeof(student), 1, ptr); // write all given data in file handling
    }
    fclose(ptr); // close the file
}
void display_data() // seond function to display the stored data of studet
{
    student s1, *s;
    FILE *ptr;

    int j, i;
    ptr = fopen("class_management.txt", "r");
    fseek(ptr, 0, SEEK_END);
    int n = ftell(ptr) / sizeof(student);
    s = (student *)calloc(n, sizeof(student));
    rewind(ptr);
    printf("\nRoll No.      Student Name   \t \tFather Name\t\t Mother Name\t   FOC\t    C Lang.   L & C     Phy.   Total\t Per.\n");
    for (i = 0; i < n; i++)
    {
        fread(&s[i], sizeof(student), 1, ptr);
    }
    for (i = 0; i < n; i++) // Logic to display all data in ascending order by following roll number.
    {
        for (j = i + 1; j < n; j++)
        {

            if (s[i].rno > s[j].rno)
            {
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("\n%-15d%-4s%25s%25s", s[i].rno, s[i].name, s[i].f_name, s[i].m_name);
        for (j = 0; j < 4; j++)
        {
            printf("%10d", s[i].sub[j].marks);
        }
        printf("  %7d%10.2f", s[i].total, s[i].per);
    }

    fclose(ptr);
}
void display_contact() // third function to display contact of the student
{
    student s1, *s;
    FILE *ptr;

    int j, i;
    ptr = fopen("class_management.txt", "r");
    fseek(ptr, 0, SEEK_END);
    int n = ftell(ptr) / sizeof(student);
    s = (student *)calloc(n, sizeof(student)); // dynamic memory allocation to make a fix memory block .
    rewind(ptr);
    printf("\nRoll No.  Student Name     \t Contact num.   \tGmail ID\t\t    Address\n");
    for (i = 0; i < n; i++)
    {
        fread(&s[i], sizeof(student), 1, ptr);
    }
    for (i = 0; i < n; i++) // Logic to display data in ascending order by following roll number.
    {
        for (j = i + 1; j < n; j++)
        {

            if (s[i].rno > s[j].rno)
            {
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("\n%-10d%-5s%22lld%30s%36s", s[i].rno, s[i].name, s[i].phnum, s[i].gmail, s[i].address);
    }

    fclose(ptr);
}
void append() // forth function to append the extra data
{
    student *s;
    int n, i, j;
    printf("Enter how many students data you want to Insert: ");
    scanf("%d", &n);
    FILE *ptr;
    ptr = fopen("class_management.txt", "a");  // open file to append data
    s = (student *)calloc(n, sizeof(student)); // dynamic memrory allocation
    for (i = 0; i < n; i++)
    {
        s[i].total = 0;
        s[i].per = 0;
        printf("\n\nEnter student Roll num:");
        scanf("%d", &s[i].rno);
        fflush(stdin);
        printf("Enter Name of Student:");
        scanf("%[^\n]s", &s[i].name);
        fflush(stdin);
        printf("Enter student father name: ");
        scanf("%[^\n]s", &s[i].f_name);
        fflush(stdin);
        printf("Enter student mother name: ");
        scanf("%[^\n]s", &s[i].m_name);
        fflush(stdin);
        printf("Enter student Mobile num: ");
        scanf("%lld", &s[i].phnum);
        fflush(stdin);
        printf("Enter student Gmail ID: ");
        scanf("%[^\n]s", &s[i].gmail);
        fflush(stdin);
        printf("Student address: ");
        scanf("%[^\n]s", &s[i].address);
        fflush(stdin);
        for (j = 0; j < 4; j++)
        {
            printf("Enter marks of sub %s: ", subject[j]);
            scanf("%d", &s[i].sub[j].marks);
            s[i].total += s[i].sub[j].marks;
        }
        s[i].per = s[i].total / 4.0;
        fwrite(&s[i], sizeof(student), 1, ptr);
    }

    fclose(ptr);
}

void recno() // fifth function to calculate the number of records
{

    student s1;
    FILE *ptr;

    ptr = fopen("class_management.txt", "r");
    fseek(ptr, 0, SEEK_END);               // to set the cursor in file at the end fo file
    long a = ftell(ptr) / sizeof(student); // it will calculate the records number.
    printf("You have stored %ld records.", a);

    fclose(ptr);
}
void search() // sixth function to search data by enter the roll number.
{
    student s1;
    int rno, j, i = 0;
    printf("Enter Roll number which you want to search: ");
    scanf("%d", &rno);
    FILE *ptr;
    ptr = fopen("class_management.txt", "r");

    while (fread(&s1, sizeof(student), 1, ptr))
    {
        if (s1.rno == rno)
        {
            i = 1;
            printf("\nRoll No.  Student Name     Father Name\t   Mother Name\t   Contact num.      \tGmail ID\t\t    Address\t\t\tFOC      C Lang.    L & C      Phy.    total    per.\n");

            printf("\n%-10d%-15s%13s%15s%15lld%30s%30s", s1.rno, s1.name, s1.f_name, s1.m_name, s1.phnum, s1.gmail, s1.address);
            for (j = 0; j < 4; j++)
            {
                printf("%10d", s1.sub[j].marks);
            }
            printf("  %8d%9.2f", s1.total, s1.per);
        }
    }
    if (!i)
    {

        printf("~RECOND NOT FIND~\n\n");
    }
    fclose(ptr);
}

void update() // function to update the information of any student who is available in stored in record
{
    student s1;
    int rno, found = 0, j;
    printf("Enter roll number which you want to update: ");
    scanf("%d", &rno);
    FILE *ptr, *ptr1;
    ptr = fopen("class_management.txt", "r");
    ptr1 = fopen("temp.txt", "w");

    while (fread(&s1, sizeof(student), 1, ptr))
    {
        if (s1.rno == rno)
        {
            s1.total = 0;
            s1.per = 0;
            found = 1;
            fflush(stdin);
            printf("Enter New Name: ");
            scanf("%[^\n]s", &s1.name);
            fflush(stdin);
            printf("Enter student father name: ");
            scanf("%[^\n]s", &s1.f_name);
            fflush(stdin);
            printf("Enter student mother name: ");
            scanf("%[^\n]s", &s1.m_name);
            fflush(stdin);
            printf("Enter student Gmail ID: ");
            scanf("%[^\n]s", &s1.gmail);
            fflush(stdin);
            printf("Student contact number: ");
            scanf("%lld", &s1.phnum);
            fflush(stdin);
            printf("Student address: ");
            scanf("%[^\n]s", &s1.address);
            fflush(stdin);
            for (j = 0; j < 4; j++)
            {
                printf("Enter Marks of sub%d: ", j + 1);
                scanf("%d", &s1.sub[j].marks);
                s1.total += s1.sub[j].marks;
            }
            s1.per = s1.total / 4.0;
        }
        fwrite(&s1, sizeof(student), 1, ptr1);
    }
    fclose(ptr);
    fclose(ptr1);

    if (found == 1)
    {
        ptr = fopen("class_management.txt", "w");
        ptr1 = fopen("temp.txt", "r");
        while (fread(&s1, sizeof(student), 1, ptr1))
        {

            fwrite(&s1, sizeof(student), 1, ptr);
        }
        fclose(ptr);
        fclose(ptr1);
    }
    else
    {
        printf("~RECORD NOT FOUND~");
    }
}

void delete() // delete function to delete  record one by one.
{
    student s1;
    int rno, found = 0, j;
    FILE *ptr, *ptr1;
    printf("Enter roll number which you want to delete: ");
    scanf("%d", &rno);

    ptr = fopen("class_management.txt", "r"); // open file in read mode which have stored data
    ptr1 = fopen("temp.txt", "w");            // open file in write mode which which contain all data except which roll number you entered

    while (fread(&s1, sizeof(student), 1, ptr))
    {
        if (s1.rno == rno)
        {
            found = 1;
        }
        else
        {
            fwrite(&s1, sizeof(student), 1, ptr1);
        }
    }
    fclose(ptr);
    fclose(ptr1);

    if (found)
    {
        ptr = fopen("class_management.txt", "w");
        ptr1 = fopen("temp.txt", "r");
        while (fread(&s1, sizeof(student), 1, ptr1))
        {

            fwrite(&s1, sizeof(student), 1, ptr);
        }
        fclose(ptr);
        fclose(ptr1);
    }
    else
    {
        printf("~RECORD NOT FOUND~");
    }
}

void per_in__descen_order() // function to sorting the data on the basis of percentage and total marks
{
    student s1, *s;
    FILE *ptr;

    int j, i;
    ptr = fopen("class_management.txt", "r");
    fseek(ptr, 0, SEEK_END);
    int n = ftell(ptr) / sizeof(student);
    s = (student *)calloc(n, sizeof(student));
    rewind(ptr);
    printf("\nRoll No.      Student Name   \t \tFather Name\t\t Mother Name\t   FOC\t    C Lang.   L & C     Phy.   Total\t Per.\n");
    for (i = 0; i < n; i++)
    {
        fread(&s[i], sizeof(student), 1, ptr);
    }
    for (i = 0; i < n; i++) // Logic to sorting the data in ascending order..
    {
        for (j = i + 1; j < n; j++)
        {

            if (s[i].per < s[j].per)
            {
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf ("\n%-15d%-4s%25s%25s", s[i].rno, s[i].name, s[i].f_name, s[i].m_name);
        for (j = 0; j < 4; j++)
        {
            printf("%10d", s[i].sub[j].marks);
        }
        printf("  %7d%10.2f", s[i].total, s[i].per);
    }

    fclose(ptr);
}

int main() // Main function where from the compiler start the execution
{

    int ch;
    do // do while loop to carry on a statement until and unless we don't press 0
    {
        printf("\n\n20.CREATE NEW DATA~");
        printf("\n0.EXIT~");
        printf("\n1.INSERT MORE DATA~");
        printf("\n2.DISPLAY STUDENT DATA~");
        printf("\n3.DISPLAY STUDENT CONTACT");
        printf("\n4.NO. OF RECORDS~");
        printf("\n5.SEARCH BY ROLL NUMBER~");
        printf("\n6.UPDATE RECORDS~");
        printf("\n7.DELETE RECORD~");
        printf("\n8.PER. IN DESCENDING ORDER~ ");
        printf("\n\nEnter you option: ");
        scanf("%d", &ch);

        switch (ch)
        { // switch cases...
        case 20:
            create();
            break;

        case 0:
            break;

        case 1:
            append();
            break;

        case 2:
            display_data();
            break;

        case 3:
            display_contact();
            break;

        case 4:
            recno();
            break;

        case 5:
            search();
            break;

        case 6:
            update();
            break;

        case 7:
            delete ();
            break;

        case 8:
            per_in__descen_order();
            break;

        default:
            printf("WRONG INPUT TRY AGAIN");
            break;
        }
    } while (ch != 0);             //while condition if we press 0 then will be  terminate
    return 0;             //End the all program execution.
}                                                                   //Enjoy the code :)


