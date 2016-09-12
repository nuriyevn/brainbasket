#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc,  string argv[])
{
    int shift;
    if (argc != 2)
    {
        printf("message");
        return 1;
    }
    string key = argv[1];
    int m = strlen(key);
    for(int i = 0; i < m; i++)
    {
        if(!isalpha(key[i]))
        {
            printf("message");
            return 1;
        }
    }
    // key = "Hello"; // H = 7, e = 4 , l = 12
    // text = "Abba baobab"; //
    // modified_text = "Hfml p";
    // Get the string
    string text = GetString();
    
    for(int i = 0, j = 0, n = strlen(text); i < n; i++)
    {
        if(isalpha(text[i]))
        {
        
        
            if (islower(key[j%m]))
            {
                shift = key[j%m] - 'a';
               // printf("shift = %d", shift);
               if (islower(text[i]))
               {
                text[i] = (text[i] - 'a' + shift) % 26 +'a';
               }
               else
               {
               text[i] = (text[i] - 'A' + shift) % 26 +'A';
               }
            }
            // letter A key A
            else
            {
                shift = key[j%m] - 'A';
                //printf("shift = %d", shift);
                
                if (islower(text[i]))
                {
                    
                text[i] = (text[i] -'a' + shift) % 26 + 'a';
                }
                else
                text[i] = (text[i] -'A' + shift) % 26 + 'A';
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
