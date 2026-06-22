#include <stdio.h>
int main()
{
    int i, j, k, m1, n1, m2, n2, arr1[100][100], arr2[100][100], product[100][100];
    printf("Enter the number of rows and columns in the first matrix: ");
    scanf("%d %d", &m1, &n1);
    printf("Enter the elements of the first matrix: ");
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n1; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("Enter the number of rows and columns in the second matrix: ");
    scanf("%d %d", &m2, &n2);
    if (n1 != m2)
    {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }
    printf("Enter the elements of the second matrix: ");
    for (i = 0; i < m2; i++)
    {
        for (j = 0; j < n2; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            product[i][j] = 0;
            for (k = 0; k < n1; k++)
            {
                product[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    printf("The product of the matrices is:\n");
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }
    return 0;
} 