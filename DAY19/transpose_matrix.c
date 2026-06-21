#include <stdio.h>
int main()
{
    int i, j, m, n, arr[100][100], transpose[100][100];
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
        for (j = 0; j < n; j++)
        {
            transpose[j][i] = arr[i][j];
        }
    }
    printf("The transpose of the matrix is: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
    return 0;
}