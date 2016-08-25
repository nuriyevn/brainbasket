#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int n;
    
    do {
        printf ("minutes: ");
        n = GetInt ();
    } while (n <= 0);
    
    printf ("bottles: %d\n", n*12);
}