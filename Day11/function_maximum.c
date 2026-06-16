#include <stdio.h>
int maximum(int a, int b)
{
    return (a > b) ? a : b;
}   
int main()
{
    printf("Finding the maximum of two numbers:\n");
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    int result = maximum(num1, num2);
    printf("Maximum: %d\n", result);
    return 0;
}