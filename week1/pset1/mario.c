#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("height: ");
    int height = GetInt();
    
    while(height<1 || height>23)
    {
        if(height == 0)
        {
            exit(0);
        }
        printf("height: ");
        height = GetInt();
    }
    
    int hashes = 2;
    
    while(0 < height)
    {
        //calculating and drowing spaces
        int spaces = height - 1;
        while(spaces > 0)
        {
            printf(" ");
            spaces--;
            
        }
        for(int j = 0 ; j < hashes ; j++ )
        {
            printf("#");
        }

        hashes++;
        height--;
        
        printf("\n");
    }
   
    
}