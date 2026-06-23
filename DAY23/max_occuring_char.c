#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    int i, j, length;
    int max_count = 0;
    char max_char;

    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    length = strlen(str);

    for (i = 0; i < length; i++)
    {
        int count = 0;
        for (j = 0; j < length; j++)
        {
            if (str[i] == str[j])
            {
                count++;
            }
        }
        if (count > max_count)
        {
            max_count = count;
            max_char = str[i];
        }
    }

    printf("Maximum occurring character: %c\n", max_char);
    return 0;
}