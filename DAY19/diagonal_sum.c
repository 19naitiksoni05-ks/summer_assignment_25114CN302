#include <stdio.h>
int main()
{
   int i, j, m, n, arr[100][100], diagonal_sum = 0;
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
        diagonal_sum += arr[i][i];
        
        if (i != n - i - 1)
        {
            diagonal_sum += arr[i][n - i - 1];
        }
    }
    printf("The sum of the diagonal elements is: %d", diagonal_sum);
    return 0;
}