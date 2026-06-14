#include <stdio.h>
int reverse(int n, int rev)
{
    if (n == 0)
        return rev;
    else
        return reverse (n / 10, rev * 10 + n % 10);
}   
int main()
{
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Reverse is not defined for negative numbers.\n");
    }
    else
    {
        int result = reverse(n, 0);
        printf("Reverse of %d = %d\n", n, result);
    }

    return 0;
}