#include <stdio.h>
int sum(int a, int b)
{
    return a + b;
}

int main()
{
    printf("Calculating the sum of two numbers:\n");
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    int result = sum(num1, num2);
    printf("Sum: %d\n", result);
    return 0;
}