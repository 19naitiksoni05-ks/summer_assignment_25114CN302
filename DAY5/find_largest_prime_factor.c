#include <stdio.h>
int main()
{
    int num, i;
    printf("Enter a number: ");
    scanf("%d", &num);  
    printf("Largest prime factor of %d is: ", num);
    for (i = 2; i <= num; i++)
    {
        while (num % i == 0)
        {
            num /= i;
        }
    }
     int lpf = i-1;
        printf("%d ", lpf);
    return 0;
}