#include <stdio.h>
int main()
{
    int i;
    char ch, str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Uppercase: ");
    for (i = 0; str[i] != '\0'; i++)
    {
        ch = str[i];
        if (ch >= 'a' && ch <= 'z')
        {
            printf("%c", ch - ('a' - 'A'));
        }
        else
        {
            printf("%c", ch);
        }
    }
    return 0;
}