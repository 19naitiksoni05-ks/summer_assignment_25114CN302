#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    int i, j, length;
    int found = 0;

    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    length = strlen(str);

    for (i = 0; i < length; i++)
    {
        found = 0;
        for (j = 0; j < length; j++)
        {
            if (str[i] == str[j] && i != j)
            {
                found = 1;
                break;
            }
        }
        if (found == 1)
        {
            printf("First repeating character: %c\n", str[i]);
            return 0;
        }
    }

    printf("No repeating character found.\n");
    return 0;
}