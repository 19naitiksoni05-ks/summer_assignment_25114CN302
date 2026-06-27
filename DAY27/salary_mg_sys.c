#include <stdio.h>

struct Employee
{
    int empId;
    char name[50];
    float basicSalary;
    float hra;
    float da;
    float grossSalary;
};

int main()
{
    struct Employee e[100];
    int n, i, choice, search, found = 0;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    do
    {
        printf("\n===== SALARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Employee Details\n");
        printf("2. Display Salary Details\n");
        printf("3. Search Employee by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            for (i = 0; i < n; i++)
            {
                printf("\nEmployee %d\n", i + 1);

                printf("Enter Employee ID: ");
                scanf("%d", &e[i].empId);

                printf("Enter Employee Name: ");
                scanf("%s", e[i].name);

                printf("Enter Basic Salary: ");
                scanf("%f", &e[i].basicSalary);

                e[i].hra = 0.20 * e[i].basicSalary; 
                e[i].da = 0.10 * e[i].basicSalary;  
                e[i].grossSalary = e[i].basicSalary + e[i].hra + e[i].da;
            }

            printf("\nEmployee Details Added Successfully!\n");
            break;

        case 2:
            printf("\n-------------------------------------------------------------\n");
            printf("ID\tName\tBasic\tHRA\tDA\tGross\n");
            printf("-------------------------------------------------------------\n");

            for (i = 0; i < n; i++)
            {
                printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n",
                       e[i].empId,
                       e[i].name,
                       e[i].basicSalary,
                       e[i].hra,
                       e[i].da,
                       e[i].grossSalary);
            }
            break;

        case 3:
            printf("Enter Employee ID to Search: ");
            scanf("%d", &search);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (e[i].empId == search)
                {
                    printf("\nEmployee Found\n");
                    printf("Employee ID  : %d\n", e[i].empId);
                    printf("Name         : %s\n", e[i].name);
                    printf("Basic Salary : %.2f\n", e[i].basicSalary);
                    printf("HRA          : %.2f\n", e[i].hra);
                    printf("DA           : %.2f\n", e[i].da);
                    printf("Gross Salary : %.2f\n", e[i].grossSalary);
                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Employee Record Not Found!\n");

            break;

        case 4:
            printf("Thank you for using the Salary Management System.\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while (choice != 4);

    return 0;
}