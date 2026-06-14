#include <stdio.h>
int fibonacci(int n)
{
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Fibonacci is not defined for negative numbers.\n");
    }
    else
    {
        int result = fibonacci(n);
        printf("Fibonacci of %d = %d\n", n, result);
    }

    return 0;
}