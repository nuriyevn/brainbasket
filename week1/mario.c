#import <cs50.h>
#import <stdio.h>

int main (void)
{
   
    int x ;
    do
   { 
        printf ("Select height of the tower:\n");
        x = GetInt();
   } while (x<0 || x>=24) ;
    
   if (x>=1 && x<=23)
    {
        
        for (int i = 0 ; i < x ; i++) 
        {
            for (int n = x-2; n >= i ; n--)
            {
            printf (" ") ;
            }
            for (int n = 0 ; n <= i+1; n++)
            {
            printf ("#") ;
            }
            
            printf ("\n");
            
            
        }
        
        
    }
}
