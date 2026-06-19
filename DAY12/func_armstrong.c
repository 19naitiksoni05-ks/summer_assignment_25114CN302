#include <stdio.h>
int armstrong(int n)
{
    int original = n, sum = 0, rem;
    while (n != 0)
    {
        rem = n % 10;                  
        sum += rem * rem * rem;       
        n /= 10;                        
    }
    return original == sum;          
}
int main()
{
    printf("Checking if a number is an Armstrong number:\n");
    int num;
    scanf("%d", &num);
    if (num < 0)
        printf("Negative numbers are not Armstrong numbers.\n");
    else
    {
        if (armstrong(num))
            printf("%d is an Armstrong number.\n", num);
        else
            printf("%d is not an Armstrong number.\n", num);
    }
    return 0;
}