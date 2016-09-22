#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int n;
    printf("enter a decimal number: \n");
    
    n = GetInt();
    
    int d = 1;
    int power = 0;
    
    do
    {
        d *= 2; 
        power++;
    } while (d * 2 <= n);
    
    while (d != 0)
    {
        
        printf("%d", n / d);
        
        n %= d;
        d /= 2;
    }
    
    printf("\n");
}