#include <stdio.h>
#include <string.h>

struct Employee
{
    int empId;
    char name[50];
    char department[30];
    float salary;
};

int main()
{
    struct Employee emp[100];
    int n = 0;
    int choice, i, id, found = 0, count;

    do
    {
        printf("\n========== EMPLOYEE MANAGEMENT SYSTEM ==========\n");
        printf("1. Add Employees\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Salary\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:

            printf("How many employees do you want to add? ");
            scanf("%d", &count);

            for (i = 0; i < count; i++)
            {

                printf("\nEmployee %d\n", n + 1);

                printf("Enter Employee ID: ");
                scanf("%d", &emp[n].empId);

                printf("Enter Employee Name: ");
                scanf("%s", emp[n].name);

                printf("Enter Department: ");
                scanf("%s", emp[n].department);

                printf("Enter Salary: ");
                scanf("%f", &emp[n].salary);

                n++;
            }

            printf("\nEmployee Records Added Successfully!\n");
            break;

        case 2:

            if (n == 0)
            {
                printf("No Employee Records Found!\n");
            }
            else
            {

                printf("\n------------------------------------------------------------\n");
                printf("ID\tName\tDepartment\tSalary\n");
                printf("------------------------------------------------------------\n");

                for (i = 0; i < n; i++)
                {

                    printf("%d\t%s\t%s\t\t%.2f\n",
                           emp[i].empId,
                           emp[i].name,
                           emp[i].department,
                           emp[i].salary);
                }
            }

            break;

        case 3:

            printf("Enter Employee ID: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < n; i++)
            {

                if (emp[i].empId == id)
                {

                    printf("\nEmployee Found\n");
                    printf("Employee ID : %d\n", emp[i].empId);
                    printf("Name        : %s\n", emp[i].name);
                    printf("Department  : %s\n", emp[i].department);
                    printf("Salary      : %.2f\n", emp[i].salary);

                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Employee Not Found!\n");

            break;

        case 4:

            printf("Enter Employee ID: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < n; i++)
            {

                if (emp[i].empId == id)
                {

                    printf("Enter New Salary: ");
                    scanf("%f", &emp[i].salary);

                    printf("Salary Updated Successfully!\n");

                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Employee Not Found!\n");

            break;

        case 5:

            printf("Enter Employee ID: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < n; i++)
            {

                if (emp[i].empId == id)
                {

                    int j;

                    for (j = i; j < n - 1; j++)
                    {
                        emp[j] = emp[j + 1];
                    }

                    n--;

                    printf("Employee Deleted Successfully!\n");

                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Employee Not Found!\n");

            break;

        case 6:

            printf("Thank You!\n");
            break;

        default:

            printf("Invalid Choice!\n");
        }

    } while (choice != 6);

    return 0;
}