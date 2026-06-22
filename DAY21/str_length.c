#include <stdio.h>
int main()
{
    int i, j, length=0;
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    for (i = 0; str[i] != '\0'; i++)
    {
        length++;
    }
    printf("Length of the string is: %d\n", length);
    return 0;
}