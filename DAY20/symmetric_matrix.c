#include <stdio.h>
int main()
{
    int i, j, n, arr[100][100], is_symmetric = 1;
    printf("Enter the number of rows and columns in the matrix: ");
    scanf("%d %d", &n, &n);
    printf("Enter the elements of the matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] != arr[j][i])
            {
                is_symmetric = 0;
                break;
            }
        }
        if (!is_symmetric)
        {
            break;
        }
    }
    if (is_symmetric)
    {
        printf("The matrix is symmetric.");
    }
    else
    {
        printf("The matrix is not symmetric.");
    }
    return 0;
}