#include <stdio.h>
int main()
{
    int num, sum, rem, original_num;
    printf("Enter a number: ");
    scanf("%d", &num);  
    original_num = num;
    sum = 0;

    while (num!=0)
    {
        rem = num%10;

        int fact = 1;
        for (int i = 1; i <= rem; i++)
        {
            fact *= i;
        }   
        sum += fact;
        num /= 10;
    }
    if (sum == original_num)
        printf("%d is a strong number.\n", original_num);
    else
        printf("%d is not a strong number.\n", original_num);
    return 0;
}