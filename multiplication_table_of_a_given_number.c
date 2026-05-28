#include <stdio.h>
int main() 
{
    int n, i, result;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    printf("Multiplication table of %d:\n", n);
    for (i = 1; i <= 10; i++) 
    {
        result = n * i;
        printf("%d x %d = %d\n", n, i, result);
    }

    return 0;
}