#include <stdio.h>
int main()
{
    int num, sum, rem, original_num, lower, higher;
    printf("Enter the lower and upper limits: ");
    scanf("%d %d", &lower, &higher);
    printf("Armstrong numbers between %d and %d are: ", lower, higher);
    for(num = lower; num <= higher; num++)
    {
        sum = 0;
        original_num = num;

        int temp = num;
        while (temp != 0)
        {
            rem = temp % 10;
            sum += rem * rem * rem;
            temp /= 10;
        }
        if (sum == original_num)
        {
            printf("%d ", original_num);
        }
    }
    return 0;
}