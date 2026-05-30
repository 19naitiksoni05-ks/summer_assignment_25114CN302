#include <stdio.h>
int main()
{
    int n, original, reverse = 0, digit;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    original = n; 

    while (n != 0) 
    {
        digit = n % 10; 
        reverse = reverse * 10 + digit; 
        n = n / 10; 
    }

    if (original == reverse) 
        printf("%d is a palindrome.\n", original);
    else
        printf("%d is not a palindrome.\n", original);

    return 0;
}