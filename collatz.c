#include <cs50.h>
#include <stdio.h>

int main (void)
{
   

    int collazt (int n)
{
  if (n == 1)
{
      return 0;
}
 else if ((n %2) == 0)
     {
     return  collazt(n/2);
     }
    else 
        {
        return collazt(3*n+1) ;
        }
      printf("%d\n",n);
 }
    
}




