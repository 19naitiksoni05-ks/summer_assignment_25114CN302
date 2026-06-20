#include <stdio.h>
int main()
{
    int i, n, d, arr[100];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the number of positions to rotate right: ");
    scanf("%d", &d);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < d; i++)
    {
        int temp = arr[n - 1];
        for (int j = n - 1; j > 0; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
    printf("The rotated array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}