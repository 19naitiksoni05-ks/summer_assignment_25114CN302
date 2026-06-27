#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100], str2[100], temp[100];
    int choice, i;

    do
    {
        printf("\n===== STRING OPERATION SYSTEM =====\n");
        printf("1. Enter String\n");
        printf("2. Display String\n");
        printf("3. Find Length\n");
        printf("4. Copy String\n");
        printf("5. Concatenate Strings\n");
        printf("6. Compare Strings\n");
        printf("7. Reverse String\n");
        printf("8. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("Enter First String: ");
            scanf("%s", str1);

            printf("Enter Second String: ");
            scanf("%s", str2);

            break;

        case 2:
            printf("First String  : %s\n", str1);
            printf("Second String : %s\n", str2);
            break;

        case 3:
            printf("Length of First String = %lu\n", strlen(str1));
            printf("Length of Second String = %lu\n", strlen(str2));
            break;

        case 4:
            strcpy(temp, str1);
            printf("Copied String = %s\n", temp);
            break;

        case 5:
            strcpy(temp, str1);
            strcat(temp, str2);
            printf("Concatenated String = %s\n", temp);
            break;

        case 6:
            if (strcmp(str1, str2) == 0)
                printf("Both Strings are Equal.\n");
            else
                printf("Strings are Not Equal.\n");
            break;

        case 7:
            strcpy(temp, str1);

            for (i = 0; i < strlen(temp) / 2; i++)
            {
                char ch = temp[i];
                temp[i] = temp[strlen(temp) - 1 - i];
                temp[strlen(temp) - 1 - i] = ch;
            }

            printf("Reversed String = %s\n", temp);
            break;

        case 8:
            printf("Exiting Program...\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while (choice != 8);

    return 0;
}