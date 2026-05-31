#include <stdio.h>
int main()  
{
    int num, sum = 0, rem, original_num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    original_num = num;
    while (num != 0)
    {
        rem = num % 10;
        sum += rem * rem * rem;
        num /= 10;
    }
    if (sum == original_num)
    {
        printf("%d is an Armstrong number.\n", original_num);
    }
    else
    {
        printf("%d is not an Armstrong number.\n", original_num);
    }
    return 0;
}