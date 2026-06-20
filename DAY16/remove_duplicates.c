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
        int j;
        for (j = 0; j < count; j++)
        {
            if (arr[i] == arr[j])
            {
                break;
            }
        }
        if (j == count)
        {
            arr[count++] = arr[i];
        }
    }
    printf("Array after removing duplicates: ");
    for (i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}