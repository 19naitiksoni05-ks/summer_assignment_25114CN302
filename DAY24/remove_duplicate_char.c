#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    int i, j, length;
    int found = 0;

    printf("Enter a string: ");
    scanf("%[^\n]", str);
    length = strlen(str);

    for (i = 0; i < length; i++)
    {
        found = 0;
        for (j = 0; j < i; j++)
        {
            if (str[i] == str[j])
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            printf("%c", str[i]);
        }
    }
    return 0;
}
