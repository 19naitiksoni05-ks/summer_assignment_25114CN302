#include <stdio.h>
#include <string.h>
int main()
{
    int i, j, length;
    char str1[100], str2[100];
    int count = 0;

    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    length = strlen(str1);

    if (strlen(str2) != length)
    {
        printf("Strings are not anagrams.\n");
        return 0;
    }

    for (i = 0; i < length; i++)
    {
        count = 0;
        for (j = 0; j < length; j++)
        {
           count += (unsigned char)str1[i] == (unsigned char)str2[j];
        }
        if (count == 0)
        {
            printf("Strings are not anagrams.\n");
            return 0;
        }
    }

    printf("Strings are anagrams.\n");
    return 0;
}