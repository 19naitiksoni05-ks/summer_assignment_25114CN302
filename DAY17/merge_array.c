#include <stdio.h>
int main()
{
    int i, j, n1, n2, arr1[100], arr2[100], merged[200];
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
    i = 0;
    j = 0;
    int k = 0;
   
    for (i=0; i < n1; i++)
    {
        merged[i] = arr1[i];
    }
    for (j=0; j < n2; j++)
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