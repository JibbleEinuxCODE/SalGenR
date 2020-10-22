//this project name is SalGenR
//This project for Employees details store in companies Database..
// Using this Project we can handle our Employees Details
// We can add new employee , we can search Employee, We can Modify Employees Records

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define _Username_ "Admin" //Define a Default Username for Login
#define _Password_ "Admin" //Define a Default Password for Login

//Declaring a Structure for store employees Details
struct employee
{
    //properties of a Employee
    char name[20];
    int age;
    int phone_number;
    double salary;
    struct employee *next;
} * head, *tail;

// login section
bool loginCheck(char name[15], char pass[15])
{
    if (strcmp(name, _Username_) == 0) //checking input Username to stored Username
    {
        if (strcmp(pass, _Password_) == 0) //checking input password to stroed Password
        {
            return true; //if Username and Password are matched then it returns a truth value
        }
    }
    else
    {
        return false; //if Username and Password are not matched then it returns a flase value
    }
}

void create_linked_list()
{
    int n, i = 1;
    char name[20];
    int age, pnumber;
    double salary;
    printf("Enter Amount of Employee: ");
    scanf("%d", &n);

    while (n--)
    {
        printf("Enter Details for Employee %d\n", i);
        printf("Enter Name: ");
        getchar();
        gets(name);
        printf("Enter Age: ");
        scanf("%d", &age);
        printf("Enter Phone number: ");
        scanf("%d", &pnumber);
        printf("Enter Salary: ");
        scanf("%lf", &salary);

        struct employee *temp_node;
        temp_node = (struct employee *)malloc(sizeof(struct employee));
        strcpy(temp_node->name, name);
        temp_node->age = age;
        temp_node->phone_number = pnumber;
        temp_node->salary = salary;
        temp_node->next = NULL;

        //For the 1st element
        if (head == NULL)
        {
            head = temp_node;
            tail = temp_node;
        }
        else
        {
            tail->next = temp_node;
            tail = temp_node;
        }
        i++;
    }
}

void insert_at_last()
{
    char name[20];
    int age, pnumber;
    double salary;
    printf("Enter Details for Employee.\n");
    printf("Enter Name: ");
    getchar();
    gets(name);
    printf("Enter Age: ");
    scanf("%d", &age);
    printf("Enter Phone number: ");
    scanf("%d", &pnumber);
    printf("Enter Salary: ");
    scanf("%lf", &salary);
    struct employee *temp_node;
    temp_node = (struct employee *)malloc(sizeof(struct employee));
    strcpy(temp_node->name, name);
    temp_node->age = age;
    temp_node->phone_number = pnumber;
    temp_node->salary = salary;
    temp_node->next = NULL;

    //For the 1st element
    if (head == NULL)
    {
        head = temp_node;
        tail = temp_node;
    }
    else
    {
        tail->next = temp_node;
        tail = temp_node;
    }
}

void insert_at_first()
{
    char name[20];
    int age, pnumber;
    double salary;
    printf("Enter Details for Employee.\n");
    printf("Enter Name: ");
    getchar();
    gets(name);
    printf("Enter Age: ");
    scanf("%d", &age);
    printf("Enter Phone number: ");
    scanf("%d", &pnumber);
    printf("Enter Salary: ");
    scanf("%lf", &salary);
    struct employee *temp_node = (struct employee *)malloc(sizeof(struct employee));
    strcpy(temp_node->name, name);
    temp_node->age = age;
    temp_node->phone_number = pnumber;
    temp_node->salary = salary;
    temp_node->next = head;
    head = temp_node;
}
void print_employee_list()
{
    struct employee *temp = head;
    if (head == NULL)
    {
        printf("Employee list is Empty\n");
    }
    else
    {
        int i = 1;
        while (temp != NULL)
        {
            printf("\n\nDetails for Employee %d\n", i);
            printf("Name: ");
            puts(temp->name);
            printf("Age: %d\n", temp->age);
            printf("Phone Number: 0%d\n", temp->phone_number);
            printf("Salary: %.2lf\n", temp->salary);
            temp = temp->next;
            i++;
        }
    }
}

void search_Employee_By_Name()
{
    char value[20];
    struct employee *searchNode = head;
    int flag = 0;
    getchar();
    gets(value);
    while (searchNode != NULL)
    {
        if (strlwr(searchNode->name) == strlwr(value))
        {
            printf("\n\nSearch Result.\n");
            printf("-----------------\n");
            printf("%s Name employee present in this database.\n", value);
            printf("Name: ");
            puts(searchNode->name);
            printf("Age: %d\n", searchNode->age);
            printf("Phone Number: 0%d\n", searchNode->phone_number);
            printf("Salary: %.2lf\n", searchNode->salary);
            flag = 1;
            searchNode = searchNode->next;
        }
        else
            searchNode = searchNode->next;
    }

    if (flag == 0)
        printf("Employee not found\n");
}

void search_Employee_By_Age()
{
    int value;
    struct employee *searchNode = head;
    int flag = 0;
    scanf("%d", &value);
    while (searchNode != NULL)
    {
        if (searchNode->age == value)
        {
            printf("\n\nSearch Result.\n");
            printf("-----------------\n");
            printf("%d Age employee present in this database.\n", value);
            printf("Name: ");
            puts(searchNode->name);
            printf("Age: %d\n", searchNode->age);
            printf("Phone Number: 0%d\n", searchNode->phone_number);
            printf("Salary: %.2lf\n", searchNode->salary);
            flag = 1;
            searchNode = searchNode->next;
        }
        else
            searchNode = searchNode->next;
    }

    if (flag == 0)
        printf("Employee not found\n");
}

void search_Employee_By_phone()
{
    int value;
    struct employee *searchNode = head;
    int flag = 0;
    scanf("%d", &value);
    while (searchNode != NULL)
    {
        if (searchNode->phone_number == value)
        {
            printf("\n\nSearch Result.\n");
            printf("-----------------\n");
            printf("%d Phone Number employee present in this database.\n", value);
            printf("Name: ");
            puts(searchNode->name);
            printf("Age: %d\n", searchNode->age);
            printf("Phone Number: 0%d\n", searchNode->phone_number);
            printf("Salary: %.2lf\n", searchNode->salary);
            flag = 1;
            searchNode = searchNode->next;
        }
        else
            searchNode = searchNode->next;
    }

    if (flag == 0)
        printf("Employee not found\n");
}

void search_Employee_By_Salary()
{
    double value;
    struct employee *searchNode = head;
    int flag = 0;
    scanf("%d", &value);
    while (searchNode != NULL)
    {
        if (searchNode->salary == value)
        {
            printf("\n\nSearch Result.\n");
            printf("-----------------\n");
            printf("%ld Salary employee present in this database.\n", value);
            printf("Name: ");
            puts(searchNode->name);
            printf("Age: %d\n", searchNode->age);
            printf("Phone Number: 0%d\n", searchNode->phone_number);
            printf("Salary: %.2lf\n", searchNode->salary);
            flag = 1;
            searchNode = searchNode->next;
        }
        else
            searchNode = searchNode->next;
    }

    if (flag == 0)
        printf("Employee not found\n");
}

void search_Employee_By_Place()
{
    char value[20];
    struct employee *searchNode = head;
    int flag = 0;
    getchar();
    gets(value);
    while (searchNode != NULL)
    {
        if (strlwr(searchNode->name) == strlwr(value))
        {
            printf("\n\nSearch Result.\n");
            printf("-----------------\n");
            printf("%s area employee present in this database.\n", value);
            printf("Name: ");
            puts(searchNode->name);
            printf("Age: %d\n", searchNode->age);
            printf("Phone Number: 0%d\n", searchNode->phone_number);
            printf("Salary: %.2lf\n", searchNode->salary);
            flag = 1;
            searchNode = searchNode->next;
        }
        else
            searchNode = searchNode->next;
    }

    if (flag == 0)
        printf("Employee not found\n");
}

void printLogo()
{
    printf("-------------------------SaLGenR---------------------------\n");
}

int main()
{
    head = NULL;
    tail = NULL;
    int option, option1, option2;
    char name[15], pass[15], name1[20];
    double salary;
    printLogo();
    while (1)
    {
        printf("You need to login first.\n");
        printf("Username: ");
        gets(name);
        printf("Password: ");
        gets(pass);
        if (loginCheck(name, pass))
        {
            while (1)
            {
                printf("\nSelect Your Option From Menu.\n");
                printf("------------------------------\n");
                printf("1.Add New\n2.List\n3.Exit\n4.Modify\n5.Search\n6.Delete\n");
                printf("\nSalGenR>> ");
                scanf("%d", &option);
                switch (option)
                {
                case 1:
                    printf("\nChoose Option.\n--------------\n1.Add Employee Continuesly.\n2.Add Employee at First.\n3.Add Employee in position\n4.Add Employee at Last.\n");
                    printf("\nAdd New>> ");
                    scanf("%d", &option1);
                    switch (option1)
                    {
                    case 1:
                        create_linked_list();
                        break;
                    case 2:
                        insert_at_first();
                        break;
                    case 3:

                        break;
                    case 4:
                        insert_at_last();
                        break;
                    default:
                        printf("You Need to select valid option\n");
                        break;
                    }
                    break;
                case 2:
                    print_employee_list();
                    break;
                case 3:
                    exit(0);
                    break;
                case 4:
                    break;
                case 5:
                    //case 5 ----Search section start
                    printf("\nChoose your Searching Option.\n");
                    printf("-------------------------------\n");
                    printf("1.Search by Name\n");
                    printf("2.Search by Age\n");
                    printf("3.Search by Phone Number\n");
                    printf("4.Search by Salary\n");
                    printf("5.Search by Place\n");
                    printf("Search>> ");
                    scanf("%d", option2);
                    switch (option2)
                    {
                    case 1:
                        search_Employee_By_Name();
                        break;
                    case 2:
                        search_Employee_By_Age();
                        break;
                    case 3:
                        search_Employee_By_phone();
                        break;
                    case 4:
                        search_Employee_By_Salary();
                        break;
                    case 5:
                        search_Employee_By_Place();
                        break;
                    default:
                        printf("You have to choose right option\n");
                        break;
                    }
                    //case 5 ----search section End
                    break;
                case 6:
                    break;
                default:
                    printf("You Need to choose option into 1-6\n");
                    break;
                }
            }

            break;
        }
    }

    return 0;
}