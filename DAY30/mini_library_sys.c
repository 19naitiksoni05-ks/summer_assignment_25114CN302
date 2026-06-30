#include <stdio.h>
#include <string.h>

struct Book
{
    int id;
    char title[50];
    char author[50];
    int quantity;
};

int main()
{
    struct Book b[100];
    int n = 0;
    int choice, i, id, found = 0, qty;

    do
    {
        printf("\n========== MINI LIBRARY SYSTEM ==========\n");
        printf("1. Add Books\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:

            printf("How many books do you want to add? ");
            scanf("%d", &qty);

            for (i = 0; i < qty; i++)
            {

                printf("\nBook %d\n", n + 1);

                printf("Enter Book ID: ");
                scanf("%d", &b[n].id);

                printf("Enter Book Title: ");
                scanf("%s", b[n].title);

                printf("Enter Author Name: ");
                scanf("%s", b[n].author);

                printf("Enter Quantity: ");
                scanf("%d", &b[n].quantity);

                n++;
            }

            printf("\nBooks Added Successfully!\n");
            break;

        case 2:

            if (n == 0)
            {
                printf("Library is Empty!\n");
            }
            else
            {

                printf("\n-----------------------------------------------\n");
                printf("ID\tTitle\tAuthor\tQuantity\n");
                printf("-----------------------------------------------\n");

                for (i = 0; i < n; i++)
                {

                    printf("%d\t%s\t%s\t%d\n",
                           b[i].id,
                           b[i].title,
                           b[i].author,
                           b[i].quantity);
                }
            }

            break;

        case 3:

            printf("Enter Book ID: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < n; i++)
            {

                if (b[i].id == id)
                {

                    printf("\nBook Found\n");
                    printf("Book ID : %d\n", b[i].id);
                    printf("Title   : %s\n", b[i].title);
                    printf("Author  : %s\n", b[i].author);
                    printf("Stock   : %d\n", b[i].quantity);

                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Book Not Found!\n");

            break;

        case 4:

            printf("Enter Book ID: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < n; i++)
            {

                if (b[i].id == id)
                {

                    found = 1;

                    if (b[i].quantity > 0)
                    {

                        b[i].quantity--;
                        printf("Book Issued Successfully!\n");
                    }
                    else
                    {

                        printf("Book Out of Stock!\n");
                    }

                    break;
                }
            }

            if (found == 0)
                printf("Book Not Found!\n");

            break;

        case 5:

            printf("Enter Book ID: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < n; i++)
            {

                if (b[i].id == id)
                {

                    b[i].quantity++;

                    printf("Book Returned Successfully!\n");

                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Book Not Found!\n");

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