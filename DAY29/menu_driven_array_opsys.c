#include <stdio.h>

int main()
{
    int arr[100], n = 0, i, choice;
    int search, found = 0;
    int max, min;
    int sum = 0, temp, j;
    float avg;

    do
    {
        printf("\n===== ARRAY OPERATION SYSTEM =====\n");
        printf("1. Enter Array Elements\n");
        printf("2. Display Array\n");
        printf("3. Search Element\n");
        printf("4. Find Largest Element\n");
        printf("5. Find Smallest Element\n");
        printf("6. Find Sum of Elements\n");
        printf("7. Find Average\n");
        printf("8. Sort Array (Ascending)\n");
        printf("9. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("Enter Number of Elements: ");
            scanf("%d", &n);

            printf("Enter %d Elements:\n", n);

            for (i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }

            printf("Array Stored Successfully!\n");
            break;

        case 2:
            if (n == 0)
                printf("Array is Empty!\n");
            else
            {
                printf("Array Elements: ");
                for (i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
            }
            break;

        case 3:
            printf("Enter Element to Search: ");
            scanf("%d", &search);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (arr[i] == search)
                {
                    printf("Element Found at Position %d\n", i + 1);
                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Element Not Found!\n");

            break;

        case 4:
            max = arr[0];

            for (i = 1; i < n; i++)
            {
                if (arr[i] > max)
                    max = arr[i];
            }

            printf("Largest Element = %d\n", max);
            break;

        case 5:
            min = arr[0];

            for (i = 1; i < n; i++)
            {
                if (arr[i] < min)
                    min = arr[i];
            }

            printf("Smallest Element = %d\n", min);
            break;

        case 6:
            sum = 0;

            for (i = 0; i < n; i++)
                sum += arr[i];

            printf("Sum = %d\n", sum);
            break;

        case 7:
            sum = 0;

            for (i = 0; i < n; i++)
                sum += arr[i];

            avg = (float)sum / n;

            printf("Average = %.2f\n", avg);
            break;

        case 8:
            for (i = 0; i < n - 1; i++)
            {
                for (j = i + 1; j < n; j++)
                {
                    if (arr[i] > arr[j])
                    {
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }

            printf("Array Sorted Successfully!\n");
            break;

        case 9:
            printf("Exiting Program...\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while (choice != 9);

    return 0;
}