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
    for (j = 0; j < n; j++)
    {
        sum[j] = 0;
        for (i = 0; i < m; i++)
        {
            sum[j] += arr[i][j];
        }
    }
    printf("Column-wise sums:\n");
    for (j = 0; j < n ; j++)
    {
        printf("Sum of column %d = %d\n", j + 1, sum[j]);
    }
    return 0;
}