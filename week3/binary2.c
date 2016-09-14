#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("input a decimal number: \n");
    
    int n;
    
    n = GetInt();
    
    int k;
    
    printf("input a digit system: \n");
    
    do
    {
        k = GetInt();
        
    } while ((k < 2) || (k > 9));
    
    int d = 1;
    int power = 0;
    
    do
    {
        d *= k;
        power++;
    } while (d * k <= n);
    
    int bits[power];
    
    int i = 0;
        while (d != 0)
        {
            if (n / d)
            {
                bits[i] = n / d;
                n %= d;
            }
            else
            {
                bits[i] = 0;
            }
            
            d /= k;
            printf("%d", bits[i]);
            
            i++;
        }
    
    printf("\n");
}