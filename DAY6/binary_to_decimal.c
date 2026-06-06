#include <stdio.h>
int main()
{
    int binary, decimal=0, i=0, rem;
    printf("Enter a binary number: ");      
    scanf("%d", &binary);

    if (binary == 0)
    {
        printf("Decimal representation: 0");
    }
    else
    {
        while (binary > 0)
        {
            rem = binary % 10;    // Get the last digit 101%10=1
            decimal = decimal + (rem * (1 << i)); // Multiply the digit by the appropriate power of 2
            binary /= 10;     // Remove the last digit 101/10=10
            i++;
        }
        printf("Decimal representation: %d", decimal);
    }
    return 0;
}