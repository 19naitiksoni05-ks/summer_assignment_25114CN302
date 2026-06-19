#include <stdio.h>
int fibonacci(int n)
{
    if (n <= 0)
        return 0; 
    else if (n == 1)
        return 1; 
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
    printf("Find the nth Fibonacci number:\n");
    int num;
    scanf("%d", &num);
    if (num < 0)
        printf("Fibonacci is not defined for negative numbers.\n");
    else
    {
        int result = fibonacci(num);
        printf("Fibonacci number at position %d is %d\n", num, result);
    }
    return 0;
}