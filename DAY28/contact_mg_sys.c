#include <stdio.h>
#include <string.h>

struct Contact
{
    int id;
    char name[50];
    char phone[15];
    char email[50];
};

int main()
{
    struct Contact c[100];
    int n, i, choice, search, found = 0;

    printf("Enter Number of Contacts: ");
    scanf("%d", &n);

    do
    {
        printf("\n====== CONTACT MANAGEMENT SYSTEM ======\n");
        printf("1. Add Contacts\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            for (i = 0; i < n; i++)
            {

                printf("\nContact %d\n", i + 1);

                printf("Enter Contact ID: ");
                scanf("%d", &c[i].id);

                printf("Enter Name: ");
                scanf("%s", c[i].name);

                printf("Enter Phone Number: ");
                scanf("%s", c[i].phone);

                printf("Enter Email: ");
                scanf("%s", c[i].email);
            }

            printf("\nContacts Added Successfully!\n");
            break;

        case 2:
            printf("\n---------------------------------------------------------\n");
            printf("ID\tName\tPhone\t\tEmail\n");
            printf("---------------------------------------------------------\n");

            for (i = 0; i < n; i++)
            {
                printf("%d\t%s\t%s\t%s\n",
                       c[i].id,
                       c[i].name,
                       c[i].phone,
                       c[i].email);
            }
            break;

        case 3:
            printf("Enter Contact ID: ");
            scanf("%d", &search);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (c[i].id == search)
                {

                    printf("\nContact Found\n");
                    printf("ID     : %d\n", c[i].id);
                    printf("Name   : %s\n", c[i].name);
                    printf("Phone  : %s\n", c[i].phone);
                    printf("Email  : %s\n", c[i].email);

                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Contact Not Found!\n");

            break;

        case 4:
            printf("Enter Contact ID to Update: ");
            scanf("%d", &search);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (c[i].id == search)
                {

                    printf("Enter New Name: ");
                    scanf("%s", c[i].name);

                    printf("Enter New Phone Number: ");
                    scanf("%s", c[i].phone);

                    printf("Enter New Email: ");
                    scanf("%s", c[i].email);

                    printf("Contact Updated Successfully!\n");

                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Contact Not Found!\n");

            break;

        case 5:
            printf("Enter Contact ID to Delete: ");
            scanf("%d", &search);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (c[i].id == search)
                {

                    int j;

                    for (j = i; j < n - 1; j++)
                    {
                        c[j] = c[j + 1];
                    }

                    n--;

                    printf("Contact Deleted Successfully!\n");

                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Contact Not Found!\n");

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