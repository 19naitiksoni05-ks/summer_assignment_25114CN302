#include <stdio.h>
int main()
{
    int i, j, k, L, rows;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    for (i = 1; i <= rows; i++)
    {
        for (j = 1; j <= rows - i; j++)
        {
            printf("  ");
        }
        for (k = 1; k <= i; k++)
        {
            printf("%d ", k);
        }
        for (L = k - 2; L >= 1; L--)
        {
            printf("%d ", L);
        }
        printf("\n");
    }
    return 0;
}