#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    int i, length, freq;
    printf("Enter a string: ");
    scanf("%[^\n]s", str);
    length = strlen(str);
    while (length>0 && str[length - 1] == ' ')
    {
        str[length - 1] = '\0';
        length--;
    }
    
    printf("Character frequencies:\n");
    for (i = 0; i < length; i++)
    {
        freq = 1;
        if (str[i] != '0')
        {
            for (int j = i + 1; j < length; j++)
            {
                if (str[i] == str[j])
                {
                    freq++;
                    str[j] = '0'; 
                }
            }
            printf("%c: %d\n", str[i], freq);
        }
    }
    return 0;
}