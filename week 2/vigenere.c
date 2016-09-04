#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc,  string argv[])
{
    if (argc != 2)
        printf("Use ./vig key");
        return 1;
    string key = argv[1];
    int m = strlen(key);
    for(int i = 0; i < m; i++)
    {
        if(!isalpha(key[i]))
        printf("Use ./vig key\n");
        return 1;
    }
    // Get the string
    string text = GetString();
    for(int i = 0, j = 0, n = strlen(text); i < n; i++)
    {
        if(isalpha(text[i]))
            {
            if (isupper(text[i]))
                {
                    // letter A key a
                    if(islower(key[j%m]))
                        text[i] = (text[i] - 65 + key[j%m] - 19)%26 + 65;
                    // letter A key A
                    else
                    {
                        text[i] = (text[i] - 65 + key[j%m] - 65)%26 + 65;
                    }
                }
                else
                {
                    if(isupper(key[j%m]))
                    // letter a key A
                        text[i] = (text[i] - 97 + key[j%m] - 13)%26 +97;
                    else
                    // letter a key a
                    {
                        text[i] = (text[i] - 97 + key[j%m] - 97)%26 +97;
                    }
                }
                printf("%c", text[i]);
            j++;
            }
        // !isalpha
        else
            {
                printf("%c", text[i]);
            }
    }
    printf("\n");
    return 0;
}
