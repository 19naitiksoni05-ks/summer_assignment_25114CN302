#include <stdio.h>

int main()
{
    int choice;
    float balance = 10000.0, amount;

    do
    {
        printf("\n===== ATM MENU =====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Current Balance: Rs. %.2f\n", balance);
            break;

        case 2:
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);

            if (amount > 0)
            {
                balance += amount;
                printf("Deposit Successful!\n");
                printf("Updated Balance: Rs. %.2f\n", balance);
            }
            else
            {
                printf("Invalid amount!\n");
            }
            break;

        case 3:
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if (amount <= 0)
            {
                printf("Invalid amount!\n");
            }
            else if (amount > balance)
            {
                printf("Insufficient Balance!\n");
            }
            else
            {
                balance -= amount;
                printf("Withdrawal Successful!\n");
                printf("Remaining Balance: Rs. %.2f\n", balance);
            }
            break;

        case 4:
            printf("Thank you for using the ATM!\n");
            break;

        default:
            printf("Invalid Choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}