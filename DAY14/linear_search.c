#include <stdio.h>
int main()
{
    int i=1, n, arr[100], search_element, found = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);   

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search for: ");
    scanf("%d", &search_element);
    for (i = 0; i < n; i++)
    {
        if (arr[i] == search_element)
        {
            found = 1;
            break; 
        }
    }
   
    if (found)
    {
        printf("Element %d found at position %d.\n", search_element, i);
    }
    else
    {
        printf("Element %d not found in the array.\n", search_element);
    }
    return 0;
}