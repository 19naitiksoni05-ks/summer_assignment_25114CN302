#include <stdio.h>
int palindrome(int n)
{
    int original = n, rev = 0, rem;
    while (n != 0)
    {
        rem = n % 10;                   // Get the last digit
        rev = rev * 10 + rem;           // Build the reversed number
        n /= 10;                        // Remove the last digit
    }
    return original == rev;             // Check if original and reversed are the same
}
int main()
{
    printf("Checking if a number is a palindrome:\n");
    int num;
    scanf("%d", &num);
    if (num < 0)
        printf("Negative numbers are not considered palindromes.\n");
    else
    {
        if (palindrome(num))
            printf("%d is a palindrome.\n", num);
        else
            printf("%d is not a palindrome.\n", num);
    }
    return 0;
}