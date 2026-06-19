#include <stdio.h>
int main()
{
    int i, n, arr[100], even_count = 0, odd_count = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            even_count++;
        }
        else
        {
            odd_count++;
        }
    }
    printf("The even elements in the array are: %d\n", even_count);
    printf("The odd elements in the array are: %d\n", odd_count);
    return 0;
}
  