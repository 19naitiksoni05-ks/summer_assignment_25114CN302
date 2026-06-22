#include <stdio.h>
int main()
{
    int i, j, m, n, arr[100][100], sum[100];
    printf("Enter the number of rows and columns in the matrix: ");
    scanf("%d %d", &m, &n);
    printf("Enter the elements of the matrix: ");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (i = 0; i < m; i++)
    {
        sum[i] = 0;
        for (j = 0; j < n; j++)
        {
            sum[i] += arr[i][j];
        }
    }
    printf("Row-wise sums:\n");
    for (i = 0; i < m; i++)
    {
        printf("Sum of row %d = %d\n", i + 1, sum[i]);
    }
    return 0;
}