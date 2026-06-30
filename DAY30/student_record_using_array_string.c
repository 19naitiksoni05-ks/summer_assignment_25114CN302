#include <stdio.h>
#include <string.h>

int main()
{
    int roll[100];
    char name[100][50];
    float marks[100];

    int n = 0, choice, i, search, found = 0, j;

    do
    {
        printf("\n===== STUDENT RECORD SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Marks\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:

            printf("How Many Students to Add: ");
            scanf("%d", &j);

            for (i = 0; i < j; i++)
            {

                printf("\nStudent %d\n", n + 1);

                printf("Enter Roll Number: ");
                scanf("%d", &roll[n]);

                printf("Enter Name: ");
                scanf("%s", name[n]);

                printf("Enter Marks: ");
                scanf("%f", &marks[n]);

                n++;
            }

            printf("Students Added Successfully!\n");
            break;

        case 2:

            if (n == 0)
            {
                printf("No Records Found!\n");
            }
            else
            {

                printf("\n-------------------------------------\n");
                printf("Roll\tName\tMarks\n");
                printf("-------------------------------------\n");

                for (i = 0; i < n; i++)
                {
                    printf("%d\t%s\t%.2f\n",
                           roll[i],
                           name[i],
                           marks[i]);
                }
            }

            break;

        case 3:

            printf("Enter Roll Number: ");
            scanf("%d", &search);

            found = 0;

            for (i = 0; i < n; i++)
            {

                if (roll[i] == search)
                {

                    printf("\nStudent Found\n");
                    printf("Roll Number : %d\n", roll[i]);
                    printf("Name        : %s\n", name[i]);
                    printf("Marks       : %.2f\n", marks[i]);

                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Student Not Found!\n");

            break;

        case 4:

            printf("Enter Roll Number: ");
            scanf("%d", &search);

            found = 0;

            for (i = 0; i < n; i++)
            {

                if (roll[i] == search)
                {

                    printf("Enter New Marks: ");
                    scanf("%f", &marks[i]);

                    printf("Marks Updated Successfully!\n");

                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Student Not Found!\n");

            break;

        case 5:

            printf("Enter Roll Number to Delete: ");
            scanf("%d", &search);

            found = 0;

            for (i = 0; i < n; i++)
            {

                if (roll[i] == search)
                {

                    for (j = i; j < n - 1; j++)
                    {

                        roll[j] = roll[j + 1];
                        strcpy(name[j], name[j + 1]);
                        marks[j] = marks[j + 1];
                    }

                    n--;

                    printf("Student Record Deleted Successfully!\n");

                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Student Not Found!\n");

            break;

        case 6:

            printf("Exiting Program...\n");
            break;

        default:

            printf("Invalid Choice!\n");
        }

    } while (choice != 6);

    return 0;
}