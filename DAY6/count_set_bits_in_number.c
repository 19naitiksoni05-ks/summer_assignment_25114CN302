#include <stdio.h>
int main()
{
    int count_set = 0, num;
    printf("Enter a number: ");
    scanf("%d", &num);

    while (num > 0)
    {
        if (num & 1)
        {
            count_set++;
        }
        num >>= 1;
    }
    printf("Number of set bits: %d", count_set);
    return 0;
}