#include <stdio.h>
int main ()
{
    int i, n, arr[100], max, min;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
   
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    max = min = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    printf("The largest element in the array is: %d\n", max);
    printf("The smallest element in the array is: %d\n", min);
    return 0;
}