#include <stdio.h>
int main()
{
    int lower, upper, i, j, Prime;
    printf("Enter the lower and upper limits: ");
    scanf("%d %d", &lower, &upper);

    printf("Prime numbers between %d and %d are: ", lower, upper);
    for (i = lower; i <= upper; i++) 
    {
        if (i <= 1) 
            continue;  
        Prime = 1; 
        
        for (j = 2; j <= i / 2; j++) 
        {
            if (i % j == 0) 
            {
                Prime = 0; 
                break; 
            }
        }

        if (Prime)
            printf("%d ", i);
    }

    printf("\n");
    return 0;
}