#include <stdio.h>
int main()
{
    int i = 0, n, arr[100] = {0}, j, duplicate_found;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Duplicate elements in the array are: ");
    for (i = 0; i < n; i++)
    {
        duplicate_found = 0;
        for (j = i+1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                duplicate_found = 1;
                break;
            }
        }
        if (duplicate_found)
        {
            printf("%d ", arr[i]);
        }
    }
    
    return 0;
}