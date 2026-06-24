#include <stdio.h>
#include <string.h> 
int main()
{
    int i, max_length = 0;
    char str[100], longest_word[100], current_word[100];

    printf("Enter a string: ");
    scanf("%[^\n]%*c", str);

    int length = strlen(str);

    i = 0;
    while (i < length)
    {
        int j = 0;
        while (i < length && str[i] != ' ')
        {
            current_word[j++] = str[i++];
        }
        current_word[j] = '\0';

        if (j > max_length)
        {
            max_length = j;
            strcpy(longest_word, current_word);
        }

        while (i < length && str[i] == ' ')
        {
            i++;
        }
    }
    printf("Longest word: %s\n", longest_word);
    return 0;
}