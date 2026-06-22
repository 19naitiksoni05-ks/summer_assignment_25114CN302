#include <stdio.h>
#include <string.h>
int main()
{
    int i, length;
    char str[100];
    printf("Enter a string: "); 
    scanf("%[^\n]s", str);
    length = strlen(str);
    for (i = 0; i < length; i++)
    {
        if (str[i] == ' ')
        {
            str[i] = '\0'; 
        }
    }

    printf("String after removing spaces: ");
    for (i = 0; i < length; i++)
    {
        if (str[i] != '\0')
        {
            printf("%c", str[i]);
        }
    }
    return 0;
}