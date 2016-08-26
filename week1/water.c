
#include <cs50.h>
#include <stdio.h>

int main(void)
{
     printf ("How long do you take shower?(in minutes, pls)\n") ;
    int y =GetInt ();
    if (y<0)
    {
        printf ("That's not correct!\n");
    }
    else if (y>0)
    {
        int x = y * 12 ;
    printf ("You use %d bottles \n", x) ;
    }
}