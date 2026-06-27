#include <stdio.h>
#include <string.h>

struct Library {
    int bookId;
    char title[50];
    char author[50];
    int quantity;
};

int main() {
    struct Library b[100];
    int n, i, choice, search, found = 0;

    printf("Enter Number of Books: ");
    scanf("%d", &n);

    do {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book Records\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            for(i = 0; i < n; i++) {

                printf("\nBook %d\n", i + 1);

                printf("Enter Book ID: ");
                scanf("%d", &b[i].bookId);

                printf("Enter Book Title: ");
                scanf("%s", b[i].title);

                printf("Enter Author Name: ");
                scanf("%s", b[i].author);

                printf("Enter Quantity: ");
                scanf("%d", &b[i].quantity);
            }

            printf("\nBooks Added Successfully!\n");
            break;

        case 2:
            printf("\n-------------------------------------------------\n");
            printf("ID\tTitle\tAuthor\tQuantity\n");
            printf("-------------------------------------------------\n");

            for(i = 0; i < n; i++) {
                printf("%d\t%s\t%s\t%d\n",
                       b[i].bookId,
                       b[i].title,
                       b[i].author,
                       b[i].quantity);
            }
            break;

        case 3:
            printf("Enter Book ID to Search: ");
            scanf("%d", &search);

            found = 0;

            for(i = 0; i < n; i++) {

                if(b[i].bookId == search) {

                    printf("\nBook Found\n");
                    printf("Book ID : %d\n", b[i].bookId);
                    printf("Title   : %s\n", b[i].title);
                    printf("Author  : %s\n", b[i].author);
                    printf("Stock   : %d\n", b[i].quantity);

                    found = 1;
                    break;
                }
            }

            if(found == 0)
                printf("Book Not Found!\n");

            break;

        case 4:
            printf("Enter Book ID to Issue: ");
            scanf("%d", &search);

            found = 0;

            for(i = 0; i < n; i++) {

                if(b[i].bookId == search) {

                    found = 1;

                    if(b[i].quantity > 0) {
                        b[i].quantity--;
                        printf("Book Issued Successfully!\n");
                    }
                    else {
                        printf("Book Out of Stock!\n");
                    }

                    break;
                }
            }

            if(found == 0)
                printf("Book Not Found!\n");

            break;

        case 5:
            printf("Enter Book ID to Return: ");
            scanf("%d", &search);

            found = 0;

            for(i = 0; i < n; i++) {

                if(b[i].bookId == search) {

                    b[i].quantity++;
                    printf("Book Returned Successfully!\n");

                    found = 1;
                    break;
                }
            }

            if(found == 0)
                printf("Book Not Found!\n");

            break;

        case 6:
            printf("Thank You!\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}