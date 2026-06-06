#include <stdio.h>
int main()
{ 
    int num, binary=0, i=1, rem;
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    while (num > 0)
    {
        rem = num % 2;
        binary = binary + (rem * i);
        num /= 2;
        i *= 10;
    }
    printf("Binary representation: %d", binary);
    return 0;
}