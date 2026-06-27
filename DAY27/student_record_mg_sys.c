#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    float marks;
};

int main()
{
    struct Student s[100];
    int n, i, choice, search;
    int found = 0;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    do
    {
        printf("\n===== STUDENT RECORD MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student Records\n");
        printf("2. Display All Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            for (i = 0; i < n; i++)
            {
                printf("\nStudent %d\n", i + 1);

                printf("Enter Roll Number: ");
                scanf("%d", &s[i].roll);

                printf("Enter Name: ");
                scanf("%s", s[i].name);

                printf("Enter Marks: ");
                scanf("%f", &s[i].marks);
            }
            printf("\nRecords Added Successfully!\n");
            break;

        case 2:
            printf("\n----- Student Records -----\n");
            printf("Roll\tName\tMarks\n");

            for (i = 0; i < n; i++)
            {
                printf("%d\t%s\t%.2f\n",
                       s[i].roll,
                       s[i].name,
                       s[i].marks);
            }
            break;

        case 3:
            printf("Enter Roll Number to Search: ");
            scanf("%d", &search);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (s[i].roll == search)
                {
                    printf("\nStudent Found\n");
                    printf("Roll Number : %d\n", s[i].roll);
                    printf("Name        : %s\n", s[i].name);
                    printf("Marks       : %.2f\n", s[i].marks);
                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Student Record Not Found!\n");

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