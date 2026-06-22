#include <stdio.h>
int main()
{
    int i, length,temp, rev_str[100];
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    for (i = 0; str[i] != '\0'; i++)
    {
        length++;
    }
    for (i = 0; i < length; i++)
    {
        rev_str[i] = str[length - i - 1];
    }
    printf("Reversed string is: ");
    for (i = 0; i < length; i++)
    {
        printf("%c", rev_str[i]);
    }
    return 0;
}