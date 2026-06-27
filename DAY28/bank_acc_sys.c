#include <stdio.h>
#include <string.h>

struct Bank
{
    int accNo;
    char name[50];
    float balance;
};

int main()
{
    struct Bank b[100];
    int n, i, choice, search, found = 0;
    float amount;

    printf("Enter Number of Customers: ");
    scanf("%d", &n);

    do
    {
        printf("\n===== BANK ACCOUNT MANAGEMENT SYSTEM =====\n");
        printf("1. Create Accounts\n");
        printf("2. Display All Accounts\n");
        printf("3. Search Account\n");
        printf("4. Deposit Money\n");
        printf("5. Withdraw Money\n");
        printf("6. Check Balance\n");
        printf("7. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            for (i = 0; i < n; i++)
            {

                printf("\nCustomer %d\n", i + 1);

                printf("Enter Account Number: ");
                scanf("%d", &b[i].accNo);

                printf("Enter Customer Name: ");
                scanf("%s", b[i].name);

                printf("Enter Initial Balance: ");
                scanf("%f", &b[i].balance);
            }

            printf("\nAccounts Created Successfully!\n");
            break;

        case 2:
            printf("\n-------------------------------------------\n");
            printf("Acc No\tName\tBalance\n");
            printf("-------------------------------------------\n");

            for (i = 0; i < n; i++)
            {
                printf("%d\t%s\t%.2f\n",
                       b[i].accNo,
                       b[i].name,
                       b[i].balance);
            }
            break;

        case 3:
            printf("Enter Account Number to Search: ");
            scanf("%d", &search);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (b[i].accNo == search)
                {
                    printf("\nAccount Found\n");
                    printf("Account Number : %d\n", b[i].accNo);
                    printf("Customer Name  : %s\n", b[i].name);
                    printf("Balance        : %.2f\n", b[i].balance);
                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Account Not Found!\n");

            break;

        case 4:
            printf("Enter Account Number: ");
            scanf("%d", &search);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (b[i].accNo == search)
                {
                    printf("Enter Deposit Amount: ");
                    scanf("%f", &amount);

                    if (amount > 0)
                    {
                        b[i].balance += amount;
                        printf("Deposit Successful!\n");
                        printf("Updated Balance: %.2f\n", b[i].balance);
                    }
                    else
                    {
                        printf("Invalid Amount!\n");
                    }

                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Account Not Found!\n");

            break;

        case 5:
            printf("Enter Account Number: ");
            scanf("%d", &search);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (b[i].accNo == search)
                {

                    printf("Enter Withdrawal Amount: ");
                    scanf("%f", &amount);

                    if (amount <= 0)
                        printf("Invalid Amount!\n");
                    else if (amount > b[i].balance)
                        printf("Insufficient Balance!\n");
                    else
                    {
                        b[i].balance -= amount;
                        printf("Withdrawal Successful!\n");
                        printf("Remaining Balance: %.2f\n", b[i].balance);
                    }

                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Account Not Found!\n");

            break;

        case 6:
            printf("Enter Account Number: ");
            scanf("%d", &search);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (b[i].accNo == search)
                {
                    printf("Current Balance: %.2f\n", b[i].balance);
                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Account Not Found!\n");

            break;

        case 7:
            printf("Thank You for Using the Banking System!\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while (choice != 7);

    return 0;
}