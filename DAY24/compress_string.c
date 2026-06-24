#include <stdio.h>
#include <string.h>
int main()
{
    int i;
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    
    int length = strlen(str);
    printf("compressed string is:");

    for (i = 0; i < length; i++)
    {
        int count = 1;
        while (i < length - 1 && str[i] == str[i + 1])
        {
            count++;
            i++;
        }
        printf("%c%d", str[i], count);
    }
    printf("\n");
    return 0;
}