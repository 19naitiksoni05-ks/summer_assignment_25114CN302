#include <stdio.h>
int main()
{
    int num, sum, rem, original_num;
    printf("Enter a number: ");
    scanf("%d", &num);
    original_num = num;
    sum = 0;    
    
    for (int i = 1; i <= num / 2; i++)
    {
        if (num % i == 0)
            sum += i;
        
    }
    if (sum == original_num)
        printf("%d is a perfect number.\n", original_num);
    else
        printf("%d is not a perfect number.\n", original_num);
    return 0;
}