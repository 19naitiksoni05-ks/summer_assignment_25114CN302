#include <stdio.h>
int main()
{
    int n1, n2, arr1[100], arr2[100];

    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);

    printf("Enter sorted elements for the first array: ", n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);

    printf("Enter sorted elements for the second array: ", n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    int i = 0, j = 0,  k = 0;
    int merged[200];

    for (i = 0; i < n1; i++)
    {
        merged[i] = arr1[i];
    }
    for (j = 0; j < n2; j++)
    {
        merged[n1 + j] = arr2[j];
    }
    printf("The merged array is: ");
    for (i = 0; i < n1 + n2; i++)
    {
        printf("%d ", merged[i]);
    }
    return 0;
}