#include <stdio.h>
int main()
{
    int i, n, arr[100], count = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    for (i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr[count++] = arr[i];
        }
    }
    while (count < n)
    {
        arr[count++] = 0;
    }
    printf("The array with zeros moved to the end is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}