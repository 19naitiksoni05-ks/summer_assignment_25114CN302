#include <stdio.h>
#include <math.h>
int main()
{
    int num1, num2, n;
    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);
    n = (num1 > num2) ? num1 : num2;
    while(1)
    {
        if(n % num1 == 0 && n % num2 == 0)
        {
            printf("LCM of %d and %d is %d", num1, num2, n);
            break;
        }
        n++;
    }
}