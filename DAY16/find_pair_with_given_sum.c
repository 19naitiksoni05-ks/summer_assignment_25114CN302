#include <stdio.h>
int main()
{
    int i, n, arr[100], sum;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the sum to find pairs: ");
    scanf("%d", &sum);
    printf("Pairs with the given sum are: ");
    for (i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                printf("(%d, %d) ", arr[i], arr[j]);
            }
        }
    }
    return 0;
}