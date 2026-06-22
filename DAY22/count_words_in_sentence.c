#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    int i, length, word_count = 0;
    printf("Enter a string: ");
    scanf("%[^\n]s", str);
    length = strlen(str);
    for (i = 0; i < length; i++)
    {
        if (str[i] == ' ' && str[i + 1] != ' ')
        {
            word_count++;
            if (str[i + 1] == '\0')
            {
                word_count--;
            }
        }
    }
    word_count++;
    printf("Number of words in the string: %d\n", word_count);
    return 0;
}