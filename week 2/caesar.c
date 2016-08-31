#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // key is the second command line argument
    int key = atoi(argv[1]);
    
    string s = GetString();

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            if (isupper(s[i]))
            {
                int letter = (s[i] - 65 + key)%26 + 65;
                printf("%c", letter);
            }
            if (islower(s[i]))
            {
                int letter = (s[i] - 97 + key)%26 + 97;
                printf("%c", letter);
            }
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
