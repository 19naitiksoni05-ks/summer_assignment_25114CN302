#include <stdio.h>
int main()
{
    int n, product = 1;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    while (n != 0) 
    {
        product *= n % 10; 
        n = n / 10; 
    }

    printf("The product of the digits in the integer is: %d\n", product);
    return 0;
}