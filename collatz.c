#include <cs50.h>
#include <stdio.h>

int collazt (int n)
{
  if (n == 1)
{
      return 0;
}
 else if ((n %2) == 0)
     {
     return 1 + collazt(n/2);
     }
    else 
        {
        return 1 + collazt(3*n+1) ;
        }
     
 }
    

