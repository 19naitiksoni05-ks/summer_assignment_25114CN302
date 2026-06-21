#include <stdio.h>
int main()
{
    int i, n, arr1[100], arr2[100], diff[100];
    printf("Enter the number of elements in the matrices: ");
    scanf("%d", &n);
    printf("Enter the elements of the first matrix: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the elements of the second matrix: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }
    for (i = 0; i < n; i++)
    {
        diff[i] = arr1[i] - arr2[i];
    }
    printf("The difference of the matrices is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", diff[i]);
    }
    return 0;
}