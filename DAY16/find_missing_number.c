#include <stdio.h>
int main()
{ 
    int i, n, arr[100], actual_sum =0, expected_sum, missing;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        actual_sum += arr[i];
    }
    expected_sum = (n * (n + 1)) / 2;
    missing = expected_sum - actual_sum;
    printf("The missing number is: %d\n", missing);
    return 0;
}