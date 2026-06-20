#include <stdio.h>
int main()
{
    int i, j, n1, n2, arr1[100], arr2[100], union_arr[200];
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);
    printf("Enter the elements of the first array: ");
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);
    printf("Enter the elements of the second array: ");
    for (j = 0; j < n2; j++)
    {
        scanf("%d", &arr2[j]);
    }

    int k = 0;
    for (i = 0; i < n1; i++)
    {
        union_arr[k++] = arr1[i];
    }
    for (j = 0; j < n2; j++)
    {
        int found = 0;
        for (i = 0; i < n1; i++)
        {
            if (arr2[j] == arr1[i])
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            union_arr[k++] = arr2[j];
        }
    }
    printf("The union of the two arrays is: ");
    for (i = 0; i < k; i++)
    {
        printf("%d ", union_arr[i]);
    }
    return 0;
}