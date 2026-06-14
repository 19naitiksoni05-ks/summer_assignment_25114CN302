#include <stdio.h>
int sumOfDigits(int n)
{
    if (n == 0)
        return 0;
    else
        return (n % 10) + sumOfDigits(n / 10);
}   
int main()
{
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Sum of digits is not defined for negative numbers.\n");
    }
    else
    {
        int result = sumOfDigits(n);
        printf("Sum of digits of %d = %d\n", n, result);
    }

    return 0;
}