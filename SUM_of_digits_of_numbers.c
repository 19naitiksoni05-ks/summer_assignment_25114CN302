#include <stdio.h>
int main()
{
    int n, sum = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    while (n != 0) 
    {
        sum += n % 10; 
        n = n / 10; 
    }

    printf("The sum of the digits in the integer is: %d\n", sum);
    return 0;
}