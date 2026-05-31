#include <stdio.h>
int main()
{
    int n, term1 = 0, term2 = 1, next_term;
    printf("Enter the term number: ");
    scanf("%d", &n);
    if (n==1)
    {
        printf("The %dth term of the Fibonacci series is: %d", n, term1);
    }
    else if (n==2)
    {
        printf("The %dth term of the Fibonacci series is: %d", n, term2);
    }
    else
    {
        for(int i = 3; i <= n; i++)
        {
            next_term = term1 + term2;
            term1 = term2;
            term2 = next_term;
        }
            printf("The %dth term of the Fibonacci series is: %d", n, next_term);
    }
    return 0;
}