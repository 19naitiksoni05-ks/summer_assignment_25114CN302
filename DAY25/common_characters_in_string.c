
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, j;

    printf("Enter a string: ");    
    scanf(" %[^\n]", str);

    int len = strlen(str);

    printf("Common (duplicate) characters are:\n");
    for (i = 0; i < len; i++)
    {
        int count = 1;
        if (str[i] == '\0')
            continue;

        for (j = i + 1; j < len; j++)
        {
            if (str[i] == str[j])
            {
                count++;
                str[j] = '\0'; 
            }
        }
        if (count > 1)
            printf("%c ", str[i]);
    }
    printf("\n");
    return 0;
}