#include <stdio.h>
int main()
{
    int i, n, arr[100];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("The reversed array is: ");
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}