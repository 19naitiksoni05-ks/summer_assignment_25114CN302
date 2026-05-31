#include <stdio.h>
int main()
{
    int n, term1 = 0, term2 = 1, next_term;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
   
    printf("%d %d", term1, term2);
    for(int i = 2; i < n; i++)
    {
        next_term = term1 + term2;
        term1 = term2;
        term2 = next_term;
        printf(" %d", next_term);
    }
    return 0;
}