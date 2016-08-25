#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    
    // loop to get a positive number
    do 
    {
        printf("minutes: ");
        n = GetInt ();
    } while (n <= 0);
    
    // printing the result
    printf("bottles: %d\n", n * 12);
}