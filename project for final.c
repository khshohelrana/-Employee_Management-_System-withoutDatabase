#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct EMS
{
    int id;
    char name[100];
    char phone[100];
    float salary;
    char date[100];
    char BDG[100];
    struct EMS *next;

}* head=NULL;

int c=0;
void insert(int id, char* name, char* phone, float salary, char* date,char* BDG)
{
    c++;
    struct EMS * employee = (struct EMS *) malloc(sizeof(struct EMS));
    employee->id = id;
    strcpy(employee->name, name);
    strcpy(employee->phone, phone);
    employee->salary = salary;
    strcpy(employee->date, date);
    strcpy(employee->BDG, BDG);
    employee->next = NULL;

    if(head==NULL)
    {
        head = employee;
    }
    else
    {
        employee->next = head;
        head = employee;
    }
}

void search(int id)
{
    struct EMS * temp = head;
    while(temp!=NULL)
    {
        if(temp->id==id)
        {
            printf("\t\t\t\t\t\t\t\tID Number: %d\n", temp->id);
            printf("\t\t\t\t\t\t\t\tName: %s\n", temp->name);
            printf("\t\t\t\t\t\t\t\tPhone Number: %s\n", temp->phone);
            printf("\t\t\t\t\t\t\t\tSalary: %0.2f\n", temp->salary);
            printf("\t\t\t\t\t\t\t\tJoining date: %s\n", temp->date);
            printf("\t\t\t\t\t\t\t\tBlood Group: %s\n", temp->BDG);

            return;
        }
        temp = temp->next;
    }
     printf("\t\t\t\t\t\t\t\tEmployee with ID %d is not found !!!\n", id);
}

void update(int id)
{       struct EMS * employee = (struct EMS *) malloc(sizeof(struct EMS));
    struct EMS * temp = head;
    while(temp!=NULL)
    {
       if(temp->id==id)
        {
            printf("\t\t\t\t\t\t\t\tRecord with ID %d Found !!!\n", id);
            printf("\t\t\t\t\t\t\t\tEnter new name: ");
            scanf("%s", temp->name);
           strcpy(temp->name, temp->name);
            fflush(stdin);
            printf("\t\t\t\t\t\t\t\tEnter new phone number: ");
            scanf("%s", temp->phone);
            fflush(stdin);
            printf("\t\t\t\t\t\t\t\tEnter new Salary: ");
            scanf("%f",&temp->salary);
            fflush(stdin);
            printf("\t\t\t\t\t\t\t\tEnter joining date: ");
            scanf("%s",temp->date);
            fflush(stdin);
            printf("\t\t\t\t\t\t\t\tEnter Blood Group: ");
            scanf("%s",temp->BDG);
            fflush(stdin);
            printf("\t\t\t\t\t\t\t\tSuccessfully updated!!!\n");
            return;
        }
        temp = temp->next;
    }
    printf("\t\t\t\t\t\t\t\tEmployee with ID %d is not found !!!\n", id);
}

void Delete(int id)
{  c--;
    struct EMS * temp1 = head;
    struct EMS * temp2 = head;
    while(temp1!=NULL)
    {
       if(temp1->id==id)
        {

            printf("\t\t\t\t\t\t\t\tRecord with id %d Found !!!\n", id);

            if(temp1==temp2)
            {
                head = head->next;
                free(temp1);
            }
            else
            {
                temp2->next = temp1->next;
                free(temp1);
            }
            printf("\t\t\t\t\t\t\t\tRecord Successfully Deleted !!!\n");
            return;

        }
        temp2 = temp1;
        temp1 = temp1->next;

    }
    printf("\t\t\t\t\t\t\t\tEmployee with ID %d is not found !!!\n", id);
}

void display()
{
    struct EMS * temp = head;
    while(temp!=NULL)
    {
        printf("\t\t\t\t\t\t\t\t-------------------------------------\n");
        printf("\t\t\t\t\t\t\t\tID Number: %d\n", temp->id);
        printf("\t\t\t\t\t\t\t\tName: %s\n", temp->name);
        printf("\t\t\t\t\t\t\t\tPhone Number: %s\n", temp->phone);
        printf("\t\t\t\t\t\t\t\tSalary: %0.2f\n", temp->salary);
        printf("\t\t\t\t\t\t\t\tJoining Date: %s\n\n", temp->date);
        printf("\t\t\t\t\t\t\t\tBlood Group: %s\n\n", temp->BDG);
        temp = temp->next;
    }
}

void bubblesort()
{
    printf("\n");
    struct EMS *temp, *cpt;
    int a;
    float b;
    char n[100], p[100],d[100],bd[100];
    temp= head;
    printf("\t\t\t\t\t\t\t\t<--All information of Employees-->\n");
    printf("\t\t\t\t\t\t\t\t----------------------------------\n");
    while(temp->next!=NULL)

    {
        cpt=temp->next;
        while(cpt!=NULL)

        {
            if(temp->id > cpt->id)

            {
                a=temp->id;
                temp->id=cpt->id;
                cpt->id=a;

                strcpy(n,temp->name );
                strcpy(temp->name,cpt->name);
                strcpy(cpt->name,n);


                strcpy(p, temp->phone);
                strcpy(temp->phone, cpt->phone);
                strcpy(cpt->phone, p);


                b=temp->salary;
                temp->salary=cpt->salary;
                cpt->salary=b;

                strcpy(d, temp->date);
                strcpy(temp->date, cpt->date);
                strcpy(cpt->date, d);

                strcpy(bd, temp->BDG);
                strcpy(temp->BDG, cpt->BDG);
                strcpy(cpt->BDG, bd);

            }
            cpt=cpt->next;
        }
        temp=temp->next;
    }
    display();
}

int main()
{
    system("color 70");
    head = NULL;
    int option,p, choice;
    char name[100];
    char phone[100];
    char date[100];
    char BDG[100];
    int id;
    float salary;
    printf("\t\t\t\t\t\t\t\t----------------------------");
    printf("\n\t\t\t\t\t\t\t\tEmployee Management System");
    printf("\n\t\t\t\t\t\t\t\t----------------------------");


    do
    {

mainMenu:
        printf("\n\n\t\t\t\t\t\t\t\t 1.Employee's information");
        printf("\n\t\t\t\t\t\t\t\t 2.Authority panel");
        printf("\n\t\t\t\t\t\t\t\t 3.Exit");
        printf("\n\t\t\t\t\t\t\t\t Enter your choice: ");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            system("cls");
            printf("\n\n\t\t\t\t\t\t\t\tEnter Employee's id: ");
            scanf("%d", &id);
            fflush(stdin);
            printf("\t\t\t\t\t\t\t\tEnter Employee's name: ");
            gets( name);
            printf("\t\t\t\t\t\t\t\tEnter phone number: ");
            scanf("%s", phone);
            fflush(stdin);
            printf("\t\t\t\t\t\t\t\tEnter Salary: ");
            scanf("%f", &salary);
            fflush(stdin);
            printf("\t\t\t\t\t\t\t\tEnter Joining Date: ");
            scanf("%s", date);
            fflush(stdin);
            printf("\t\t\t\t\t\t\t\tEnter Blood Group: ");
            scanf("%s", BDG);
            fflush(stdin);
            insert(id, name, phone, salary, date, BDG);
            break;
        case 2:
            system("cls");
            printf("\n\t\t\t\t\t\t\t\t 1 Information List of Employees");
            printf("\n\t\t\t\t\t\t\t\t 2 Search for an Employee details");
            printf("\n\t\t\t\t\t\t\t\t 3 Delete of an Employee details");
            printf("\n\t\t\t\t\t\t\t\t 4 Update of an Employee details");
            printf("\n\t\t\t\t\t\t\t\t 5 Display all Employee details");
            printf("\n\t\t\t\t\t\t\t\t 6 The total number of the employees of the company");
            printf("\n\t\t\t\t\t\t\t\t 7 Back to Main Menu");


            do
            {
                printf("\n\t\t\t\t\t\t\t\tEnter Choice: ");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    bubblesort();
                    break;

                case 2:
                    printf("\t\t\t\t\t\t\t\tEnter Employee's ID to search: ");
                    scanf("%d", &id);
                    search(id);
                    break;
                case 3:
                    printf("\t\t\t\t\t\t\t\tEnter Employee's ID to Delete: ");
                    scanf("%d", &id);
                    Delete(id);
                    break;
                case 4:
                    printf("\t\t\t\t\t\t\t\tEnter Employee's ID number to Update: ");
                    scanf("%d", &id);
                    update(id);
                    break;
                case 5:
                    display();
                    break;
                case 6:
                    printf("\t\t\t\t\t\t\t\tThe total employees of the company is %d", c);
                    break;

                case 7:
                    system("cls");
                    goto mainMenu;
                    break;
                default:
                    printf("\t\t\t\t\t\t\t\tPlease Enter Correct Option");
                }

            }
            while (choice != 0);
        case 3:
            exit(0);
            break;
        }

    }
    while (option !=0);

}




