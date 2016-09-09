#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (int argc , string argv[]) 
{
     if (argc == 2)
    {
     string plain_text = GetString();
     int k = atoi (argv [1]);
    k = k % 26 ;
    for (int i = 0, n = strlen(plain_text); i < n; i++)
     {
         if (isalpha(plain_text[i]))
         {
              if (islower(plain_text[i]))
                {
                if (plain_text[i]+k > 122)
                {
                 printf ("%c", plain_text[i]+k-26);
                }
                else 
                {
                 printf("%c", plain_text[i]+k);
                }
                }
          else if (isupper(plain_text[i]))
             {
              if (plain_text[i]+k > 90)
              {
               printf("%c",plain_text[i]+k-26);
              }
             else
             {
              printf("%c",plain_text[i]+k);
             }
             }
         }
         else  
         {
             printf("%c" , plain_text[i]);
         }
    
    
     }
     printf("\n");
    }
  
    
     
    else 
    {
     return 1 ;
    }
     
      
    
    
    
     
}