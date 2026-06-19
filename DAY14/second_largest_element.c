#include <stdio.h>
int main()
{
    int i, n, arr[100], largest, second_largest;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");   
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    if (n < 2)
    {
        printf("At least two elements are required to find the second largest.\n");
        return 1;
    }
    else 
    {
        largest = second_largest = arr[0];
        for (i = 1; i < n; i++)
        {
            if (arr[i] > largest)
            {
                second_largest = largest;
                largest = arr[i];
            }
            else if (arr[i] > second_largest && arr[i] != largest)
            {
                second_largest = arr[i];
            }
            else 
            {
                continue; // Skip duplicates of the largest element
            }
        }
            printf("The second largest element in the array is: %d\n", second_largest);
    }
    return 0;
}