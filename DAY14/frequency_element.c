#include <stdio.h>
int main()
{
    int i, n, arr[100], frequency=0, search_element;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to find its frequency: ");
    scanf("%d", &search_element);   
    for (i = 0; i < n; i++)
    {
        if (arr[i] == search_element)
        {
            frequency++;
        }
    }
    printf("Frequency of %d is %d.\n", search_element, frequency);
    return 0;
}