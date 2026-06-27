#include <stdio.h>
#include <string.h>

struct Product
{
    int productId;
    char name[50];
    int quantity;
    float price;
};

int main()
{
    struct Product p[100];
    int n, i, choice, search, found = 0, sold, j;

    printf("Enter Number of Products: ");
    scanf("%d", &n);

    do
    {
        printf("\n========= INVENTORY MANAGEMENT SYSTEM =========\n");
        printf("1. Add Products\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Stock\n");
        printf("5. Sell Product\n");
        printf("6. Delete Product\n");
        printf("7. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            for (i = 0; i < n; i++)
            {

                printf("\nProduct %d\n", i + 1);

                printf("Enter Product ID: ");
                scanf("%d", &p[i].productId);

                printf("Enter Product Name: ");
                scanf("%s", p[i].name);

                printf("Enter Quantity: ");
                scanf("%d", &p[i].quantity);

                printf("Enter Price: ");
                scanf("%f", &p[i].price);
            }

            printf("\nProducts Added Successfully!\n");
            break;

        case 2:
            printf("\n----------------------------------------------------------\n");
            printf("ID\tName\tQuantity\tPrice\n");
            printf("----------------------------------------------------------\n");

            for (i = 0; i < n; i++)
            {
                printf("%d\t%s\t%d\t\t%.2f\n",
                       p[i].productId,
                       p[i].name,
                       p[i].quantity,
                       p[i].price);
            }
            break;

        case 3:
            printf("Enter Product ID: ");
            scanf("%d", &search);

            found = 0;

            for (i = 0; i < n; i++)
            {

                if (p[i].productId == search)
                {

                    printf("\nProduct Found\n");
                    printf("Product ID : %d\n", p[i].productId);
                    printf("Name       : %s\n", p[i].name);
                    printf("Quantity   : %d\n", p[i].quantity);
                    printf("Price      : %.2f\n", p[i].price);

                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Product Not Found!\n");

            break;

        case 4:
            printf("Enter Product ID: ");
            scanf("%d", &search);

            found = 0;

            for (i = 0; i < n; i++)
            {

                if (p[i].productId == search)
                {

                    int add;

                    printf("Enter Quantity to Add: ");
                    scanf("%d", &add);

                    if (add > 0)
                    {
                        p[i].quantity += add;
                        printf("Stock Updated Successfully!\n");
                    }
                    else
                    {
                        printf("Invalid Quantity!\n");
                    }

                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Product Not Found!\n");

            break;

        case 5:
            printf("Enter Product ID: ");
            scanf("%d", &search);

            found = 0;

            for (i = 0; i < n; i++)
            {

                if (p[i].productId == search)
                {

                    printf("Enter Quantity to Sell: ");
                    scanf("%d", &sold);

                    if (sold <= 0)
                        printf("Invalid Quantity!\n");
                    else if (sold > p[i].quantity)
                        printf("Insufficient Stock!\n");
                    else
                    {
                        p[i].quantity -= sold;
                        printf("Sale Successful!\n");
                        printf("Bill Amount = %.2f\n", sold * p[i].price);
                    }

                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Product Not Found!\n");

            break;

        case 6:
            printf("Enter Product ID to Delete: ");
            scanf("%d", &search);

            found = 0;

            for (i = 0; i < n; i++)
            {

                if (p[i].productId == search)
                {

                    for (j = i; j < n - 1; j++)
                    {
                        p[j] = p[j + 1];
                    }

                    n--;

                    printf("Product Deleted Successfully!\n");

                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Product Not Found!\n");

            break;

        case 7:
            printf("Thank You!\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while (choice != 7);

    return 0;
}