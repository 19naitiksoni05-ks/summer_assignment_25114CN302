#include <stdio.h>

struct Employee
{
    int empId;
    char name[50];
    float salary;
};

int main()
{
    struct Employee e[100];
    int n, i, choice, search;
    int found = 0;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    do
    {
        printf("\n===== EMPLOYEE MANAGEMENT SYSTEM =====\n");
        printf("1. Add Employee Records\n");
        printf("2. Display All Records\n");
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

                printf("Enter Salary: ");
                scanf("%f", &e[i].salary);
            }
            printf("\nEmployee Records Added Successfully!\n");
            break;

        case 2:
            printf("\n----- Employee Records -----\n");
            printf("ID\tName\tSalary\n");

            for (i = 0; i < n; i++)
            {
                printf("%d\t%s\t%.2f\n",
                       e[i].empId,
                       e[i].name,
                       e[i].salary);
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
                    printf("Employee ID   : %d\n", e[i].empId);
                    printf("Employee Name : %s\n", e[i].name);
                    printf("Salary        : %.2f\n", e[i].salary);
                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Employee Record Not Found!\n");

            break;

        case 4:
            printf("Exiting Program...\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while (choice != 4);

    return 0;
}