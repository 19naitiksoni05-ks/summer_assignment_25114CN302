#include <stdio.h>
int main()
{
    int i, n, arr[100], max_freq = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > max_freq)
        {
            max_freq = count;
        }
    }
    printf("The maximum frequency is: %d\n", max_freq);
    return 0;
}