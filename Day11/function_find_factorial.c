#include <stdio.h>
int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1; // Factorial of 0 and 1 is 1
    return n * factorial(n - 1); // Recursive call
}
int main()
{
    printf("Finding the factorial of a number:\n");
    int num;
    scanf("%d", &num);
    if (num < 0)
        printf("Factorial is not defined for negative numbers.\n");
    else
    {
        int result = factorial(num);
        printf("Factorial of %d is %d\n", num, result);
    }
    return 0;
}